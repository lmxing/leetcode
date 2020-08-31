
#include "../my_include.h"
#include "../my_util.h"


class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> res;
        map<int,int> cnt;

        for(int i = 0; i < nums.size(); ++i){
            cnt[nums[i]]++;
			print(cnt);
            if(i >= k-1){
                res.push_back(cnt.rbegin()->first);
				 // 大小为k的窗口的第一个原始，每次加一个元素减少一个原始
                cnt[nums[i-k+1]]--;
                if(cnt[nums[i-k+1]] == 0) cnt.erase(nums[i-k+1]);
            }
        }

        return res;
    }


    vector<int> maxSlidingWindow11(const vector<int>& num, unsigned int size)
    {
        int len = num.size();
        vector<int> result;
        if(len < size||size==0)
            return result;
        for(int i=0; i<=len-size; i++)
        {   
            int max = num[i];
            for(int j = i; j< i+size;j++)
            {              
                if(num[j]>max)
                    max = num[j];
            }
            result.push_back(max);
        }      
        return result;
    };

    vector<int> maxSlidingWindow111(vector<int>& nums, int k) {
        vector<int> result;
        int ai = 0;
        int n = nums.size();
        if (n == 0) return result;
        map<int, int> val2id;
        map<int, int> id2val;
        for (int i = 0; i < k; ++i) {
            val2id[nums[i]] = i;
            id2val[i] = nums[i];
        }
        result.push_back(val2id.rbegin()->first);
        for (int i = k; i < n; ++i) {
            for(auto iter = id2val.begin(); iter != id2val.end(); ) {
                if (iter->first <= i-k) {
                    if (val2id[iter->second] == iter->first)
                        val2id.erase(iter->second);
                    id2val.erase(iter++);
                }  else break;
            }
            val2id[nums[i]] = i;
            id2val[i] = nums[i];
            result.push_back(val2id.rbegin()->first);

        }
        
        return result;
    }
};

int main()
{
	Solution sol;
	vector<int> nums = {1,3,-1,-3,5,3,6,7};
	int k = 3;
	vector<int> result = sol.maxSlidingWindow(nums, k);
	return 1;
}
