#include "Windows.h"
#include "iostream"

struct PatternInfo {
    const char* pattern;
    const char* name;
};

inline PatternInfo patterns[] = {
    {"48 89 54 24 ? 4C 89 44 24 ? 4C 89 4C 24 ? 55 53 56 57 41 54 41 55", "print"},
    {"80 79 06 00 0F 85 ? ? ? ? E9 ? ? ? ?", "luau_execute"},
    // add more
};

namespace globals
{
	inline std::string file_path;
}