/**
 * @file	ModbusSerialTransaction.cpp
 * @author	boy
 * @version 
 * @date	03 џэт. 2015 у.
 * @brief
 */
#include "ModbusSerialTransaction.h"

namespace modbus {

ModbusSerialTransaction::ModbusSerialTransaction(SerialConnection& ser_conn) {
	// TODO Auto-generated constructor stub
	ser_conn_ = &ser_conn;
}

ModbusSerialTransaction::~ModbusSerialTransaction() {
	// TODO Auto-generated destructor stub
}

ReadInputRegistersResponse
ModbusSerialTransaction::ExecRequest(ReadInputRegistersRequest& request) {
	return ExecRequest<ReadInputRegistersRequest, ReadInputRegistersResponse>(request);
}

ReadHoldingRegistersResponse
ModbusSerialTransaction::ExecRequest(ReadHoldingRegistersRequest& request) {
	return ExecRequest<ReadHoldingRegistersRequest, ReadHoldingRegistersResponse>(request);
}

template<typename TReq, typename TResp>
TResp ModbusSerialTransaction::ExecRequest(TReq& request) {

	std::lock_guard<std::mutex> lck (transaction_lck_);

	ser_conn_->send_request(request);
	TResp response(ser_conn_->get_response());

	return response;
}
} /* namespace modbus */
