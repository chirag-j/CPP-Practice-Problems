// You are given an array prerequisites where prerequisites[i] = [ai, bi] 
// indicates that you must take course bi first if you want to take course ai

// Return the ordering of courses you should take to finish all courses. 
// If there are many valid answers, return any of them. 
// If it is impossible to finish all courses, return an empty array.

class Solution {
public:
    bool topsort(vector<vector<int>> &adj, vector<int> &order, vector<bool> &visited,vector<bool> &curr, int x){
        if(curr[x]){return false;}
        visited[x] = true;
        curr[x] = true;
        for(int i:adj[x]){
            if(curr[i]){return false;}
            if(!visited[i]){
                if(!topsort(adj,order,visited,curr,i)){return false;}
            }
        }
        order.push_back(x);
        curr[x] = false;
        return true;
    }
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        for(int i=0; i<prerequisites.size();i++){
            adj[prerequisites[i][0]].push_back(prerequisites[i][1]);
        }
        vector<bool> visited(numCourses,false), curr(numCourses,false);
        vector<int> order;
        for(int i=0; i<adj.size(); i++){
            if(!visited[i]){
                if(!topsort(adj,order,visited,curr,i)){return {};}
            }
        }
        // reverse(order.begin(), order.end());
        return order;
    }
};