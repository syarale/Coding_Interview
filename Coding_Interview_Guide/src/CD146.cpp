
// CD146：在其他数都出现偶数次的数组中找到出现奇数次的数 

#include <iostream>
#include <vector> 
using namespace std;

int find_x(vector<int> arr) {
    int ret = 0;
    int len = arr.size();
    
    // assert(!arr.empty());
    for (int i = 0; i < len; i++) {
        ret = ret ^ arr[i];
    }
    
    return ret;
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
    
    int res = find_x(arr);
    cout<<res;
    
    return 0;
}
