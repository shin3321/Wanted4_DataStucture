#pragma once

template<typename T, int capacity = 10>
class Stack
{
public:
	//생성자
	Stack()
		:top(0)
	{

	}

	//추가하는 함수
	bool Push(const T& value)
	{
		//스택이 가득 찼다면 실패
		if (IsFull())
		{
			return false;
		}

		//가득 차지 않았다면 저장 가능
		data[top] = value;
		++top;
		//data[++top] = value;

		//저장 처리
		return true;
	}

	//삭제하는 함수
	//고민해 볼 사항
	//1: 반환값을 성공/실패 여부로 할지
	//2: 반환값을 스택의 값으로 할지
	bool Pop(T& outValue)
	{
		//스택이 비어 있으면 추출할 값이 없음
		if (IsEmpty())
		{
			return false;
		}

		//값 추출 처리
		--top;
		outValue = data[top];
		//현재 저장된 위치를 가리키게 쓰고 있음 top = 0;
		// top = -1로 한다면 top 위치 조정 순서가 바뀌어야 함
		return true;

	}

	//Getter
	inline int Count() const { return top; }
	//스택에 데이터가 얼마나 들어있는지 확인 ㄱ사능

	//스택이 비었는지 확인
	inline bool IsEmpty() const { return top == 0; }
	//초기 상태라면 top이 0

	//스택이 가득 찼는지 확인
	inline bool IsFull() const { return top >= capacity; }

private:
	//스택 비우는 함수
	void clear()
	{
		top = 0;
	}

private:

	T data[capacity] = {};
	//실제 데이터가 있다면 순회를 돌면서 기본값으로 정리해 주는 게 좋다
	int top = 0;
};