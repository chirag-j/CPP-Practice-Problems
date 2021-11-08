#include<iostream>
#include<vector>
#include<queue>
using namespace std;

class Solution {
public:
    
    void addToSet(int i, int j, vector<int> &parent, vector<int> &rank){
        int i_id = find_parent(i,parent);
        int j_id = find_parent(j,parent);
        if(rank[i_id] > rank[j_id]){
            parent[j_id] = i_id;
        }
        else{
            parent[i_id] = j_id;
            if(rank[i_id] == rank[j_id]){rank[j_id]++;}
        }
    }
    int find_parent(int i, vector<int> &parent){
        if(parent[i]!=i){
            parent[i] = find_parent(parent[i],parent);
        }
        return parent[i];
    }
    int man_dist(vector<int> p1, vector<int> p2){
        return abs(p1[0]-p2[0]) + abs(p1[1]-p2[1]);
    }
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        if(n<=1){return 0;}
        vector<int> parent(n), rank(n, 1);
        auto comp = [](vector<int> a, vector<int> b){
            return a[2]>b[2];
        };
        priority_queue<vector<int>, vector<vector<int>>, decltype(comp)> pq(comp);
//         Fill all edges in the priority queue
        for(int i=0; i<n;i++){
            for(int j=i+1; j<n; j++){
                if(i==j){continue;}
                pq.push({i,j,man_dist(points[i], points[j])});
            }
            parent[i] = i; //Initializing the parent array
        }
        int cost = 0;
        int p1, p2;
        while(!pq.empty()){
            // cout<<pq.top()[0]<<" "<<pq.top()[1]<<" "<<pq.top()[2]<<endl;
            p1 = (pq.top())[0];
            p2 = (pq.top())[1];
            if(find_parent(p1,parent) != find_parent(p2,parent)){
                cost+=(pq.top())[2];
                addToSet(p1,p2,parent,rank);
            }
            pq.pop();
        }
        return cost;
    }
};