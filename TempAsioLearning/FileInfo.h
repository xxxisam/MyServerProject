#pragma once
#include <filesystem>

class FileInfo
{
public:
	FileInfo(const std::filesystem::path& path);



private:
	std::filesystem::path path_;
	std::filesystem::path fileName_;
	std::filesystem::path fileExtantion_;
};