/**
 * @file	ReadInputRegistersRequest.h
 * @author	boy
 * @version 
 * @date	03 џэт. 2015 у.
 * @brief
 */
#ifndef READINPUTREGISTERSREQUEST_H_
#define READINPUTREGISTERSREQUEST_H_

#include "Request.h"

namespace modbus {

class ReadInputRegistersRequest : public Request {
public:
	ReadInputRegistersRequest(uint16_t start_addr,
								uint16_t quantity);
	~ReadInputRegistersRequest();

private:
	struct Data {
		uint16_t start_addr;
		uint16_t quantity;
	};

	const uint8_t function_code_ = 0x04;
};

} /* namespace modbus */

#endif /* READINPUTREGISTERSREQUEST_H_ */
