#include "Server.h"


Server::Server(std::shared_ptr<boost::asio::io_context> io, const std::string& address, uint16_t port)
	: io_(std::move(io)),
	endpoint_(setEndpoint(address, port)),
	acceptor_(*io_, endpoint_),
	fileManager(FileManager::getInstance())
{

}


boost::asio::ip::tcp::endpoint Server::setEndpoint(const std::string_view endpointAddress, uint16_t port)
{
	return boost::asio::ip::tcp::endpoint(boost::asio::ip::make_address(endpointAddress), port);
}

void Server::setDefPath(std::filesystem::path path)
{
	fileManager.setDefFolder(path);
}



void Server::connect()
{
	newConnection();
}


void Server::newConnection()
{
	auto socket_ = std::make_shared<boost::asio::ip::tcp::socket>(*io_);

	acceptor_.async_accept(*socket_,
		[self = shared_from_this(), socket_](const boost::system::error_code& ec) {
		if (!ec)
		{
			auto connect = std::make_shared<Connection>(std::move(*socket_));
			self->connections_.push_back(connect);
			connect->getConnectionInfo();
		}
		self->newConnection();
		}
	);
}