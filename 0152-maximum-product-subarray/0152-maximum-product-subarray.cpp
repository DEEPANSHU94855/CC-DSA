class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int best = nums[0];
        int worst = nums[0];
        int ans = nums[0];
        int a,b,c;
        for(int i=1;i<nums.size();i++){
            a=nums[i]*best;
            b=nums[i];
            c=nums[i]*worst;

            best=max(a,max(b,c));
            worst=min(a,min(b,c));
            ans=max(ans,best);
        }
        return ans;
    }
};