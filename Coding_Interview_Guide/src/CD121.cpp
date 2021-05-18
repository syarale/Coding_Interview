//CD121：删除多余字符得到字典序最小的字符串

#include <iostream>
#include <string>
#include <stack>
#include <map>
using namespace std;


string erase_str(string str) {
    stack<char> dic;
    bool exist[26];
    map<char, int> num;
    int len = str.size();
    
    if (str.empty()) {
        return "";
    }
    
    for (int i = 0; i < len; i++) {
        if (num.find(str[i]) == num.end()) {
            num[str[i]] = 1;
        } else {
            num[str[i]] ++;
        }
        exist[str[i] - 'a'] = false;
    }
    
    for (int i = 0; i < len; i++) {
        if (exist[str[i] - 'a']) {
            continue;
        }
        
        while ((!dic.empty()) && dic.top() > str[i] && num[dic.top()] > 0) {
            exist[dic.top() - 'a'] = false;
            dic.pop();
        }
        dic.push(str[i]);
        num[str[i]] --;
        exist[str[i] - 'a'] = true;
    }
    
    string ret = "";
    while (!dic.empty()) {
        ret = dic.top() + ret;
        dic.pop();
    }
    
    return ret;
}




int main()
{
    string str;
    
    cin>>str;
    cout<<erase_str(str);
    
    return 0;
 } 
