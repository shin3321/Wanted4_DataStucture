#include "Container/Stack.h"
#include "Location2D.h"
#include <iostream>
#include <Windows.h>

//e = entry: 시작 위치, 1: 벽, 0: 갈 수 있음, x: 탈출구
// 0이거나 x인 경우에는 이동 가능

// 작은 맵.
//const int mazeSize = 6;
//char map[mazeSize/*y, 행*/][mazeSize/*x, 열*/] =
//{
//	{'1','1','1','1','1','1'},
//	{'e','0','1','0','0','1'},
//	{'1','0','0','0','1','1'},
//	{'1','0','1','0','1','1'},
//	{'1','0','1','0','0','x'},
//	{'1','1','1','1','1','1'}
//};

// 큰 맵.
const int mazeSize = 20;
char map[mazeSize][mazeSize] =
{
	{'1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1'},
	{'1', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '1', '0', '0', '0', '1'},
	{'1', '0', '1', '1', '1', '1', '1', '1', '1', '0', '1', '0', '1', '0', '1', '0', '1'},
	{'1', '0', '1', '0', '0', '0', '1', '0', '0', '0', '1', '0', '0', '0', '1', '0', '1'},
	{'1', '0', '1', '0', '1', '0', '1', '0', '1', '1', '1', '1', '1', '1', '1', '0', '1'},
	{'1', '0', '0', '0', '1', '0', '1', '0', '0', '0', '0', '0', '0', '0', '1', '0', '1'},
	{'1', '1', '1', '1', '1', '0', '1', '1', '1', '1', '1', '1', '1', '0', '1', '0', '1'},
	{'e', '0', '1', '0', '0', '0', '0', '0', '0', '0', '1', '0', '0', '0', '1', '0', '1'},
	{'1', '0', '1', '1', '1', '1', '1', '1', '1', '0', '1', '0', '1', '1', '1', '0', '1'},
	{'1', '0', '1', '0', '0', '0', '0', '0', '1', '0', '1', '0', '1', '0', '1', '0', '1'},
	{'1', '0', '1', '0', '1', '1', '1', '0', '1', '0', '1', '0', '1', '0', '1', '0', '1'},
	{'1', '0', '0', '0', '1', '0', '1', '0', '1', '0', '1', '0', '1', '0', '0', '0', '1'},
	{'1', '1', '1', '1', '1', '0', '1', '0', '1', '1', '1', '0', '1', '1', '1', '0', '1'},
	{'1', '0', '0', '0', '0', '0', '1', '0', '0', '0', '1', '0', '0', '0', '1', '0', '1'},
	{'1', '0', '1', '1', '1', '1', '1', '1', '1', '0', '1', '1', '1', '0', '1', '0', '1'},
	{'1', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '1', '0', 'x'},
	{'1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1'}
};


//방문하려는 위치가 유효한지 확인하는 함수
bool IsValidLocation(const Location2D& location)
{
	//편의 목적으로 받아 둠
	const int row = location.row;
	const int col = location.col;

	//맵을 벗어나면 안 됨
	if (row < 0 || row >= mazeSize ||
		col < 0 || col >= mazeSize)
	{
		return false;
	}

	//이동하려는 곳이 이동 가능한지 확인
	return map[row][col] == '0' || map[row][col] == 'x';
}

//콘솔 화면 지우는 함수
void ClearScreen()
{
	//콘솔 명령어 cls 실행
	system("cls");
}

//텍스트 색상 지정 함수
void SetConsoleColor(WORD color)
{
	SetConsoleTextAttribute(
		GetStdHandle(STD_OUTPUT_HANDLE),
		color
	);
}

//맵 그리는 함수
void PrintMap(const Location2D& playerPosition, DWORD delay)
{
	//스레드 재우는 함수(단위: 밀리초 1/1000초), 중단할 때 자주 씀...
	Sleep(delay);

	//콘솔 화면 지우기
	ClearScreen();

	//맵 순회하면서 그리기
	for (int row = 0; row < mazeSize; ++row) //행(세로) 순회
	{
		for (int col = 0; col < mazeSize; ++col) //열(가로) 순회
		{
			//플레이어 출력
			if (row == playerPosition.row && col == playerPosition.col)
			{
				//플레이어 색 다르게 출력
				SetConsoleColor(FOREGROUND_GREEN);
				std::cout << "P "; //빈칸 하나를 넣어 줘야 배열이 맞음
				SetConsoleColor(FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);
				//숫자 7 넣어도 됨
				continue;
			}
			//목표 위치 출력
			if (map[row][col] == 'x')
			{
				SetConsoleColor(FOREGROUND_RED);
				std::cout << "X "; //빈칸 하나를 넣어 줘야 배열이 맞음
				SetConsoleColor(FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);
				continue;
			}
			//맵 출력
			std::cout << map[row][col] << " ";
		}
		std::cout << "\n";
	}
}


int main()
{
	CONSOLE_CURSOR_INFO info;
	info.dwSize = 1;
	info.bVisible = FALSE;
	SetConsoleCursorInfo(
		GetStdHandle(STD_OUTPUT_HANDLE),
		&info
	);

	//e의 위치가 바뀔 수도 있음 고정값보다는 e 문자를 찾아서 실행
	//시작 위치 검색
	Location2D start;

	bool found = false;
	for (int row = 0; row < mazeSize; ++row)
	{
		for (int col = 0; col < mazeSize; ++col)
		{
			if (map[row][col] == 'e')
			{
				start.row = row;
				start.col = col;
				found = true;
				break;
				//이 루프는 col 루프만 break
			}
		}
		if (found)
		{
			break;
		}
	}

	//초기 맵 출력
	//처음에는 딜레이 없이 바로 출력
	PrintMap(start, 0);

	//길찾기를 위한 스택 생성
	Stack<Location2D, mazeSize> stack;

	//시작 위치 스택에 추가
	stack.Push(start);

	//길찾기(dfs)
	//스택이 비어있지 않으면 = 방문할 위치가 남아 있으면
	//방문 및 길찾기 진행
	while (!stack.IsEmpty())
	{
		//방문할 위치 꺼내기
		Location2D current;
		if (!stack.Pop(current))
		{
			//pop 실패 = 데이터 뺄 때 실패 = 비어 있으면 실패함
			break;
		}
		//위치 출력
		PrintMap(current, 500);

		//출구에 도착했는지 확인
		if (map[current.row][current.col] == 'x')
		{
			std::cout << "\n미로탐색 성공\n";
			return 0;
		}

		//방문 및 방문한 위치 표시
		map[current.row][current.col] = '.';

		//방문할 지점 스택에 추가
		//스택에 넣을 순서는 정할 수 있음
		//상하좌우 순서대로 스택에 삽입, 상하좌우 순서는 상관없음
		//=> 실제 우선순위는 우좌하상 순서임

		//상 방문, 콘솔은 -1이 위로 올라감
		if (IsValidLocation(Location2D(current.row - 1, current.col)))
		{
			stack.Push(Location2D(current.row - 1, current.col));
		}

		//하 방문
		if (IsValidLocation(Location2D(current.row + 1, current.col)))
		{
			stack.Push(Location2D(current.row + 1, current.col));
		}

		//좌 방문
		if (IsValidLocation(Location2D(current.row, current.col - 1)))
		{
			stack.Push(Location2D(current.row, current.col - 1));
		}

		//우 방문
		if (IsValidLocation(Location2D(current.row, current.col + 1)))
		{
			stack.Push(Location2D(current.row, current.col + 1));
		}
	}
	//길찾기 실패
	std::cout << "미로 탐색 실패\n";
}
