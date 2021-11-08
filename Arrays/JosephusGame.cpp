// n friends, starts with pointer on friend1's hand
// He kills the next kth alive person (start by counting himself)
// One who remains in the end is the winner

class Solution {
public:

    int next(int x,int n,int k, vector<bool> &alive){
        // Gives us the next kth person
        int c = 1;
        while(c!=k){
            x = (x==n)? 1:x+1;
            if(alive[x]){
                c++;
            }
        }
        return x;
    }
    int findTheWinner(int n, int k) {
        vector<bool> alive(n+1, true);
        int count = n, x=1;
        while(count!=1){
            while(!alive[x]){x = (x==n)? 1:x+1;}    //Find the next alive person in cthe clockwise dir
            cout<<x<<" ";
            x = next(x,n,k,alive);
            alive[x] = false;
            count--;
            cout<<x<<endl;
        }
        while(!alive[x]){x = (x==n)? 1:x+1;}
        return x;
    }
};
