class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int n=nums.size();
        int s=accumulate(nums.begin(),nums.end(),0);
        for(int i=0,su=0;i<n;su+=nums[i],i++)
            if((s-su-nums[i])==su) return i;
        return -1;
    }
};