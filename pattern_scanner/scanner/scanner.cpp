#include "scanner.hpp"

std::pair<std::vector<unsigned char>, std::string> format_pattern(const std::string& pattern_str) 
{
    std::vector<unsigned char> bytes;
    std::string mask;
    std::istringstream stream(pattern_str);
    std::string token;
    while (stream >> token) {
        if (token == "?") {
            bytes.push_back(0x00);
            mask += '?';
        }
        else {
            bytes.push_back(static_cast<unsigned char>(std::strtol(token.c_str(), nullptr, 16)));
            mask += 'x';
        }
    }
    return std::make_pair(bytes, mask);
}

uintptr_t pattern_scanner::scan_pattern(const std::string& hex_pattern)
{
    std::ifstream file(globals::file_path, std::ios::binary | std::ios::ate);
    if (!file) return 0;

    std::streamsize size = file.tellg();
    std::vector<unsigned char> data(size);
    file.seekg(0);
    if (!file.read(reinterpret_cast<char*>(data.data()), size)) return 0;

    std::pair<std::vector<unsigned char>, std::string> pattern_result = format_pattern(hex_pattern);
    const std::vector<unsigned char>& pattern = pattern_result.first;
    const std::string& mask = pattern_result.second;

    for (size_t i = 0; i <= data.size() - pattern.size(); ++i) {
        bool match = true;
        for (size_t j = 0; j < pattern.size(); ++j) {
            if (mask[j] != '?' && data[i + j] != pattern[j]) {
                match = false;
                break;
            }
        }
        if (match) return static_cast<uintptr_t>(i);
    }
    return 0;
}