//CD12：换钱的最少货币数

#include <iostream>
#include <vector>
using namespace std;


int get_min_coins(const vector<int>& arr, int aim) {
    //assert(!arr.empty());
    int len = arr.size();
    vector<vector<int> > dp(len, vector<int>(aim + 1, 0));
    
    for (int i = 1; i <= aim; i++) {
        if (i % arr[0] == 0) {
            dp[0][i] = (i/arr[0]); 
        } else {
            dp[0][i] = -1;
        }
    }
    
    for (int i = 1; i < len; i++) {
        for (int j = 1; j <= aim; j++) {
            if (j < arr[i]) {
                dp[i][j] = dp[i-1][j];
            } else {
                if (dp[i-1][j] == -1 && dp[i][j-arr[i]] == -1) {
                    dp[i][j] = -1;
                    continue;
                } 
                
                if(dp[i-1][j] == -1 && dp[i][j-arr[i]] != -1) {
                    dp[i][j] = dp[i][j-arr[i]] + 1;
                    continue;
                }
                
                if (dp[i-1][j] != -1 && dp[i][j-arr[i]] == -1) {
                    dp[i][j] = dp[i-1][j];
                    continue;
                }
                
                //if (dp[i-1][j] != -1 && dp[i][j-arr[i]] != -1) ... 
                dp[i][j] = min(dp[i-1][j], dp[i][j-arr[i]] + 1);
            }
        }
    }
    
    return dp[len - 1][aim];
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
    
    int res = get_min_coins(arr, aim);
    cout<<res;
    
    return 0;
}
