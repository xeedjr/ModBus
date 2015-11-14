/**
 * @file	Exception.h
 * @author	boy
 * @version 
 * @date	01 февр. 2015 г.
 * @brief
 */
#ifndef EXCEPTION_H_
#define EXCEPTION_H_

#include <exception>
#include <string>
#include <sstream>

namespace modbus {

class Exception : public std::exception {
public:
	Exception(const std::string& err) {
		what_ += err;
	};
	~Exception() {
		/// empty
	};

	template<typename T>
	Exception& operator <<(T const& right)	{
		std::stringstream sstr;
		sstr << what_ << right;
		what_ = sstr.str();

		return *this;
	}

	const char* what() const noexcept {
		return what_.c_str();
	}

private:
	std::string what_ = "ModBus Lib Error: ";
};

} /* namespace modbus */

#endif /* EXCEPTION_H_ */
