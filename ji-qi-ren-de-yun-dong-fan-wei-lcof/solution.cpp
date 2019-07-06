
#include "../my_include.h"
#include "../my_util.h"

class Solution {
public:
    int bitSum (int num) {
        int s = 0;
        while(num !=0) {
            s += num %10;
            num /= 10;
        }
        return s;
    }
    bool ismove(int i, int j , int k) {
        int s = bitSum(i) + bitSum(j);
        return s <= k;
    }
    int visit[1001][1001] = {0};

    int movingCount(int m, int n, int k) {
        int result = 0;
        visit[0][0] = 1;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (!ismove(i, j, k)) continue;
				MY_LOG(__LINE__)
                if (i == 0 && j == 0) {
                    result ++;
                } else 
                if ( (i>= 1 && visit[i-1][j] == 1) || 
                      (j>=1 && visit[i][j-1] == 1) ) {
                    result ++;
                    visit[i][j] = 1;
                }
            }
        }
        return result;
    }
    int movingCount1(int m, int n, int k) {
        int result = 0;
        visit[1][1] = 1;
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (ismove(i-1, j-1, k)) continue;
                if (i == 1 && j == 1) {
                    result ++;
                } else 
                if (visit[i-1][j] == 1 || visit[i][j-1] == 1) {
                    result ++;
                    visit[i][j] = 1;
                }
            }
        }
        return result;
    }
};

int main()
{
	Solution sol;
	vector<int> nums = {1,2,3,4};
	//string result = sol.;
	int result = sol.movingCount(1,2,1);
	MY_LOG_PAIR("result: ", result)
	return 1;
}
