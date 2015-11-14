/**
 * @file	Request.h
 * @author	boy
 * @version 
 * @date	04 џэт. 2015 у.
 * @brief
 */
#ifndef REQUEST_H_
#define REQUEST_H_

#include <memory>

#include "PDU.h"

namespace modbus {

class Request {
public:
	Request();
	~Request();

	void set_unit_id(uint8_t unit_id);
	uint8_t get_unit_id();

	PDU& get_pdu();
protected:
	uint8_t unit_id_ = 0;
	std::unique_ptr<PDU> pdu_;
};

} /* namespace modbus */

#endif /* REQUEST_H_ */
