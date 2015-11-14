/**
 * @file	ReadHoldingRegistersResponse.h
 * @author	boy
 * @version 
 * @date	25 џэт. 2015 у.
 * @brief
 */
#ifndef READHOLDINGREGISTERSRESPONSE_H_
#define READHOLDINGREGISTERSRESPONSE_H_

#include "Response.h"

namespace modbus {

class ReadHoldingRegistersResponse {
public:
	ReadHoldingRegistersResponse(std::unique_ptr<Response> response);
	~ReadHoldingRegistersResponse();

	std::vector<uint16_t>&
	get_registers(void);
private:
	std::vector<uint16_t> data_;
	const uint8_t function_code_ = 0x03;
};

} /* namespace modbus */

#endif /* READHOLDINGREGISTERSRESPONSE_H_ */
