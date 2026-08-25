class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n =nums.size();
        int flips=0;
        int h,l=0,size=0;
        for(h=0;h<n;h++){
            if(nums[h]==0){
                flips++;
            }
            while(flips>k){
                if(nums[l]==0){
                    flips--;
                }
                l++;
            }
            size = max(size,h-l+1);
        }
        return size;
    }
};