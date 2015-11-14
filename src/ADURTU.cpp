/**
 * @file	ADURTU.cpp
 * @author	boy
 * @version 
 * @date	04 џэт. 2015 у.
 * @brief
 */

#include "mbcrc.h"

#include "Exception.h"
#include "ADURTU.h"

namespace modbus {

ADURTU::ADURTU(uint8_t unit_id, PDU& pdu) {
	adu_.push_back(unit_id);
	adu_.insert(adu_.end(), pdu.get().begin(), pdu.get().end());

	//uint16_t crc = __builtin_bswap16(usMBCRC16(adu_.data(), adu_.size()));
	uint16_t crc = __builtin_bswap16(crc16(adu_.data(), adu_.size()));
	adu_.insert(adu_.end(), reinterpret_cast<uint8_t*>(&crc), reinterpret_cast<uint8_t*>(&crc) + sizeof(crc));
}

ADURTU::ADURTU(std::vector<uint8_t>& adu) {
	uint16_t crc = __builtin_bswap16(crc16(adu.data(), adu.size()));
	if (crc != 0) {
		Exception ex("crc error ");

		throw ex;
	}

	adu_ = adu;
}

ADURTU::~ADURTU() {
	// TODO Auto-generated destructor stub
}

std::vector<uint8_t>& ADURTU::get() {
	return adu_;
}

uint8_t ADURTU::get_unit_id() {
	return adu_.at(0);
}

std::unique_ptr<PDU> ADURTU::get_pdu() {
	auto size = adu_.size();
	std::vector<uint8_t> data(adu_.begin() + 1, adu_.end() - 2);

	std::unique_ptr<PDU> pdu(new PDU(data));

	return pdu;
}

} /* namespace modbus */
