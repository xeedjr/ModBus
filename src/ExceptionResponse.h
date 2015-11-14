/**
 * @file	ExceptionResponse.h
 * @author	boy
 * @version 
 * @date	01 февр. 2015 г.
 * @brief
 */
#ifndef EXCEPTIONRESPONSE_H_
#define EXCEPTIONRESPONSE_H_

#include <exception>
#include <cstdint>

namespace modbus {

class ExceptionResponse : public std::exception {
public:
	ExceptionResponse(uint8_t exception_code) {
		exception_code_ = exception_code;
	};
	~ExceptionResponse() {
		/// empty
	};


	const char* what() const noexcept {
		return "Received exception responce";
	}
private:
	uint8_t exception_code_;
};

} /* namespace modbus */

#endif /* EXCEPTIONRESPONSE_H_ */
