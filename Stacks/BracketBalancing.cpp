#include <iostream>
#include <stack>
#include <string>
#include <vector>
using namespace std;

void display(vector<char> v){
	for(int i = 0; i<v.size(); i++){
		cout<<v[i]<<" ";
	}
	cout<<endl;
}

void display(vector<pair<int, char>> v){
	for(int i = 0; i<v.size(); i++){
		cout<<v[i].first<<v[i].second<<" ";
	}
	cout<<endl;
}

int balance_brackets(string text){
	vector<pair<int, char>> store;

    for(int i=0; i<text.size(); i++){
    	if(text[i] == '(' || text[i] == '[' || text[i] == '{'){
    		store.push_back({i+1, text[i]});
    	}
    	else if(text[i] == ')' || text[i] == ']' || text[i] == '}'){
    		if(store.empty() == 0 && ((store.back().second=='(' && text[i] == ')') || (store.back().second=='[' && text[i] == ']') || (store.back().second=='{' && text[i] == '}'))){
    			store.pop_back();
    		}
    		else{
    			return i+1;
    		}
    	}
    	// display(store);

    }
    if(store.empty() ==1){
    	return -1;
    }
    else{
    	return store.back().first;
    }
}

int main() {
    string text;
    cin>>text;
    // text = "[](()";
    int a = balance_brackets(text);
    if(a == -1){
    	cout<<"Success"<<endl;
    }
    else{
    	cout<<a<<endl;
    }


    // Printing answer, write your code here

    return 0;
}
