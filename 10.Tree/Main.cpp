#include "Container/Tree.h"
#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>

int main()
{
	_CrtSetReportMode(_CRT_WARN, _CRTDBG_MODE_DEBUG);
	_CrtDumpMemoryLeaks();

	Tree<int> tree(10);
	tree.AddChild(10, 9);
	tree.AddChild(10, 8);
	tree.AddChild(9, 7);
	tree.AddChild(9, 6);

	//검색 테스트
	Node<int>* outNode = nullptr;
	if (tree.Find(6, outNode))
	{
		int n = 2;
	}
	//
	////삭제 테스트
	//if (tree.Remove(9))
	//{
	//	int num = 30;
	//}

	//전위 순회 테스트
	tree.PreorderTraversal();

	int number = 10;
}