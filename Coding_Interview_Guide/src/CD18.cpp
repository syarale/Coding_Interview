/* CD18：最大值减去最小值小于或等于num的子数组数量 */

#include <iostream>
#include <queue>
#include <deque>
using namespace std;


/* 
 * Class OptQueue is a queue, and it can return 
 * max value or min value on O(1) time.
 */ 
class OptQueue {
private:
	int len;
	queue<int> data;
	deque<int> qmax;
	deque<int> qmin;

public:
	OptQueue();
	~OptQueue();
	int size();
	int push(int x);
	int pop();
	int get_max();
	int get_min();
};

OptQueue::OptQueue() {
	len = 0;
	deque<int> qmax;
	deque<int> qmin;
}

OptQueue::~OptQueue() {
	
}

/* Return max value of Queue */ 
int OptQueue::get_max() {
	if (qmax.empty()) {
		/* TODO：handle error */ 
	}
	return qmax.front();
} 

/* Return min value of Queue */ 
int OptQueue::get_min() {
	if (qmin.empty()) {
		/* TODO: handle error */ 
	}
	return qmin.front();
}

/* Push x to the end of queue and Return the value. */ 
int OptQueue::push(int x) {
	data.push(x);
	while (!qmax.empty() && qmax.back() < x) {
		qmax.pop_back();
	}
	qmax.push_back(x);
	
	while (!qmin.empty() && qmin.back() > x) {
		qmin.pop_back();
	}
	qmin.push_back(x);
	 
	len++;
	return x;
	
} 

/* Pop the first element of queue, and return the value.*/ 
int OptQueue::pop() {
	int temp = data.front();
	data.pop();
	
	if (temp == qmax.front()) {
		qmax.pop_front();
	}
	
	if (temp == qmin.front()) {
		qmin.pop_front();
	}
	
	len--;
	return temp;
}


/* Return the size of the queue */ 
int OptQueue::size() {
	/* if (data.size() != len) {
		....debug error...
	} */
	return data.size();	
}



/* ----------- Solution the problem ------------*/

int get_num(const vector<int>& data, int num) {
	int i = 0;
	int j = 0;
	int res = 0;
	int len = data.size();
	OptQueue opt;
	
	if (len == 0) {
		return 0;
	}
	opt.push(data[0]);
	
	for (;;) {
		while (j+1 < len) {
			if (data[j+1] - opt.get_min() <= num
			    && opt.get_max() - data[j+1] <= num) {
			    opt.push(data[j+1]);
				j++;	
			} else {
				break;
			}
		} 
		
		res += (j - i + 1);
		
		i++;
		opt.pop();
		if (i >= len) {
			break;      /* Now, i > j, and opt is empty. */ 
		}
		
		if (i > j) {
			j++;        /* Now, i = j and opt is empty. */ 
			opt.push(data[j]);
		}
		
	}
	
	return res;
}





int main()
{
	int n, num;
	int ret;
	vector<int> input;
	OptQueue opt;
	
	cin>>n>>num;
	for (int i = 0; i < n; i++) {
		int x = 0;
		cin>>x;
		input.push_back(x);
	}
		
	ret = get_num(input, num);
	cout<<ret;
	
	return 0;
 } 
