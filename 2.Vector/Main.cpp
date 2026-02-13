#include <iostream>

#include "List.h"

int main()
{
	List<int> list;
	for (int i = 0; i < 10; ++i)
	{
		list.Add(i + 1);
	}

	//Range-based loop
	for (const int item : list)
	{
		std::cout << item << std::endl;
	}

	//for (List<int>::Iterator it = list.begin();
	//	it != list.end();
	//	++it)
	//{
	//	std::cout << *it << std::endl;
	//}
	std::cin.get();
}