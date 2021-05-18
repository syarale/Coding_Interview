/* CD13：用一个栈实现另一个栈的排序 */

#include <iostream>
#include <stack>
using namespace std;

int sort_stack(stack<int> in, stack<int>& out) {
	
	while (!in.empty()) {
		int num = 0;
		int in_top = in.top();
		in.pop();
	
		while (!out.empty() && in_top < out.top()) {
			int out_top = out.top();
			out.pop();
			in.push(out_top);
			num ++;
		}
		
		out.push(in_top);	
		for (int i = 0; i < num; i++) {
			int tmp = in.top();
			in.pop();
			out.push(tmp);
		}
		
	}
	
	return 0;
}


int main()
{
	int N = 0;
	int number= 0;
	stack<int> in;
	stack<int> out;
	
	cin>>N;
	for (int i = 0; i < N; i++) {
		cin>>number;
		out.push(number);
	}
	
	while (!out.empty()) {
		int top = out.top();
		out.pop();
		in.push(top);
	}
	
	sort_stack(in, out);
	
	while (!out.empty()) {
		cout<<out.top()<<" ";
		out.pop();
	}		
	return 0;
 } 
