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
class Solution
{
public:
    ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
    {
        ListNode *tempHead, *temp;

        if (!list1)
            return list2;
        if (!list2)
            return list1;
        if (!list1 && !list2)
            return temp;

        if (list1->val <= list2->val)
        {
            temp = list1;
            tempHead = list1;
            list1 = list1->next;
        }
        else
        {
            temp = list2;
            tempHead = list2;
            list2 = list2->next;
        }

        while (list1 != nullptr && list2 != nullptr)
        {
            if (list1->val <= list2->val)
            {
                temp->next = list1;
                list1 = list1->next;
                temp = temp->next;
            }
            else
            {
                temp->next = list2;
                list2 = list2->next;
                temp = temp->next;
            }
        }

        if (list1 != nullptr)
        {
            temp->next = list1;
        }

        if (list2 != nullptr)
        {
            temp->next = list2;
        }

        return tempHead;
    }
};