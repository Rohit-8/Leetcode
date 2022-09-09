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
    ListNode* reverse(ListNode* head){
        if(head == NULL) return head;
        ListNode* r = head;
        ListNode* t = NULL;
        
        while(r and r -> next){
            ListNode* x = r -> next;
            r -> next = t;
            t = r;
            r = x;
        }
        r -> next = t;
        return r;
    }
    ListNode* reverseList(ListNode* head) {
        return reverse(head);
    }
};