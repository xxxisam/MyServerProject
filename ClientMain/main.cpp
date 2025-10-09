#include <iostream>
#include <fstream>
#include <filesystem>
#include <boost/asio.hpp>
#include "Serelization.h"



int main()
{
	boost::asio::io_context io;

	const boost::asio::ip::tcp::endpoint endpoint(boost::asio::ip::make_address("127.0.0.1"), 8080);
	boost::asio::ip::tcp::socket clientSocket(io);

	clientSocket.connect(endpoint);

	std::filesystem::path filepath{R"(D:\Client\text.txt)"};
	std::string stringFilePath{filepath.string()};

	FileMetaData fileMetaData{getFileMetadata(R"(D:\Client\text.txt)") };
	nlohmann::json metadata_json = toJSON(fileMetaData);



	return 0;
}