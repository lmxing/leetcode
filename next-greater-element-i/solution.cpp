
#include "../my_include.h"
#include "../my_util.h"

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        
        vector<int> result;
        stack<int> stk;
        unordered_map<int, int> map;
        for (auto num: nums2) {
            while(!stk.empty() && stk.top() < num) {
                map[stk.top()] = num;
                stk.pop();
            }
            stk.push(num);
        }
        for (auto num: nums1) {
            if (map.count(num) >= 1) {
                result.push_back(map[num]);
            } else {
                result.push_back(-1);
            }
        }
        return result;
    }
};

int main()
{
	Solution sol;
	vector<int> nums1 = {4,1,2};
	vector<int> nums2 = {1,3,4,2};
	vector<int> result = sol.nextGreaterElement(nums1, nums2);

	print(result);

	return 1;
}
