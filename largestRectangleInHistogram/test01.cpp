#include <iostream>
#include <vector>
#include <stack>

using namespace std;


void print(vector<int> v) {
	for (int i:v) 
		std::cout<< i << " ";
	std::cout << "\n";
}
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int> left(n), right(n);
        
        stack<int> mono_stack;
        for (int i = 0; i < n; ++i) {
            while (!mono_stack.empty() && heights[mono_stack.top()] >= heights[i]) {
                mono_stack.pop();
            }
            left[i] = (mono_stack.empty() ? -1 : mono_stack.top());
            mono_stack.push(i);
        }

        mono_stack = stack<int>();
        for (int i = n - 1; i >= 0; --i) {
            while (!mono_stack.empty() && heights[mono_stack.top()] >= heights[i]) {
                mono_stack.pop();
            }
            right[i] = (mono_stack.empty() ? n : mono_stack.top());
            mono_stack.push(i);
        }
       	print(left);
		print(right);
 
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            ans = max(ans, (right[i] - left[i] - 1) * heights[i]);
        }
        return ans;
    }
};

class Solution1 {
public:
    int largestRectangleArea(vector<int>& heights) {
        int res = 0;
        int n = heights.size();
        if (n == 0) return 0;
        if (n == 1) return heights[0];
        stack<int> stack_min;
        vector<int> left_min(n);
        vector<int> right_min(n);
        for (int i = 0; i < n; ++i) {
            while(!stack_min.empty() && heights[stack_min.top()] >= heights[i]) {
                stack_min.pop();
            }
            left_min[i] = (stack_min.empty()? -1 : stack_min.top());
            stack_min.push(i);
        }
        stack_min = stack<int>();
        for (int i = n-1; i >= 0; --i) {
            while(!stack_min.empty() && heights[stack_min.top()] >= heights[i]) {
                stack_min.pop();
            }
            right_min[i] = (stack_min.empty()? -1 : stack_min.top());
            stack_min.push(i);
        }
		print(left_min);
		print(right_min);
        for (int i = 0; i < n; ++i) {
            res = max(res, (right_min[i] - left_min[i] - 1 ) * heights[i]);
        }
        return res;
    }
};

int main()
{
	Solution s;
//	vector<int> heights{2,1,5,6,2,3};
	vector<int> heights{1,1};
	int res = s.largestRectangleArea(heights);
	std::cout << res << std::endl;
	return 1;
}
