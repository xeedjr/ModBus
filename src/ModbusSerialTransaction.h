/**
 * @file	ModbusSerialTransaction.h
 * @author	boy
 * @version 
 * @date	03 џэт. 2015 у.
 * @brief
 */
#ifndef MODBUSSERIALTRANSACTION_H_
#define MODBUSSERIALTRANSACTION_H_

#include <mutex>

#include "ReadInputRegistersRequest.h"
#include "ReadInputRegistersResponse.h"
#include "ReadHoldingRegistersRequest.h"
#include "ReadHoldingRegistersResponse.h"


#include "SerialConnection.h"

namespace modbus {

class ModbusSerialTransaction {
public:
	ModbusSerialTransaction(SerialConnection& ser_conn);
	~ModbusSerialTransaction();

	ReadInputRegistersResponse
	ExecRequest(ReadInputRegistersRequest& request);
	ReadHoldingRegistersResponse
	ExecRequest(ReadHoldingRegistersRequest& request);

private:
	template<typename TReq, typename TResp>
	TResp ExecRequest(TReq& request);

	std::mutex transaction_lck_;
	SerialConnection* ser_conn_;
};

} /* namespace modbus */

#endif /* MODBUSSERIALTRANSACTION_H_ */
