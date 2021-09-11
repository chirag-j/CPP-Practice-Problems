#include<iostream>
#include<vector>
using namespace std;

template<class T>
void display(vector<T> v){
    for(int i=0; i<v.size(); i++){
        cout<<v[i]<<" ";
    }
    cout<<endl;
}

vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
    vector<bool> visited(graph.size(), false);
    vector<bool> cycle(graph.size(), false);
    vector<bool> recSt(graph.size(), false);
    vector<int> result;
    for(int i = 0; i<graph.size(); i++){
        if(!visited[i]){
            dfs(graph, i, visited, recSt, cycle);
        }
    }
    display(cycle);
    for(int i=0; i<cycle.size(); i++){
        if(!cycle[i]){
            result.push_back(i);
        }
    }
    return result;
}

void dfs(vector<vector<int>>& graph, int x, vector<bool> &visited, vector<bool> &recSt, vector<bool> &cycle){
    if(recSt[x]){
        cycle[x] = true;
    }
    recSt[x] = true;
    visited[x] = true;
    
    if(graph[x].size()>0){
        for(int next : graph[x]){
            if(!visited[next]){
                dfs(graph, next, visited, recSt, cycle);
                if(cycle[next]){
                    cycle[x] = true;
                }
            }
            else if(recSt[next] || cycle[next]){
                cycle[x] = true;
                cycle[next] = true;
            }
        }
    }
    recSt[x] = false;
}


int main(){
    
    return 0;
}