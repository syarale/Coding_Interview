// CD132：找到指定的新类型字符

 
#include <iostream>
#include <string>
#include <map>
using namespace std;


bool is_capital(char ch) {
    if ('A' <= ch && ch <= 'Z') {
        return true;
    } else {
        return false;
    }
}



string get_char(string str, int k) {
    // assert str is valid. 
    string ret = "";
    int len = str.size();
    
    if (str.empty() || k >= len || k < 0) {
        return "";
    }
    
    int i = 0;
    while (i < len) {
        int left, right;
        if (is_capital(str[i])) {
            left = i;
            right = i + 1;
            i = i + 2;
        } else {
            left = i;
            right = i;
            i = i + 1;
        }
        
        if (left <= k && k <= right) {
            ret = str.substr(left, right - left + 1);
            break;
        }
    }
    
    return ret;
    
}


int main()
{
    int n, k;
    string str;
    
    cin>>n>>k;
    cin>>str;
    
    string res = get_char(str, k);
    cout<<res;
    
    return 0;
 } 
