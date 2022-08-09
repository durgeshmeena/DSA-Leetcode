class NumArray {
public:
    vector<int> segment;
    int n;
    NumArray(vector<int>& nums) {
        n = nums.size();
        segment.resize(4*n);
        build(nums, 1, 0, n-1);
    }
    
    int sumRange(int left, int right) {
        return sum(1, 0, n-1, left, right);
    }
    
    void build(vector<int>& a, int v, int l, int r){
        if(l == r)
            segment[v] = a[l];
        else{
            int mid = (l+r)/2;
            build(a, 2*v, l, mid);
            build(a, 2*v+1, mid+1, r);
            
            segment[v] = segment[2*v] + segment[2*v+1];
        }
    }
    
    int sum(int v, int tl, int tr, int l, int r){
        if(l > r) return 0;
        
        if(tl==l && tr==r)
            return segment[v];

        int mid = (tl+tr)/2;
        return sum(2*v, tl, mid, l, min(mid, r)) + sum(2*v+1, mid+1, tr, max(mid+1, l), r);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */