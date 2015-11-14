/**
 * @file	SerialConnection.h
 * @author	boy
 * @version 
 * @date	03 џэт. 2015 у.
 * @brief
 */
#ifndef SERIALCONNECTION_H_
#define SERIALCONNECTION_H_

#include <memory>
#include <mutex>              // std::mutex, std::unique_lock
#include <condition_variable>

#include <boost/asio/serial_port.hpp>
#include <boost/asio.hpp>
#include <boost/thread.hpp>

#include "SerialParameters.h"
#include "Request.h"
#include "Response.h"


namespace modbus {

class SerialConnection {
public:
	SerialConnection(SerialParameters& params);
	~SerialConnection();

	void open();
	void close();

	void send_request(Request& request);
	std::unique_ptr<Response> get_response();
private:
	/// @brief Different ways a serial port may be flushed.
	enum flush_type
	{
	  flush_receive = TCIFLUSH,
	  flush_send = TCIOFLUSH,
	  flush_both = TCIOFLUSH
	};

	void flush_serial_port(boost::asio::serial_port& serial_port,
							  flush_type what,
							  boost::system::error_code& error);
	void start_frame();
	void stop_frame();
	void timer_recv_flush(const boost::system::error_code& error);
	void timer_expired(const boost::system::error_code& e);
	void receiver_complete(const boost::system::error_code& error,
			size_t bytes_transferred);
	void service_io_thread(void);
	void start_receive();
	uint8_t recv_byte_;
	std::vector<uint8_t> recv_raw_data_;
	//std::unique_ptr<boost::asio::deadline_timer> recv_flush_timer_;
	std::unique_ptr<boost::asio::deadline_timer> recv_timer_;
	SerialParameters params_;

	std::mutex recv_mutex_;
	std::condition_variable recv_cv_;

	boost::thread io_thread_;
	boost::asio::io_service io_;
	std::unique_ptr<boost::asio::serial_port> port_;

	//const uint32_t rtu_timeout_flush_recv_us_ = 1000;
	const uint32_t rtu_silence_interval_ms_ = 200;
	const uint32_t rtu_timeot_receive_responce_sec_ = 1;
	//const uint32_t rtu_timeout_recv_s = 10;
};

} /* namespace modbus */

#endif /* SERIALCONNECTION_H_ */
