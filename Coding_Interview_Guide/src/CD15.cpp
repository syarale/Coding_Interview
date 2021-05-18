/* CD15：生成窗口最大值数组 */
 
#include <iostream>
#include <stack>
#include <queue>
#include <vector>
using namespace std;

class GetMaxQue {
private:
	queue<int> data;
	deque<int> max_que;

public:
	int  empty();
	int  size();
	void push(int x);
	void pop();
	int  front();
	int  back();
	int  get_max();
	GetMaxQue();
	~GetMaxQue();

};

GetMaxQue::GetMaxQue() {
	queue<int> data;
	deque<int> max_que;
}

GetMaxQue::~GetMaxQue() {

}

void GetMaxQue::push(int x) {
	data.push(x);

	while (!max_que.empty() && x > max_que.back()) {
		max_que.pop_back();
	}

	max_que.push_back(x);
}


void GetMaxQue::pop() {
	int tmp = data.front();
	data.pop();

	if (tmp == max_que.front()) {
		max_que.pop_front();
	}
}

int GetMaxQue::front() {
	return data.front();
}

int GetMaxQue::back() {
	return data.back();
}

int GetMaxQue::get_max() {
	return max_que.front();
}

/* if the queue is empty, then return 1 */
int GetMaxQue::empty() {
	int len = data.size();
	return (len > 0) ? 0 : 1;
}

int GetMaxQue::size() {
	return data.size();
}

/* Get the max value when window move through input.The size
 * of window is wsize.
 * Return a vector which include these max value.
 */
vector<int> get_max_vec(const vector<int>& input, int wsize) {
	int len = input.size();
	vector<int> output;
	GetMaxQue maxque;

	/* if input.size < the size of window, 
	 * return a empty vector.
	 */
	if (len < wsize)
		return output;

	for (int i = 0; i < wsize; i++)
		maxque.push(input[i]);
	output.push_back(maxque.get_max());

	for (int i = wsize; i < len; i++) {
		maxque.pop();
		maxque.push(input[i]);
		output.push_back(maxque.get_max());
	}

	return output;
}

int main()
{
	int N;
	int w;
	vector<int> input;
	vector<int> output;
	cin >> N >> w;

	for (int i = 0; i < N; i++) {
		int tmp = 0;
		cin >> tmp;
		input.push_back(tmp);
	}

	//cout << "input size: " << input.size() << endl;
	output = get_max_vec(input, w);

	int len = output.size();
	for (int i = 0; i < len; i++)
		cout << output[i] << " ";

	return 0;
}
