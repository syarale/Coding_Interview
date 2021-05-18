//CD45：龙与地下城游戏问题

#include <iostream>
#include <vector>
using namespace std;

int get_min(const vector<vector<int> >& in_map) {
    if (in_map.empty()) {
        return 0;
    }
    
    int n = in_map.size();
    int m = in_map[0].size();
    vector<vector<int> > dp(n, vector<int> (m, 0));
    
    dp[n-1][m-1] = max(1-in_map[n-1][m-1], 1);
    for (int j = m - 2; j >= 0; j--) {
        dp[n-1][j] = max(dp[n-1][j+1] - in_map[n-1][j], 1);
    }
    
    for (int i = n - 2; i >= 0; i--) {
        dp[i][m-1] = max(dp[i+1][m-1] - in_map[i][m-1], 1);
    }
    
    for (int i = n - 2; i >= 0; i--) {
        for (int j = m - 2; j >= 0; j--) {
            int to_right = max(dp[i][j+1] - in_map[i][j], 1);
            int to_down = max(dp[i+1][j] - in_map[i][j], 1);
            dp[i][j] = min(to_right, to_down);
        }
    }
    
    return dp[0][0];
}



int main()
{
    int n, m;
    cin>>n>>m;
    
    vector<vector<int> > in_map(n, vector<int> (m, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int tmp;
            cin>>tmp;
            in_map[i][j] = tmp;
        }
    }
    
    int res = get_min(in_map);
    cout<<res;
    
    return 0;
 } 
 
