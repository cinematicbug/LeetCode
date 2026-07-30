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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {

        ListNode* temp1 = list1;
        ListNode* temp2 = list2;
        ListNode* dummy = new ListNode;
        ListNode* current = dummy;
        int sm;

        while (temp1 != nullptr && temp2 != nullptr) {
            if (temp1->val <= temp2->val) {
                sm = temp1->val;
                temp1 = temp1->next;
            } else {
                sm = temp2->val;
                temp2 = temp2->next;
            }

            ListNode* n_node = new ListNode(sm);
            current->next = n_node;
            current = n_node;
        }

        while (temp1 != nullptr) {
            ListNode* n_node = new ListNode(temp1->val);
            current->next = n_node;
            current = n_node;
            temp1 = temp1->next;
        }

        while (temp2 != nullptr) {
            ListNode* n_node = new ListNode(temp2->val);
            current->next = n_node;
            current = n_node;
            temp2 = temp2->next;
        }

        return dummy->next;
    }
};