/**
 * @file	ReadHoldingRegistersRequest.h
 * @author	boy
 * @version 
 * @date	25 џэт. 2015 у.
 * @brief
 */
#ifndef READHOLDINGREGISTERSREQUEST_H_
#define READHOLDINGREGISTERSREQUEST_H_

#include <cstdint>

#include "Request.h"

namespace modbus {

class ReadHoldingRegistersRequest  : public Request {
public:
	ReadHoldingRegistersRequest(uint16_t start_addr,
								uint16_t quantity);
	~ReadHoldingRegistersRequest();

private:
	struct Data {
		uint16_t start_addr;
		uint16_t quantity;
	};

	const uint8_t function_code_ = 0x03;
};

} /* namespace modbus */

#endif /* READHOLDINGREGISTERSREQUEST_H_ */
