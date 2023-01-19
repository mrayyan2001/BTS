#include<iostream>
#include <string>
using namespace std;

class BSTNode {
public:
	int key;
	BSTNode* left, * right;

	BSTNode(int key, BSTNode* left = 0, BSTNode* right = 0) {
		this->key = key;
		this->left = left;
		this->right = right;
	}
};

class BST
{
private:
	BSTNode* root;
	void clear(BSTNode*);
	void insert(BSTNode*&, int);
	void print(BSTNode*, const string, bool);
	BSTNode* search(BSTNode*, int);
	int count(BSTNode*);
	int countLeaves(BSTNode*);
	int height(BSTNode*);
	void deleteLeaves(BSTNode*&);
	bool indeed(BSTNode*);
	void mirrorImage(BSTNode*);

public:
	BST() { root = 0; }
	~BST() { clear(root); }
	void insert(int v);
	void print();
	BSTNode* search(int);
	int count();
	int countLeaves();
	int height();
	void deleteLeaves();
	bool indeed();
	void mirrorImage();
	void editNode(int, int);
};

