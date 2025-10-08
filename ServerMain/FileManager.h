#pragma once
#include <iostream>
#include <filesystem>
#include <map>
#include <functional>
#include <memory>
#include "File.h"


class FileManager
{
public:
	static FileManager& getInstance();


	void setDefFolder(const std::filesystem::path& folder);

	std::filesystem::path getDefFolder();

	size_t toHash(std::filesystem::path);

	void scanFolder();

	void addNewFileInList(const std::filesystem::path& path);



private:
	FileManager();
	~FileManager();
	FileManager(FileManager const&) = delete;
	FileManager& operator=(FileManager const&) = delete;

	//folder fields
	std::filesystem::path defaultFolder_;
	std::filesystem::path currentFolder_;
	
	//
	std::unordered_map<size_t, std::unique_ptr<File>> Files;


};

