/**
 * @file	Response.h
 * @author	boy
 * @version 
 * @date	18 џэт. 2015 у.
 * @brief
 */
#ifndef RESPONSE_H_
#define RESPONSE_H_

#include <memory>

#include "PDU.h"

namespace modbus {

class Response {
public:
	Response(uint8_t unit_id, std::unique_ptr<PDU> pdu);
	~Response();

	uint8_t get_unit_id();
	std::unique_ptr<PDU>& get_pdu();
private:
	uint8_t unit_id_ = 0;
	std::unique_ptr<PDU> pdu_;
};

} /* namespace modbus */

#endif /* RESPONSE_H_ */
