#pragma once

#include <string>
#include <map>
#include <vector>

class Zipper
{
private:
    std::map<std::string, int> current_words_dict;

public:
    //Zipper();

    std::vector<int> encode(std::string& text);
    void decode();
};