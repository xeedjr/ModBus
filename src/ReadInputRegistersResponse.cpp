/**
 * @file	ReadInputRegistersResponse.cpp
 * @author	boy
 * @version 
 * @date	04 џэт. 2015 у.
 * @brief
 */

#include "Exception.h"
#include "ExceptionResponse.h"

#include "ReadInputRegistersResponse.h"

namespace modbus {

ReadInputRegistersResponse::ReadInputRegistersResponse(std::unique_ptr<Response> response) {

	if (response->get_pdu()->get_function_code() == function_code_ + 0x80)
	{
		/// Received Exception
		std::vector<uint8_t> exception_code;
		response->get_pdu()->get_data(exception_code);
		throw ExceptionResponse(exception_code.at(0));
	}

	if (response->get_pdu()->get_function_code() != function_code_) {
		Exception ex("error function code ");
		ex << "must bee " << function_code_ << " received " << response->get_pdu()->get_function_code();

		throw ex;
	}


	std::vector<uint8_t> data;
	response->get_pdu()->get_data(data);

	/// cheack received input registers
	if (data.at(0) != (data.size() - 1)) {
		Exception ex("received data size not match with size in packet ");

		throw ex;
	}

	if ((data.at(0) % 2) != 0) {
		Exception ex("Received Data size not % 2");

		throw ex;
	};

	/// convert uint8_t to uint_16_t
	for (auto it = (data.begin() + 1); it != data.end(); it += 2) {
		uint16_t val = ((*it << 8) + *(it + 1));
		data_.push_back(val);
	}

	//data_.assign(data.begin() + 1, data.end());
}

ReadInputRegistersResponse::~ReadInputRegistersResponse() {
	// TODO Auto-generated destructor stub
}

std::vector<uint16_t>&
ReadInputRegistersResponse::get_registers(void) {
	return data_;
}

} /* namespace modbus */
