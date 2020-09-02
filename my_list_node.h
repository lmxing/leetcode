#pragma once

#include "my_include.h"

struct ListNode
{
    int val;
    ListNode *next;
    ListNode (int x): val(x), next(NULL) {}
};

ListNode * buildListNode(vector<int> & nums) {
    ListNode * head = new ListNode(-1);
    ListNode * cur = head;
    for (auto num: nums) {
        ListNode *tmp = new ListNode(num);
	cur->next = tmp;
	cur = tmp;
    }
    return head->next;
}

