#pragma once
#include <string>

inline const std::string GetResourceDir()
{
#ifdef NDEBUG // release build
    return "assets/";
#else
    return "/Users/patrykkozlowski/Desktop/Projekty/EarthDefender/assets/";
#endif
}
