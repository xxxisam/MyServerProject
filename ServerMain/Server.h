#pragma once
#define _WIN32_WINNT 0x0601

#include <iostream>
#include <boost/asio.hpp>
#include <memory>
#include <string>
#include <filesystem>
#include "Connection.h"
#include "FileManager.h"


class Server : public std::enable_shared_from_this<Server>
{
public:
	Server(std::shared_ptr<boost::asio::io_context> io,
		   const std::string& address = "127.0.0.1",
		   uint16_t port = 8080);

	boost::asio::ip::tcp::endpoint setEndpoint(const std::string_view endpointAdress, uint16_t port);

	void setDefPath(std::filesystem::path path);

	void connect();

private:
	std::shared_ptr<boost::asio::io_context> io_;
	boost::asio::ip::tcp::endpoint endpoint_;
	boost::asio::ip::tcp::acceptor acceptor_;

	std::vector<std::shared_ptr<Connection>> connections_;
	std::filesystem::path defaultServerFilePath_;
	FileManager& fileManager;

	void newConnection();
};

