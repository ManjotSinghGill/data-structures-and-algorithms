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
    ListNode *deleteDuplicates(ListNode *head)
    {
        ListNode *temp = head;
        if (temp == nullptr || temp->next == nullptr)
            return temp;
        while (temp != nullptr && temp->next != nullptr)
        {
            if (temp->val == temp->next->val)
            {
                while (temp->next != nullptr && temp->val == temp->next->val)
                {
                    ListNode *nodeToBeDeleted = temp->next;
                    temp->next = temp->next->next;
                    delete nodeToBeDeleted;
                }
                temp = temp->next;
            }
            else
            {
                temp = temp->next;
            }
        }
        return head;
    }
};