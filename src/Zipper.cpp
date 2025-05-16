#include "Zipper.h"

#include <map>
#include <vector>

#include <iostream>

std::vector<int> Zipper::encode(std::string &text)
{
    // Просмотр всех букв что есть в словаре
    for (size_t i = 0; i < text.size(); i++)
    {
        if (current_words_dict.find(std::string(1, text[i])) == current_words_dict.end())
        {
            current_words_dict[std::string(1, text[i])] = i;
        }
    }

    // Счетчик для уникальных, новых комбинаций букв
    int counter = current_words_dict.size();

    std::string current_letter;

    // Финальный закодированный словарь
    std::vector<int> code_word;

    for (size_t i = 0; i < text.size(); i++)
    {
        // Переменная для комбинаций букв типа АБ БА АБА
        std::string temp = current_letter + text[i];     

        // Если буква найдена в словаре
        if (current_words_dict.find(temp) != current_words_dict.end())
        {
            current_letter = temp;
        }
        else
        {
            code_word.push_back(current_words_dict[current_letter]);
            current_words_dict[temp] = counter++;
            current_letter = text[i];
        }
    }
    // Выгружаем остатки из переменной с последовательностью
    if (!current_letter.empty())
    {
        code_word.push_back(current_words_dict[current_letter]);
    }

    return code_word;
}
