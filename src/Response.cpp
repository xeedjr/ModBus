/**
 * @file	Response.cpp
 * @author	boy
 * @version 
 * @date	18 џэт. 2015 у.
 * @brief
 */
#include "Response.h"

namespace modbus {

Response::Response(uint8_t unit_id, std::unique_ptr<PDU> pdu) {
	// TODO Auto-generated constructor stub
	unit_id_ = unit_id;
	pdu_ = std::move(pdu);
}

Response::~Response() {
	// TODO Auto-generated destructor stub
}

uint8_t Response::get_unit_id() {
	return unit_id_;
}

std::unique_ptr<PDU>& Response::get_pdu() {
	return pdu_;
}

} /* namespace modbus */
