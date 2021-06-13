
vector<int> ids;

void Union(int a, int b){
    int ida = ids[a];
    int idb = ids[b];
    if(ida == idb){
        return;
    }
    for(int i=0; i<ids.size(); i++){
        if(ids[i] == ida || ids[i]==idb){
            ids[i] = ida;
        }
    }
}
void display(vector<int> v){
    for(int i=0; i<v.size(); i++){
        cout<<v[i]<<" ";
    }
    cout<<endl;
}
class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        ids.clear();
        for(int i=0; i<isConnected.size(); i++){
            ids.push_back(i);
        }
        for(int i=0; i<isConnected.size(); i++){
            for(int j=0; j<isConnected.size(); j++){
                if(isConnected[i][j] == 1){
                    Union(i,j);
                }
            }
        }
        int count = 0;
        for(int i=0; i<ids.size(); i++){
            if(ids[i] == i){
                count++;
            }
        }
        display(ids);

        return count;
    }
};