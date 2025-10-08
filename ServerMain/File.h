#pragma once
#include <filesystem>
#include <iostream>


class File
{
public:

	File(const std::filesystem::path& filePath);

	void toString() const;

	std::filesystem::path getPathFile();



private:
	//file
	std::filesystem::path filePath_;

	//file info
	std::filesystem::path fileFullName_{ filePath_.filename() };
	std::filesystem::path fileName_{ filePath_.stem() };
	std::filesystem::path fileExtension_{ filePath_.extension() };
	std::filesystem::path fileParentFolder_{ filePath_.parent_path() };

	//file size
	uintmax_t fileSize{ std::filesystem::file_size(filePath_)};
};

