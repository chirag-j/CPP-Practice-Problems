// Consider a list of all factors of n sorted in ascending order, 
// return the kth factor in this list or return -1 if n has less than k factors.

// running from 1 to sqrt of n gives us factors in order
// except for the quotient(2nd factor), which is in decending order
// so store the quotients, if k exceeds look for the values (stored in descending order)


class Solution {
public:
    int kthFactor(int n, int k) {
        int c = 0;
        vector<int> qu;
        for(int i=1; i<=sqrt(n);i++){
            if(n%i == 0){
                c++;
                if(c==k){
                    return i;
                }
                if(n!=i*i){qu.push_back(n/i);}
            }
        }
        if(c+qu.size() <k){
            return -1;
        }
        cout<<c<<qu.size();
        return qu[qu.size()-1 -(k-c-1)];
    }
};