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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {

        ListNode* temp1 = l1;
        ListNode* temp2 = l2;

        ListNode* l3 = new ListNode;
        ListNode* temp3 = l3;

        int carry = 0;

        while (temp1 != nullptr || temp2 != nullptr) {
            int sum = 0;

            if (temp1 != nullptr && temp2 != nullptr) {
                sum = temp1->val + temp2->val + carry;
                temp1 = temp1->next;
                temp2 = temp2->next;
            }

            else if (temp1 == nullptr && temp2 != nullptr) {
                sum = temp2->val + carry;
                temp2 = temp2->next;
            }

            else if (temp1 != nullptr && temp2 == nullptr) {
                sum = temp1->val + carry;
                temp1 = temp1->next;
            }

            carry = sum / 10;
            sum = sum % 10;

            ListNode* new_node = new ListNode(sum);
            temp3->next = new_node;
            temp3 = new_node;
        }

        if (temp1 == nullptr && temp2 == nullptr && carry != 0) {
            ListNode* n_node = new ListNode(carry);
            temp3->next = n_node;
        }

        return l3->next;
    }
};