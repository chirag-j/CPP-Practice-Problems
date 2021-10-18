// Given a word pat and a text txt. 
// Return the count of the occurences of anagrams of the word in the text.
class Solution{
public:
    void display(unordered_map<char, int> &window){
        for(auto &itr : window){
            cout<<itr.first<<" : "<<itr.second<<endl;
        }
    }
	int search(string pat, string txt) {
	    unordered_map<char, int> window;
	    int j=0, k = pat.size(), count, res = 0;;
	    for(int i=0; i<k; i++){
	        window[pat[i]]++;
	    }
	    count = window.size();
	    for(int i=0; i<txt.size(); i++){
	       // display(window);
	       // cout<<count<<" "<<txt[i]<<" "<<res<<endl;
	        if(window.find(txt[i])!=window.end()){
                window[txt[i]]--;
                if(window[txt[i]]==0){
                    count--;
                }
            }
	        if(i<k-1){
	            continue;
	        }
	        else if(i==k-1){
	            if(count==0){res++;}
	           // j++;
	        }
	        else{
	            if(window.find(txt[j])!=window.end()){
	                if(window[txt[j]] == 0){
	                    count++;
	                }
    	            window[txt[j]]++;
	            }
	            if(count==0){res++;}
	            
	            j++;
	        }
	    }
	    return res;
	    // code here
	}

};