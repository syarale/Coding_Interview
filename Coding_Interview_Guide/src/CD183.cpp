//CD183：斐波那契数列的递归和动态规划

#include <iostream>
#include <vector>
using namespace std;

const int MOD = 1e9 + 7;

vector<vector<int> > muti_matrix(vector<vector<int> > matrix1,
                                 vector<vector<int> > matrix2) {
    int len = matrix1.size();
    vector<vector<int> > res(len, vector<int>(len, 0));
    for (int i = 0; i < len; i++) {
        for (int j = 0; j < len; j++) {
            for (int k = 0; k < len; k++) {
                res[i][j] += ((matrix1[i][k] * matrix2[k][j]));
            }
        }
    }
    
    return res;                          
}


void power_matrix(vector<vector<int> > base, long n,
                  vector<vector<int> >& result) {
    
    long ptr = n;
    for (int i = 0; i < result.size(); i++) {
        result[i][i] = 1;
    }
    vector<vector<int> > tmp = base;
    for (ptr = n; ptr != 0; ptr >>= 1) {
        if ((ptr & 1) != 0) {
            result = muti_matrix(result, tmp);
        }
        tmp = muti_matrix(tmp, tmp);
    }
    
    return;
                      
} 

int fibonacci(long n) {
    if (n <= 2) {
        return 1;
    }
    
    vector<vector<int> > p_matrix(2, vector<int>(2, 0));
    vector<vector<int> > base(2, vector<int>(2, 1));
    base[1][1] = 0;
    power_matrix(base, n - 2, p_matrix);
    return p_matrix[0][0] + p_matrix[1][0];
}


int main()
{
    int n = 0;
    cin>>n;
    
    int ret = fibonacci(n);
    cout<<ret;
    
    return 0;    
} 


 
