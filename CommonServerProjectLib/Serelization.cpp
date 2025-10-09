#include "Serelization.h"


nlohmann::json toJSON(const FileMetaData& file)
{
	return {
		{ "Name: ", file.file_name},
		{ "Size: ", file.file_size},
		{ "Hash: ", file.file_hash},
		{ "Extension: ", file.file_extension},
	};
}


std::string SHA256HashString(std::string aString) {
	std::string digest;
	CryptoPP::SHA256 hash;

	CryptoPP::StringSource foo(aString, true,
		new CryptoPP::HashFilter(hash,
			new CryptoPP::Base64Encoder(
				new CryptoPP::StringSink(digest))));

	return digest;
}

std::string readFileToBinary(const std::string& file_path) {
	std::ifstream file(file_path, std::ios::binary);
	if (!file.is_open()) {
		throw std::runtime_error("Cannot open file: " + file_path);
	}

	std::ostringstream oss;
	oss << file.rdbuf();
	return oss.str();
}

FileMetaData getFileMetadata(const std::string& file_path) {
	std::filesystem::path path(file_path);

	if (!std::filesystem::exists(path)) {
		throw std::runtime_error("File does not exist: " + file_path);
	}

	std::string file_content = readFileToBinary(file_path);

	FileMetaData metadata;
	metadata.file_name = path.filename().string();
	metadata.file_size = std::filesystem::file_size(path);
	metadata.file_hash = SHA256HashString(file_content);
	metadata.file_extension = path.extension().string();

	return metadata;
}

