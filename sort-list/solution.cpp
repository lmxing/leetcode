
#include "../my_include.h"
#include "../my_util.h"

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
    ListNode* sortList(ListNode* head) {
        // return mergeSort(head);
        return quickSort(head, NULL);
    }
    ListNode * quickSort(ListNode * slow, ListNode * fast) {
        if (slow == fast) return slow;
        ListNode * k = partition(slow, fast);
        quickSort(slow, k);
        quickSort(k->next, fast);
        return slow;
    }
    ListNode * partition(ListNode * slow, ListNode * fast) {
        ListNode * p1 = slow;
        ListNode * p2 = slow;
        int val = p1->val;
       	MY_LOG_PAIR("val", val) 
	/*定义两个辅助指针p1，p2,这两个指针均往next方向移动，移动的过程中保持p1之前的值都小于选定的pivot，
    p1和p2之间的值都大于选定的pivot，那么当p2走到末尾时交换p1的值与pivot便完成了一次切分*/

        while(p2 != fast) {
            if (p2->val < val) {
               	MY_LOG_PAIR("p2->val", p2->val) 
                p1 = p1->next;
                int tmp = p1->val;
                p1->val = p2->val;
                p2->val = tmp;   
            }
            p2 = p2->next;
        }
        int tmp = p1->val;
        p1->val = slow->val;
        slow->val = tmp;
        return p1;
    }
    ListNode* mergeSort(ListNode * head) {
        if (head == NULL || head->next == NULL) return head;
        ListNode * slow = head;
        ListNode * fast = head->next;
        while(fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode * right = mergeSort(slow->next);
        slow->next = NULL;
        ListNode * left = mergeSort(head);
        return mergeList(left, right);
    }
    ListNode* mergeList(ListNode * head1, ListNode * head2) {
        if (head1 == NULL) return head2;
        if (head2 == NULL) return head1;
        ListNode * dump = new ListNode(-1);
        ListNode * cur = dump;
        while(head1 && head2) {
            if (head1->val < head2->val) {
                cur->next = head1;
                cur = cur->next;
                head1 = head1->next;
            } else {
                cur->next = head2;
                cur = cur->next;
                head2 = head2->next;
            }
        }
        if (head1) cur->next = head1;
        if (head2) cur->next = head2;
        return dump->next;
    }
};

int main()
{
	Solution sol;
	vector<int> nums = {100,3,4};
	ListNode * head = buildListNode(nums);
	ListNode * head_sort = sol.sortList(head);

	print(head_sort);
	return 1;
}
