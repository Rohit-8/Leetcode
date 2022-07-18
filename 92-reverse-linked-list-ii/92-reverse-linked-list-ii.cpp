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
        
        while(head){
            ListNode* x = head->next;
            head->next = t;
            t = head;
            head = x;
        }
        return t;
    }
    
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(left == right) return head;
        
        ListNode* r = NULL;
        ListNode* l = NULL;
        if(left ==  1) l = head;
        
        ListNode* t;
        
        ListNode* x = new ListNode(0);
        x->next = head;
        t = x;
        for(int i = 1; i <= right; i++){
            if(i + 1 == left) x = head, l = head->next;
            if(i == right){
                r = head->next;
                head->next = NULL;
                break;
            }
            head = head->next;
        }
        x->next = reverseList(l);
        x = t;
        while(x and x->next){
            x = x->next;
        }
        x->next = r;
        return t->next;
    }
};