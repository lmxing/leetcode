
#include "../my_include.h"
#include "../my_util.h"

class CustomStack {
public:
    CustomStack(int maxSize) {
        maxSize = maxSize;
    }
    
    void push(int x) {
		MY_LOG_PAIR("push", x)
		MY_LOG_PAIR("size", stk.size())
        if (stk.size() == maxSize) {
            return;
        }
     	MY_LOG_PAIR("push", x) 
        stk.push_back(x);
    }
    
    int pop() {
        if (stk.size() <= 0) return -1;
        int index = stk.size() - 1;
        int tmp = stk[index];
        
        stk.pop_back();
        return tmp;
    }
    
    void increment(int k, int val) {
        int min_len = min(k, (int)stk.size());
        for (int i = 0; i < min_len; i++) {
            stk[i] +=val;
        }
    }
    int maxSize;
   
    std::vector<int> stk;
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */


int main()
{
	CustomStack sol(3);
	sol.push(1);
	sol.push(2);
	sol.pop();
	sol.push(2);
	sol.push(3);
	sol.push(4);
	return 1;
}
