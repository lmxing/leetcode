
#include "../my_include.h"
#include "../my_util.h"

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int len = nums.size();
        int left =0;
        int right = len - 1;
        int pos = partition(nums, left, right);
        while(pos != k-1) {
            if (pos == -1) return -1;
            if (pos < k) pos = partition(nums, pos + 1, right);
            else pos = partition(nums, left, pos );
			//MY_LOG(pos)
			//print(nums);
        }
        return nums[k-1];

    }
    int partition(vector<int> &nums, int left, int right) {
        if(left >= right) return -1;
		int mid = left + (right - left) /2;
        int priv = nums[mid];
        int left_back = left;
        int right_back = right;
        while (left < right) {
            while(left < right && nums[right] < priv) right--;
            while(left < right && nums[left] >= priv) left++;
			if (left < right) {
				int t = nums[left];
				nums[left] = nums[right];
				nums[right] = t;
			}
        }
        nums[mid] = priv;
		print(nums);
		MY_LOG(priv)
        return left;
   
    } 
};

int main()
{
	Solution sol;
	vector<int> nums = {3,2,3,1,2,4,5,5,6};
	int k = 4;
	sol.findKthLargest(nums, k);
	return 1;
}
