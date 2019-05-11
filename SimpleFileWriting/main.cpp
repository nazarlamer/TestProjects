#include <iostream>
#include <fstream>
#include "mydata.h"

int main()
{
    const MyProject::MyData myData{35, "John", "Smitt"};
    std::cout << "Console out: " << myData << std::endl;

    // file out:
    std::ofstream ofs{"myFileData.txt"}; // lock this file at binary folder
    if (ofs.is_open())
        ofs << myData;
}
