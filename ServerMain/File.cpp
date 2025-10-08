#include "File.h"

File::File(const std::filesystem::path& filePath) : filePath_(filePath)
{
}

void File::toString() const 
{
	std::cout << fileFullName_;
}

std::filesystem::path File::getPathFile()
{
	return filePath_;
}
