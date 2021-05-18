
// CD96：判断两个字符串是否互为旋转词 
#include <iostream>
#include <string>
#include <map>
using namespace std;

bool is_roll(string str1, string str2) {
    int len1 = str1.size();
    int len2 = str2.size();
    
    if (str1.empty() && str2.empty()) {
        return true;
    }
    
    if (len1 != len2) {
        return false;
    }
    
    string d_str2 = str2 + str2;
    if (d_str2.find(str1) == string::npos) {
        return false;
    } else {
        return true;
    }
}


int main()
{
    int n, m;
    string str1, str2;
    
    cin>>n>>m;
    cin>>str1>>str2;
    if (is_roll(str1, str2)) {
        cout<<"YES";
    } else {
        cout<<"NO";
    }
    return 0;
}
 
