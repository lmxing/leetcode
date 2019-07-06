
#include "../my_include.h"
#include "../my_util.h"


class Solution {
public:
    vector<int> getLeastNumbers(vector<int>& arr, int k) {
        int left = 0;
        int len = arr.size();
         int right = len - 1;
        quitsort(arr, left, right, len) ;
        vector<int> list(arr.begin(), arr.begin() + k);
        return list;
    }
    void quitsort(vector<int> & arr, int left, int right, int len) {
        if (left >= right) return;
        int part = partition(arr, left, right, len );
        quitsort(arr, left, part -1, len);
        quitsort(arr, part+1, right, len);
    }
    int partition(vector<int> & arr, int left, int right, int len) {
        // 腾出left
        int p = arr[left];
        while(left < right) {
            while(left < right && arr[right] > p) right--;
            // 腾出right
            arr[left] = arr[right];
            while(left < right && arr[left] <= p) left++;
            // 腾出left
            arr[right] = arr[left];
        }
        // left 更新
        arr[left] = p;
        return left;
    }
};

int main()
{
	Solution sol;
	vector<int> nums = {1,2,3,4};
	string result = sol.;
	int result = sol.;
	MY_LOG_PAIR("result", result)
	return 1;
}
