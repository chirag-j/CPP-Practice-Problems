#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

class Node{
public:
	Node* parent = this;
	int size, key;
};

Node* Find(Node *i){
	// while(i->parent != i){
	if(i->parent != i){
		i->parent = Find(i->parent);
	}
	
	return i->parent;
}

void UnionRank(Node *d, Node *s, int &maxSize){
	Node *d_id = Find(d);
	Node *s_id = Find(s);
	if(d_id->key != s_id->key){
		d_id->size += s_id->size;
		s_id->size = 0;
		s_id->parent = d_id;
		maxSize = max(maxSize, d_id->size);
	}
}


int main(){
	int n, m, d, s;
	cin>>n>>m;
	vector<Node> table(n+1);
	int maxSize = 0;
	for(int i=1; i<=n; i++){
		cin>>table[i].size;
		table[i].key = i;
		maxSize = max(maxSize, table[i].size);
	}
	for(int i=0; i<m; i++){
		cin>>d>>s;
		UnionRank(&table[d], &table[s], maxSize);
		cout<<maxSize<<endl;
	}

	// vector<Node> table(6);
	// int maxSize = 0;
	// for(int i=1; i<=5; i++){
	// 	table[i].size = 1;
	// 	table[i].key = i;
	// 	maxSize = max(maxSize, table[i].size);
	// }

	// UnionRank(&table[2],&table[3], maxSize);
	// UnionRank(&table[3],&table[4], maxSize);
	// UnionRank(&table[4],&table[5], maxSize);

	// cout<<table[4].parent->key<<" "<<maxSize;
	return 0;
}