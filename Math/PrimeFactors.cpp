// return all prime factors of given number N

class Solution{
	public:
	vector<int>AllPrimeFactors(int N) {
	    set<int> st;
	    int temp = N;
	    if(temp%2 ==0){
	        st.insert(2);
	        while(temp%2==0){
	            temp/=2;
	        }
	    }
	    for(int i=3; i<=sqrt(N); i+=2){
	        if(temp%i == 0){
	            st.insert(i);
	            while(temp%i==0){temp/=i;}
	        }
	    }
	    if(temp>2){
	        st.insert(temp);
	    }
	    vector<int> res;
	    for(auto &it : st){
	        res.push_back(it);
	    }
	    return res;
	    // Code here
	}
};