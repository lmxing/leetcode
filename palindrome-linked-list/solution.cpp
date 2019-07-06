
#include "../my_include.h"
#include "../my_util.h"
#include "../my_list_node.h"

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    int depth(ListNode * head) {
        ListNode * cur = head;
        int len = 0;
        while(cur) {
            len++;
            cur = cur->next;
        }
        return len;
    }
    bool isPalindrome(ListNode* head) {
        int len = depth(head);
        if (len <=1 ) return true;
        if (len == 2) return head->val == head->next->val;
        // len =5  [0 1 2 3 4 ]s2 = (5+1)/2
        // len = 4 0 1 2 3 s2 = (4+1)/2
        int s1 = 0;
        int s2 = (len+1) / 2;
        ListNode *head2 = head;
        while(s2 > 0) {
            head2 = head2->next;
			MY_LOG_PAIR("s2 ", s2)
			print(head2);
			MY_LOG("--------")
            s2--;
        }
			print(head2);
        //if (true) return head2 == NULL;
       //if (head2->next == NULL) return head2->val == head->val;
        ListNode * cur2 = NULL;
        ListNode * p2 = head2;
        while(p2) {
            ListNode * tmp = p2->next;
            p2->next = cur2;
            cur2 = p2;
            p2 = tmp;
        }
        
        ListNode * revHead2 = cur2;

        while(revHead2 && head) {
            if (revHead2->val != head->val) return false;
            revHead2 = revHead2->next;
            head = head->next;
        }
        return true;



    }
};

int main()
{
	Solution sol;
	vector<int> nums = {1,2,3};
	ListNode *head = buildListNode(nums);
	print(head);
	bool result = sol.isPalindrome(head);
	MY_LOG_PAIR("result", result)
	return 1;
}
