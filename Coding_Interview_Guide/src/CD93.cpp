//CD93：数组中的最长连续序列

#include <iostream>
#include <vector>
#include <set>
using namespace std;


int get_max_len(vector<int> arr) {
    int len = arr.size();
    set<int> num_set;
    
    if (arr.empty()) {
        return 0;
    }
    
    for (int i = 0; i < len; i++) {
        num_set.insert(arr[i]);
    }
    
    
    int max_len = 0;
    set<int>::iterator it = num_set.begin();
    for (; it != num_set.end(); it++) {
        if (num_set.find(*it - 1) == num_set.end()) {
            int curr_len = 0;
            int curr_val = *it;
            while (num_set.find(curr_val) != num_set.end()) {
                curr_len++;
                curr_val++;
            }
            max_len = max(curr_len, max_len);
        }
    }
    
    return max_len;
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
    
    int res = get_max_len(arr);
    cout<<res;
    
    
    return 0;
}
 
