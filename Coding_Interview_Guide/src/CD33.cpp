//CD33：最长公共子串问题


#include <iostream>
#include <string>
using namespace std;


string get_substr(string str1, string str2) {
    int len1 = str1.size();
    int len2 = str2.size();
    
    if (str1.empty() || str2.empty()) {
        return "";
    }
    
    int max_val = 0;
    int loc_i = 0;
    int row = 0;
    int col = len2 - 1;
    while (row < len1) {
        int i = row;
        int j = col;
        int curr = 0;
        
        while (i < len1 && j < len2) {
            if (str1[i] != str2[j]) {
                curr = 0;
            } else {
                curr++;
            }
            
            if (curr > max_val) {
                max_val = curr;
                loc_i = i;
            }
            i++;
            j++;
        }
        
        if (col > 0) {
            col--;
        } else {
            row++;
        }
    } 
    
    string ret = "";
    if (max_val != 0) {
        ret = str1.substr(loc_i - max_val + 1, max_val);
    }
    
    return ret;
}


int main()
{
    string str1, str2;
    string ret = "";
    
    cin>>str1>>str2;
    ret = get_substr(str1, str2);
    cout<<ret;
    
    return 0;
} 
