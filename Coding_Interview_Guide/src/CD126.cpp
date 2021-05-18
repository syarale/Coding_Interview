//CD126：括号字符串的有效性 

#include <iostream>
#include <string>
using namespace std;


bool check(string str) {
    int len = str.size();
    
    if (str.empty() || len == 1) {
        return false;
    }
      
    int left = 0;
    int right = 0;
    for (int i = 0; i < len; i++) {
        if (str[i] != '(' && str[i] != ')') {
            return false;
        }
        
        if (str[i] == '(') {
            left++;
        } else {
            right++;
        }
        
        if (left < right) {
            return false;
        }
    }
    
    if (left == right) {
        return true;
    } else {
        return false;
    }
    
}


int main() {
    string str;
    cin>>str;
    
    if (check(str)) {
        cout<<"YES";
    } else {
        cout<<"NO";
    }
    
    return 0;
}
