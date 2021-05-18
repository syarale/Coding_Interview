//CD47：表达式得到期望结果的组成种数

// 取模的地方可能有问题，有部分用例过不了 


#include <iostream>
#include <string>
#include <vector>
using namespace std;

const int MOD = 1e9 + 7;

bool is_valid(string exp) {
    int len = exp.size();
    
    if (len % 2 == 0) {
        return false;
    } 
    
    for (int i = 0; i < len; i++) {
//        cout<<222222222222<<endl;
        if (i % 2 == 0 && (exp[i] == '0' || exp[i] == '1')) {
            continue;
        }
        
        if (i % 2 != 0 && (exp[i] == '&' || exp[i] == '|' || exp[i] == '^')) {
            continue;
        }
        
        return false;
    }
    
    return true;
}

int get_num(string exp, bool desired) {
    int len = exp.size();
    
    if (!is_valid(exp)) {
        return 0;
    }
    
    vector<vector<int> > tdp(len, vector<int> (len, -1));
    vector<vector<int> > fdp(len, vector<int> (len, -1));
    
    for (int i = 0; i < len; i += 2) {
        if (exp[i] == '1') {
            tdp[i][i] = 1;
            fdp[i][i] = 0;
        } else {
            tdp[i][i] = 0;
            fdp[i][i] = 1;
        }
    }
    
    for (int i = len - 3; i >= 0; i -= 2) {
        for (int j = i + 2; j < len; j += 2) {
            tdp[i][j] = 0;
            fdp[i][j] = 0;

            for (int k = i + 1; k < j; k += 2) {
                if (exp[k] == '^') {
                    tdp[i][j] = (tdp[i][j] + (((tdp[i][k-1] * fdp[k+1][j]) % MOD + (fdp[i][k-1] * tdp[k+1][j]) % MOD) % MOD)) % MOD;
                    fdp[i][j] = (fdp[i][j] + (((tdp[i][k-1] * tdp[k+1][j]) % MOD + (fdp[i][k-1] * fdp[k+1][j]) % MOD) % MOD)) % MOD;
                }
                
                if (exp[k] == '&') {
                    tdp[i][j] = (tdp[i][j] + ((tdp[i][k-1] * tdp[k+1][j]) % MOD)) % MOD;
                    fdp[i][j] = (fdp[i][j] + (((tdp[i][k-1] * fdp[k+1][j]) % MOD + (fdp[i][k-1] * tdp[k+1][j]) % MOD 
                                  + (fdp[i][k-1] * fdp[k+1][j] % MOD)) % MOD)) % MOD;
                }
                
                if (exp[k] == '|') {
                    tdp[i][j] = (tdp[i][j] + (((tdp[i][k-1] * fdp[k+1][j]) % MOD + (fdp[i][k-1] * tdp[k+1][j]) % MOD
                                  + (tdp[i][k-1] * tdp[k+1][j]) % MOD) % MOD)) % MOD;
                    fdp[i][j] = (fdp[i][j] + ((fdp[i][k-1] * fdp[k+1][j]) % MOD)) % MOD;
                }
            }

//            for (int k = i + 1; k < j; k += 2) {
//                if (exp[k] == '^') {
//                    tdp[i][j] = (tdp[i][j] + (tdp[i][k-1] * fdp[k+1][j] + fdp[i][k-1] * tdp[k+1][j]) % MOD) % MOD;
//                    fdp[i][j] = (fdp[i][j] + (tdp[i][k-1] * tdp[k+1][j] + fdp[i][k-1] * fdp[k+1][j]) % MOD) % MOD;
//                }
//                
//                if (exp[k] == '&') {
//                    tdp[i][j] = (tdp[i][j] + (tdp[i][k-1] * tdp[k+1][j] % MOD)) % MOD;
//                    fdp[i][j] = (fdp[i][j] + (tdp[i][k-1] * fdp[k+1][j] + fdp[i][k-1] * tdp[k+1][j]+fdp[i][k-1]*fdp[k+1][j]) % MOD) % MOD;
//                }
//                
//                if (exp[k] == '|') {
//                    tdp[i][j] = (tdp[i][j] + (tdp[i][k-1] * fdp[k+1][j] + fdp[i][k-1] * tdp[k+1][j]+tdp[i][k-1] * tdp[k+1][j]) % MOD)% MOD;
//                    fdp[i][j] = (fdp[i][j] + (fdp[i][k-1] * fdp[k+1][j]) % MOD) % MOD;
//                }
//            }
        }
    }
    
    if (desired) {
        return tdp[0][len - 1];
    } else {
        return fdp[0][len - 1];
    }
}



