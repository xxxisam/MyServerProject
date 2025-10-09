#pragma once
#include <nlohmann/json.hpp>
#include <sha.h>
#include <filters.h>
#include "base64.h"
#include <filesystem>
#include <fstream>
#include <sstream>

struct FileMetaData {
	std::string file_name;
	size_t file_size;
	std::string file_hash;
	std::string file_extension;
};


nlohmann::json toJSON(const FileMetaData& file);

std::string SHA256HashString(std::string aString);
std::string readFileToBinary(const std::string& file_path);
FileMetaData getFileMetadata(const std::string& file_path);