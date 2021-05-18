/* CD101：单调栈结构(不含重复元素) */ 

#include <iostream>
#include <stack>
#include <vector>
#include <utility>
using namespace std;

const int TO_RIGHT = 1;
const int TO_LEFT = 0;

vector<int> do_traverse(const vector<int>& data, int direction)
{
	int len = data.size();
	int begin = 0;
	int end = 0;
	int var = 0;
	int ptr = 0;
	vector<int> ret;
	stack<int> all_smaller;

	if (data.empty())
		return ret;

	if (direction == TO_RIGHT) {
		begin = 0;
		end = len - 1;
		var = 1;
	} else if (direction == TO_LEFT) {
		begin = len - 1;
		end = 0;
		var = -1;
	} else {
		/* TODO： handle invalid input*/
	}

	ptr = begin;
	for (int i = 0; i < len; i++) {
		while (!all_smaller.empty()
		       && data[all_smaller.top()] > data[ptr]) {   /* data'element are different */ 
                                                     /* CD188：If two element are equeal(may be), the case should be: data[all_smaller.top()] >= data[ptr] */ 
			all_smaller.pop();
		}

		if (all_smaller.empty()) {
			ret.push_back(-1);
		} else {
			ret.push_back(all_smaller.top());
		}

		all_smaller.push(ptr);
		ptr += var;

	}

	return ret;
}


vector<pair<int, int> > get_nearest_smaller(const vector<int>& data)
{
	int len = 0;
	vector<int> left;     /* left：the location of left-nearest-smaller element */
	vector<int> right;    /* right：the location of right-nearest-smaller element */
	vector<pair<int, int> > smaller_val;

	left = do_traverse(data, TO_RIGHT);   /* Traverse to right */
	right = do_traverse(data, TO_LEFT);

	len = left.size();   /* Debug when left.size != right.size */
	for (int i = 0; i < len; i++) {
		pair<int, int> tmp(left[i], right[len - 1 - i]);
		smaller_val.push_back(tmp);
	}

	return smaller_val;
}


int main()
{
	int n = 0;
	int out_len = 0;
	cin >> n;
	vector<int> data;
	vector<pair<int, int> > out;

	for (int i = 0; i < n; i++) {
		int tmp = 0;
		cin >> tmp;
		data.push_back(tmp);
	}
	
	out = get_nearest_smaller(data);

	out_len = out.size();    /* Debug when out_len != len */
	for (int i = 0; i < out_len; i++) {
		cout << out[i].first << " " << out[i].second << endl;
	}

	return 0;
}
