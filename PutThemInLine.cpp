#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

template<class T>
void display(vector<T> v){
    for(int i=0; i<v.size(); i++){
        cout<<v[i]<<" ";
    }
    cout<<endl;
}

void display(vector<vector<int>> v){
    for(int i=0; i<v.size(); i++){
        display(v[i]);
    }
}


vector<vector<int>> results;

void recurLine(vector<int> &ast, unordered_map<int, int> &icst, vector<int> curr, vector<bool> cpres){

    if(curr.size() == ast.size()){
        results.push_back(curr);
        return;
    }

    for(int i=0; i<ast.size(); i++){
        if(cpres[i]){continue;}
        if(icst.find(ast[i]) == icst.end() || curr.size()==0 || icst[ast[i]] != curr.back()){
            curr.push_back(ast[i]);
            cpres[i] = 1;
        }
        else{continue;}
        // display(curr);
        recurLine(ast, icst, curr, cpres);
        curr.pop_back();
        cpres[i] = 0;
    }
}

int main(){
    results.clear();
    vector<int> ast = {0,1,2,3}; //ast -- all_students
    vector<vector<int>> icst_vec = {{0,1}}; //incompatible_students
    unordered_map<int, int> icst;
    icst.clear();
    for(int i=0; i<icst_vec.size(); i++){
        icst[icst_vec[i][0]] = icst_vec[i][1];
        icst[icst_vec[i][1]] = icst_vec[i][0];
        // cout<<icst_vec[i][0]<<" "<<icst_vec[i][1]<<endl;
    }
    vector<bool> cpres(ast.size(), 0);
    recurLine(ast, icst, {}, cpres);
    display(results);
    // cout<<int('0');
    // cout<<char(int('0') +1)<<endl;
    // cout<<char(1) - char(0);
    return 0;
}