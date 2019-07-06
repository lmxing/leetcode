
#include "../my_include.h"
#include "../my_util.h"

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n = nums.size();
        for (int i = 0 ; i < n; i++) {
            while(nums[i] != i + 1) {
                if (nums[i] == nums[nums[i] - 1]) return nums[i];
                int t = nums[ nums[i] -1 ];
                nums[ nums[i] -1 ] = nums[i];
                nums[i] = t; 
				print(nums);
            }
        }
        return -1;
    }
};

int main()
{
	Solution sol;
	vector<int> nums = {1,3,4,2,2};
	//string result = sol.;
	int result = sol.findDuplicate(nums);
	MY_LOG_PAIR("result", result)
	return 1;
}
