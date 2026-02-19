#include"Container/Queue.h"

int main()
{
	// 큐 객체 생성
	Queue<int> queue;
	const int count = 10;
	for (int i = 0; i < count; ++i)
	{
		queue.Enqueue(i + 1);
	}

	queue.Print();

	int value;
	queue.Dequeue(value);
	queue.Dequeue(value);
	queue.Dequeue(value);

	queue.Print();

	queue.Enqueue(11);
	queue.Enqueue(12);
	queue.Enqueue(13);
	queue.Enqueue(14);

	std::cin.get();
}