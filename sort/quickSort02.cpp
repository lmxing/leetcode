
#include "../my_include.h"
#include "../my_util.h"

class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        int right = nums.size() - 1;
        if (right <= 1) return nums;
        quickSort(nums, 0, right);
        return nums;
    }
    void quickSort(vector<int>& nums, int left, int right) {
        if (left >= right) return;
        int pos = partIndex(nums, left, right);

        quickSort(nums, left, pos-1);
        quickSort(nums, pos+1, right);
    }
    int partIndex(vector<int>& nums, int left, int right) {
        int val = nums[left];
        int l = left;
        int r = right;
        while (l != r) {
			std::cout <<l << " "; 
            while (l <= r && nums[r] >= val) r--;
            while (l <= r && nums[l] < val) l++;
            if (l < r) {
                int t = nums[l];
                nums[l] = nums[r];
                nums[r] = t;
            }
        }
        nums[left] = nums[l];
        nums[l] = val;
        return left;
    }
};

int main()
{
	vector<int> num{5,2,3,1};
	Solution sol;
	sol.sortArray(num);
	return 1;
}
