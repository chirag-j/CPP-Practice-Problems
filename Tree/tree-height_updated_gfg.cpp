#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

void display(vector<int> v){
	for(int i = 0; i<v.size(); i++){
		cout<<v[i]<<" ";
	}
	cout<<endl;
}

class Node{
public:
	int key, level;

	Node* parent;

	vector<Node*> children;
	Node(){
		this->parent = NULL;
	}
	void setparent(Node *theparent){
		this->parent = theparent; 
		theparent->children.push_back(this);
	}
	void display_Node(){
		cout<<"key: "<<key<<endl;
		cout<<"level: "<<level<<endl;
		for(int i=0; i<children.size(); i++){
			cout<<children[i]->key<<" ";
		}
		cout<<endl;
	}
};

void levelUp(Node* root, int l, int &height){
	root->level = l+1;
	height = max(height, l+1);
	for(int i=0; i<root->children.size(); i++){
		levelUp(root->children[i], l+1, height);
	}
}

int main(){
	int n;
	cin>>n;
	vector<int> arr(n);
	for(int i=0; i<n; i++){
		cin>>arr[i];
	}
	// n = 5;
	// vector<int> arr = {-1,0,4,0,3};
	vector<Node> tree(n);
	Node *root;
	for(int i=0; i<arr.size(); i++){
		if(arr[i]>=0){
			// Node temp(tree[arr[i]], i);
			tree[i].setparent(&tree[arr[i]]);
		}
		else{
			// tree[i].level = 1;
			root = &tree[i];
		}
		tree[i].key = i;
	}
	int height = 0;
	levelUp(root, 0, height);
	// for(int i=0; i<tree.size(); i++){
	// 	tree[i].display_Node();
	// }
	cout<<height<<endl;


	return 0;
}

// GFG 22-10-2021
//Function to find the height of a binary tree.
// int height(struct Node* node)
// {
//     if(node->right == NULL && node->left == NULL){
//         return 1;
//     }
//     if(node->right == NULL){
//         return height(node->left) +1;
//     }
//     if(node->left == NULL){
//         return height(node->right) +1;
//     }
//     int a = height(node->left) +1;
//     int b = height(node->right) +1;
//     if(a>b){
//         return a;
//     }
//     return b;
//     //code here
    
// }