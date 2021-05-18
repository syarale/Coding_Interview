//CD2����Ŀ�����������ĳ���
// ���г�ʱ 


#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;


int get_max_length(vector<int> arr) {
    int len = arr.size();
    cout<<"len: "<<len<<endl;
    if (arr.empty()) {
        return 0;
    }
    
    int max_len = 0;
    for (int i = 0; i < len; i++) {
        int max_v = -1;
        int min_v = -1;
        int curr_max = 0;
        set<int> number;
        
        for (int j = i; j < len; j++) {
            if (number.find(arr[j]) == number.end()) {   // O(logN) �� O(1), Ӧʹ�ò����ٶ�ΪO(1)��set���� 
                number.insert(arr[j]);
                if (min_v == -1) {
                    min_v = arr[j];
                    max_v = arr[j];
                    max_len = max(max_len, 1);
                } else {
                    max_v = max(arr[j], max_v);
                    min_v = min(arr[j], min_v);
                    if (max_v - min_v + 1 == j - i + 1) {
                        max_len = max(max_len, j - i + 1);
                    }
                }
            } else {
                break;
            }
        }
    }
    
    return max_len;
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
    
    int res = get_max_length(arr);
    cout<<res;
    
    return 0;
} 
