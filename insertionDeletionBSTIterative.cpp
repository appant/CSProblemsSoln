// Example program
#include <iostream>
#include <string>

using namespace std;

struct Node {
	int data;
	Node *left, *right;
};

Node* newNode(int key)
{
	Node* node = new Node;
	node->data = key;
	node->left = node->right = nullptr;
	return node;
}

void inorder(Node *root)
{
	if (root == nullptr)
		return;

	inorder(root->left);
	cout << root->data << " ";
	inorder(root->right);
}

void insert(Node*& root, int key){
    if(!root){
        root = newNode(key);
        return;
    }
    bool orientation = 0; //1 meaning we have traversed right, 0 meaning we have travered left.
    Node* currNode = root;
    Node* prev = nullptr;
    while(currNode){
        prev = currNode;
        if(key <= currNode->data){            
            currNode = currNode->left;
            orientation = 0;
        }
        else{
            currNode = currNode->right;
            orientation = 1;
        }            
    }
    if(orientation)
        prev->right = newNode(key);
    else
        prev->left = newNode(key);        
}

void searchKey(Node* &curr, int key, Node* &parent, bool& orientation)
{
	// traverse the tree and search for the key
	while (curr != nullptr && curr->data != key)
	{
		// update parent node as current node
		parent = curr;		
		if (key < curr->data){
			curr = curr->left;
			orientation = 0;
		}
		else{
			curr = curr->right;
			orientation = 1;
		}
	}
}

Node* minimumKey(Node* curr, Node*& prev, int& orientation)
{
    orientation = 1;
	while(curr->left != nullptr) {
	    prev = curr;
		curr = curr->left;
		orientation = 0;
	}
	return curr;
}

void deleteNode(Node*& root, int key){
    Node* parent = nullptr;
    Node* curr = root;
    bool orientation = 0;
    searchKey(curr, key, parent, orientation);
    if(curr){
        //No child present
        if(!curr->left && !curr->right){
            if(curr == root) // When the current node is root. 
            {
                free(curr);
                curr = nullptr;
                root = nullptr;
            }
            else{            // When current node is not root.  
                free(curr);
                curr = nullptr;
                if(!orientation)
                    parent->left = nullptr;
                else
                    parent->right = nullptr;
            }
        }
        //both child present
        else if(curr->left && curr->right){
            Node* prev = curr;
            int orientation = 1; // First we have to traverse to right, thus the orientation is 1
            Node* minRight = minimumKey(curr->right, prev, orientation);
            curr->data = minRight->data;
            free(minRight);
            minRight = nullptr;
            if(orientation)
                prev->right = nullptr;
            else
                prev->left = nullptr;
        }
        //one child present
        else{        
            if(curr==root)
            {
                root = root->left? root->left : root->right;            
            }
            else{
                if(orientation){ // We have traversed right from parent to curr node
                    parent->right = curr->left ? curr->left : curr->right; // since curr node has only one child, it could have only right or left child. 
                }
                else{
                    parent->left = curr->left ? curr->left : curr->right;
                }            
            }
            free(curr);
        }
    }
}

int main()
{
  Node* root = nullptr;
  int keys[] = {15, 10, 20, 8, 12, 16 };
  for (int key : keys)
  insert(root, key);
  inorder(root);
  cout << endl;
  deleteNode(root, 150);  
  inorder(root);
}
