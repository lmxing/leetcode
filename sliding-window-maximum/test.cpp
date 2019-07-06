
#include "../my_include.h"
#include "../my_util.h"


class Solution {
public:
	vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        if(k==0)return {};
		vector<int>res;
		deque<size_t>window;
		/*Init K integers in the list*/
		for (size_t i = 0; i < k; i++) {
			while (!window.empty()  && nums[i] > nums[window.back()]) {
				window.pop_back();
			}
			window.push_back(i);
		}
		res.push_back(nums[window.front()]);
		/*End of initialization*/
		for (size_t i = k; i < nums.size(); i++) {
			// 去除队头不在滑动窗口的数据
			if (!window.empty() && window.front() <= i - k) {
				window.pop_front();
			}
			// 更新队尾部的最大值: 理由最新的值更新
			while (!window.empty() && nums[i] > nums[window.back()]) {
				window.pop_back();
			}
			window.push_back(i);

			print(window);
			res.push_back(nums[window.front()]);
		}
		return res;
	}
};


int main()
{
	Solution sol;
	vector<int> nums = {1,3,-1,-3,5,3,6,7};
	print(nums);
	int k = 3;
	vector<int> res = sol.maxSlidingWindow(nums, k);
	print(res);
	return 1;
}
