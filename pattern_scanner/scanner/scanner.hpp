#include "iostream"
#include "Windows.h"
#include <fstream>
#include "vector"
#include <cstdlib>
#include <sstream>
#include <utility>
#include <cstdint>
#include "string"
#include <filesystem>
#include "../Other/globals.hpp"

namespace pattern_scanner
{
	uintptr_t scan_pattern(const std::string& hex_pattern);
}