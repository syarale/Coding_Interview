
// CD181：统计和生成不同的二叉树

#include <iostream>
#include <vector>
using namespace std;

int get_num(int n) {
    vector<int> num;
    
    if (n <= 1) {
        return 1;
    }
    
    if (n == 2) {
        return 2;
    } 
    
    num.push_back(1);   //num[0] = 1
    num.push_back(1);   //num[1] = 1
    num.push_back(2);   //num[2] = 2
    for (int i = 3; i <= n; i++) {
        int num_i = 2 * num[i - 1];
        for (int j = 2; j < i; j++) {
            num_i += ((num[j-1] * num[i - j]));
        }
        num.push_back(num_i);
    }
      
    return num[n];
}

int main()
{
    int n = 0;
    cin>>n;
    
    cout<<get_num(n);
    return 0;
} 
