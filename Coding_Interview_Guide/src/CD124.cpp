//CD124：添加最少字符使字符串整体都是回文字符串

#include <iostream>
#include <string>
#include <vector>
using namespace std;



string get_palindrome(string str) {
    int len = str.size();
    
    if (str.empty() || len == 1) {
        return str;
    }
    
    vector<vector<int> > dp(len, vector<int> (len, 0));
    for (int i = 0; i < len - 1; i++) {
        if (str[i] == str[i+1]) {
            dp[i][i+1] = 0;
        } else {
            dp[i][i+1] = 1;
        }
    }
    
    for (int i = len - 3; i >= 0; i--) {
        for (int j = i + 2; j < len; j++) {
            if (str[i] == str[j]) {
                dp[i][j] = dp[i+1][j-1];
            } else {
                dp[i][j] = min(dp[i+1][j], dp[i][j-1]) + 1;
            }
        }
    }
    
    string res(len + dp[0][len-1], ' ');
    int lptr = 0;
    int rptr = res.size() - 1;
    int i = 0;
    int j = len - 1;
    while (i <= j) {
        if (str[i] == str[j]) {
            res[lptr++] = str[i];
            res[rptr--] = str[i];
            i++;
            j--;
        } else if (dp[i+1][j] < dp[i][j-1]) {
            res[lptr++] = str[i];
            res[rptr--] = str[i];
            i++;
        } else {
            res[lptr++] = str[j];
            res[rptr--] = str[j];
            j--;
        }
    }
    
    return res;
}


int main()
{
    string str;
    cin>>str;
    string res = get_palindrome(str);
    cout<<res;
    
    return 0;
 } 
