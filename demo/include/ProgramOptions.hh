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


#ifndef DEMO_INCLUDE_PROGRAMOPTIONS_HH_
#define DEMO_INCLUDE_PROGRAMOPTIONS_HH_

#include <cstddef>
#include <map>
#include <ostream>
#include <stdexcept>
#include <string>
#include <vector>

namespace po {

/**
 * Holds the raw text of a parsed option value and converts it on demand.
 */
class OptionValue {
  public:
	OptionValue()
	    : _value(), _set(false) {
	}

	explicit OptionValue(std::string value)
	    : _value(std::move(value)), _set(true) {
	}

	template <typename T>
	T as() const;

  private:
	std::string _value;

	bool _set;
};

template <>
inline std::string OptionValue::as<std::string>() const {
	return _value;
}

template <>
inline int OptionValue::as<int>() const {
	return std::stoi(_value);
}

struct value_semantic {};

template <typename T>
inline value_semantic value() {
	return value_semantic();
}


class options_description {
  public:
	struct option {
		std::string name;
		std::string help;
		bool takesValue;
	};

	explicit options_description(std::string caption)
	    : _caption(std::move(caption)) {
	}


	class adder {
	  public:
		explicit adder(options_description& owner)
		    : _owner(owner) {}

		adder& operator()(const std::string& name, const std::string& help) {
			_owner._options.push_back({name, help, false});
			return *this;
		}

		adder& operator()(const std::string& name, const value_semantic&, const std::string& help) {
			_owner._options.push_back({name, help, true});
			return *this;
		}

	  private:
		options_description& _owner;
	};

	adder add_options() {
		return adder(*this);
	}

	const std::vector<option>& options() const {
		return _options;
	}

	const std::string& caption() const {
		return _caption;
	}

	const option* find(const std::string& name) const {
		for (const option& o : _options)
			if (o.name == name)
				return &o;
		return nullptr;
	}

  private:
	std::string _caption;

	std::vector<option> _options;
};

inline std::ostream& operator<<(std::ostream& os, const options_description& desc) {
	os << desc.caption() << ":\n";
	for (const options_description::option& o : desc.options()) {
		os << "  --" << o.name << (o.takesValue ? " arg" : "")
		   << "\t" << o.help << "\n";
	}
	return os;
}

class variables_map {
  public:
	std::size_t count(const std::string& name) const {
		return _values.count(name);
	}

	bool empty() const {
		return _values.empty();
	}

	const OptionValue& operator[](const std::string& name) const {
		return _values.at(name);
	}

	std::map<std::string, OptionValue>& values() {
		return _values;
	}

  private:
	std::map<std::string, OptionValue> _values;
};

inline variables_map parse_command_line(int argc, char* argv[], const options_description& desc) {
	variables_map vm;

	for (int i = 1; i < argc; ++i) {
		std::string arg(argv[i]);

		if (arg.rfind("--", 0) != 0)
			throw std::runtime_error("unrecognised option '" + arg + "'");

		std::string name = arg.substr(2);
		std::string inlineValue;
		bool hasInlineValue = false;

		std::string::size_type eq = name.find('=');
		if (eq != std::string::npos) {
			inlineValue = name.substr(eq + 1);
			name = name.substr(0, eq);
			hasInlineValue = true;
		}

		const options_description::option* def = desc.find(name);
		if (def == nullptr)
			throw std::runtime_error("unrecognised option '--" + name + "'");

		if (def->takesValue) {
			std::string value;
			if (hasInlineValue) {
				value = inlineValue;
			} else if (i + 1 < argc) {
				value = argv[++i];
			} else {
				throw std::runtime_error("option '--" + name + "' requires an argument");
			}
			vm.values()[name] = OptionValue(value);
		} else {
			vm.values()[name] = OptionValue();
		}
	}

	return vm;
}

inline void store(variables_map parsed, variables_map& vm) {
	vm = std::move(parsed);
}

inline void notify(variables_map&) {}

} // namespace po

#endif /* DEMO_INCLUDE_PROGRAMOPTIONS_HH_ */
