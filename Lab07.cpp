#include <iostream>
#include"BST.h"
using namespace std;


int main()
{
	
	BST tree;

	tree.insert(4);
	tree.insert(2);
	tree.insert(1);
	tree.insert(5);
	tree.insert(3);
	tree.insert(6);

	tree.editNode(6, 0);

	tree.print();

	cout << "Search: " << (tree.search(4) != 0 ? "Yes" : "No") << endl;
	cout << "Number of nodes: " << tree.count() << endl;
	cout << "Number of leaves: " << tree.countLeaves() << endl;
	cout << "Height of tree: " << tree.height() << endl;
	cout << "Indeed tree: " << (tree.indeed() ? "Yes, it is a binary tree" : "No, it isn't a binary tree") << endl;

	tree.deleteLeaves();
	tree.print();

	tree.mirrorImage();
	tree.print();

}
