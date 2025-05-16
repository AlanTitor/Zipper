#pragma once

#include <string>
#include <fstream>
#include <iostream>
#include <vector>


class FileHandler
{
private:
    std::fstream file;

    std::string buffer;

    std::string file_name_before_dot;
    std::string file_extention;
    std::streampos file_size;

public:
    FileHandler(std::string file_name);
    ~FileHandler();
    FileHandler(const FileHandler &) = delete;
    FileHandler &operator=(const FileHandler &) = delete;

    const std::string &read_file();

    const void write_file(std::vector<int>&);

    const std::streampos get_file_size();
};