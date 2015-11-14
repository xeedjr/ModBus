/**
 * @file	SerialConnection.cpp
 * @author	boy
 * @version 
 * @date	03 џэт. 2015 у.
 * @brief
 */
#include <boost/bind.hpp>

#include "Exception.h"
#include "ADURTU.h"

#include "SerialConnection.h"

using namespace boost;

namespace modbus {

SerialConnection::SerialConnection(SerialParameters& params) {
	params_ = params;
}

SerialConnection::~SerialConnection() {
	close();
}

void SerialConnection::open() {
	port_.reset(new asio::serial_port(io_, params_.getPortName()));
	recv_timer_.reset(new asio::deadline_timer(io_));
	//recv_flush_timer_.reset(new asio::deadline_timer(io_));

	port_->set_option(asio::serial_port_base::baud_rate(params_.getBaudRate()));

	io_thread_ = thread(&SerialConnection::service_io_thread, this);
}

void SerialConnection::close() {
	port_->close();
}

void SerialConnection::send_request(Request& request) {
	ADURTU send_adu_rtu(request.get_unit_id(),
					request.get_pdu());
	std::vector<uint8_t> response_adu;

	/// clear for new frame
	recv_raw_data_.clear();

	asio::write(*port_, asio::buffer(send_adu_rtu.get()));
}

std::unique_ptr<Response>
SerialConnection::get_response() {
	std::unique_lock<std::mutex> lck(recv_mutex_);

	if (recv_cv_.wait_for(lck, std::chrono::seconds(rtu_timeot_receive_responce_sec_)) ==
			std::cv_status::timeout) {
		/// Error received responce Timeout
		Exception ex("Received response timeout sec = ");
		ex << rtu_timeot_receive_responce_sec_;

		throw ex;
	};

	ADURTU recv_adu_rtu(recv_raw_data_);

	std::unique_ptr<Response> response(new Response(recv_adu_rtu.get_unit_id(),
													recv_adu_rtu.get_pdu()));

	return response;
}





/// @brief tcflush - flush non-transmitted output data, non-read input data or both
/// Flush a serial port's buffers. Oll data in buffer is
///
/// @param serial_port Port to flush.
/// @param what Determines the buffers to flush.
/// @param error Set to indicate what error occurred, if any.
void SerialConnection::flush_serial_port(boost::asio::serial_port& serial_port,
										  flush_type what,
										  boost::system::error_code& error)
{
  if (0 == ::tcflush(serial_port.lowest_layer().native_handle(), what))
  {
    error = boost::system::error_code();
  }
  else
  {
    error = boost::system::error_code(errno,
        boost::asio::error::get_system_category());
  }
}


void SerialConnection::start_frame() {

	/// Flush deadline timer on
	//recv_flush_timer_->expires_from_now(boost::posix_time::microseconds(rtu_timeout_flush_recv_us_));
	//recv_flush_timer_->async_wait(boost::bind(&SerialConnection::timer_recv_flush,
	//										this,
	//										boost::asio::placeholders::error));
}

void SerialConnection::stop_frame() {
	/// Flush deadline timer off
	//recv_flush_timer_->cancel();

	std::unique_lock<std::mutex> lck(recv_mutex_);
	recv_cv_.notify_one();
}

/*
void SerialConnection::timer_recv_flush(const boost::system::error_code& error) {
	if (error)
	{
		/// errror
		return;
	}

	boost::system::error_code error_fl;

	if (recv_flush_timer_->expires_from_now(boost::posix_time::microseconds(rtu_timeout_flush_recv_us_)) > 0)
	{
		// We managed to cancel the timer. Start new asynchronous wait.
		recv_flush_timer_->async_wait(boost::bind(&SerialConnection::timer_recv_flush,
												this,
												boost::asio::placeholders::error));
	}
	else
	{
		// Too late, timer has already expired!
	}
}
*/

void SerialConnection::timer_expired(const boost::system::error_code& error) {
	if (error)
	{
		/// errror
		return;
	}

	/// frame received
	if (recv_raw_data_.size() > 0)
	{
		stop_frame();
	}
}

void SerialConnection::receiver_complete(const boost::system::error_code& error,
											size_t bytes_transferred) {
	if (recv_raw_data_.size() == 0)
		start_frame();

	recv_raw_data_.push_back(recv_byte_);

	start_receive();

	if (recv_timer_->expires_from_now(boost::posix_time::milliseconds(rtu_silence_interval_ms_)) > 0)
	{
		// We managed to cancel the timer. Start new asynchronous wait.
		recv_timer_->async_wait(boost::bind(&SerialConnection::timer_expired,
												this,
												boost::asio::placeholders::error));
	}
	else
	{
		// Too late, timer has already expired!
		recv_timer_->async_wait(boost::bind(&SerialConnection::timer_expired,
												this,
												boost::asio::placeholders::error));
	}
}

void SerialConnection::start_receive() {
	asio::async_read(*port_,
						boost::asio::buffer(&recv_byte_, 1),
						boost::bind(&SerialConnection::receiver_complete,
									this,
									boost::asio::placeholders::error,
									boost::asio::placeholders::bytes_transferred));
}

void SerialConnection::service_io_thread(void) {
	///asio::read(*port_, asio::buffer(response_adu));

	recv_raw_data_.clear();
	start_receive();

	while (true) {
		io_.run();
	}
}

} /* namespace modbus */
