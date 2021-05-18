
// CD95：判断两个字符串是否互为变形词
#include <iostream>
#include <string>
#include <map>
using namespace std;

bool is_deformation(string str1, string str2) {
    int len1 = str1.size();
    int len2 = str2.size();
    map<char, int> map1;
    map<char, int> map2;
    
    if (str1.empty() && str2.empty()) {
        return true;
    }
    
    if (len1 != len2) {
        return false;
    }
    
    for (int i = 0; i < len1; i++) {
        if (map1.find(str1[i]) == map1.end()) {
            map1[str1[i]] = 1;
        } else {
            map1[str1[i]]++;
        }
        
        if (map2.find(str2[i]) == map2.end()) {
            map2[str2[i]] = 1;
        } else {
            map2[str2[i]]++;
        }
    }
    
    int map1_len = map1.size();
    int map2_len = map2.size();
    if (map1_len != map2_len) {
        return false;
    }
    
    map<char, int>::iterator it = map1.begin();
    for (; it != map1.end(); it++) {
        if (map2.find(it->first) == map2.end() ||  it->second != map2[it->first]) {
            return false;
        }
    }
    
    return true;
}


int main()
{
    int n, m;
    string str1, str2;
    
    cin>>n>>m;
    cin>>str1>>str2;
    if (is_deformation(str1, str2)) {
        cout<<"true";
    } else {
        cout<<"false";
    }
    return 0;
}
 
