
#include "../my_include.h"
#include "../my_util.h"

class Solution {
public:
    vector<int> singleNumbers(vector<int>& nums) {
        int xor1 = 0;
        for (int i = 0; i < nums.size(); ++i) {
            xor1 = xor1 ^ nums[i];
        }
        int one = 1;
        int k = 0;
        while( (xor1 & one ) == 0 ) {
            k++;
            one = one << 1;
			MY_LOG_PAIR("one", one)
			MY_LOG_PAIR("k", k)
        }
		MY_LOG_PAIR("k", k)
		MY_LOG_PAIR("xor1", xor1)
        int a = 0;
        int b = 0;
        for (int i = 0; i < nums.size(); ++i) {
				MY_LOG_PAIR("xor ", (one & nums[i]))
            if ( (one & nums[i]) == 0) {
                a = a ^ nums[i];
				MY_LOG_PAIR("a-i", nums[i]);	
            } else {
                b = b ^ nums[i];
				MY_LOG_PAIR("b-i", nums[i]);	
            }
        }
        return {a, b};
    }
   
};

int main()
{
	Solution sol;
	vector<int> nums = {1,2,5,2};
	vector<int> ret = sol.singleNumbers(nums);
	MY_LOG("result")
	print(ret);
	return 1;
}
