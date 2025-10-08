#include "Server.h"

int main()
{
	auto io = std::make_shared<boost::asio::io_context>();

	auto server = std::make_shared<Server>(io);

	server->connect();

	io->run();

	return 0;
}