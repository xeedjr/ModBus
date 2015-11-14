/**
 * @file	Request.cpp
 * @author	boy
 * @version 
 * @date	04 џэт. 2015 у.
 * @brief
 */
#include "Request.h"

namespace modbus {

Request::Request() {
	// TODO Auto-generated constructor stub

}

Request::~Request() {
	// TODO Auto-generated destructor stub
}

void Request::set_unit_id(uint8_t unit_id) {
	unit_id_ = unit_id;
}
uint8_t Request::get_unit_id() {
	return unit_id_;
}

PDU& Request::get_pdu() {
	return *pdu_;
}

} /* namespace modbus */
