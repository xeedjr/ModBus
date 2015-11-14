/**
 * @file	PDU.h
 * @author	boy
 * @version 
 * @date	04 џэт. 2015 у.
 * @brief
 */
#ifndef PDU_H_
#define PDU_H_

#include <cstdint>
#include <vector>

namespace modbus {

class PDU {
public:
	PDU(uint8_t function_code,
		std::vector<uint8_t> data);
	PDU(std::vector<uint8_t>& raw_pdu);
	~PDU();

	std::vector<uint8_t>& get();

	uint8_t get_function_code();
	void get_data(std::vector<uint8_t>& data);
private:
	std::vector<uint8_t> pdu_;
};

} /* namespace modbus */

#endif /* PDU_H_ */
