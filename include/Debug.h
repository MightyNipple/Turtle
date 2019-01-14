#pragma once


#include <iostream>


inline void assert(bool statement, const char* file, int lineNo, const char* statmentStr)
{
    if (!statement)
    {
        std::cout << "[Assertion failed] \"" << statmentStr << "\" expected to be true at " << file << ":" << lineNo << std::endl;
    }
}


#define ASSERT(x) assert(x,__FILE__,__LINE__,#x)

