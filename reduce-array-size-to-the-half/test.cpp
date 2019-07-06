
#include "../my_include.h"
#include "../my_util.h"

class Solution {
public:
    static bool comp(const int & a, const int &b) {
        return a > b;
    }
    int minSetSize(vector<int>& arr) {
        vector<int> freq(10, 0);
        for (int i = 0; i < arr.size(); ++i) {
            freq[arr[i]]++;
        }
		print(freq);
        //sort(freq.begin(), freq.end());
        sort(freq.begin(), freq.end(), comp);
		print(freq);
        int sum =0;
        for (int i = 0; i <10; ++i) {
            sum += freq[i];
            if (sum >= arr.size() / 2) return i + 1;
        }
        return -1;
    }
};

int main()
{
	Solution sol;
	vector<int> nums = {3,3,3,3,5,5,5,2,2,7};
	sol.minSetSize(nums);
	return 1;
}
