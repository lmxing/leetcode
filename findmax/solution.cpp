
#include "../my_include.h"
#include "../my_util.h"

void findMax(vector<int> nums)
{
	int len = nums.size();
	int left = 0;
	int right = len - 1;
	while(left < right - 1) {
		int mid = left + (right - left) / 2;
		if (nums[left] <= nums[mid]) {
			left = mid;
		} else {
			right = mid - 1;
		}
		MY_LOG(mid)
	}
	std::cout << "res: ";
	std::cout << max(nums[left], nums[right]) << std::endl;
}


    int findMin(vector<int> nums) {
        int len = nums.size();
        int left = 0;
        int right = len - 1;
        while(left < right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] > nums[right]) {
                left = mid + 1;
            } else if (nums[mid] < nums[right]) {
                right = mid;
            } else {
                right--;
            }
        }
if (left >= 1) std::cout << "max: "<<nums[left-1];
else std::cout<< "max: "<< nums[len-1];
std::cout << "\n";
        return nums[left];
    }

int main()
{
	vector<int> nums = {1,2,3,4};
	findMin({1,2,3,4});
	findMin({4,5,6,1,2,3});
	findMin({5,6,2});
	std::cout << "========\n";
	findMax({1,2,3,4});
	findMax({4,5,6,1,2,3});
	findMax({5,6,2});
	findMax({1,2});
	findMax({2});
	findMax({2, 1});
	findMax({1,2,3});

	return 1;
}
