// starting from scratch
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

class Query{
public:
	string type, word;
	int num;
};

long long hashfunc(string s, int bucket_count){
	int multiplier = 263;
	long long prime = 1e9 +7, hash = 0;
	for(int i=s.size()-1; i>=0; i--){
		hash = (hash*multiplier + s[i])%prime;
	}
	return hash%bucket_count;
}

vector<Query> read_queries(){
	//Have to get value of bucket size before this
	int n;
	cin>>n;
	vector<Query> queries(n);
	for (int i = 0; i < n; ++i){
		cin>>queries[i].type;
		if(queries[i].type == "check"){
			cin>>queries[i].num;
		}
		else{
			cin>>queries[i].word;
		}
	}
	return queries;
}

vector<string> process_queries(vector<Query> queries, int bucket_count){
	vector<string> results;
	vector<vector<string>> storage(bucket_count);
	int temp = 0;
	for(int i=0; i<queries.size(); i++){
		// cout<<"processing "<<i<<endl;
		if(queries[i].type == "add"){
			temp = hashfunc(queries[i].word, bucket_count);
			// cout<<i<<" "<<temp<<endl;
			int found = 0;
			for(int j=0; j<storage[temp].size(); j++){
				if(storage[temp][j] == queries[i].word){
					found = 1;
					break;
				}
			}
			if(found == 0){
				storage[temp].push_back(queries[i].word);
			}
		}
		else if(queries[i].type == "del"){
			temp = hashfunc(queries[i].word, bucket_count);
			for(int j=0; j<storage[temp].size(); j++){
				if(storage[temp][j] == queries[i].word){
					storage[temp].erase(storage[temp].begin()+j);
					break;
				}
			}
		}
		else if(queries[i].type == "find"){
			temp = hashfunc(queries[i].word, bucket_count);
			results.push_back("no");

			for(int j=0; j<storage[temp].size(); j++){
				if(storage[temp][j] == queries[i].word){
					results.erase(results.end());
					results.push_back("yes");
					break;
				}
			}
		}
		else{
			string str = "";
			if(storage[queries[i].num].size() == 0){
				results.push_back(str);
			}
			else{
				 int len = storage[queries[i].num].size();
				str = storage[queries[i].num][len-1];
				for(int j=len-2; j>=0; j--){
					str = str + " " + storage[queries[i].num][j];
				}
				results.push_back(str);
			}
		}
	}
	// for(int i=0; i<storage.size(); i++){
	// 	for(int j = 0; j<storage[i].size(); j++){
	// 	cout<<storage[i][j]<<" ";
	// 	}
	// 	cout<<endl;
	// }
	return results;
}

void display(vector<string> v){
	cout<<v[0];
	for(int i = 1; i<v.size(); i++){
		cout<<endl<<v[i];
	}
}

int main(){
	int bucket_count;
	// creating queries
	bucket_count = 5;
	vector<Query> que(7);
	que[0].type = "add";
	que[0].word = "world";
	que[1].type = "add";
	que[1].word = "HellO";
	que[2].type = "find";
	que[2].word = "World";
	que[3].type = "check";
	que[3].num = 4;
	que[4].type = "find";
	que[4].word = "world";
	que[5].type = "del";
	que[5].word = "world";
	que[6].type = "check";
	que[6].num = 4;

	// display(process_queries(que, bucket_count));
	cin>>bucket_count;
	display(process_queries(read_queries(), bucket_count));
	return 0;
}