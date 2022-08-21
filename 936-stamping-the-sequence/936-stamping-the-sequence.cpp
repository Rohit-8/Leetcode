class Solution {
public:
    
    string st,tar;
    
    bool isvalid(int pos){
        int counh = 0;
        for(int i = 0; i < st.size(); i++){
            if(tar[i+pos]=='#')
                counh++;
            
            else if(tar[i + pos] != st[i])
                return false;
        }
        if(counh != st.size()){
            return true;
        }
        return false;
    }
    
    vector<int> movesToStamp(string stamp, string target){
        st = stamp;
        tar = target;
        vector<int> res;
        int lim = 10 * target.size();
        int tot = 0;
        while(res.size() < lim){
            int pr = res.size();
            for(int i = 0; i <= tar.size()-st.size(); i++){ 
                if(isvalid(i)){ 
                    cout<<i<<" ";
                    res.push_back(i);
                    for(int j = 0; j < st.size(); j++){
                        if(tar[j+i] != '#'){
                            tot++;
                            tar[i+j] = '#';
                        }
                    }
                }
            }
            if(pr == res.size()){
                break;
            }
        }
        
        reverse(res.begin(), res.end());
        if(tot == tar.size()){
            return res;
        }
        
        return {};
    }
};