/**
 * @file	SerialParameters.h
 * @author	boy
 * @version 
 * @date	03 џэт. 2015 у.
 * @brief
 */
#ifndef SERIALPARAMETERS_H_
#define SERIALPARAMETERS_H_

#include <string>
#include <cstdint>

namespace modbus {

class SerialParameters {
public:
	enum Parity {
		kNone
	};
	enum Encoding {
		kRTU,
		kASCII,
	};
public:
	SerialParameters();
	~SerialParameters();

	void setPortName(std::string port_name);
	void setBaudRate(uint32_t baud_rate);
	void setDatabits(uint8_t data_bit);
	void setParity(Parity parity);
	void setStopbits(uint8_t stop_bits);
	void setEncoding(Encoding encoding);
	void setEcho(bool echo);

	std::string getPortName();
	uint32_t getBaudRate();
private:
	std::string port_name_;
	uint32_t baud_rate_ = 9600;
	uint8_t data_bit_ = 8;
	Parity parity_ = kNone;
	uint8_t stop_bits_ = 1;
	Encoding encoding_ = kRTU;
	bool echo_ = false;
};

} /* namespace modbus */

#endif /* SERIALPARAMETERS_H_ */
