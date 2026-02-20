#include "Container/HashTable.h"
#include <iostream>

int main()
{
	HashTable table;

	//데이터 추가
	table.Add("Ronnie", "010-1234-1234");
	table.Add("merong", "010-1234-5678");
	table.Add("baboll", "010-6789-1234");
	table.Add("kkabab", "010-1254-1234");
	table.Add("baboqq", "010-1234-1567");
	table.Add("mungch", "010-1234-1346");
	table.Add("mungch", "010-1234-1346");
	table.Add("qkqhap", "010-2264-1632");

	table.Print();

	//검색
 	Pair<std::string, std::string> outValue;
	if (table.Find("baboqq", outValue))
	{
		std::cout << "검색 성공, Key: " << outValue.key << 
			" | Value: " << outValue.value << "\n";
	}
	table.Delete("Ronnie");
	table.Delete("baboqq");
	table.Print();

	std::cin.get();
}