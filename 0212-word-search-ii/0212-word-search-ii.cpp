class Solution {
public:
    struct Node{
        Node *links[26];
        string word="";
        bool containsKey(char ch)
        {
            return links[ch-'a']!=NULL;
        }

    };
    
    Node *buildTrie(vector<string>&words)
    {
        Node *root=new Node();
        for(int i=0;i<words.size(); i++)
        {
            string temp=words[i];
            Node *curr = root;
            for(int j = 0; j<words[i].size(); j++)
            {
                char ch = temp[j];
                if(!curr->containsKey(ch))
                {
                    curr->links[ch-'a']=new Node();
                }
                curr=curr->links[ch-'a'];
            }
            curr->word=temp;
        }
        return root;
    }
    
    vector<vector<int>>dir={{0,1},{0,-1},{1,0},{-1,0}};
    void dfs(int row, int col , vector<vector<char>> &board, Node *root, vector<string> &ans)
    {
        // char ch=board[row][col];
        if(row<0 || row>=board.size() || col<0 || col>=board[0].size())
        return ;
        char ch=board[row][col];
        if( board[row][col]=='V'|| root->links[ch-'a']==NULL )return ;
        
        
        root=root->links[ch-'a'];
        if(root->word.size()>0)
        {
            ans.push_back(root->word);
            root->word="";
        }
        
        board[row][col]='V';
        for(int i=0; i<4; i++)
        {
            int nx=row+dir[i][0];
            int ny=col+dir[i][1];
            // if(nx>=0 && nx<board.size() && ny>=0 && board[0].size() && board[nx][ny]!='V')
            dfs(nx,ny,board, root,ans);
        }
        board[row][col]=ch;
        return ;
    }
    
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        Node *root=buildTrie(words);
        vector<string>ans;
        int n=board.size(),m=board[0].size();
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                dfs(i,j,board,root,ans);
            }
        }
        return ans;
    }
    
};