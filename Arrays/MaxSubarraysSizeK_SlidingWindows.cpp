// Given an array arr[] of size N and an integer K. 
// Find the maximum for each and every contiguous subarray of size K.


class Solution
{
  public:
    //Function to find maximum of each subarray of size k.
    void display(list<int> ls){
        for(auto &x : ls){
            cout<<x<<" ";
        }
        cout<<endl;
    }
    vector <int> max_of_subarrays(int *arr, int n, int k)
    {
        vector<int> res;
        list<int> ml;
        res.clear();
        ml.clear();
        int j=0;
        for(int i=0; i<n ;i++){
            while(ml.size()!=0 && ml.front()<arr[i]){ml.pop_front();}  //made the mistake of writing (<=) instead of (<), it made problems because of delete operations that i do later, if found equal
            while(ml.size()!=0 && ml.back()<arr[i]){ml.pop_back();}
            ml.push_back(arr[i]);
            // display(ml);
            if(i<k-1){
                continue;
            }
            else if(i>k-1){
                if(arr[j] == ml.front()){ml.pop_front();}
                j++;
            }
            if(!ml.empty()){res.push_back(ml.front());}
        }
        // your code here
        return res;
    }
};