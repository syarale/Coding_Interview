//CD116£º·­×ª×Ö·û´®1

#include <iostream>
#include <string>
using namespace std;

void reverse(string& chas, int begin, int end) {
    int i = begin;
    int j = end;
//    cout<<"revese: "<<chas<<endl;
    
    if (chas.empty() || end >= chas.size()) {
        return;
    }
    
    while (i < j) {
        char tmp = chas[i];
        chas[i] = chas[j];
        chas[j] = tmp;
        i++;
        j--;
    }
    
//    cout<<"leave reverse: "<<chas<<endl;
    return;
}


void reverse_chas(string& chas) {
    int len = chas.size();
    string ret = "";
    
    if (chas.empty()) {
        return;
    }
    
//    reverse(chas, 0, len - 1);
//    cout<<chas<<endl;
    for (int i = 0; i < len; i++) {
        if (chas[i] == ' ') {
            continue;
        }
        
        int begin = i;
        int ptr = i;
        while (ptr != len && chas[ptr] != ' ') {
            ptr++;
        }
        int end = ptr - 1;
        
        reverse(chas, begin, end);
        i = end + 1;
    }
    
    return;
}



int main()
{
    string chas;
    
    getline(cin, chas);
    reverse_chas(chas);
    cout<<chas;
    
    return 0;
 } 
