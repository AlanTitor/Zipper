#include <string>
#include <fstream>

#include "FileHandler.h"

FileHandler::FileHandler(std::string file_name) : file(file_name)
{
    if (!file.is_open())
    {
        throw std::runtime_error("failed to open file " + file_name);
    }
}

FileHandler::~FileHandler()
{
    if (file.is_open())
    {
        file.close();
    }
}

const std::string &FileHandler::read_file()
{

    std::string line;
    buffer.clear();

    while (std::getline(file, line))
    {
        buffer += line;
        buffer += "\n";
    }

    if (!buffer.empty() && buffer.back() == '\n')
    {
        buffer.pop_back();
    }

    return buffer;
}