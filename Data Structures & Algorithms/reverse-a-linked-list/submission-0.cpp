/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    ListNode* reverseList(ListNode* head) 
    {
        ListNode* temp = nullptr;
        ListNode* mover = head;
        ListNode* temp2 = head; ;
        while(mover != nullptr)
        {
            mover = mover->next;
            temp2->next = temp;
            temp = temp2;
            temp2 = mover;
        }
        return temp;
    }
};
