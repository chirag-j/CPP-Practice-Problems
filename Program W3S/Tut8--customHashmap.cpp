#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;

template<class T>
void display(vector<T> v){
    for(int i=0; i<v.size(); i++){
        cout<<v[i]<<" ";
    }
    cout<<endl;
}

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
    bool operator==(ListNode *a){
        return this->val == a->val;
    }
};

class myHashFunc{
	public:
	auto operator()(vector<int> x) const{
        // hash<int> inth;
        if(x.empty()){return hash<int>()(0);}
        return (hash<int>()(x.front()+x.back()));
    }

};
int main(){
    // For pointer of any kind the default hash works 
    vector<int> av = {1,2,3,4}, bv = {3,-1,2};
    unordered_set<vector<int>, myHashFunc> egset;
    egset.insert(av);
    egset.insert(bv);
    for(auto &itr: egset){
        display(itr);
    }
    if(egset.find(av)!=egset.end()){
        cout<<"Works";
    }
    return 0;
}