#include <string>
#include <fstream>

#include "FileHandler.h"

FileHandler::FileHandler(std::string file_name) : file(file_name)
{

    if (!file.is_open())
    {
        throw std::runtime_error("failed to open file " + file_name);
    }

    file_name_before_dot = file_name.substr(0, file_name.find_last_of('.'));
    file_extention = file_name.substr(file_name.find_last_of('.') + 1);
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

    file.seekg(0, std::ios::end);
    file_size = file.tellg();

    return buffer;
}

const void FileHandler::write_file(std::vector<int>& text)
{
    std::ofstream new_file(file_name_before_dot + ".zp", std::ios::binary);

    for(auto i : text){
        new_file << i << " ";
    }
}

const std::streampos FileHandler::get_file_size(){
    if(file_size != 0){
        return file_size;
    }
    throw "File is empty!";
}