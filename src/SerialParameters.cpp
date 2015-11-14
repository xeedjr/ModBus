/**
 * @file	SerialParameters.cpp
 * @author	boy
 * @version 
 * @date	03 џэт. 2015 у.
 * @brief
 */
#include "SerialParameters.h"

namespace modbus {

SerialParameters::SerialParameters() {
	// TODO Auto-generated constructor stub

}

SerialParameters::~SerialParameters() {
	// TODO Auto-generated destructor stub
}

void SerialParameters::setPortName(std::string port_name) {
	port_name_ = port_name;
}

void SerialParameters::setBaudRate(uint32_t baud_rate) {
	baud_rate_ = baud_rate;
}

void SerialParameters::setDatabits(uint8_t data_bit) {
	data_bit_ = data_bit;
}

void SerialParameters::setParity(Parity parity) {
	parity_ = parity;
}

void SerialParameters::setStopbits(uint8_t stop_bits) {
	stop_bits_ = stop_bits;
}

void SerialParameters::setEncoding(Encoding encoding) {
	encoding_ = encoding;
}

void SerialParameters::setEcho(bool echo) {
	echo_ = echo;
}

std::string SerialParameters::getPortName() {
	return port_name_;
}

uint32_t SerialParameters::getBaudRate() {
	return baud_rate_;
}

} /* namespace modbus */
