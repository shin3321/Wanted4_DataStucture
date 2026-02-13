#include <iostream>
#include "LinkedList.h"

int main()
{
	LinkedList<int> list;
	for (int i = 0; i < 10; ++i)
	{
		list.InsertLast((i + 1) * 10);
	}

	std::cout << "리스트 추가 후 출력\n";
	list.Print();

	list.Delete(20);
	list.Delete(50);
	list.Delete(80);

	std::cout << "리스트 제거 후 출력\n";
	list.Print();

	std::cin.get();

}