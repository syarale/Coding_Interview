//CD99：在有序但含有空的数组中查找字符串

#include <iostream>
#include <vector>
#include <string>

using namespace std;


// [begin, end]
int binary_search(vector<string> arr, int begin, int end, string str) {
   //assert(!arr.empty() && begin >= 0); 
   int len = arr.size();  // assert(end < len);
   int mid = (begin + end) / 2;
   
   if (end < begin) {
       return -1;
   }
   
   if (arr[mid] == str) {
       int tmp = binary_search(arr, begin, mid - 1, str);
       if (tmp != -1 && tmp < mid) {
           return tmp;
       }
       return mid;
   } 
   
   // assert(arr[mid] != str);
   if (arr[mid] != "") {
       if (arr[mid] < str) {
           return binary_search(arr, mid + 1, end, str);
       } else {
           return binary_search(arr, begin, mid - 1, str);
       }
   }
   
   // assert(arr[mid] == "");
   int i = 0;
   for (i = mid - 1; i >= begin; i--) {
       if (arr[i] != "") {
           break;
       }
   }
   
   if (i < begin) {
       return binary_search(arr, mid + 1, end, str);
   } else {
       if (arr[i] == str) {
           int tmp = binary_search(arr, begin, i - 1, str);
           if (tmp != -1 && tmp < i) {
               return tmp;
           }
           return i;
       } 
       
       if (arr[i] < str) {
           return binary_search(arr, mid + 1, end, str);
       } else {
           return binary_search(arr, begin, i - 1, str);
       }
   }
}


int get_index(vector<string> arr, string str) {
    int len = arr.size();
    
    if (arr.empty()) {
        return -1;
    }
    
    int ret = binary_search(arr, 0, len - 1, str);
    return ret;
}


int main() {
    int n;
    vector<string> arr;
    string str = "";
    
    cin>>n;
    cin>>str;
    for (int i = 0; i < n; i++) {
        string tmp;
        cin>>tmp;
        if (tmp == "0") {
            tmp = "";
        }
        arr.push_back(tmp);
    }
    
    int res = get_index(arr, str);
    cout<<res;
    
    return 0;
} 
 
