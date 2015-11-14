/**
 * @file	ReadInputRegistersRequest.cpp
 * @author	boy
 * @version 
 * @date	03 џэт. 2015 у.
 * @brief
 */

#include "Exception.h"

#include "ReadInputRegistersRequest.h"

namespace modbus {

ReadInputRegistersRequest::ReadInputRegistersRequest(uint16_t start_addr,
														uint16_t quantity) {
	// TODO Auto-generated constructor stub
	if (quantity < 1 && quantity > 0x7D)
	{
		/// error data
		Exception ex("quantity < 1 && quantity > 0x7D");

		throw ex;
	}

	Data data;
	data.start_addr = __builtin_bswap16(start_addr);
	data.quantity = __builtin_bswap16(quantity);
	std::vector<uint8_t> data_v((uint8_t*)&data, (uint8_t*)((uint8_t*)&data + sizeof(data)));

	Request::pdu_.reset(new PDU(function_code_, data_v));
}

ReadInputRegistersRequest::~ReadInputRegistersRequest() {
	// TODO Auto-generated destructor stub
}

} /* namespace modbus */
