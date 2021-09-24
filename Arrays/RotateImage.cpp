// You have to rotate the image in-place, which means you have to modify the input 2D matrix directly. 
// DO NOT allocate another 2D matrix and do the rotation.

#include<iostream>
#include<vector>
using namespace std;

template<class T>
void display(vector<T> v){
    for(int i=0; i<v.size(); i++){
        cout<<v[i]<<" ";
    }
    cout<<endl;
}

void display(vector<vector<int>> v){
    for(int i=0; i<v.size(); i++){
        display(v[i]);
    }
}

void rotate(vector<vector<int>>& matrix) {
    vector<int> tl, tr, bl, br;
    int n = matrix.size();
    // Taking transpose
    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            swap(matrix[i][j], matrix[j][i]);
        }
    }
    display(matrix);
    // reversing each row
    int j=0;
    for(int i=0; i<n; i++){
        j=0;
        while(j < n-j-1){
            swap(matrix[i][j], matrix[i][n-j-1]);
            j++;
        }
    }
}

int main(){
    vector<vector<int>> matrix = {{5,1,9,11},
                                           {2,4,8,10},
                                           {13,3,6,7},
                                           {15,14,12,16}};
    // matrix.push_back({5,1,9,11});
    // matrix.push_back({2,4,8,10});
    // matrix.push_back({13,3,6,7});
    // matrix.push_back({15,14,12,16});
    display(matrix);
    cout<<endl;
    rotate(matrix);
    display(matrix);
    return 0;
}