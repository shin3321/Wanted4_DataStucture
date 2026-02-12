#pragma once
#include <iostream>
#include <cassert>

//자동으로 크기가 늘어나는 배열(List/Vector)

template<typename T>
class List
{
public:
	List()
	{
		//저장 공간 할당
		//Reallocate(capacity);
		data = new T[capacity];
		memset(data, 0, sizeof(T) * capacity);
	}

	~List()
	{
		//자원 해제
		if (data)
		{
			delete[] data;
		}
	}
	//값 추가 함수
	void Add(const T& value)
	{
		//크기가 부족한지 확인
		if (size == capacity)
		{
			//크기 재할당 (2배 크기로 재할당)
			Reallocate(capacity * 2);
		}
		//항목 추가 
		data[size++] = value;
		//저장된 항목 수 증가 처리
		//++size;
	}

	//r-value reference
	void Add(T&& value)
	{
		if (size == capacity)
		{
			//크기 재할당 (2배 크기로 재할당)
			Reallocate(capacity * 2);
		}
		//저장된 항목 수 증가 처리
		data[size++] = std::move(value);
	}

	//인덱스 연산자 오버로딩
	T& operator[](int index)
	{
		//static_assert(index < 0 || index >= size);
		assert(index < 0 || index >= size);
		return data[index];
	}

	//Getter
	int Size() const { return size; }
	int Capacity() const { return capacity; }


private:

	//저장 공간 할당(재할당)하는 함수
	void Reallocate(int newCapacity)
	{
		//1. 이주할 새로운 공간 할당 (new)
		T* newBlock = new T[newCapacity];
		memset(newBlock, 0, sizeof(T) * newCapacity);

		//size를 줄여서 갈 때
		if (newCapacity < size)
		{
			size = newCapacity;
		}
		//2. 기존 항목을 새로운 공간에 복사/이동
		/*for (int i = 0; i < size; ++i) {
			newBlock[i] = data[i];
		}*/
		memcpy(newBlock, data, sizeof(T) * capacity);

		//3. 기존 배열 공간 해제.
		delete[] data;
		data = newBlock;
		capacity = newCapacity;
	}

private:
	//힙에 할당되는 배열을 관리할 포인터 변수
	T* data = nullptr;

	//배열에 저장된 항목의 수
	int size = 0;

	//배열 저장 공간의 크기
	int capacity = 2;

};