int main()
{
    string express = "";
    string desired = "";
    bool aim = true;
    
    cin>>express;
    cin>>desired;
    
    if (desired == "true") {
        aim = true;
//        cout<<"yes"<<endl;;
    } else {
        aim = false;
//        cout<<"no"<<endl;
    }
    
//    cout<<aim;
    
//    cout<<is_valid(express);
    
    int res = get_num(express, aim);
    cout<<res;


    
    return 0;
} 



//
//            for (int k = i + 1; k < len; k += 2) {
//                if (exp[k] == '^') {
//                    tdp[i][j] = (tdp[i][j] + (((tdp[i][k-1] * fdp[k+1][j]) % MOD + (fdp[i][k-1] * tdp[k+1][j]) % MOD) % MOD)) % MOD;
//                    fdp[i][j] = (fdp[i][j] + (((tdp[i][k-1] * tdp[k+1][j]) % MOD + (fdp[i][k-1] * fdp[k+1][j]) % MOD) % MOD)) % MOD;
//                }
//                
//                if (exp[k] == '&') {
//                    tdp[i][j] = (tdp[i][j] + ((tdp[i][k-1] * tdp[k+1][j]) % MOD)) % MOD;
//                    fdp[i][j] = (fdp[i][j] + (((tdp[i][k-1] * fdp[k+1][j]) % MOD + (fdp[i][k-1] * tdp[k+1][j]) % MOD 
//                                  + (fdp[i][k-1] * fdp[k+1][j] % MOD)) % MOD)) % MOD;
//                }
//                
//                if (exp[k] == '|') {
//                    tdp[i][j] = (tdp[i][j] + (((tdp[i][k-1] * fdp[k+1][j]) % MOD + (fdp[i][k-1] * tdp[k+1][j]) % MOD
//                                  + (tdp[i][k-1] * tdp[k+1][j]) % MOD) % MOD)) % MOD;
//                    fdp[i][j] = (fdp[i][j] + ((fdp[i][k-1] * fdp[k+1][j]) % MOD)) % MOD;
//                }
//            }



//            for (int k = i + 1; k < j; k += 2) {
//                if (exp[k] == '^') {
//                    tdp[i][j] = (tdp[i][j] + (tdp[i][k-1] * fdp[k+1][j] + fdp[i][k-1] * tdp[k+1][j]) % MOD) % MOD;
//                    fdp[i][j] = (fdp[i][j] + (tdp[i][k-1] * tdp[k+1][j] + fdp[i][k-1] * fdp[k+1][j]) % MOD) % MOD;
//                }
//                
//                if (exp[k] == '&') {
//                    tdp[i][j] = (tdp[i][j] + (tdp[i][k-1] * tdp[k+1][j] % MOD)) % MOD;
//                    fdp[i][j] = (fdp[i][j] + (tdp[i][k-1] * fdp[k+1][j] + fdp[i][k-1] * tdp[k+1][j]+fdp[i][k-1]*fdp[k+1][j]) % MOD) % MOD;
//                }
//                
//                if (exp[k] == '|') {
//                    tdp[i][j] = (tdp[i][j] + (tdp[i][k-1] * fdp[k+1][j] + fdp[i][k-1] * tdp[k+1][j]+tdp[i][k-1] * tdp[k+1][j]) % MOD)% MOD;
//                    fdp[i][j] = (fdp[i][j] + (fdp[i][k-1] * fdp[k+1][j]) % MOD) % MOD;
//                }
//            }
 
