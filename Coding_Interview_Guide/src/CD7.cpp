/* CD7: 用递归函数和栈操作逆序一个栈 */

#include <iostream>
#include <stack>
using namespace std;

/* Get and remove the last element of input. 
 * Return the value of last element. 
 */ 
int get_remove_last(stack<int>& input)
{
	int ret = 0;
	int temp = input.top();
	
	input.pop();
	if (input.empty())
		return temp;
	else {
		ret = get_remove_last(input);    /* input cann't be null */
	}
	
	input.push(temp);
	
	return ret;
}



/* Reverse stack input.
 * Return 0 when successed, and return -1 when failed(cann't happen).
 */ 
int reverse (stack<int>& input)
{
	int last = 0;
	
	if (input.empty())
		return 0;
	
	last = get_remove_last(input);   /* input cann't be null */
	reverse(input);
	input.push(last);
	
	return 0;	
}



int main()
{
	int N = 0;
	stack<int> input;
	
	
	cin>>N;
	for (int i = 0; i < N; i++) {
		int temp = 0;
		
		cin>>temp;
		input.push(temp);
	}
	
	(void)reverse(input);
	(void)reverse(input);
	
	for (int i = 0; i < N; i++) {
		int out = input.top();
		
		input.pop();
		if (i == N - 1)
			cout<<out;
		else
			cout<<out<<" ";
	}
	
	return 0;
}


 
