#pragma once

#include <string>
#include <map>
#include <vector>

class Zipper
{
private:
    std::map<char, int> ascii_dict;

public:
    Zipper();

    std::vector<int> encode(std::string& text);
    void decode();
};