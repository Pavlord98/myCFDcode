#ifndef READBOUNDARY
#define READBOUNDARY

#include <fstream>
#include <string>
#include <iostream>

struct boundaries
    {
        std::string top;
        std::string bottom;
        std::string left;
        std::string right;
    };

boundaries getBoundaries();


#endif