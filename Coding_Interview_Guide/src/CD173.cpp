
// CD173: 根据后序数组重建二叉树 
#include <iostream>
#include <vector>
using namespace std;

// [begin, end)
bool is_postorder(const vector<int>& arr, int begin, int end){
     //assert(end - begin > 0);
     int pivot = 0;
     int ptr = 0;
     bool is_post = false;
     int len = end - begin;
     
     if (len <= 2) {
         return true;
     }
     
     pivot = arr[end - 1];
     ptr = begin;
     while (ptr < end - 1 && arr[ptr] < pivot) {
         ptr++;
     }
     
     if (ptr == end - 1) {
         is_post = is_postorder(arr, begin, end - 1);
         return is_post;
     }
     
     
     for (int i = ptr; i < end; i++) {
         if (arr[i] < pivot) {
            return false;
         }
     }
     
     is_post = is_postorder(arr, begin, ptr) && is_postorder(arr, ptr, end - 1);
     
     return is_post;
}



int main()
{
    
    int n;
    vector<int> arr;
    cin>>n;
    
    for (int i = 0; i < n; i++) {
        int tmp;
        cin>>tmp;
        arr.push_back(tmp);
    }
    
    if (is_postorder(arr, 0, n)) {
        cout<<"true";
    } else {
        cout<<"false";
    }

    return 0;
} 
