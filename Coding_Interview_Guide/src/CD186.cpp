//CD186：矩阵的最小路径和


#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int get_min_pathsum(const vector<vector<int> >& matrix) {
    // assert(!matrix.empty());
    int row = matrix.size();
    int col = matrix[0].size();
    vector<int> raw_vec(col, 0);
    vector<int> col_vec(row, 0);
    
    //init arr with the 0-th raw of matrix
    int p = 0;
    for (int i = 0; i < col; i++) {
        p = p + matrix[0][i];
        raw_vec[i] = p;
    }
    
    int k = 0;
    for (int i = 0; i < row; i++) {
        k = k + matrix[i][0];
        col_vec[i] = k;
    }
    
    for (int i = 1; i < row; i++) {
        int tmp = col_vec[i];
        for (int j = 1; j < col; j++) {
            tmp = min(tmp, raw_vec[j]) + matrix[i][j];
            raw_vec[j] = tmp;
        }
    }
    
    return raw_vec[col - 1];
}

int main(){
    int n, m;
    cin>>n>>m;
    vector<vector<int> > matrix(n, vector<int>(m, 0));
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int tmp = 0;
            cin>>tmp;
            matrix[i][j] = tmp;
        }
    }
    
    cout<<get_min_pathsum(matrix);

    return 0;
} 
