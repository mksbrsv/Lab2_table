#include "table.h"
#include <string>
#include <fstream>

int main() {
	table<int, std::string> tab(100000);
	std::ofstream file("file.txt");
	for (int i = 1; i < 100; i++) {
		tab.insert(i, std::to_string(i));
	}
	std::vector<std::string> vec(5, "a");
	tab.insert(vec);
	tab.insert({ "a", "b", "c", "ffuck" });
	file << tab;
	tab.find(1) = "asdf";
	std::cout << tab;
}