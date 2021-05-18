// CD149£º×ªÈ¦´òÓ¡¾ØÕó 

#include <iostream>
#include <vector> 
using namespace std;

void print_edge(vector<vector<int> > input, 
                int ti, int tj, int di, int dj) {
    if (ti == di) {
        for (int j = tj; j <= dj; j++) {
            cout<<input[ti][j]<<" ";
        } 
        return;
    }   
    
    
    if (tj == dj) {
        for (int i = ti; i <= di; i++) {
            cout<<input[i][tj]<<" ";
        }
        return;
    }
    
    int i = ti;
    int j = tj;
    while (j != dj) {
        cout<<input[i][j]<<" ";
        j++;
    }
    
    while (i != di) {
        cout<<input[i][j]<<" ";
        i++;
    }
    
    while (j != tj) {
        cout<<input[i][j]<<" ";
        j--;
    }
    
    while (i != ti) {
        cout<<input[i][j]<<" ";
        i--;
    }
    
    return;
    
                
}


void print_matrix(vector<vector<int> > input) {
    if (input.empty()) {
        return;
    }
    
    int n = input.size();
    int m = input[0].size();
    
    int ti = 0;
    int tj = 0;
    int di = n - 1;
    int dj = m - 1;
    while (ti <= di && tj <= dj) {
        print_edge(input, ti, tj, di, dj);
        ti++;
        tj++;
        di--;
        dj--;
    }
    
    return;
}


int main() {
    int n = 0;
    int m = 0;
    
    cin>>n>>m;
    vector<vector<int> > input(n, vector<int> (m, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int tmp = 0;
            cin>>tmp;
            input[i][j] = tmp;
        }
    }
    
    print_matrix(input);
    
    return 0;
    
} 
