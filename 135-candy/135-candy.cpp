class Solution {
public:
    int candy(vector<int>& ratings) {
        
        vector<int> distribute(ratings.size(),1);
        int candy=0;   
        for(int i=0;i<ratings.size()-1;i++)
        {
            if(ratings[i+1]>ratings[i])
            {
                distribute[i+1]=distribute[i]+1;
            } 
        }
        for(int i=ratings.size()-1;i>0;i--)
        {
            if(ratings[i-1]>ratings[i])
            {
                if(distribute[i-1]<=distribute[i])
                    distribute[i-1]=distribute[i]+1;
            }
        }
        for(int i=0;i<ratings.size();i++)
            candy = candy+distribute[i];

        return candy;

    }
};