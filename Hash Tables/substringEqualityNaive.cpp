#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

int multiplier = 263;
long long prime1 = 1e9 + 7, prime2 = 1e9 + 9;

template <class T>
void display(vector<T> v){
	for(int i = 0; i<v.size(); i++){
		cout<<v[i]<<" ";
	}
	cout<<endl;
}

long long hashfunc(string s, int multiplier, long long prime){
	long long hashval = 0;
	for(int i = s.size()-1; i>=0; i--){
		hashval = (hashval*multiplier + s[i])%prime;
	}
	return hashval;
}

void precomputePrefixHashes(string s, vector<long long> &H1, vector<long long> &H2){
	H1[0] = 0;
	H2[0] = 0;
	long long x1 = 0, x2 = 1;
	for(int i = 1; i<=s.size(); i++){
		// H1[i] = (H1[i-1] + x1*s[i-1])%prime1;
		// H2[i] = (H2[i-1] + x2*s[i-1])%prime2;
		H1[i] = (H1[i-1]*x1 + s[i-1])%prime1;
		H2[i] = (H2[i-1]*x2 + s[i-1])%prime2;


		// x1 = (x1*multiplier)%prime1;
		// x2 = (x2*multiplier)%prime2;
	}
}

int main(){
	string s = "trololo";
	int n;
	int a,b,l;
	cin>>s;
	cin>>n;
	vector<long long> H1(s.size()+1);
	vector<long long> H2(s.size()+1);
	precomputePrefixHashes(s, H1, H2);
	// display(H1);
	// display(H2);
	long long s1hash1, s1hash2, s2hash1, s2hash2;
	for(int i=0; i<n; i++){
		cin>>a>>b>>l;
		// int y1 = 1, y2 =1;
		// for(int j=0; j<l; j++){
		// 	y1 = (y1*multiplier)%prime1;
		// 	y2 = (y2*multiplier)%prime2;
		// }
		// s1hash1 = (H1[a+l] - (y1*H1[a])%prime1)%prime1;
		// s2hash1 = (H1[b+l] - (y1*H1[b])%prime1)%prime1;

		// s1hash2 = (H2[a+l] - (y2*H2[a])%prime2)%prime2;
		// s2hash2 = (H2[b+l] - (y2*H2[b])%prime2)%prime2;
		// cout<<H1[a+l]<<" "<<H1[a]<<endl;
		cout<<s1hash1<<" "<<s2hash1<<" "<<s1hash2<<" "<<s2hash2<<endl;
		// cout<<s1hash1<<" "<<s2hash1<<" "<<s1hash2<<" "<<s2hash2<<endl;
		s1hash1 = hashfunc(s.substr(a, l),multiplier, prime1);
		s1hash2 = hashfunc(s.substr(a, l),multiplier,prime2);
		s2hash1 = hashfunc(s.substr(b, l),multiplier,prime1);
		s2hash2 = hashfunc(s.substr(b, l),multiplier, prime2);
		if(s1hash1 == s2hash1 && s1hash2 == s2hash2){
			cout<<"Yes"<<endl;
		}
		else{
			cout<<"No"<<endl;

		}
	}
	// cout<<s.substr(0,7);
	return 0;
}