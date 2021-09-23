class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        set<vector<int>> intset;
        for(auto x:intervals){
            intset.insert(x);
        }
        set<vector<int>> :: iterator it = intset.begin();
        it++;
        intervals.clear();
        intervals.push_back(*(intset.begin()));
        int i=0;
        while(it!=intset.end()){
            if(intervals[i][1] >= (*it)[0]){
                intervals[i][1] = max((*it)[1], intervals[i][1]);
            }
            else{
                intervals.push_back(*it);
                i++;
            }
            it++;
            // it++;
        }
        return intervals;
    }
};