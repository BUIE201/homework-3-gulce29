
#include <iostream>
#include <vector>
using namespace std;

class TreeNode {
public:
	int data;
	TreeNode* right;
	TreeNode* left;
	TreeNode(int data = 0, TreeNode* right = NULL, TreeNode* left = NULL) : data(data), right(right), left(left) {}

};
class BinarySearchTree {
	TreeNode* root;
	vector<int> v;
public:
	BinarySearchTree(TreeNode* root = NULL) :root(root) {}

	TreeNode* insert(TreeNode* start, int data) {
		if (start) {
			if (data < start->data)
				start->left = insert(start->left, data);
			else
				start->right = insert(start->right, data);
		}
		else
			return new TreeNode(data);
		return start;
	}

	void insert(int data) {
		root = insert(root, data);
	}
	int maxSumbranch(TreeNode* root)
	{   
		if (root) {

			int left = maxSumbranch(root->left);
			int right = maxSumbranch(root->right);
			return max(left, right) + root->data;
		}
		else
			return 0;
	}
	int maxSumbranch() {
		return maxSumbranch(root);
	}
	bool findPath(TreeNode* root, int maxsum)
	{

		if (maxsum == 0)
			return true;

		if (root == nullptr)
			return false;

		bool left = findPath(root->left, maxsum - root->data);
		bool right = findPath(root->right, maxsum - root->data);

        if (left || right)
		v.push_back(root->data);
		
			

		return left || right;
	}

	void printpath() {
		findPath(root, maxSumbranch());
		cout << "Branch with the largest sum is : ";
		for (int i = (v.size() - 1); i >= 0;i--) {
			cout << v[i] << " ";
			}
		cout << "-> SUM = " << maxSumbranch() << endl;
	}
};
int main()
{

	TreeNode* n1 = new TreeNode(5);
	TreeNode* n2 = new TreeNode(4);
	TreeNode* n3 = new TreeNode(8);
	TreeNode* n4 = new TreeNode(11);
	TreeNode* n5 = new TreeNode(13);
	TreeNode* n6 = new TreeNode(4);
	TreeNode* n7 = new TreeNode(7);
	TreeNode* n8 = new TreeNode(2);
	TreeNode* n9 = new TreeNode(1);
	n1->left = n2;
	n1->right = n3;
	n2->left = n4;
	n3->left = n5;
	n3->right = n6;
	n4->left = n7;
	n4->right = n8;
	n6->right = n9;

	BinarySearchTree btree(n1);
	
	/*FOR SORTED BINARY TREE
	/*BinarySearchTree btree;
	btree.insert(5);
	btree.insert(4);
	btree.insert(8);
	btree.insert(11);
	btree.insert(13);
	btree.insert(4);
	btree.insert(7);
	btree.insert(2);
	btree.insert(1);*/

	btree.printpath();

}


