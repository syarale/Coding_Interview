//CD98: ×Ö·û´®µÄÍ³¼Æ×Ö·û´®

#include <iostream>
#include <string>
using namespace std;

string transfer(string str) {
    int len = str.size();
    
    if (str.empty()) {
        return "";
    }
    
    int ptr = 0;
    string res = "";
    while (ptr < len) {
        int i = ptr;
        int num = 0;
        while (i < len && str[i] == str[ptr]) {
            num++;
            i++;
        }
        
        res = res + str[ptr] + "_" + to_string(num) + "_";
        ptr = i; 
    }
    
    res.erase(res.end()-1, res.end());
    return res;
}




int main()
{
    string str = "";
    cin>>str;
    
    string res = transfer(str);
    cout<<res;
    
    return 0;    
}  
