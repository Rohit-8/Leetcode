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
    ListNode* reverseList(ListNode* head) {
        if(head == NULL or head->next == NULL) return head;
        ListNode* t = NULL;
        
        while(head and head->next){
            ListNode* x = head->next;
            head->next = t;
            t = head;
            head = x;
        }
        head->next = t;
        return head;
    }
};