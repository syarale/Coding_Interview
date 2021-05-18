//CD44：字符串的交错组成

#include <iostream>
#include <string>
#include <vector>
using namespace std;

bool is_cross(string str1, string str2, string aim)
{
    int len1 = str1.size();
    int len2 = str2.size();
    int aim_len = aim.size();
    
    if (len1 + len2 != aim_len) {
        return false;
    }
    
    vector<vector<int> > dp(len1 + 1, vector<int> (len2 + 1, 0));
    dp[0][0] = 1;
    for (int i = 1; i <= len1; i++) {
        if(str1[i-1] == aim[i-1]) {
            dp[i][0] = 1;
        } else {
            dp[i][0] = 0;
            break;
        }
    }
    
    for (int i = 1; i <= len2; i++) {
        if (str2[i-1] == aim[i-1]) {
            dp[0][i] = 1;
        } else {
            dp[0][i] = 0;
            break;
        }
    }
    
    for (int i = 1; i <= len1; i++) {
        for (int j = 1; j <= len2; j++){
            if (dp[i-1][j] == 1 && str1[i-1] == aim[i+j-1]) {
                dp[i][j] = 1;
            } else if (dp[i][j-1] == 1 && str2[j-1] == aim[i+j-1]) {
                dp[i][j] = 1;
            } else {
                dp[i][j] = 0;
            }
        }
    }
    
    if (dp[len1][len2] == 1) {
        return true;
    } else {
        return false;
    }
}


int main()
{
    string str1, str2, aim;
    cin>>str1>>str2>>aim;
    
    bool res = is_cross(str1, str2, aim);
    if (res) {
        cout<<"YES";
    } else {
        cout<<"NO";
    }
    
    return 0;
 } 
