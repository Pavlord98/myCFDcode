#include "readBoundary.h"

boundaries getBoundaries()
{
    boundaries b;
    std::ifstream inf{"boundary"};

    //inf.seekg(5);
    std::string dummy;
    //std::getline(inf, dummy);
    
    inf >> b.top >> dummy;
    inf >> b.bottom >> dummy;
    inf >> b.left >> dummy;
    inf >> b.right >> dummy;
    

    //std::getline(inf, strInput);

    return b;
};