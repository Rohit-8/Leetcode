class NumArray {
public:
    
    vector<int>seg;
    int n;
    void build(int ind,int low,int high,vector<int>&nums){
        if(low==high){
            seg[ind]=nums[low];
            return; 
        }
        
        int mid=(low+high)/2;
        build(2*ind+1,low,mid,nums);
        build(2*ind+2,mid+1,high,nums);
        seg[ind]=seg[2*ind+1]+seg[2*ind+2];
        
    }
    NumArray(vector<int>& nums) {
        if(nums.size()>0){
            n=nums.size();
            seg.resize(4*n,0);
            build(0,0,n-1,nums);
        }
    }
    void updatenew(int ind,int low,int high,int index,int val){
        if(low==high){
            
            seg[ind]=val;
            return;
        }
        int mid=(low+high)/2;
        if(index>=low&&index<=mid)
          updatenew(2*ind+1,low,mid,index,val);    
        else
            updatenew(2*ind+2,mid+1,high,index,val);
        seg[ind]=seg[2*ind+1]+seg[2*ind+2];
    }
    void update(int index, int val) {
        if(n==0)
            return;
         updatenew(0,0,n-1,index,val);
    }
    int query(int ind,int low,int high,int left,int right){
        
        if(left>high||right<low)
            return 0;
        if(left<=low&&right>=high)
            return seg[ind];
        int mid=(low+high)/2;
        
        int leftsum=query(2*ind+1,low,mid,left,right);
        int rightsum=query(2*ind+2,mid+1,high,left,right);
            return leftsum+rightsum;
        
    }
    int sumRange(int left, int right) {
        if(n==0)
            return 0;
        
        return query(0,0,n-1,left,right);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */