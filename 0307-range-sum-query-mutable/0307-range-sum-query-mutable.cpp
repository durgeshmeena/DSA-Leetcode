class NumArray {
public:
    int n;
    vector<int> arr;
    vector<int> t;
    
    NumArray(vector<int>& nums) {
        n = nums.size();
        arr = nums;
        t.resize(4*n);
        
        build(1, 0, n-1);
    }
    
    void update(int index, int val) {
        update(1, 0, n-1, index, val);
    }
    
    int sumRange(int left, int right) {
        return sum(1, 0, n-1, left, right);
    }
    
    
    void build(int v, int al, int ar){
        if(al==ar){
            t[v]=arr[al];
        }
        else{
            int am = (al+ar)/2;
            
            build(2*v, al, am);
            build(2*v+1, am+1, ar);
            
            t[v] = t[2*v] + t[2*v+1];
        }
    }
    
    void update(int v, int al, int ar, int i, int val){
        if(al==ar)
            t[v] = val;
        else{
            int am = (al+ar)/2;
            if(i<=am)
                update(2*v, al, am, i, val);
            else
                update(2*v+1, am+1, ar, i, val);
            
            t[v] = t[2*v] + t[2*v+1];
        }
    }
    
    int sum(int v, int al, int ar, int i, int j){
        if(i>j)
            return 0;
        
        if(i==al and j==ar){
            return t[v];
        }
        int am = (al+ar)/2;
        
        return sum(2*v, al, am, i, min(j, am)) + sum(2*v+1, am+1, ar, max(am+1, i), j);
    }
    
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */