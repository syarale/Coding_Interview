//CD43：最小编辑代价

#include <iostream>
#include <string>
#include <vector> 
using namespace std;

int insert_v = 0;
int delete_v = 0;
int replace_v = 0;
vector<vector<int> > dp;

int get_min_cost(string optr, string tptr) {
    int olen = optr.size();
    int tlen = tptr.size();
    
    if (optr.empty() && tptr.empty()) {
        return 0;
    }
    
    dp.resize(olen + 1, vector<int>(tlen + 1, 0));
    dp[0][0] = 0;
    for (int i = 1; i <= olen; i++) {
        dp[i][0] = delete_v * i;
    }
    
    for (int i = 1; i <= tlen; i++) {
        dp[0][i] = insert_v * i;
    }
    
    for (int i = 1; i <= olen; i++) {
        for (int j = 1; j <= tlen; j++) {
            int min_cost = min(dp[i-1][j] + delete_v, dp[i][j-1] + insert_v);
            if (optr[i-1] == tptr[j-1]) {
                min_cost = min(min_cost, dp[i-1][j-1]);
            } else {
                min_cost = min(min_cost, dp[i-1][j-1] + replace_v);
            }
            dp[i][j] = min_cost;
        }
    }

    return dp[olen][tlen];
}


int main()
{
    string str1, str2;
    
    cin>>str1>>str2;
    cin>>insert_v>>delete_v>>replace_v;
    
    int res = get_min_cost(str1, str2);
    cout<<res;
    
    return 0;
}
