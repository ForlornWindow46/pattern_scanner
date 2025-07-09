// simple pattern scanner made by Forlorn (this is a static scanner so you will need decrypted roblox)
#include "scanner/scanner.hpp"

std::string hex(uintptr_t value) {
	std::stringstream ss;
	ss << "0x" << std::hex << std::uppercase << value;
	return ss.str();
}

int main()
{
	globals::file_path = "RobloxPlayerBeta.exe";

	for (auto& pattern : patterns)
	{
		uintptr_t address = pattern_scanner::scan_pattern(pattern.pattern);
		std::cout << pattern.name << " = " << hex(address) << std::endl;
	}

	system("pause");
	return 0;
}