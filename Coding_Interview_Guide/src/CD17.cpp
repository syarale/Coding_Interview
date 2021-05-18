// CD17：机器人到达指定位置方法数


#include <iostream>
#include <vector>
using namespace std;

const int MOD = 1e9 + 7;

int walk(int n, int m, int k, int p) {
    vector<int> dp(n + 1, 0);
    
    for (int i = 1; i <= n; i++) {
        if (i == p) {
            dp[i] = 1;
        } else {
            dp[i] = 0;
        }
    } 
    
    for (int i = 1; i <= k; i++) {
       int tmp = 0;
       for (int j = 1; j <= n; j++) {
           if (j == 1) {
               tmp = dp[j+1];
               continue;
           }
           
           if (j == n) {
               int curr = dp[j-1];
               dp[j-1] = tmp;
               dp[j] = curr;
               continue;
           }
           
           int curr = (dp[j-1] + dp[j+1]) % MOD;
           dp[j-1] = tmp;
           tmp = curr;
           
           if (i == k && j == m) {
               return tmp;
           }
       } 
       

    }
    
    return dp[m];
}

int main()
{
    int N, M, K, P;
    cin>>N>>M>>K>>P;
    
    int ret = walk(N, M, K, P);
    cout<<ret;
    
    return 0;
}
 
