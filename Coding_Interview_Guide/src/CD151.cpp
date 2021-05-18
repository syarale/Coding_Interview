// CD151£ºÖ®×ÖĞÎ´òÓ¡¾ØÕó 

#include <iostream>
#include <vector> 
using namespace std;


void print_matrix(vector<vector<int> > input) {
    if (input.empty()) {
        return;
    }
    
    int n = input.size();
    int m = input[0].size();
    
    cout<<input[0][0]<<" ";
    if (n == 1 && m == 1) {
        return;
    }
    
    if (n == 1) {
        for (int j = 0; j < m; j++) {
            cout<<input[0][j]<<" ";
        }
        return;
    }
    
    if (m == 1) {
        for (int i = 0; i < n; i++) {
            cout<<input[i][0]<<" ";
        }
        return;
    }
    
    int idt = 1;
    int jdt = -1;
    int i = 0;
    int j = 1;
    for (;;) {
        cout<<input[i][j]<<" ";
        
        if (0 <= i + idt && i + idt < n &&
            0 <= j + jdt && j + jdt < m) {
            i += idt;
            j += jdt;
            continue;        
        }
        
        
        if (i == n - 1 && j == m - 1) {
            break;
        }
        
        if ((i == 0 || i == n - 1) && j < m - 1) {
            idt = -1 * idt;
            jdt = -1 * jdt;
            j++;
            continue;
        }
        
        if ((j == 0 || j == m - 1) && i < n - 1) {
            idt = -1 * idt;
            jdt = -1 * jdt;
            i++;
            continue;
        }
        
        i += idt;
        j += jdt;
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
