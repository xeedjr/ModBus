/**
 * @file	ReadInputRegistersResponse.h
 * @author	boy
 * @version 
 * @date	04 џэт. 2015 у.
 * @brief
 */
#ifndef READINPUTREGISTERSRESPONSE_H_
#define READINPUTREGISTERSRESPONSE_H_

#include "Response.h"

namespace modbus {

class ReadInputRegistersResponse {
public:
	ReadInputRegistersResponse(std::unique_ptr<Response> response);
	~ReadInputRegistersResponse();

	std::vector<uint16_t>&
	get_registers(void);
private:
	std::vector<uint16_t> data_;
	const uint8_t function_code_ = 0x04;
};

} /* namespace modbus */

#endif /* READINPUTREGISTERSRESPONSE_H_ */
