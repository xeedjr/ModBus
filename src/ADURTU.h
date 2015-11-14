/**
 * @file	ADURTU.h
 * @author	boy
 * @version 
 * @date	04 џэт. 2015 у.
 * @brief
 */
#ifndef ADURTU_H_
#define ADURTU_H_

#include <vector>
#include <cstdint>
#include <memory>

#include "PDU.h"

namespace modbus {

class ADURTU {
public:
	ADURTU(uint8_t unit_id, PDU& pdu);
	ADURTU(std::vector<uint8_t>& adu);
	~ADURTU();

	std::vector<uint8_t>& get();
	uint8_t get_unit_id();
	std::unique_ptr<PDU> get_pdu();
private:
	std::vector<uint8_t> adu_;
};

} /* namespace modbus */

#endif /* ADURTU_H_ */
