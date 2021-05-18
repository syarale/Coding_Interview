//CD131：找到字符串的最长无重复字符字串
// OJ 上的输入为数组，并非字符串 

#include <iostream>
#include <string>
#include <map>
using namespace std;


int get_substr(string str) {
    int len = str.size();
    int left = 0;
    int right = 1;
    int max_len = 0;
    map<char, int> ch_map;
    
    
    if (str.empty() || len == 1) {
        return len;
    }
    
    ch_map[str[left]] = 0;
    while (right < len) {
        if (ch_map.find(str[right]) == ch_map.end()) {
            int curr_len = right - left + 1;
            max_len = max(max_len, curr_len);
            ch_map[str[right]] = right;
            right++;
        } else {
            left = ch_map[str[right]] + 1;
            ch_map[str[right]] = right;
            
            int curr_len = right - left + 1;
            max_len = max(max_len, curr_len);
            right++;
        } 
    }
    
    
    return max_len;
}



int main()
{
    int n;
    cin>>n;
    string str = "";
    
    for (int i = 0; i < n; i++) {
        char ch;
        cin>>ch;
        str += ch;
    }
    
    int res = get_substr(str);
    cout<<res;
    
    
    return 0;
 } 
 
