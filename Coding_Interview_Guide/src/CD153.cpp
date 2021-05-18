// CD153：需要排序的最短子数组长度

#include <iostream>
#include <vector>
using namespace std;

int get_min_sort(vector<int> arr) {
    int len = arr.size();
    int left = -1;
    int right = -1;
    
    if (arr.empty()) {
        return 0;
    }
    
    int min = arr[len - 1];
    for (int i = len - 2; i >= 0; i--) {
        if (arr[i] <= min) {
            min = arr[i];
        } else {
            left = i;
        }
    }
    
    if (left == -1) {
        return 0;
    }
    
    int max = arr[0];
    for (int i = 1; i < len; i++) {
        if (arr[i] >= max) {
            max = arr[i];
        } else {
            right = i;
        }
    }
    
    return right - left + 1;

}


int main() {
    int n = 0;
    vector<int> arr;
    
    cin>>n;
    for (int i = 0; i < n; i++) {
        int tmp = 0;
        cin>>tmp;
        arr.push_back(tmp);
    }
    
    int res = get_min_sort(arr);
    cout<<res;
    
    return 0;
} 
