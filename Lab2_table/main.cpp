#include "table.h"
#include <string>

int main() {
	table<int, std::string> tab({ { 1, "a" }, { 2, "b" } });
	//tab.insert(1, "a");
	//tab.insert(2, "b");
	//tab.insert(3, "c");
	//tab.insert("d");
	//tab.remove(2);
	std::string ta = tab.find(1);
	std::cout << tab;
	std::cout << ta;
	std::cout << tab.get_data_count();
}