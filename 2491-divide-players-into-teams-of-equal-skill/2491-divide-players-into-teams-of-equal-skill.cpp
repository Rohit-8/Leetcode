class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        sort(skill.begin(), skill.end());
        long long ans = 0;
        
        int c = skill[0] + skill[skill.size() - 1];
        for(int i = 0, j = skill.size() -1; i < j; i++, j--){
            if(skill[i] + skill[j] != c)
                return -1;
            ans += (skill[i] * skill[j]);
        }
        
        return ans;
    }
};