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

int multiplier = 263;
long long prime = 1e9 +7;

long long hashfunc(string s){
	long long hash = 0;
	for(int i=s.size()-1; i>=0; i--){
		hash = (hash*multiplier + s[i])%prime;
	}
	return hash;
}

void precomputeHashes(string T, string P, vector<long long> &H){
	// cout<<"g";
	// int multiplier = 263;
	long long y = 1;
	for(int i=0; i<P.size(); i++){
		y = (y*multiplier)%prime;
	}

	H[T.size()-P.size()] = hashfunc(T.substr( T.size()-P.size(), P.size()));

	for(int i=(T.size()-P.size()-1); i>=0; i--){
		H[i] = (multiplier*H[i+1] + T[i] - (y*T[i+P.size()])%prime)%prime;
	}
}



void display(vector<long long> v){
	for(int i = 1; i<v.size(); i++){
		cout<<v[i]<<" ";
	}
	cout<<endl;
}

int main(){
	string T, P;
	T = "testTesttesT";
	P = "tes";

	// cin>>P>>T;
	
	vector<long long> H(T.size() - P.size() +1);
	precomputeHashes(T, P, H);
	// cout<<hashfunc(T.substr( T.size()-P.size()-1, P.size()))<<endl;
	// display(H);
	long long phash = hashfunc(P);
	for(int i=0; i<=(T.size()-P.size()); i++){
		// cout<<"entered";
		if(H[i]==phash){
			if(P == T.substr(i,P.size())){
				cout<<i<<" ";
			}
		}
	}
	cout<<endl;
	return 0;
}