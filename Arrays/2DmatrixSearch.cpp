#include<iostream>
#include<vector>
using namespace std;

// first attempt(failed- doesn't generalize well) : search in the first row and first column,
// get 2 rows and 2 columns between which our target lies
// Failed because that doesnt generalize

// second attempt(accepted) -- search row
// if not found drop y pointer by 1

// Best method -- Search from the top-right element and 
// reduce the search space by one row or column at each time.


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

int binary_search_row(vector<vector<int>>& matrix, int target, int x, int y1, int y2){
    // int y1 = 0, y2 = matrix[0].size()-1;
    int mid;
    do{
        mid = y1 + (y2-y1)/2;
        if(matrix[x][mid] == target){
            return -1;
        }
        else if(matrix[x][mid] > target){
            y2 = mid;
        }
        else{
            y1 = mid;
        }
    }
    while(y2-y1>1);
    cout<<x<<"-"<<y1<<" "<<y2<<endl;
    if(matrix[x][y1] == target){
        return -1;
    }
    return y1;
}
// int binary_search_col(vector<vector<int>>& matrix, int target, int y){
//     int x1 = 0, x2 = matrix.size()-1;
//     int mid;
//     do{
//         // cout<<mid<<" "<<y<<endl;
//         mid = x1 + (x2-x1)/2;
//         if(matrix[mid][y] == target){
//             return -1;
//         }
//         else if(matrix[mid][y] > target){
//             x2 = mid;
//         }
//         else{
//             x1 = mid;
//         }
//     }
//     while(x2-x1>1);
//     if(matrix[x1][y] == target || matrix[x2][y] == target){
//         return -1;
//     }
//     return x1;
// }



// bool searchMatrix(vector<vector<int>>& matrix, int target) {
//     // int x1=0,x2=matrix.size()-1, y1=0, y2=matrix[0].size()-1;
//     // int mid;
//     int y1 = binary_search_row(matrix,target,0), y2;
//     int x1 = binary_search_col(matrix,target,0), x2;
//     if(y1 == -1 || x1 == -1){
//         return true;
//     }
//     cout<<x1<<" "<<y1<<endl;
//     if(binary_search_col(matrix,target,y1) == -1 || binary_search_row(matrix, target,x1) == -1 ){
//         return true;
//     }
//     if(x1 < matrix.size()-1 && binary_search_row(matrix, target,x1+1) == -1 ){
//         return true;
//     }
//     if(y1 < matrix[0].size()-1 && binary_search_col(matrix, target,y1+1) == -1 ){
//         return true;
//     }
//     return false;
// }

bool searchMatrix(vector<vector<int>>& matrix, int target) {
    int x=0, y=0;
    y = binary_search_row(matrix, target, x, 0, matrix[0].size());
    cout<<y<<endl;
    if(y==-1){
        return true;
    }
    x++;
    while(x<matrix.size()){
        if(matrix[x][y] > target){
            y = binary_search_row(matrix, target, x, 0, y);
        }
        else if(matrix[x][y] < target){
            y = binary_search_row(matrix, target, x, y, matrix[0].size());
        }
        else{
            return true;
        }
        if(y == -1){
            return true;
        }
        x++;
    }
    return false;
}

int main(){
    // vector<vector<int>> matrix = 
    // {{1,4,7,11,15},
    // {2,5,8,12,19},
    // {3,6,9,16,22},
    // {10,13,14,17,24},
    // {18,21,23,26,30}};
    // vector<vector<int>> matrix = {{1,3,5,7,9},{2,4,6,8,10},{11,13,15,17,19},{12,14,16,18,20},{21,22,23,24,25}};
    vector<vector<int>> matrix = {{-1, 3}};
    display(matrix);
    int target = 3;
    cout<<searchMatrix(matrix, target);
    return 0;
}