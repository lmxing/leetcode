
#include "../my_include.h"
#include "../my_util.h"

class Solution {
public:
    int findString(vector<string>& words, string s) {
        int len = words.size();
        int left = 0;
        int right = len - 1;
		// 最后一次相等的时候需要考虑，否则，需要单独判断
        while(left < right) {
            while(left < right && words[left] == "") left++;
            while(left < right && words[right] == "") right--;
            
            int mid = (left + right) / 2;
//std::cout << words[mid] << " " << words[left] << " " << words[right] << "\n";
            if (words[mid] == s) {
                return mid;
            } else if (words[mid] == "") {
                if (s == words[left]) return left;
                left = left + 1;
            } else if (words[mid] < s) {
                left = mid + 1;
            } else if (words[mid] > s) {
                right = mid - 1;
            } 
        }
		if (left < 0) return -1;
		if (left >= len) return -1;
		if (words[left] == s) return -1;
        return left;
    }
};

int main()
{
	Solution sol;
	vector<string> words = {"at", "", "", "", "ball", "", "", "car", "", "", "dad", "", ""};
	string s = "ta";

	words = {"AX zEfzhxdXXbeCQOKa", "aLRAEYPIZokU", "giqyZpvcOHdfPpRqHAD", "mhQf", "uwIPRHFftk"};
	s = "btRVwblGdpLTtSLbjFzB";

	int result = sol.findString(words, s);
	MY_LOG_PAIR("result", result)
	return 1;
}
