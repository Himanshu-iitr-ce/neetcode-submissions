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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) 
    {
        ListNode* ans;
        ListNode* ans_head;
        if(list1 == nullptr)
        {
            return list2;
        }else if(list2 == nullptr) return list1;
        if(list1->val <= list2 ->val)
        {
            ans = list1;
            ans_head= list1;
            list1= list1->next;
        }else 
        {
            ans = list2;
            ans_head = list2;
            list2 = list2->next;
        }
        while(list1 && list2)
        {
            if(list1->val <= list2->val)
            {
                ans->next = list1;
                list1 = list1->next;
                ans = ans->next;
            }
            else if(list1->val > list2->val)
            {
                ans -> next = list2;
                list2 = list2->next;
                ans =ans->next;
            }
        }
        if(list1 != nullptr || list2 != nullptr)
        {
            if(list1 == nullptr)
            {
                while(list2)
                {
                    ans->next = list2;
                    list2= list2->next;
                    ans = ans->next;
                }
            }
            else
            {
                while(list1)
                {
                    ans->next = list1;
                    list1 = list1->next;
                    ans = ans->next;
                }
            }
        }
        return ans_head;
    }
};
