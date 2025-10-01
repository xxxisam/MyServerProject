#pragma once

#include <vector>
#include <boost/asio.hpp>
#include <memory>
#include <iostream>

class Connection : public std::enable_shared_from_this<Connection>
{
public:
	Connection(boost::asio::ip::tcp::socket socket);

	void getConnectionInfo();

	boost::asio::ip::tcp::socket& getSocket();

private:
	boost::asio::ip::tcp::socket socket_;
};

