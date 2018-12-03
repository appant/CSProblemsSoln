#include <iostream>
#include <string>
#include <vector>
using namespace std;

// Data structure to store a Binary Search Tree node
struct node {
	int val;
	node *left, *right;
	node(int key)
    {    	
    	val = key;
    	left = right = nullptr;    	
    }
};

void floorCeilBSTRecursive(node* root, int& floor, int& ceiling, int key){
	if(!root)
		return;
	if(key == root->val)
    {
        floor = key;
        ceiling = key;
        return;
    }
	
	if (key > root->val){
		floor = root->val;
		floorCeilBSTRecursive(root->right, floor, ceiling, key);
	}
	else {
		ceiling = root->val;
		floorCeilBSTRecursive(root->left, floor, ceiling, key);
	}
}

int main()
{
  node* root = new node(8);
  root->left = new node(4);
  root->left->left = new node(2);
  root->left->right = new node(6);
  root->right = new node(10);
  root->right->left = new node(9);
  root->right->right = new node(12);
  int floor=-1;
  int ceiling=-1;
  vector<int> input = {1,3,9,7};
  for(int i:input){
    floorCeilBSTRecursive(root, floor, ceiling, i);
    cout << "For " << i << " floor is " << floor << " and ceiling is " << ceiling << endl;
  }
}
