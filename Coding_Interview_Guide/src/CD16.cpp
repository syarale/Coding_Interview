/* CD16: 求最大子矩阵大小 */

#include <iostream>
#include <vector>
#include <stack> 
using namespace std;

const int TO_LEFT = 0;
const int TO_RIGHT = 1;

/* update height-vector by the curr-th raw of matrix */
void update_height(const vector<vector<int> >& matrix,
				   int curr, vector<int>& height) {
	
	int len = height.size();
	for (int i = 0; i < len; i++) {
		if (matrix[curr][i] == 0) {
			height[i] = 0;
		} else {
			height[i] += 1;
		}
	}
	return;

}

vector<int> get_nearest_less(vector<int> height, int direction) {
	int len = height.size();
	int begin = 0;
	int end = len - 1;
	int ans = 1;
	int curr = 0;
	
	vector<int> ret;
	vector<int> res; 
	stack<int> tmp;
	
	if (direction == TO_LEFT) {
		begin = len - 1;
		end = 0;
		ans = -1;
	}
	
	curr = begin;
	for (int i = 0; i < len; i++) {
		while (!tmp.empty() && height[tmp.top()] >= height[curr]) {
			tmp.pop();
		}
		
		if (tmp.empty()) {
			ret.push_back(-1);
		} else {
			ret.push_back(tmp.top());
		}
		tmp.push(curr);
		curr += ans;
	}
	
	if (direction == TO_LEFT) {
		for (int i = len - 1; i >= 0; i--) {
			res.push_back(ret[i]);
		}
		
		return res;
		
	}
	
	return ret;
	
}

/* 
 * Get largest-submatrix area of 'matrix', caller should promise
 * every element's value is 1 or 0.
 * Return the area of largest-submatrix, return 0 when 'matrix' is empty.
 */
int get_largest_submatrix(const vector<vector<int> >& matrix) {
	int raw_len = matrix.size();
	int col_len = matrix[0].size();
	int max_area = 0;
	vector<int> height(col_len, 0);
	vector<int> l_less;               /* left-nearest-less vector  */
	vector<int> r_less;               /* right-nearest-less vector */
	
	 
	if (matrix.empty()) {
		return 0;
	}
	
	for (int i = 0; i < raw_len; i++) {
		int curr_area = 0;
		
		/* update height */
		update_height(matrix, i, height);
		l_less = get_nearest_less(height, TO_RIGHT);
		r_less = get_nearest_less(height, TO_LEFT);
		
		for (int j = 0; j < col_len; j++) {
			int lbound = 0;
			int rbound = 0;
			
			if (l_less[j] == -1) {
				lbound = 0;
			} else {
				lbound = l_less[j] + 1;
			}
			
			if (r_less[j] == -1) {
				rbound = col_len - 1;
			} else {
				rbound = r_less[j] - 1;
			}
			
			curr_area = (rbound - lbound + 1) * height[j];
			if (curr_area > max_area) {
				max_area = curr_area;
			} 
		}
		
	}
	
	return max_area;
} 


int main()
{
	int n, m, k;
	int largest_area;
	
	cin>>n>>m;
	vector<vector<int> > input(n, vector<int>(m, 0));
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin>>k;
			input[i][j] = k; 
		}
	}
	
	largest_area = get_largest_submatrix(input);
	cout<<largest_area;
	
	return 0;
} 
