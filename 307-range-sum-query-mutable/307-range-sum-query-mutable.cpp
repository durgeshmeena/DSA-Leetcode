class NumArray {
public:
    
    int n;
    vector<int> t;
    vector<int> a;
    
    NumArray(vector<int>& nums) {
        n = nums.size();
        a = nums;
        t.resize(4*n);
        build(1, 0, n-1);
    }
    
    void update(int index, int val) {
        update(1, 0, n-1, index, val);
    }
    
    int sumRange(int left, int right) {
        return sum(1, 0, n-1, left, right);
    }
    
    void build(int v, int tl, int tr){
        if(tl == tr)
            t[v] = a[tl];
        else{
            int tm = (tl+tr)/2;
            build(2*v, tl, tm);
            build(2*v+1, tm+1, tr);
            
            t[v] = t[2*v] + t[2*v+1];
            
        }
    }
    
    void update(int v, int tl, int tr, int pos, int new_val){
        if(tl == tr)
            t[v] = new_val;
        else{
            int tm = (tl+tr)/2;
            if(pos <= tm)
                update(2*v, tl, tm, pos, new_val);
            else
                update(2*v+1, tm+1, tr, pos, new_val);
            t[v] = t[2*v] + t[2*v+1];
        }
    }
    
    
    int sum(int v, int tl, int tr, int l, int r){
        if(l > r)
            return 0;
        if(tl==l and tr==r)
            return t[v];
        
        int tm = (tl+tr)/2;
        
        return sum(2*v, tl, tm, l, min(tm, r)) + sum(2*v+1, tm+1, tr,  max(tm+1, l), r);
        
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */