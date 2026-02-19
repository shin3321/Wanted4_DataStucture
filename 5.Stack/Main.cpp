#include "Container/Stack.h"
#include <iostream>
#include <time.h>

//랜덤
//강의자료 알고리즘 -> 난수 -> 정수난수 -> 맨 아래 코드
//랜덤(정수)
int RandomRange(int min, int max)
{
	int diff = (max - min) + 1;
	return ((diff * rand()) / (RAND_MAX + 1)) + min;
}

//강의자료 알고리즘 -> 난수 -> 부동소수점 난수 -> 맨 아래 코드
//랜덤(부동소수)
float RandomRange(float min, float max)
{
	float percent = static_cast<float>(rand()) / static_cast<float>(RAND_MAX);
	float diff = (max - min);
	return (percent * diff) + min;
}

int main()
{
	//랜덤 시드 값 주기
	srand(time(nullptr));
	//time()이 값을 반환도 해 줌 참조로 받아서 쓰기도 가능

	//스택 생성
	const int count = 10;
	Stack<float, count> stack;

	for (int i = 0; i < count+1; ++i)
	{
		if (stack.Push(RandomRange(100.0f, 200.0f)))
		{
			//예외 처리
			//예외 처리를 해 보기 위해 일부러 count + 1 함
			std::cout << "스택 값 추가 실패\n";
		}
	}

	//스택에서 값 빼 오면서 출력
	const int stackCount = stack.Count();
	//스택에서 가져온 수만큼 가져와도 되고 while문으로 pop 가능할 때까지 돌려도 됨
	for (int i = 0; i < stackCount; ++i)
	{
		float value = 0.0f;
		if (stack.Pop(value))
		{
			std::cout << value << " \n";
		}
	}

	std::cin.get();
}