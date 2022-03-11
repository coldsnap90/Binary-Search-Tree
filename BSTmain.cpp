#include<iostream>
#include "bst.hpp"
using namespace BST;
using namespace std;

int main()
{
	int values[] = { 10, 5, 15, 3, 7, 13, 18, 4, 6, 9, 8, 16, 19, 17 };
	BinarySearchTree bst1;
	for (int i = 0; i < sizeof(values)/sizeof(int); i++) bst1.insertNode(values[i]);
	cout << bst1 << endl;

	BinarySearchTree bst2, bst3;
	bst3 = bst2 = bst1;
	cout << bst2 << endl;
	cout << bst3 << endl;

	BinarySearchTree bst4(bst3);
	cout << bst4 << endl;

	bst1.deleteNode(4);
	cout << bst1 << endl;
	bst1.deleteNode(9);
	cout << bst1 << endl;
	bst2.deleteNode(10);
	cout << bst2 << endl;
	bst3.deleteNode(3);
	cout << bst3 << endl;
	bst3.deleteNode(9);
	cout << bst3 << endl;
	bst3.deleteNode(16);
	cout << bst3 << endl;
	bst4.deleteNode(18);
	cout << bst4 << endl;
	bst4.deleteNode(7);
	cout << bst4 << endl;
	bst4.deleteNode(10);
	cout << bst4 << endl;

	cout << bst1 << endl;
	cout << bst2 << endl;
	cout << bst3 << endl;
	cout << bst4 << endl;



	return 0;
}