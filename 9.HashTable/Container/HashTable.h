#pragma once

#include"Pair.h"
#include <vector>
#include <string>

//해시 테이블 클래스
class HashTable
{
private:
	//장황한 타입을 Entry로 치환
	using Entry = Pair<std::string, std::string>;

public:
	HashTable();
	~HashTable();

	//키-값 조합으로 저장할 수 있도록
	bool Add(const std::string& key, const std::string& value);
	
	//삭제: 키를 활용해 K_value 조합 데이터 삭제
	bool Delete(const std::string& key);

	//검색 함수
	bool Find(const std::string& key, Entry& outEntry);

	//출력 함수
	void Print();

	//getter
	bool IsEmpty() const;

private:
	//내부 저장소 크기
	// - 내부 저장소 크기는 소수(1과 자기 자신ㄷ으로만 나줘지는 수)를 
	// 선택하는 게 해시 충돌 방지에 좋음
	//사용 가능한 소수 중에서 큰 수를 사용 
	static const int bucketCount = 19;
	
	//이차 저장소 (해시 충돌 해결 방법으로 체이닝(chaining))
	//늘어나면 성능이 안 좋아져서 resizing을 많이 함
	std::vector<Entry> table[bucketCount];

};