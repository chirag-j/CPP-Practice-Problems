// Given an array of integers temperatures represents the daily temperatures, 
// return an array answer such that answer[i] is the number of days you have to wait after the ith day to get a warmer temperature. 
// If there is no future day for which this is possible, keep answer[i] == 0 instead.



vector<int> dailyTemperatures(vector<int>& temperatures) {
    int n = temperatures.size();
    vector<int> res(n,0);

    int j=0, temp;
    
    for(int i=n-2; i>=0; i--){
        temp = i+1;
        if(temperatures[temp]>temperatures[i]){
            res[i] = temp-i;
        }
        else{
            while(temp<n && res[temp]!=0){
                temp += res[temp];
                if(temperatures[temp]>temperatures[i]){
                    res[i] = temp-i;
                    break;
                }
            }
        }
    }
    return res;
}