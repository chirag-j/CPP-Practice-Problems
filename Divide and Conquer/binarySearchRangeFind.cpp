class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        // nums = {5,7,7,8,10};
        // target = 6;
        if(nums.size() == 0){
            return {-1,-1};
        }
        int mid, x, y, xd = -1, yd = -1;
        x = 0;
        y = nums.size();
        do{
            mid = x + (y-x)/2;
            cout<<mid<<" "<<x<<" "<<y<<endl;
            if(nums[mid] == target){
                xd = mid;
                while(xd-1>=0 && nums[xd-1] == target){
                    xd--;
                }
                yd = mid;
                while(yd+1 < nums.size() && nums[yd+1] == target){
                    yd++;
                }
                return {xd, yd};
            }
            else if(nums[mid] > target){
                y = mid;
            }
            else{
                x = mid+1;
            }
            
        }
        while(mid!=0 && y>x);
        return {-1,-1};
    }
};