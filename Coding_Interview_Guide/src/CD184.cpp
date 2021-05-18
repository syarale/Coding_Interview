//CD184：CD183：斐波那契数列的递归和动态规划2


#include <iostream>
#include <vector>
using namespace std; 


int get_num(int n) {
    if (n == 1) {
        return 1;
    }
    
    if (n == 2) {
        return 2;
    }
    
    vector<int> num(n + 1, 0);
    num[1] = 1;
    num[2] = 2;
    
    for (int i = 3; i <= n; i++) {
        num[i] = num[i - 1] + num[i - 2];
    }
    
    return num[n];  
}


int main()
{
    int n = 0;
    cin>>n;
    
    int ret = get_num(n);
    cout<<ret;
    
    return 0;    
} 
