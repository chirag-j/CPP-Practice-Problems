//Question :
// return the minimum number of intervals you need to remove to make the rest of the intervals non-overlapping.


// my approach (Failed - TLE) :custom sort based on 0th element
// recursively remove both elements, one at a time if they overlap, increase score by 1

// best method : greedy approach
// sort by 0th element
// Go one pass: if any two overlap remove the one with larger end interval

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

template<class T>
void display(vector<T> v){
    for(int i=0; i<v.size(); i++){
        cout<<v[i]<<" ";
    }
    cout<<endl;
}
bool overlaps(vector<int> p1, vector<int> p2){
    if(p1[1] > p2[0]){
        return true;
    }
    return false;
}

bool compFunc(vector<int> a, vector<int> b){
    if(a[0]==b[0]){
        return a[1]<b[1];
    }
    return a[0]<b[0];
}

int eraseOverlaps(vector<vector<int>> &intervals, vector<bool> present, int curr, int score) {
    cout<<score<<"   ";
    display(present);
    if(curr >= intervals.size()-1){
        return score;
    }
    int x = curr, y=1;
    // int score = 0;
    y = x+1;
    while(!present[y]){
        y++;
        if(y>=intervals.size()){return score;}
    }

    if(overlaps(intervals[x], intervals[y])){
        present[y] = false;
        int A = eraseOverlaps(intervals, present, x, score+1);
        present[y] = true;
        present[x] = false;
        int B = eraseOverlaps(intervals, present, y, score+1);
        return min(A,B);
    }
    else{
        return eraseOverlaps(intervals, present, y,score);
    }
}
int main(){
    // vector<vector<int>> intervals = {{1,2},{0,3},{2,6},{1,5},{1,2}};
    vector<vector<int>> intervals = {{1,2},{2,3}};
    vector<bool> present(intervals.size(), true);
    sort(intervals.begin(), intervals.end(), compFunc);
    for(int i=0; i<intervals.size(); i++){
        display(intervals[i]);
    }
    // cout<<overlaps({1,2}, {2,6});
    cout<<eraseOverlaps(intervals, present, 0, 0);
    return 0;
}




//////////
// bool mycomp(vector<int> &a, vector<int> &b){
//     return (a[0]<b[0]);
// }

// class Solution {
// public:
    
//     int eraseOverlapIntervals(vector<vector<int>>& intervals) {
//         int n = intervals.size();
//         sort(intervals.begin(), intervals.end(), mycomp);
        
//         int res = 0;
//         int las = intervals[0][1];
        
//         for(int i = 1; i < n; i++) {
//             if(intervals[i][0] < las){
//                 las = min(intervals[i][1], las);
//                 res++;
//             }
//             else las = intervals[i][1];
//         }
        
//         return res;
//     }
// };