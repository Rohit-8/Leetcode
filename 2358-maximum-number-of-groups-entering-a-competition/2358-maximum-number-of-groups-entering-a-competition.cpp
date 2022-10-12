class Solution {
public:
    int maximumGroups(vector<int>& a) {
        
        return (-1 + sqrt(1 + 8 * a.size())) /  2;
    }
};