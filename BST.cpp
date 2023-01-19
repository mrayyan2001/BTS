#include "BST.h"
void BST::clear(BSTNode* node) {
	if (node == 0) return;
	clear(node->left);
	clear(node->right);
	delete node;
}

void BST::insert(int v) { insert(root, v); }
void BST::insert(BSTNode*& node, int v) {
	if (node == NULL) node = new BSTNode(v);
	else if (v < node->key) insert(node->left, v);
	else insert(node->right, v);
}

void BST::print() { print(root, "", false); }
void BST::print(BSTNode* node, const string prefix, bool isLeft) { // preorder print (root,left,right)
	if (node == 0) {
		cout << prefix << "|__NULL" << endl;
		return;
	}
	cout << prefix << "|__" << node->key << endl;
	print(node->left, prefix + (isLeft ? "|  " : "   "), true);
	print(node->right, prefix + (isLeft ? "|  " : "   "), false);
}

BSTNode* BST::search(int v) { return search(root, v); }
BSTNode* BST::search(BSTNode* node, int v) {
	if (node == NULL) return 0;
	if (v == node->key) return node;
	if (v < node->key) return search(node->left, v);
	else return search(node->right, v);
}


int BST::count() { return count(root); }
int BST::count(BSTNode* node) {
	if (node == 0)return 0;
	return count(node->left) + count(node->right) + 1;
}

int BST::countLeaves() { return countLeaves(root); }
int BST::countLeaves(BSTNode* node) {
	if (node == 0) return 0; // if is empty or end of tree
	if (node->left == 0 && node->right == 0) return 1; // leaves
	return countLeaves(node->left) + countLeaves(node->right);
}

int BST::height() { return height(root); }
int BST::height(BSTNode* node) {
	if (node == 0) return 0;
	return 1 + max(height(node->left), height(node->right));
}

void BST::deleteLeaves() { deleteLeaves(root); }
void BST::deleteLeaves(BSTNode*& node) {
	if (node == 0) return;
	if (node->left == 0 && node->right == 0) {
		delete node;
		node = 0;
		return;
	}
	deleteLeaves(node->left);
	deleteLeaves(node->right);
}

int getMax(BSTNode* node) {
	if (node->left == 0 && node->right == 0)
		return node->key;
	else if (node->left != 0 && node->right != 0)
		return max(node->key, max(getMax(node->left), getMax(node->right)));
	else if (node->left != 0)
		return max(node->key, getMax(node->left));
	else
		return max(node->key, getMax(node->right));
}
int getMin(BSTNode* node) {
	if (node->left == 0 && node->right == 0)
		return node->key;
	else if (node->left != 0 && node->right != 0)
		return min(node->key, min(getMin(node->left), getMin(node->right)));
	else if (node->left != 0)
		return min(node->key, getMin(node->left));
	else
		return min(node->key, getMin(node->right));
}
bool checkLeft(BSTNode* node) {
	if (node->left == 0) return true;
	if (!(getMax(node->left) < node->key)) {
		cout << "The max number in the left must be less than the parent: max["
			<< getMax(node->left) << "] >= parent[" << node->key << "]" << endl;
		return false;
	}
	if (!(node->left->key < node->key)) {
		cout << "In every subtree the left node must be less than the parent left["
			<< node->left->key << "] >= paretn[" << node->key << "]" << endl;
		return false;
	}
	return true;
}
bool checkRight(BSTNode* node) {
	if (node->right == 0) return true;
	if (!(getMin(node->right) >= node->key)) {
		cout << "The min number in the right must be greater than or equal the parent: min["
			<< getMin(node->right) << "] < parent[" << node->key << "]" << endl;
		return false;
	}
	if (!(node->right->key >= node->key)) {
		cout << "In every subtree the right node must be greater than or equal the parent rihgt["
			<< node->right->key << "] < paretn[" << node->key << "]" << endl;
		return false;
	}
	return true;
}
bool BST::indeed() {
	return indeed(root);
}
bool BST::indeed(BSTNode* node) {
	if (node == 0) return true;
	if (node->left == 0 && node->right == 0) return true;
	if (!(checkLeft(node) && checkRight(node))) return false;
	return indeed(node->left) && indeed(node->right);
}

void BST::mirrorImage() { mirrorImage(root); }
void BST::mirrorImage(BSTNode* node) {
	if (node == 0) return;
	// swap(left, right)
	BSTNode* temp = node->left;
	node->left = node->right;
	node->right = temp;
	mirrorImage(node->left);
	mirrorImage(node->right);
}

// ---------------------------------
void BST::editNode(int v, int newValue) {
	search(v)->key = newValue;
}