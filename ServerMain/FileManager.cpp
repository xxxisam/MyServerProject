#include "FileManager.h"


FileManager::FileManager()
{
    
}

FileManager::~FileManager()
{

}

FileManager& FileManager::getInstance()
{
    static FileManager fileManager;
    return fileManager;
}

void FileManager::setDefFolder(const std::filesystem::path& folder)
{
	defaultFolder_ = folder;
}

std::filesystem::path FileManager::getDefFolder()
{
    return defaultFolder_;
}

size_t FileManager::toHash(std::filesystem::path path_) {
    
    return std::hash<std::filesystem::path> {} (path_);

}



void FileManager::scanFolder()
{
    for (auto& iter : std::filesystem::directory_iterator(defaultFolder_))
    {
        std::cout << iter.path().string() << "\n";
        if ( !(Files.count(toHash(iter.path())) ) )
        {
            addNewFileInList(iter.path());
        }
    }
    
    for (auto iter = Files.begin(); iter != Files.end(); )
    {
        if ( !(std::filesystem::exists(iter->second->getPathFile())) )
        {
            iter = Files.erase(iter);
        }
        else
        {
            ++iter;
        }
    }
}

void FileManager::addNewFileInList(const std::filesystem::path& path)
{
    Files.insert( std::make_pair ( toHash(path), std::make_unique<File>(path) ) );
}
