
#include "../my_include.h"
#include "../my_util.h"

class Solution {
public:

    vector<vector<int>> threeSum(vector<int>& nums) {
        int index = 0;
        vector<vector<int>>  result;
        std::unordered_set<string> set;
        sort(nums.begin(), nums.end());
		print(nums);
        for (int i = 0; i < nums.size(); ++i) {
            while (i + 1 < nums.size() && nums[i] == nums[i+1]) {
                i++;
            }
            int val1 = nums[i];
            int left = i + 1;
            int right = nums.size() - 1;
            while(left < right) {
                while(left < right && nums[left] == nums[left + 1]) left++;
                while(left < right && nums[right] == nums[right - 1]) right--;
                int s = nums[i] + nums[left] + nums[right] ;
                if (s  == 0 ) {
                    result.push_back({nums[i], nums[left], nums[right]});
                } else if (s <0) {
                    left++;
                } else {
                    right--;
                }
				if(left == right) break;
            }
        }
         return result;
    }
  
    vector<vector<int>> threeSum1(vector<int>& nums) {
        
        int index = 0;
        vector<vector<int>>  result;
        std::unordered_set<string> set;
        for (int i = 0; i < nums.size(); ++i) {
            int val1 = nums[i];
            std::unordered_map<int, int> map;
            int j = i + 1;
            while(j < nums.size()) {
                int val2 = nums[j];
                if (map.find(val2) == map.end()) {
                    map[-val1 - val2] = j;
                } else {
                    string key = getKey(val1, val2);
                    if (set.find(key)!= set.end()) {
						++j;
						continue;
					}
					set.insert(key);
                    result.push_back({val1, val2, -val1 - val2});
                }
                ++j;
            }
            map.clear();
        }
        return result;
    }
    string getKey(int val1, int val2) {
        int val3 = -val1-val2;
        if (val1 > val2) {
            swap(val1, val2);
        }
        if (val1 > val3) {
            swap(val1, val3);
        }
        if (val2 > val3) {
            swap(val2, val3);
        }
        string key = to_string(val1) + to_string(val2) + to_string(val3);
		MY_LOG(key)
        return key;
    }
    void swap(int & val1, int & val2) {
        int  t = val1;
        val1 = val2;
        val2 = t;
    }
    
};

int main()
{
	Solution sol;
	vector<int> nums= {-1, 0, 1, 2, -1, -4};
	sol.threeSum(nums);
	return 1;
}
