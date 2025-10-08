#include "FileInfo.h"

FileInfo::FileInfo(const std::filesystem::path& path) : path_(path)
{
	fileName_ = path_.stem();

	auto size = std::filesystem::file_size(path_);
}
