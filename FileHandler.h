#pragma once

#include <string>
#include <fstream>
#include <iostream>

class FileHandler
{
private:
    std::ifstream file;
    std::string buffer;

public:
    FileHandler(std::string file_name);
    ~FileHandler();
    FileHandler(const FileHandler &) = delete;
    FileHandler &operator=(const FileHandler &) = delete;

    const std::string &read_file();
};