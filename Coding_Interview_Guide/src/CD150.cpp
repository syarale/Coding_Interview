// CD150：将正方形矩阵顺时针转动 90° 

#include <iostream>
#include <vector> 
using namespace std;

void tranverse_edge(vector<vector<int> >& input, 
                int ti, int tj, int di, int dj) {
    if (ti == di) {
        // assert(tj == dj);
        return;
    }
    
    int len = dj - tj;
    for (int i = 0; i < len; i++) {
        int tmp = input[ti][tj + i];
        input[ti][tj + i] = input[di - i][tj];
        input[di - i][tj] = input[di][dj - i];
        input[di][dj - i] = input[ti + i][dj]; 
        input[ti + i][dj] = tmp;
    }
    
    return;
                  
}


void tranverse_matrix(vector<vector<int> >& input) {
    if (input.empty()) {
        return;
    }
    
    int n = input.size();
    int m = input[0].size();
    int ti = 0;
    int tj = 0;
    int di = n - 1;
    int dj = n - 1;
    while (ti <= di && tj <= dj) {
        tranverse_edge(input, ti, tj, di, dj);
        ti++;
        tj++;
        di--;
        dj--;
    }

    
    return;
}


int main() {
    int n = 0;
    
    cin>>n;
    vector<vector<int> > input(n, vector<int> (n, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int tmp = 0;
            cin>>tmp;
            input[i][j] = tmp;
        }
    }
    
    tranverse_matrix(input);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout<<input[i][j]<<" ";
        }
        cout<<endl;
    }
    
    return 0;
    
} 
