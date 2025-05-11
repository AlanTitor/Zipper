#include <iostream>
#include <vector>

#include "Zipper.h"

int main()
{

    Zipper zip;

    std::vector<int> v = zip.encode();

    for (int i : v)
    {
        std::cout << i << " ";
    }

    return 0;
}