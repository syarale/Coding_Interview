// CD145：整数的二进制数表达中有多少个1 

#include <iostream>
using namespace std;


int count_one(int n) {
    int num = 0;
    while (n != 0) {
        num++;
        n = n & (n-1);
    }
    
    return num;
}


int main() {
    int n;
    cin>>n;
    
    int res = count_one(n);
    cout<<res;
    
    return 0;
} 
