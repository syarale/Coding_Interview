/* CD6: 用两个栈实现队列 */

#include <iostream>
#include <stack>
#include <string>
using namespace std;


class StackQueue{
	private:
		stack<int> stack_push;
		stack<int> stack_pop;
		int move_stack(stack<int>& src, stack<int>& des);
	
	public:
		int add(int x);
		int poll();
		int peek();
		StackQueue();
		~StackQueue();	
};

StackQueue::StackQueue()
{
	stack<int> stack_push;
	stack<int> stack_pop;
} 

StackQueue::~StackQueue(){
	
}


/* Add x to queue, and return the value of x. */ 
int StackQueue::add(int x){
	int ret = x;
	
	stack_push.push(x);
	return ret;
	
}

/* pop a element from queue, if success, return 0. 
 * If the queue is empty, return -1;
 */ 
int StackQueue::poll(){
	int ret = 0;
	
	if (stack_pop.empty()) {
		int mret = move_stack(stack_push, stack_pop);
		
		if (mret == 0)
			return -1;
	}
	
	stack_pop.pop();
	
	return ret;
}

/* return the value of the first elements in the queue.
 * If the queue is empty, return ERROR.
 */
int StackQueue::peek()
{
	int ret = 0;
	
	if (stack_pop.empty()){
		int mret = move_stack(stack_push, stack_pop);
		
		/* if the queue is empty handle the error  
		if (mret == 0){
			//TODO:handle the error
			return ERROR;
		}  */
		
	}
	
	ret = stack_pop.top();
	
	return ret;
}


/* Move elements from src to des,
 * Return the number of moved elements. 
 */ 
int StackQueue::move_stack(stack<int>& src, stack<int>& des)
{
	int num = 0;
	
	if (src.empty())
		return 0;
	
	while (!src.empty()){
		int temp = src.top();
		des.push(temp);
		src.pop();
		num++;
	}
	
	return num;
}



int main()
{
	StackQueue squeue;
	int N = 0;
	cin>>N;
	
	for (int i = 0; i < N; i++){
		string cmd = "";
		cin>>cmd;
		
		if (cmd == "add") {
			int x = 0;
			cin>>x;
			squeue.add(x);
			
		} else if (cmd == "peek") { 
			int ret = squeue.peek();
			
			/* if (ret == ERROR){
					//TODO: handle the error 
			} */ 
			
			cout<<ret<<endl;
		} else if (cmd == "poll") {
			int ret = squeue.poll();
			
			/* if (ret == -1){
				  //TODO: handle the error 
			} */
			
		} else {
			/* the cmd is invalid */
			//TODO： handle the error 
		}
	}
	
	return 0;
 } 
