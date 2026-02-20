#include "HashTable.h"
#include <iostream>

//해시 함수(Hash Function)
//키를 어떠한 과정을 통해서 숫자로 변환해 주는 함수
//static은 private의 의미
//이 코드는 원래 key에 내장되어 있어야 함
static int GenerateHash(const std::string& keyString)
{
	//출력할 해시 변수 선언	
	int hash = 0;
	
	//문자열을 문자 배열로 활용해 해시 생성
	const int length = static_cast<int>(keyString.length());
	for (int i = 0; i < length; ++i)
	{
		//해시 생성 로직
		//hash += keyString[i] * (i + 1);
		//자바 방식, Hornor' method
		hash = (hash * 31) + keyString[i]; 
	}

	//절댓값
	return std::abs(hash);
}

HashTable::HashTable()
{
}

HashTable::~HashTable()
{
}

bool HashTable::Add(const std::string& key, const std::string& value)
{
	//해시 값을 생성한 후에 이를 버킷 인덱스로 변환
	int bucketIndex = GenerateHash(key) % bucketCount;

	//저장할 동적 배열(2차 자료구조) 선택
	//자료 추가할 거라서 const 안 붙임
	std::vector<Entry>& position = table[bucketIndex];

	//이미 같은 인덱스를 가진 키를 추가하면 실패 (키의 중복 허용 안 함)
	//중복된 키가 있는지 확인 후 없으면 추가
	const int length = static_cast<int>(position.size());

	//순차 탐색(처음부터 일일이 하나씩 검색하는 방법
	for (int i = 0; i < length; ++i)
	{
		//중복된 키 값 확인
		if (position[i].key == key)
		{
			//중복된 키 허용 안 함
			return false;
		}
	}

	//중복된 키가 없다면 자료 추가
	position.emplace_back(Entry(key, value));
	return true;
} 

bool HashTable::Delete(const std::string& key)
{
	//해시 값을 생성한 후에 이를 버킷 인덱스로 변환
	int bucketIndex = GenerateHash(key) % bucketCount;

	//저장할 동적 배열(2차 자료구조) 선택
	std::vector<Entry>& position = table[bucketIndex];

	//중복된 키가 있는지 확인 후 있으면 삭제
	const int length = static_cast<int>(position.size());

	//순차 탐색(처음부터 일일이 하나씩 검색하는 방법
	for (int i = 0; i < length; ++i)
	{
		//중복된 키 값 확인
		if (position[i].key == key)
		{
			//erase가 iterator(pointer)을 받아서 인덱스를 더해서 포인터를 넘김
			//해당 키를 갖는 데이터를 2차 자료구조에서 제거
			position.erase(position.begin() + i);
			return true;
		}
	}

	//원하는 키를 갖는 데이터를 찾지 못 함 - 삭제 실패
	return false;
}

bool HashTable::Find(const std::string& key, Entry& outEntry)
{
	//해시 값을 생성한 후에 이를 버킷 인덱스로 변환
	int bucketIndex = GenerateHash(key) % bucketCount;

	//저장할 동적 배열(2차 자료구조) 선택
	std::vector<Entry>& position = table[bucketIndex];

	//예외 처리 - 2차 자료구조에 저장된 데이터가 없으면 실패
	if (position.size() == 0)
	{
		return false;
	}

	//중복된 키가 있는지 확인 
	const int length = static_cast<int>(position.size());

	//순차 탐색(처음부터 일일이 하나씩 검색하는 방법
	for (int i = 0; i < length; ++i)
	{
		//중복된 키 값 확인
		if (position[i].key == key)
		{
			//출력용 변수에 값 할당
			outEntry = position[i];
			return true;
		}
	}
	//원하는 키를 갖는 데이터를 찾지 못하면 검색 실패
	return false;
}

void HashTable::Print()
{
	//모든 자료를 출력
	for (const auto& container : table)
	{
		//2차 자료구조에 저장된 데이터가 없으면 건너뛰기
		if (container.size() == 0)
		{
			continue;
		}
		//데이터가 있으면 출력
		for (const auto& item : container)
		{
			std::cout << "Key: " << item.key << " | Value: " << item.value << "\n";
		}
	}
}

bool HashTable::IsEmpty() const
{
	//배열 - 2차 자료구조 전체에 저장된 데이터가 없는지 확인
	int sum = 0;
	for (const auto& container : table)
	{
		//2차 자료구조의 저장된 데이터 수를 합산
		sum += static_cast<int>(container.size());
	}

	return sum == 0;
}
