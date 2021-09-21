template <class T>
void display(vector<T> v){
    for(int i:v){
        cout<<i<<" ";
    }
    cout<<endl;
}
class Solution {
public:
    int maximum69Number (int num) {
        int rem, n=10;
        rem = num%n;
        vector<int> numvec;
        while(rem!=0){
            numvec.push_back(rem);
            rem = num%(n*10);
            rem = rem/n;
            n*=10;
        }
        for(int i=numvec.size()-1; i>=0; i--){
            if(numvec[i] == 6){
                numvec[i] = 9;
                break;
            }
        }
        int num_out = 0;
        
        for(int i=numvec.size() -1; i>=0; i--){
            num_out += pow(10,i) * numvec[i];
        }
        display(numvec);
        
        return num_out;
    }
};