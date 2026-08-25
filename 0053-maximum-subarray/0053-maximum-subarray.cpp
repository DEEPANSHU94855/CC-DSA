class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n =nums.size();
        int ans=nums[0];
        int best =nums[0];
        int a,b;
        for (int i=1;i<n;i++){
            a=nums[i]+best;
            b=nums[i];
            best =max(a,b);
            ans = max(ans,best);
        }
        return ans;
    }
};
