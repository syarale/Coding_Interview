// CD1：在行列都排好序的矩阵中找指定的数 

#include <iostream>
#include <vector>
using namespace std;

bool is_exist(vector<vector<int> > arr, int k) {
    if (arr.empty()) {
        return false;
    }
    
    int row = arr.size();
    int col = arr[0].size();
    int i = 0;
    int j = col - 1;
    while (0 <= i && i < row && 
           0 <= j && j < col) {

        if (k == arr[i][j]) {
            return true;
        } else if (k < arr[i][j]) {
            j--;
        } else {
            i++;
        }
    }
    
    return false;
 
}


int main() {
    int n = 0;
    int m = 0;
    int k = 0;
    
    cin>>n>>m>>k;
    vector<vector<int> > arr(n, vector<int> (m, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int tmp = 0;
            cin>>tmp;
            arr[i][j] = tmp;    
        }  
    }
    
    if (is_exist(arr, k)) {
        cout<<"Yes";
    } else {
        cout<<"No";
    }
    
    return 0;
} 
