#pragma once
#define _WIN32_WINNT 0x0601

#include <iostream>
#include <boost/asio.hpp>
#include <memory>
#include <string>
#include <filesystem>
#include <nlohmann/json.hpp>
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

	void addFileToServer();

private:
	std::shared_ptr<boost::asio::io_context> io_;
	boost::asio::ip::tcp::endpoint endpoint_;
	boost::asio::ip::tcp::acceptor acceptor_;

	std::vector<std::shared_ptr<Connection>> connections;
	std::filesystem::path defaultServerFilePath;
	FileManager& fileManager;
	nlohmann::json json;

	void newConnection();
};

