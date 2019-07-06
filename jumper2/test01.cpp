#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int jump(vector<int>& nums) {
        int res = 0, n = nums.size(), i = 0, cur = 0;
		std::cout <<"cur " << cur << "  num[ " << i << " ] " << nums[i] << " \n";  
        while (cur < n - 1) {
			std::cout << "jumper " << i << "\n";
            ++res;
            int pre = cur;
            while(i <= pre) {
                cur = max(cur, i + nums[i]);
				//std::cout <<"cur " << cur << "  num[ " << i << " ] " << nums[i] << " \n";  
				++i;
            }
			std::cout <<"cur " << cur << "  num[ " << i << " ] " << nums[i] << " \n";  
            if (pre == cur) return -1; // May not need this
        }
        return res;
    }
};

int main()
{
	Solution s;
	vector<int> vec{1, 2, 2,1, 3,1,1,4};
	int res = s.jump(vec);
	std::cout << "result "<< res << "\n";
	return 1;
}
