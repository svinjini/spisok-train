#include <iostream>
#include "List.h"

int main()
{
	List<int> listok;
	listok += 5;
	listok += 7;
	listok += 9;
	listok += 0;
	std::cout << listok << std::endl;
	return 0;
}
