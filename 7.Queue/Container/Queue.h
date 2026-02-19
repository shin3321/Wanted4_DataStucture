#pragma once
#include<iostream>

//FIFO 형태로 동작하는 큐 클래스
template<typename T, int capacity = 10>
class Queue
{
public:
	//변수 선언할 때 초기값을 넣어서 따로 초기화 ㄴㄴ
	Queue()
	{

	}
	//추가 함수
	bool Enqueue(const T& value)
	{
		if (IsFull())
		{
			return false;
		}

		//추가
		//추가ㅣ 인덱스가 배열 범위를 벗어나지 않도록

		rear = (rear + 1) % (capacity + 1);
		data[rear] = value;
		return true;
	}

	//추출함수
	bool Dequeue(T& outValue)
	{
		//큐가 비어 있으면 실패
		if (IsEmpty())
		{
			return false;
		}

		front = (front + 1) % (capacity + 1);
		outValue = data[front];

		data[front] = T();
		//	memset(&data[front], 0, sizeof(T));
		return true;


		//// 인덱스가 배열 범위 벗어나지 않도록.
		//front = (front + 1) % (capacity + 1);
		//outValue = data[front];

		//// 값 비우기 (초기화).
		//data[front] = T();
		////memset(&data[front], 0, sizeof(T));
		//return true;
	}

	//삭제하지 않고 제일 앞의 값 반환하는 함수
	bool Peek(T& outValue)
	{
		if (IsEmpty())
			return false;

		outValue = data[(front + 1) % (capacity + 1)];
			return true;
	}

	//출력함수
	void Print()
	{
		std::cout << " 큐 내용 출력: ";

		//출력
		const int max = (front < rear) ? rear : (rear + (capacity + 1));
		for (int i = front + 1; i <= max; ++i)
		{
			std::cout << " " << data[i];
		}

		//마무리
		std::cout << "\n";
	}

	//Getter
	inline bool IsEmpty() const { return rear == front; }
	inline bool IsFull() const { return ((rear + 1) % (capacity + 1)) == front; }

	//크기 반환 함수
	inline int Capacity() const { return capacity; }
private:
	//데이터 삽입 위치
	int front = 0;

	//데이터 삭제(추출) 위치
	//증가를 먼저 시킴
	int rear = 0;

	//데이터 저장 공간
	T data[capacity + 1] = {};

};