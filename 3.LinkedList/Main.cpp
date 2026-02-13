#include "LinkedList/LinkedList.h"
#include <iostream>

int main()
{
	//연결 리스트 생성
	LinkedList<int> list;
	list.Insert(20);
	list.Insert(30);
	list.Insert(10);

	std::cout << "노드 추가 후 출력\n";
	//출력
	list.Print();

	//삭제
	list.Delete(30);
	list.Delete(10);
	
	std::cout << "삭제 후 출력\n";
	list.Print();

	std::cin.get();
}