// CD128：公式字符串求值 

#include <iostream>
#include <string>
#include <vector>
#include <stack>
using namespace std;

bool isdigit(char ch) {
    if ('0' <= ch && ch <= '9') {
        return true;
    } else {
        return false;
    }
}

int caculate_sum(stack<int> number) {
    int sum = 0;
//    cout<<"caculate sum: ";
    while (!number.empty()) {
        sum += number.top();
//        cout<<number.top()<<" ";
        number.pop();
    }
//    cout<<endl<<"sum: "<<sum<<endl;
    return sum;
}

void clear(stack<int>& number, char sign, int num) {
    int tmp;
    switch(sign) {
        case '+' :
            number.push(num);
            break;
        case '-' :
            number.push(-1 * num);
            break;
        case '*' :
            tmp = number.top();
            number.pop();
            number.push(tmp * num);
            break;
        case '/' :
            tmp = number.top();
            number.pop();
            number.push(tmp / num);
            break;                    
    } 
    
//    cout<<"top: "<<number.top()<<endl;
    
    return;
}


// caculate str[begin, end]
int caculate(string str, int begin, int& next_loc) {
    //assert str is valid. and 0 <= begin <= end

    int len = str.size();
    stack<int> number;
    
    char sign = '+';
    int num = 0;
    int i = begin;
    while (i < len) {
//        cout<<"i: "<<i<<endl;
        char ch = str[i];
        if (isdigit(ch)) {
            num = num * 10 + (ch - '0');
            if (i == len - 1) {
                clear(number, sign, num);
            }
            i++;
        }
        
        if (ch == '(') {
            int j = 0;
            num = caculate(str, i + 1, j);
            i = j;
            if (i >= len) {
                clear(number, sign, num);
            }
        } 
        
        if (ch == ')') {
            next_loc = i + 1;
            clear(number, sign, num);
            int sum = caculate_sum(number);
            return sum;
        }
        
        if (ch == '+' || ch == '-' || ch == '*' || ch == '/'){
            clear(number, sign, num);
            i++;
            sign = ch;
            num = 0;
        }
    }
    
    int sum = caculate_sum(number);
    
//    cout<<"sum: "<<sum<<endl;
    return sum;
}


int main()
{
    string str;
    int loc = 0;
    cin>>str; 
    int res = caculate(str, 0, loc);
    cout<<res;
    
    return 0;
} 
