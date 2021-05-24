#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<cmath>

using namespace std;

class Node{
public:
	double key;
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

bool isBST(Node* root, double max, double min){
	if(root->leftChild!=NULL){
		if(((root->leftChild)->key < root->key) && ((root->leftChild)->key < max) && ((root->leftChild)->key >= min)) {
			if(!isBST(root->leftChild, root->key, min)){
				return false;
			}
		}
		else{
			return false;
		}
	}
	if(root->rightChild!=NULL){
		if(((root->rightChild)->key >= root->key) && ((root->rightChild)->key >= min && (root->rightChild)->key < max)){
			if(!isBST(root->rightChild, max, root->key)){
				return false;
			}
		}
		else{
			return false;
		}
	}
	return true;
}

int main(){
	vector<Node> tree;
	readTree(tree);
	
	if(tree.size() == 0 || isBST(&tree[0], pow(2,32), -pow(2,32))){
		cout<<"CORRECT"<<endl;
	}
	else{
		cout<<"INCORRECT"<<endl;
	}
	// double a = -pow(2,32);
	// cout<<a;
	return 0;
}