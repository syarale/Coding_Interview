//CD97：将整数字符串转成整数值


#include <iostream>
#include <string>
using namespace std;

bool is_valid(string str) {
    int len = str.size();
    
    if (str.empty()) {
        return false;
    }
    
    if (str[0] != '-' && !('0' <= str[0] && str[0] <= '9')) {
        return false;
    }
    
    if (str[0] == '-' && len == 1) {
        return false;
    }
    
    if (str[0] == '0' && len > 1) {
        return false;
    }
    
    for (int i = 1; i < len; i++) {
        if (str[i] < '0' || str[i] > '9') {
            return false;
        }
    }
    
    return true;
}


int nega_transfer(string str, int begin, int end) {
    int res = 0;
    int len = str.size();
    if (str.empty() || end < begin) {
        return 0;
    }
    
    for (int i = begin; i <= end; i++) {
        int tmp = res * 10 - (str[i] - '0');
        if (tmp >= res) {
            // overflow
            return 0;
        }
        res = tmp;
    }
    
    return res;
}


int transfer(string str) {
    int posi = 1;
    int res = 0;
    
    if (!is_valid(str)) {
        return 0;
    }
    
    if (str[0] == '-') {
        posi = -1;
        res = nega_transfer(str, 1, str.size() - 1);
    } else {
        posi = 1;
        res = nega_transfer(str, 0, str.size() - 1);
//        if (res - 1 > 0) {
//            return 0;
//        }
        if (res == -2147483648) {
            return 0;
        }
    }
    
    res = -1 * posi * res;
    return res;
}




int main()
{
    string str = "";
    cin>>str;
    
    int res = transfer(str);
    cout<<res;
    
    return 0;    
} 
