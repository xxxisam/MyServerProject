#include <nlohmann/json.hpp>
#include <sha.h>
#include <filters.h>
#include "base64.h"

struct FileMetaData {
	std::string file_name;
	size_t file_size;
	std::string file_hash;
	std::string file_extension;
};


nlohmann::json to_JSON(const FileMetaData& file)
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