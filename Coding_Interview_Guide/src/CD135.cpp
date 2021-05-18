//CD135：回文最少分割数

#include <iostream>
#include <string>
#include <vector>
using namespace std; 

int get_min_cut(string str) {
    int len = str.size();
    
    if (str.empty() || len == 1) {
        return 0;
    }
    
    vector<int> dp(len, 0);
    vector<vector<bool> > palid_dp(len, vector<bool> (len, false));
    for (int i = 0; i < len - 1; i++) {
        palid_dp[i][i] = true;
        if (str[i] == str[i+1]) {
            palid_dp[i][i+1] = true;
        } else {
            palid_dp[i][i+1] = false;
        }
    }
    palid_dp[len - 1][len - 1] = true;
    
    for (int i = len - 3; i >= 0; i--) {
        for (int j = i + 2; j < len; j++) {
            if (str[i] == str[j] && palid_dp[i+1][j-1]) {
                palid_dp[i][j] = true;
            } else {
                palid_dp[i][j] = false;
            }
        }
    }
    
    
    dp[len - 1] = 0;
//    if (str[len - 2] == str[len - 1]) {
//        dp[len - 2] = 0;
//    } else {
//        dp[len - 2] = 1;
//    }
    
    
    for (int i = len - 2; i >= 0; i--) {
        int min_cut = -1;
        if (palid_dp[i][len - 1]) {
            dp[i] = 0;
            continue;
        }
        
        for (int j = i; j < len - 1; j++) {
            if (palid_dp[i][j]) {
                int curr_cut = 1 + dp[j + 1];
                if (min_cut == -1) {
                    min_cut = curr_cut;
                } else {
                    min_cut = min(min_cut, curr_cut);
                }
            }
        } 
        dp[i] = min_cut;
    }
    
    return dp[0];
}



int main()
{
    string str = "";
    
    cin>>str;
    int res = get_min_cut(str);
    cout<<res;

    return 0;
 } 
