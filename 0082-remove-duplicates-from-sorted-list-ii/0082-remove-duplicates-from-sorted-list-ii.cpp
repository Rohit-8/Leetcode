class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(head == NULL or head -> next == NULL)
            return head;
    
        while(head and head -> next and head -> val == head -> next ->val){
            while(head and head -> next and head -> val == head -> next -> val)
                head = head -> next;
            head = head -> next;
        }
        if(head == NULL) return head;
        ListNode* t = head;
        ListNode* prev = t;
        head = head -> next;
        while(head) {
            while(head and head -> next and head -> val == head -> next ->val){
                while(head and head -> next and head -> val == head -> next -> val)
                    head = head -> next;
                head = head -> next;
            }
            prev -> next = head;
            prev = prev -> next;
            if(head)
            head = head -> next;
        }
        return t;
    }
};
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