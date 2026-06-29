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
    ListNode* mergeNodes(ListNode* head) {
        ListNode *dummy = new ListNode(0);
        ListNode *new_tail = dummy;
        //ListNode* temp_1 = head;
        ListNode* temp_2 = head->next;
        int sum = 0;
        while (temp_2 != nullptr)
        {
            if (temp_2->val != 0)
            {
                sum += temp_2->val;
                temp_2 = temp_2->next;
            }
            else
            {
                if (!dummy->next)
                {
                    ListNode* new_node = new ListNode(sum);
                    dummy->next = new_node;
                    new_tail = new_node;
                }
                else
                {
                    ListNode* new_node = new ListNode(sum);
                    new_tail->next = new_node;
                    new_tail = new_node;
                }
                temp_2 = temp_2->next;
                sum = 0;
            }
        }

        ListNode *res = dummy->next;
        delete dummy;
        return res;
    }
};