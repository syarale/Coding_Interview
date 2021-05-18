//CD25：最长递增子序列

#include <iostream>
#include <vector>
using namespace std;


int get_max_order(vector<int> arr, vector<int>& seq)
{
    int len = arr.size();
    vector<int> dp(len, 0);
    vector<vector<int> > dp_seq(len, vector<int> ());
    
    if (arr.empty()) {
        return 0;
    }
    
    dp[0] = 1;
    dp_seq[0].push_back(arr[0]);
    for (int i = 1; i < len; i++) {
        int max_num = -1;
        int ptr = -1;
        for (int j = 0; j < i; j++) {
            if (arr[j] < arr[i] && dp[j] >= max_num) {
                if (dp[j] > max_num) {
                    max_num = dp[j];
                    ptr = j;
                }
                
                if (arr[j] < dp_seq[ptr].back()) {
                    max_num = dp[j];
                    ptr = j;     
                }
            }
        }
        
        if (max_num == -1) {
            dp[i] = 1;
            dp_seq[i].push_back(arr[i]);
        } else {
            dp[i] = max_num + 1;
            vector<int> tmp(dp_seq[ptr].begin(), dp_seq[ptr].end());
            tmp.push_back(arr[i]);
            dp_seq[i] = tmp;
        }
    }
    
    int ret = -1;
    int ptr = -1;
    for (int i = 0; i < len; i++) {
        if (dp[i] > ret) {
            ptr = i;
            ret = dp[i];
        }
        
        if(dp[i] == ret) {
            if (dp_seq[i].back() < dp_seq[ptr].back()) {
                ptr = i;
                ret = dp[i]; 
            }
        }
    }
    
    seq.insert(seq.end(), dp_seq[ptr].begin(), dp_seq[ptr].end());
    return ret;
}


int main()
{
    int n;
    vector<int> arr;
    vector<int> seq;
    
    cin>>n;
    for (int i = 0; i < n; i++) {
        int tmp;
        cin>>tmp;
        arr.push_back(tmp);
    }
    
    int res = get_max_order(arr, seq);
    for (int i = 0; i < seq.size(); i++) {
        cout<<seq[i]<<" ";
    }
    
    return 0;
} 
