#pragma once

template <typename T>
class Node
{
	//연결리스트 friend 지정
	template<typename T>
	friend class LinkedList;
public:

	//생성자
	Node()
		: data(), next(nullptr), previous(nullptr)
	{
	}

private:



private:
	//데이터 필드
	T data;

	//다음 노드를 가리키는 링크 필드
	Node<T>* next = nullptr;	

	//이전 노드를 가리키는 링크 필드
	Node<T>* previous = nullptr;

};