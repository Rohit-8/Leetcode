class Solution {
public:
    int inf = INT_MAX;
    vector<vector<string>> re;
    vector<vector<int>> prev; 
    string bg;
    
    void dfs(int in,vector<string> &nums,vector<string>& wordList){
        if(in==-1){
            vector<string> arr = nums; arr.push_back(bg);
            reverse(arr.begin(),arr.end());  re.push_back(arr); 
            return;
        }
        nums.push_back(wordList[in]);
        for(int i = 0; i<prev[in].size();++i){
            dfs(prev[in][i],nums,wordList);
        }
        nums.pop_back();
    }
    
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        bg = beginWord;   
        map<string,int> mp, ind;
        for(int i = 0; i<wordList.size();++i){ 
            mp[wordList[i]]=inf;
            ind[wordList[i]] = i;
        }
        prev = vector<vector<int>>(wordList.size());
        
        if(mp.find(endWord)==mp.end()) return {};
        
        queue<string> q; int level = 1; bool found = 0;
        q.push(beginWord); 
        
        while(!q.empty() && !found){
            int t = q.size();
            while(t--){
                string s = q.front(); q.pop();
                if(s==endWord){
                    found = 1; break;
                }
                for(int i = 0;i<s.size();++i){
                    for(int j = 0; j<26;++j){
                        if('a'+j==s[i]) continue;
                        string temp = s;  temp[i] = 'a'+j;
                        if(mp.find(temp)!=mp.end()){
                            if(mp[temp]>=level+1){
                                int in = -1;
                                if(s!=beginWord) in = ind[s];
                                if(mp[temp]==level+1){
                                    prev[ind[temp]].push_back(in);
                                    continue;
                                }
                                mp[temp] = level+1;
                                prev[ind[temp]].push_back(in);
                                q.push(temp);
                            }
                        }
                    }
                }
            }
            level++;
        }
        if(found){
            vector<string> nums;
            dfs(ind[endWord],nums,wordList);
        }
        return re;
    }
};