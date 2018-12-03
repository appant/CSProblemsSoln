// Example program
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

void findFloorCeilIterative(node* root, int& floor, int& ceiling, int key){
	if(!root)
		return;
	node* currNode = root;
	floor = -1;
	ceiling = -1;
	while(currNode){
		if(key == currNode->val)
		{
			floor = ceiling = currNode->val;
			break;
		}	
		if(key > currNode->val){
			floor = currNode->val;
			currNode = currNode->right;
		}
		else{
			ceiling = currNode->val;
			currNode = currNode->left;
		}
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
    findFloorCeilIterative(root, floor, ceiling, i);
    cout << "For " << i << " floor is " << floor << " and ceiling is " << ceiling << endl;
  }
}
