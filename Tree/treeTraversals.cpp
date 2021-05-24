#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

class Node{
public:
	int key;
	Node *leftChild, *rightChild, *parent=NULL;
};

void readTree(vector<Node> &tree){
	int n;
	cin>>n;
	tree.resize(n);
	int l, r;
	for(int i=0; i<n; i++){
		cin>>tree[i].key>>l>>r;
		if(l==-1){
			tree[i].leftChild = NULL;
		}
		else{
			tree[i].leftChild = &tree[l];
			tree[l].parent = &tree[i];
		}

		if(r==-1){
			tree[i].rightChild = NULL;
		}
		else{
			tree[i].rightChild = &tree[r];	
			tree[r].parent = &tree[i];
		}

	}
}

void displayTree(vector<Node> tree){
	for(int i=0; i<tree.size(); i++){
		cout<<tree[i].key<<" ";
		if(tree[i].parent!=NULL){
			cout<<tree[i].parent->key;
		}
		cout<<endl;
	}
}

void inorderTraversal(Node* root){
	if(root->leftChild ==NULL){
		cout<<root->key<<" ";
	}
	else{
		inorderTraversal(root->leftChild);
		cout<<root->key<<" ";

	}
	if(root->rightChild !=NULL){
		inorderTraversal(root->rightChild);
	}
}

void preorderTraversal(Node* root){
	cout<<root->key<<" ";
	if(root->leftChild!=NULL){
		preorderTraversal(root->leftChild);
	}
	if(root->rightChild!=NULL){
		preorderTraversal(root->rightChild);
	}
}

void postorderTraversal(Node* root){
	if(root->leftChild!=NULL){
		postorderTraversal(root->leftChild);
	}
	if(root->rightChild!=NULL){
		postorderTraversal(root->rightChild);
	}
	cout<<root->key<<" ";
}
int main(){
	vector<Node> tree;
	readTree(tree);
	// displayTree(tree);
	inorderTraversal(&tree[0]);
	cout<<endl;
	preorderTraversal(&tree[0]);
	cout<<endl;
	postorderTraversal(&tree[0]);
	return 0;
}