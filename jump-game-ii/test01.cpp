
#include "../my_include.h"
#include "../my_util.h"


class Solution {
public:
    int jump(vector<int>& nums) {
        int res = 0;//记录最小次数
        int maxIndex = 0;//每轮的最大位置
        int end = 0;
        for(int i = 0; i < nums.size() - 1; ++i){
			if ( maxIndex >= i ) {
           		maxIndex = max(maxIndex, i + nums[i]);
           		if(i == end){
               		res++;
               		end = maxIndex;
			   		std::cout << "\t\t i " << i << " end " << end << " maxIndex " << maxIndex << "\n";
		   		}
			   	std::cout << " i " << i << " end " << end << " maxIndex " << maxIndex << "\n";
			}
           	if(end >= nums.size() - 1)return res;
        }
        return res;
    }
};

int main()
{
	Solution sol;
	vector<int> nums{2,3,1,2,4,2,3}; //{2,3,1,1,4};
	int res = sol.jump(nums);
	std::cout << res << "\n";
	return 1;
}
