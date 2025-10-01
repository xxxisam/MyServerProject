#include "Connection.h"


Connection::Connection(boost::asio::ip::tcp::socket socket) : socket_(std::move(socket))
{

}


void Connection::getConnectionInfo()
{
	std::cout << socket_.remote_endpoint().address().to_string() << ":" << socket_.remote_endpoint().port();
}

boost::asio::ip::tcp::socket& Connection::getSocket()
{
	return socket_;
}