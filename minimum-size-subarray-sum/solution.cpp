
#include "../my_include.h"
#include "../my_util.h"

class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int len = nums.size();
        int left = 0;
        int right = 0;
        int min_len = len;
        int sum = 0;
        while (right < len) {
			print(nums, left, right);
            sum += nums[right];
            while (sum >= s) {
                min_len = min(min_len, right - left + 1);
                sum -= nums[left];
                left++;
            }
			right++;
        }
        if (min_len == len) return 0;
        return min_len;
    }
};

int main()
{
	Solution sol;
	vector<int> nums = {2,3,1,2,4,3};
	int result = sol.minSubArrayLen(7, nums);
	MY_LOG_PAIR("result", result)
	return 1;
}
