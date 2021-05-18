//CD92：跳跃游戏


//时间复杂度O(n^2), 另有O(n)解法 
#include <iostream>
#include <vector>
using namespace std;


int get_min_num(vector<int> arr) {
    int len = arr.size();
    
    if (arr.empty() || len == 2) {
        return 0;
    }
    
    vector<int> dp(len, -1);
    int num = 0;
    for (int i = 0; i < len; i += arr[i]) {
        dp[i] = num;
        num++;
    }
    
    for (int i = 1; i < len; i++) {
        for (int k = i - 1; k >= 0; k--) {
            if (k + arr[k] >= i) {
                if (dp[i] == -1) {
                    dp[i] = dp[k] + 1;
                } else {
                    dp[i] = min(dp[i], dp[k] + 1);
                }
            }
        }
    }
    
    return dp[len-1];
}



int main()
{
    int n;
    vector<int> arr;
    
    cin>>n;
    for (int i = 0; i < n; i++) {
        int tmp;
        cin>>tmp;
        arr.push_back(tmp);
    }
    
    int res = get_min_num(arr);
    cout<<res;
    
    return 0;
}
