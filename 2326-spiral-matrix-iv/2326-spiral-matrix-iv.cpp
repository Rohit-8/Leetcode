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
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        vector<vector<int>> ans(m, vector<int> (n, -1));
        
        int right = n - 1, left = 0, top = 0, down = m - 1;
        while(left <= right and top <= down){
            for(int i = left; i <= right; i++){
                if(!head) return ans;
                ans[top][i] = head -> val;
                head = head -> next;
            }
            
            if(!head) return ans;
            top ++;
            
            for(int i = top; i <= down; i++){
                if(!head) return ans;
                ans[i][right] = head -> val;
                head = head -> next;
            }
            if(!head) return ans;
            right --;
            
            for(int i = right; i >= left; i--){
                if(!head) return ans;
                ans[down][i] = head -> val;
                head = head -> next;
            }
            if(!head) return ans;
            down --;
            
            for(int i = down; i >= top; i--){
                if(!head) return ans;
                ans[i][left] = head -> val;
                head = head -> next;
            }
            if(!head) return ans;
            left ++;
            
        }
        
        return ans;
    }
};