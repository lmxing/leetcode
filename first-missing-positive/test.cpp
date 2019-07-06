
#include "../my_include.h"
#include "../my_util.h"


class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int len = nums.size();
        for (int i = 0; i < len; ++i) {
            while(nums[i] > 0  
                && nums[i] <= len 
                && nums[nums[i] - 1] != nums[i]) {
				 // 交换需要nums[nums[i] - 1]; 在上面，否则nums[i]已经被修改了
				int t = nums[nums[i] - 1];
                nums[nums[i] - 1] = nums[i];
				nums[i] = t;
				print(nums);
            }
				print(nums);
        }
        for (int i = 0; i < len; ++i) {
            if (nums[i] -1 != i) 
                return i + 1;
        }
        return len + 1;
    }
};

int main()
{
	Solution sol;
	vector<int> nums = {7,8,9,11,12}; //{3, 4, -1, 1};
	int res = sol.firstMissingPositive(nums);
	MY_LOG_PAIR("res", res);
	return 1;
}
