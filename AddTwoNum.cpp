/*
You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.

Example:
    Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
    Output: 7 -> 0 -> 8
    Explanation: 342 + 465 = 807.

*/

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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *l_pos1 = l1;
        ListNode *l_pos2 = l2;

        ListNode *l_pHead = new ListNode(0);
        ListNode *l_pos = l_pHead;

        char l_carry = 0;
        while (l_pos1 != NULL || l_pos2 != NULL)
        {
            int l_left = (l_pos1 != NULL) ? l_pos1->val : 0;
            int l_wright = (l_pos2 != NULL) ? l_pos2->val : 0;

            int l_sum = l_left + l_wright + l_carry;
            l_carry = (l_sum >= 10) ? 1 : 0;
            
            ListNode *l_pNode = new ListNode(l_sum % 10);
            l_pos->next = l_pNode;
            l_pos = l_pNode;

            l_pos1 = (l_pos1 != NULL) ? l_pos1->next : l_pos1;
            l_pos2 = (l_pos2 != NULL) ? l_pos2->next : l_pos2;
        }

        if (l_carry)
        {
            ListNode *l_pNode = new ListNode(1);
            l_pos->next = l_pNode;
            l_pos = l_pNode;
        }

        ListNode *l_pTemp = l_pHead;
        l_pHead = l_pHead->next;

        delete l_pTemp;

        return l_pHead;
    }
};