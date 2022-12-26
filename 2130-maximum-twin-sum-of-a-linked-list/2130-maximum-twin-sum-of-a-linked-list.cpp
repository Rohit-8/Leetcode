class Solution {
public:
    ListNode* reverse(ListNode* head){
        ListNode* t = head;
        ListNode* r = NULL;
        while(t and t -> next){
            ListNode* temp = t -> next;
            t -> next = r;
            r = t;
            t = temp;
        }
        t -> next = r;
        return t;
    }
    
    int pairSum(ListNode* head) {
        ListNode* slow = head, *fast = head -> next;
        while(fast and fast -> next){
            slow = slow -> next;
            fast = fast -> next -> next;
        }
        fast = reverse(slow -> next);
        slow -> next = NULL;
        int ans = 0;
        
        while(fast){
            ans = max(ans, fast -> val + head -> val);
            fast = fast -> next;
            head = head -> next;
        }
        
        return ans;
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