#include <iostream>
#include <vector>

#include "FileHandler.h"
#include "Zipper.h"

int main(int argc, char* argv[])
{

    Zipper zip;
    
    FileHandler file(argv[1]);
    
    std::string text = file.read_file();
    
    std::vector<int> v = zip.encode(text);

    
    file.write_file(v);
    
    return 0;
}