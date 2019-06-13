#include <set>
#include <iostream>
#include <set>
#include <string>

int main()
{
	std::set<std::string> set;
	
	set.insert("first");
	set.insert("second");
	set.insert("third");
	set.insert("first");

	std::cout << "Set size = " << set.size() << std::endl;

	for(std::set<std::string>::iterator it = set.begin(); it != set.end(); it++)
		std::cout << *it << ' ';
	std::cout << "\n";
	
	std::set<std::string>::iterator it = set.find("fst");
	if(it != set.end())
		std::cout << "Data is found\n";
	else
		std::cout << "Data is not present\n";

	return 0;
}
