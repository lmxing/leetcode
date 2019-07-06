
#include "../my_include.h"
#include "../my_util.h"

class Solution {
public:
    string multiply(string num1, string num2) {
        if (num1=="0" || num2=="0")
            return "0";
        int A[111] = {0}, B[111] = {0}, C[511] = {0};
        for (int i = num1.length() - 1; i >=0 ;--i) {
            A[num1.length() -1 -i] = num1[i] - '0';
        }
        for (int i = num2.length() - 1; i >=0 ;--i) {
            B[num2.length() -1 -i] = num2[i] - '0';
        }
        for (int i = 0 ;i < num1.length(); ++i) {
            for (int j = 0; j < num2.length(); ++j) {
                C[i+j] += A[i] * B[j];
            }
        }
        for (int i = 0 ; i < num1.length() + num2.length(); ++i) {
            if (C[i] > 9) {
                C[i+1] += C[i]/10;
                C[i] %=10;
            }
        }
        string res = "";
        int endindex =  num1.length() + num2.length() + 1;
        while(endindex >=0 && C[endindex]==0) endindex--;
        while(endindex>=0) {
            res = res + ""+ to_string(C[endindex]);
			MY_LOG_PAIR("res", res)
            --endindex;
        }
		print(C, 510);
        return res;
    }
};

int main()
{
	Solution sol;
	string num1 = "311";
	string num2 = "222";
	string result = sol.multiply(num1, num2);
	std::cout << result << std::endl;

	return 1;
}
