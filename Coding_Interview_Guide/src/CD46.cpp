
//CD46：数字字符串转换为字母组合的种数

#include <iostream>
#include <string>
#include <vector>
using namespace std;

const int MOD = 1e9 + 7;

bool one_to_nine(char i) {
    if ('1' <= i && i <= '9') {
        return true;
    } else {
        return false;
    }
}

bool A_to_Z(char i, char j) {
    int tens = i - '0';
    int units = j - '0';
    int sum = tens * 10 + units;
    
    if (tens == 0) {
        return false;
    }
    
    if (1 <= sum && sum <= 26) {
        return true;
    } else {
        return false;
    }
}


int get_num(const string& str)
{
    int len = str.size();
    vector<int> dp(len, 0);
    
    if (str.empty()) {
        return 0;
    }
    
    if (one_to_nine(str[0])) {
       dp[0] = 1;
    } else {
       dp[0] = 0;   
    }
    
    if (len == 1) {
        return dp[0];
    }
    
    
    int num = 0;
    if (one_to_nine(str[0]) && one_to_nine(str[1])) {
       num++;
    } 
        
    if (A_to_Z(str[0], str[1])) {
       num++;
    }
    dp[1] = num;
    
    if (len == 2) {
        return dp[1];
    }
    
    for (int i = 2; i < len; i++) {
        dp[i] = 0;
        if (one_to_nine(str[i])) {
            dp[i] = (dp[i] + dp[i-1]) % MOD;
        } 
        
        if (A_to_Z(str[i-1], str[i])) {
            dp[i] = (dp[i] + dp[i-2]) % MOD;
        }
    }
    
    return dp[len - 1];
}


int main()
{
    string str = "";
    cin>>str;
    
    int ret = get_num(str);
    cout<<ret;   

    return 0;    
} 
