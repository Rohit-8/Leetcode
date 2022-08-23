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
    
    ListNode* reverseList(ListNode* h) {
        if(h == NULL or h->next == NULL) return h;
        ListNode* d = NULL;
        while(h){
            ListNode* tmp = h->next;
            h->next = d;
            d = h;
            h = tmp;
        }
        return d;
    }
    
    bool isPalindrome(ListNode* head) {
        if(head->next == NULL) return true;
        
        ListNode* slow = head;
        ListNode* fast = head;
        
        while(fast->next and fast->next->next){
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode* d = reverseList(slow->next);
        
        while(d){
            if(d->val!=head->val) return false;
            d = d->next;
            head = head->next;
        }
        return true;
    }
};