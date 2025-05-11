#include "Zipper.h"
#include "FileHandler.h"

#include <map>
#include <vector>

Zipper::Zipper()
{
    for (int i = 0; i < 256; i++)
    {
        ascii_dict[(char)i] = i;
    }
}

std::vector<int> Zipper::encode()
{
    // FileHandler file("hello.txt");
    std::string text = "ababaabbaa";
    std::map<std::string, int> current_dict;

    int counter = 256;

    std::string current_letter;

    std::vector<int> code_word;

    for (size_t i = 0; i < text.size(); i++)
    {
        if (i <= text.size())
        {
            current_letter = text[i];
            current_dict[current_letter] = counter++;
            current_letter += text[i + current_letter.size()];
            //std::cout << current_letter << " ";
            
            //if letter not found
            if (current_dict.find(current_letter) == current_dict.end()) {
                current_dict[current_letter] = counter++;
                code_word.push_back(ascii_dict[text[i]]);
            }
            else {
                code_word.push_back(current_dict[current_letter]);
                current_letter += text[i + current_letter.size()];
                current_dict[current_letter] = counter++;
                i++;
            }

        }
    }

    return code_word;
}
