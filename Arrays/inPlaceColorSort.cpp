// Given an array nums with n objects colored red, white, or blue, sort them in-place so that 
// objects of the same color are adjacent, with the colors in the order red, white, and blue.

// We will use the integers 0, 1, and 2 to represent the color red, white, and blue, respectively.


#include<iostream>
#include<vector>
using namespace std;

void quicksort(vector<int>& nums, int x){
    int m = 0, n = 1;

}
template<class T>
void display(vector<T> v){
    for(int i=0; i<v.size(); i++){
        cout<<v[i]<<" ";
    }
    cout<<endl;
}

void sortColors(vector<int>& nums) {
    int m=0, n=0;
    for(int i=0; i<nums.size(); i++){
        if(nums[i] < 1){
            if(n==i){
                swap(nums[m], nums[i]);
            }
            else{
                swap(nums[m], nums[n]);
                swap(nums[m], nums[i]);
            }
            m++;
            n++;
        }
        else if(nums[i] == 1){
            swap(nums[i], nums[n]);
            n++;
        }
        display(nums);
        cout<<m<<" "<<n<<endl;
    }
}

int main(){
    vector<int> nums = {1,0,2,1,1,0,2};
    sortColors(nums);
    display(nums);
    return 0;
}