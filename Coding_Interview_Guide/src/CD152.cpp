//CD152：找到无序数组中最小的 K个数 

#include <iostream>
#include <queue>
using namespace std;


void print_min_k(vector<int> arr, int k) {
    int len = arr.size();
    priority_queue<int, vector<int> > heap;
    
    for (int i = 0; i < k && i < len; i++) {
        heap.push(arr[i]);
    }
    
    for (int i = k; i < len; i++) {
        if (arr[i] < heap.top()) {
            heap.pop();
            heap.push(arr[i]);
        }
    }
    
    while (!heap.empty()) {
        cout<<heap.top()<<" ";
        heap.pop();
    }
    
    return;
}


int main() {
    int n = 0;
    int k = 0;
    vector<int> arr;
    
    cin>>n>>k;
    for (int i = 0; i < n; i++) {
        int tmp = 0;
        cin>>tmp;
        arr.push_back(tmp);
    }
    
    print_min_k(arr, k);
    
    return 0;
} 
