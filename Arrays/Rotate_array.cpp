#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<queue>

using namespace std;

void display(vector<int> v){
	for(int i = 0; i<v.size(); i++){
		cout<<v[i]<<" ";
	}
	cout<<endl;
}
// rotates an array by d
void rotateArr(int arr[], int d, int n){
	// vector<int> vec(arr, arr+n);
	// for(int i=0; i<n; i++){

	// }
	queue<int> temp;
    for(int i=0; i<n; i++){
        if(i<d){
            temp.push(arr[i]);
        }
        if(i>=n-d){
        	arr[i] = temp.front();
        	temp.pop();
        	continue;
        }
        arr[i] = arr[i+d];
    }
   // arr = &arr[d];

}

int main(){
	// int arr[] = {1,2,3,4,5}, d = 3;
	int arr[] = {2,4,6,8,10,12,14,16,18,20}, d = 4;
	int n = sizeof(arr)/sizeof(int);
	rotateArr(arr, d, n);
	for(int i = 0; i<10; i++){
		cout<<arr[i]<<" ";
	}
	return 0;
}