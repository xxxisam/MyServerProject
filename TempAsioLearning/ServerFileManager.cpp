#include "ServerFileManager.h"


ServerFileManager::ServerFileManager(std::filesystem::path defaultPath) : defaultPath_(defaultPath)
{

}


ServerFileManager& ServerFileManager::getInstance(const std::filesystem::path& defaultPath)
{
	if () {
		return 
	}
}

void ServerFileManager::setDefaultPath(const std::filesystem::path& path)
{
	if (std::filesystem::exists(path) && std::filesystem::is_directory(path))
	{
		defaultPath_ = std::filesystem::canonical(path);
	}
	else
	{
		throw std::runtime_error("Invalid default path");
	}

}

std::filesystem::path ServerFileManager::getDefaultPath() const
{
	return defaultPath_;
}

void ServerFileManager::updateDirectory()
{
	for (const auto& entry : std::filesystem::directory_iterator("D:\server")) {
		std::cout << entry.path() << "\n";
	}
}