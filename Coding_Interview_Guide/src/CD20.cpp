//CD20：打气球的最大分数

#include <iostream>
#include <vector>
using namespace std;

vector<vector<int> >dp;

int get_max_goals(vector<int>& arr) {
    //assert(!arr.empty());
    if (arr.empty()) {
        return 0;
    }
    
    int len = arr.size();
    arr.insert(arr.begin(), 1);
    arr.insert(arr.end(), 1);
    
    for (int i = 1; i <= len; i++) {
        dp[i][i] = arr[i] * arr[i - 1] * arr[i + 1]; 
    }
    
    for (int l = len - 1; l > 0; l--) {
        for (int r = l + 1; r <= len; r++) {
            int max_goal = max(dp[l+1][r] + arr[l-1] * arr[l] * arr[r+1],
                               dp[l][r-1] + arr[l-1] * arr[r] * arr[r+1]);
            for (int k = l + 1; k < r; k++) {
                max_goal =max(max_goal, dp[l][k-1] + dp[k+1][r] + arr[l-1] * arr[k] * arr[r+1]);
            } 
            dp[l][r] = max_goal;
        } 
    } 
     
    return dp[1][len];
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
    
    dp.resize(n + 1, vector<int>(n + 1, 0));
//    dp.resize(n + 2, vector<int>(n + 2, 0));
//    vector<vector<int> >dp(len + 1, vector<int>(len + 1, 0));
    
    int res = get_max_goals(arr);
    cout<<res;
    return 0;    
} 
 
