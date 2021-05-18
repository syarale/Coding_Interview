/* CD5: 设计一个有getMin功能的栈 */ 

#include <iostream>
#include <stack>
#include <string>
using namespace std;

class minStack{
	private:
		stack<int> data;
		stack<int> min;
	
	public:
		int push (int x);
		int pop();
		int getMin();
		minStack();
		
		/* other function */ 
};

minStack::minStack(){
	stack<int> data;
	stack<int> min;
}


int minStack::push(int x){
	int temp = 0; 
	
	if (data.empty() && min.empty()){
		data.push(x);
		min.push(x);
		return x;
	}
	
	/* 取top前判断栈是否为空 */ 
	temp = min.top();
	data.push(x);
	if (x <= temp){
		min.push(x);
	}
	
	return x;
}

int minStack::pop(){
	int ret = 0;
	
	ret = data.top();
	data.pop();
	
	if (ret == min.top()){
		min.pop();
	}
	
	/* the case can not be happen */ 
	if ( ret < min.top()){
		/* DEBUG error */ 
	}
	
	return ret; 
	
}


int minStack::getMin(){
	int ret = 0;
	
	ret = min.top();
	return ret;
}



int main(){
	int N = 0;
	string operate = "";
	int number = 0;
	minStack mystack;
	
	cin>>N;
	
	for (int i = 0; i < N; i++){
		cin>>operate;
		
		if (operate == "push"){
			cin>>number;
			mystack.push(number);
			continue;
		}
		
		if (operate == "pop"){
			mystack.pop();
			continue;
		}
		
		if (operate == "getMin"){
			cout<<mystack.getMin()<<endl;
			continue;
		}
		
		/* Debug error : the case shouldn't be happen */
		/* TODO */
		
	} 
	
	return 0;
} 
