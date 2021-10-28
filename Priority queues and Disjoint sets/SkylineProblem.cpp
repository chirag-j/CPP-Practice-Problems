// The geometric information of each building is given in the array buildings 
// where buildings[i] = [lefti, righti, heighti]:

#define temp pq.top()

class compclass{
  public:
    bool operator()(vector<int> a, vector<int> b){
        if(a[0]==b[0]){             //same x value
            if(a[3]==0 & b[3]==0){
                return a[1] > b[1];     //same point end : ascending accdg to height
            }
            else if(a[3]==1 & b[3]==1){
                return a[1] < b[1];     //same point start : descending accdg to height
            }
            else{
                return a[3]<b[3];       //end coincides with start--> start first
            }
            
        }
        return a[0] > b[0];
    }
};

void display(vector<int> v){
    for(int i: v){
        cout<<i<<" ";
    }
    cout<<endl;
}

void display(priority_queue<vector<int>, vector<vector<int>>, compclass> pq){
    while(!pq.empty()){
        display(pq.top());
        pq.pop();
    }
}

int parent(int i){
    return (i-1)/2;
}
int leftChild(int i){
    return 2*i + 1;
}
int rightChild(int i){
    return 2*i + 2;
}
void siftup(vector<int>&pq, int i){
    while(i!=0 && pq[parent(i)]<pq[i]){
        swap(pq[parent(i)], pq[i]);
        i = parent(i);
    }
}
void siftdown(vector<int> &pq, int i){
    int maxInd = i;
    if(leftChild(i)<pq.size() && pq[leftChild(i)]>pq[i]){
        maxInd = leftChild(i);
    }
    if(rightChild(i)<pq.size() && pq[rightChild(i)]>pq[maxInd]){
        maxInd = rightChild(i);
    }
    if(maxInd!=i){
        swap(pq[maxInd], pq[i]);
        siftdown(pq,maxInd);
    }
}
void deletepq(vector<int> &pq, int val, int i){
    if(pq.empty() || i>=pq.size()){return;}
    if(pq[i] < val){return;}
    else if(pq[i] == val){
        swap(pq[pq.size()-1],pq[i]);
        pq.pop_back();
        siftdown(pq,i);
        return;
    }
    deletepq(pq,val,leftChild(i));
    deletepq(pq,val,rightChild(i));
}
void insert(vector<int> &pq, int val){
    pq.push_back(val);
    siftup(pq,pq.size()-1);
}
void extractMax(vector<int> &pq){
    if(pq.size()==0){return;}
    swap(pq[pq.size()-1], pq[0]);
    pq.pop_back();
    siftdown(pq,0);
}

class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings){
        // buildings = {{0,2,10},{2,9,10},{9,12,5}};
        priority_queue<vector<int>, vector<vector<int>>, compclass> pq;
        for(int i=0; i<buildings.size(); i++){
            pq.push({buildings[i][0],buildings[i][2], i, 1});
            pq.push({buildings[i][1],buildings[i][2], i, 0});
        }
        vector<vector<int>> res;
        vector<int> st;
        insert(st,0);
        display(pq);
        int curr_max = 0;
        cout<<"start"<<endl;
        while(!pq.empty()){
            if(temp[3] ==1){                      //new building entry
                if(st[0] < temp[1]){           //new building is taller
                    res.push_back({temp[0],temp[1]});
                    curr_max = temp[1];
                }
                insert(st,temp[1]);
            }
            else if(temp[3]==0){                    //end of a building
                if(temp[1]==st[0]){          //end of currTallest building 
                    extractMax(st);
                    if(st[0]!=temp[1]){res.push_back({temp[0],st[0]});}
                }
                else{deletepq(st,temp[1],0);}
                
            }
            display(st);
            cout<<endl;
            pq.pop();
            
        }
        return res;
    }
};