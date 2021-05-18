//CD19：换钱的方法数

#include <iostream>
#include <vector>
using namespace std;

const int MOD = 1e9 + 7; 

int get_coins(const vector<int>& arr, int aim) {
    int n = arr.size();
    vector<vector<int> > dp(n, vector<int>(aim + 1, 0));
    
    for (int i = 0; i < n; i++) {
        dp[i][0] = 1;
    }
    
    for (int k = 1; arr[0] * k <= aim; k++) {
        dp[0][arr[0] * k] = 1;
    }
    
    for (int i = 1; i < n; i++) {
        for (int j = 1; j <= aim; j++) {
            dp[i][j] = dp[i-1][j];
            if (j - arr[i] >= 0) {
                dp[i][j] = (dp[i][j] + dp[i][j-arr[i]]) % MOD;
            }
        }
    }
    
    
    return dp[n-1][aim];
}


int main()
{
    int n, aim;
    vector<int> arr;
    cin>>n>>aim;
    
    for (int i = 0; i < n; i++) {
        int tmp;
        cin>>tmp;
        arr.push_back(tmp);
    }
    
    int ret = get_coins(arr, aim);
    cout<<ret; 
    
    return 0;
}
