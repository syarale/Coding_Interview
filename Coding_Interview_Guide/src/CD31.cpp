//CD31：最长公共子序列问题

#include <iostream>
#include <string>
#include <vector>
using namespace std;


string get_max_seq(string str1, string str2)
{
    int len1 = str1.size();
    int len2 = str2.size();
    
    if (str1.empty() || str2.empty()) {
        return "";
    }
    
    vector<vector<int> > dp(len1, vector<int> (len2, 0)); 
//    for (int i = 0; i < len1; i++) {
//        if (str1[i] == str2[0]) {
//            for (int k = i; k < len1; k++) {
//                dp[k][0] = 1;
//            }
//            break;
//        }
//    }
//    
//    for (int i = 0; i < len2; i++) {
//        if (str2[i] == str1[0]) {
//            for (int k = i; k < len2; k++) {
//                dp[0][k] = 1;
//            }
//            break;
//        }
//    }
    
    for (int i = 1; i < len1; i++) {
        for (int j = 1; j < len2; j++) {
            int max_val = max(dp[i-1][j], dp[i][j-1]);
            if (str1[i] == str2[j]) {
                max_val = max(max_val, dp[i-1][j-1] + 1);
            }
            dp[i][j] = max_val;
        }
    }
    
//    for (int i = 0; i < len1; i++) {
//        for (int j = 0; j <len2; j++) {
//            cout<<dp[i][j]<<" ";
//        }
//        cout<<"        i = "<<i;
//        cout<<endl;
//    }
//    cout<<endl;
    
    
    int max_num = dp[len1-1][len2-1];
    if (max_num == 0) {
        return "";
    }
//    cout<<"max_num: "<<max_num<<endl;

    
    string seq = "";
    int loc_i = len1 - 1;
    int loc_j = len2 - 1;
     
    int index = max_num - 1;
    while (index >= 0) {
        if (loc_j > 0 && dp[loc_i][loc_j] == dp[loc_i][loc_j-1]) {
            loc_j--;
        } else if (loc_i > 0 && dp[loc_i][loc_j] == dp[loc_i-1][loc_j]) {
            loc_i--;
        } else {
            seq = str1[loc_i] + seq;
            index--;
            loc_i--;
            loc_j--;
        }
    }
    
//    while (loc_i > 0 && loc_j > 0) {
////        cout<<222223<<endl;
//        if (dp[loc_i][loc_j] == dp[loc_i-1][loc_j-1] + 1) {
//            if (str1[loc_i] == str2[loc_j]) {
//                index++;
////                cout<<"index: "<<index<<endl;
////                cout<<str1[loc_i]<<endl;
//                seq = str1[loc_i] + seq;
//                loc_i--;
//                loc_j--;
//                continue;               
//            }
//        }
//        
//        if (dp[loc_i][loc_j] == dp[loc_i-1][loc_j]) {
//            loc_i--;
//            continue;
//        }
//        
//        if (dp[loc_i][loc_j] == dp[loc_i][loc_j-1]) {
//            loc_j--;
//            continue;
//        }
//    }
//    
//    if (index < max_num) {
//        if (loc_i == 0) {
//            seq = str1[loc_i] + seq;
//        }else {
//            seq = str2[loc_j] + seq;
//        }
//    }
    
    
//    cout<<seq.size()<<endl;
//    cout<<111111111<<endl;
//    cout<<seq<<endl;
    return seq;
}


int main()
{
    string str1, str2;
    cin>>str1>>str2;
    
    string ret = get_max_seq(str1, str2);
    cout<<ret;
    
    return 0;
 } 
