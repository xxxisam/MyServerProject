#include <iostream>
#include <boost/asio.hpp>



int main()
{
	boost::asio::io_context io;

	const boost::asio::ip::tcp::endpoint endpoint(boost::asio::ip::make_address("127.0.0.1"), 8080);
	boost::asio::ip::tcp::socket clientSocket(io);

	clientSocket.connect(endpoint);



	return 0;
}