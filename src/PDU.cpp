/**
 * @file	PDU.cpp
 * @author	boy
 * @version 
 * @date	04  эт. 2015 у.
 * @brief
 */

#include "Exception.h"

#include "PDU.h"

namespace modbus {

PDU::PDU(uint8_t function_code,
		std::vector<uint8_t> data) {
	/// Valid codes are in the range of 1 ... 255 decimal
	/// (the range 128 Ц 255 is reserved and used for exception responses)
	/// The size of the MODBUS PDU is limited by the size constraint inherited from the first
	/// MODBUS implementation on Serial Line network (max. RS485 ADU = 256 bytes).
	if (function_code == 0) {
		Exception ex("function code error ");
		ex << "must bee 1 ... 255";
		throw ex;
	}

	if ((data.size() + sizeof(function_code)) > 256) {
		Exception ex("data size + functio n code > 256");
		throw ex;
	}

	pdu_.push_back(function_code);
	pdu_.insert(pdu_.end(), data.begin(), data.end());
}

PDU::PDU(std::vector<uint8_t>& raw_pdu) {
	pdu_ = raw_pdu;
}

PDU::~PDU() {
	// TODO Auto-generated destructor stub
}

std::vector<uint8_t>& PDU::get() {
	return pdu_;
}

uint8_t PDU::get_function_code() {
	return pdu_.at(0);
}

void PDU::get_data(std::vector<uint8_t>& data) {
	data.assign(pdu_.begin() + 1, pdu_.end());
}

} /* namespace modbus */
