#include <iostream>
#include <cassert>

//템플릿으로 배열 만들기
template <typename T, size_t size = 10>
class Array
{
public:
	size_t Size() const
	{
		return size;
	}

	T& operator[](size_t index)
	{
		assert(index < 0 || index >= size);
		return data[index];
	}
	const T& operator[](size_t index) const
	{
		return data[index];
	}

private:
	T data[size] = {};
};

int main()
{
	//배열 변수 선언
	Array<int, 5> array;
	array[3] = 20;

	//const 접근
	const auto& arrayReference = array;

	std::cin.get();
}
