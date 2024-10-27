#pragma once
#include <string>

inline const std::string GetResourceDir()
{
#ifdef NDEBUG // release build
    return "assets/";
#else
    return "C:/Users/Patryk/source/repos/PatryKozlowski/EarthDefender/assets/";
#endif
}
