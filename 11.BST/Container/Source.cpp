#include "../Container/BinarySearchTree.h"
#include<iostream>

int main()
{
	BinarySearchTree<int>tree;

	tree.InsertNode(20);
	tree.InsertNode(10);
	tree.InsertNode(5);
	tree.InsertNode(30);
	tree.InsertNode(25);
	tree.InsertNode(35);
	tree.InsertNode(8);

	//삭제
	tree.DeleteNode(30);
	tree.DeleteNode(10);
}