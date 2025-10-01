#pragma once
#include <filesystem>
#include <map>
#include <iostream>
#include "FileInfo.h"

class ServerFileManager
{
	static ServerFileManager& getInstance(const std::filesystem::path& defaultPath = R"(D:\Server)");

	void setDefaultPath(const std::filesystem::path& path);


	std::filesystem::path getDefaultPath() const;

	void updateDirectory();

private:
	ServerFileManager(std::filesystem::path defaultPath);
	ServerFileManager(const ServerFileManager&) = delete;
	ServerFileManager& operator=(ServerFileManager) = delete;

	std::filesystem::path defaultPath_;
	std::map<std::filesystem::path, FileInfo> files_;


};

