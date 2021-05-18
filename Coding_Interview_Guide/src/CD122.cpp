// CD122：数组中两个字符串的最小距离

#include <iostream>
#include <string>
#include <vector>
using namespace std;


int get_min_distance(vector<string> arr, string str1, string str2) {
    int last1 = -1;
    int last2 = -1;
    int len = arr.size();
    
    if (str1.empty() || str2.empty() || arr.empty()) {
        return -1;
    }
    
    
    int min_distance = len + 1;
    for (int i = 0; i < len; i++) {
        if (arr[i] == str1) {
            last1 = i;
            if (last2 != -1) {
                min_distance = min(min_distance, last1 - last2);
            }
        }
        
        if (arr[i] == str2) {
            last2 = i;
            if (last1 != -1) {
                min_distance = min(min_distance, last2 - last1);
            }
        }
        
    }
    
    if (min_distance == len + 1) {
        return -1;
    } else {
        return min_distance;   
    }
}



int main()
{
    string str1, str2;
    int n;
    
    cin>>n;
    cin>>str1>>str2;
    
    vector<string> arr(n, "");
    for (int i = 0; i < n; i++) {
        string tmp;
        cin>>tmp; 
        arr[i] = tmp;
    } 
    
    int res = get_min_distance(arr, str1, str2);
    cout<<res;
    
    return 0;
}
