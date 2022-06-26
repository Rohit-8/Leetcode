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
    
    ListNode* swapPairs(ListNode* head) {
        if(!head or head->next == NULL) return head;
        ListNode* t = head;
        head = head->next;
        ListNode* x;
        ListNode* pre = NULL;
        
        while(t and t->next){
            x = t->next;
            t->next = x ->next;
            x->next = t;
            if(pre) pre->next = x;
            pre = t;
            t = t->next;
        }
        return head;
    }
};