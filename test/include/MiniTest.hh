/*
 * MIT License
 *
 * Copyright (c) 2015 Alexis LE GOADEC
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 *
 */

#ifndef TEST_INCLUDE_MINITEST_HH_
#define TEST_INCLUDE_MINITEST_HH_

#include <functional>
#include <iostream>
#include <string>
#include <vector>

#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

namespace minitest {

typedef void (*Fixture)();
typedef void (*Body)();

struct TestCase {
	std::string suite;
	std::string name;
	Body body;
	Fixture init;
	Fixture fini;
};

inline std::vector<TestCase>& registry() {
	static std::vector<TestCase> instance;
	return instance;
}

inline int& failureCount() {
	static int count = 0;
	return count;
}

struct Registrar {
	Registrar(const std::string& suite, const std::string& name, Body body, Fixture init, Fixture fini) {
		registry().push_back({suite, name, body, init, fini});
	}
};

inline void check(bool condition, const char* expr, const std::string& message, const char* file, int line) {
	if(!condition) {
		++failureCount();
		std::cerr << "    [FAIL] " << file << ":" << line << ": (" << expr << ")";
		if(!message.empty())
			std::cerr << " -- " << message;
		std::cerr << std::endl;
	}
}

inline int runAll() {
	int total = 0;
	int passed = 0;

	for (const TestCase& test : registry()) {
		++total;
		std::cout << "[ RUN  ] " << test.suite << "." << test.name << std::endl;
		std::cout.flush();

		pid_t pid = fork();
		if(pid == 0) {
			/* Child: run the test in isolation. */
			if(test.init) test.init();
			test.body();
			if(test.fini) test.fini();
			std::cout.flush();
			std::cerr.flush();
			_exit(failureCount() == 0 ? 0 : 1);
		} else if(pid > 0) {
			int status = 0;
			waitpid(pid, &status, 0);
			bool ok = WIFEXITED(status) && WEXITSTATUS(status) == 0;
			if(ok) {
				++passed;
				std::cout << "[  OK  ] " << test.suite << "." << test.name << std::endl;
			} else {
				std::cout << "[ FAIL ] " << test.suite << "." << test.name << std::endl;
			}
		} else {
			std::cerr << "fork() failed for " << test.suite << "." << test.name << std::endl;
		}
	}

	std::cout << "\n"
	          << passed << "/" << total << " tests passed." << std::endl;
	return (passed == total) ? 0 : 1;
}

} // namespace minitest

/**
 * Declare a test. init / fini may be a fixture function or nullptr.
 */
#define TEST(suite, name, init, fini)                      \
	static void suite##_##name##_body();                   \
	static minitest::Registrar suite##_##name##_registrar( \
		#suite, #name, suite##_##name##_body, init, fini); \
	static void suite##_##name##_body()

#define cr_expect(cond, ...) \
	minitest::check((cond), #cond, std::string("" __VA_ARGS__), __FILE__, __LINE__)

#define cr_assert(cond, ...) \
	minitest::check((cond), #cond, std::string("" __VA_ARGS__), __FILE__, __LINE__)

#define MINITEST_MAIN              \
	int main() {                   \
		return minitest::runAll(); \
	}

#endif /* TEST_INCLUDE_MINITEST_HH_ */
