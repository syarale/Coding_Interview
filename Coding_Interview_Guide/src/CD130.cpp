//CD130：拼接所有的字符串产生字典顺序最小的大写字符串

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std; 


bool compare(const string& str1, const string& str2) {
    if (str1 + str2 < str2 + str1) {
        return true;
    } else {
        return false;
    }
}


string get_minstr(vector<string> arr) {
    int len = arr.size();
    
    if (arr.empty()) {
        return "";
    }
    
    sort(arr.begin(), arr.end(), compare);
    string ret = "";
    for (int i = 0; i < len; i++) {
        ret += arr[i];
    }
    
    return ret;
}


int main()
{
    int n;
    
    cin>>n;
    vector<string> arr;
    for (int i = 0; i < n; i++) {
        string tmp = "";
        cin>>tmp;
        arr.push_back(tmp);
    }
    
    string res = get_minstr(arr);
    cout<<res;
    
    return 0;
 } 
