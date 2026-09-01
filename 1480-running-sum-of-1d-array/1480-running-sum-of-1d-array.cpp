// class Solution {
// public:
//     vector<int> runningSum(vector<int>& nums) {
//         int n = nums.size();
//         vector<int> ans(n);

//         for (int i = 0; i < n; i++) {
//             int sum = 0;

//             for (int j = 0; j <= i; j++) {
//                 sum += nums[j];
//             }

//             ans[i] = sum;
//         }

//         return ans;
//     }
// };



class Solution {
public:
    vector<int> runningSum(vector<int>& nums){
        for (int i=1;i <nums.size();i++){
            nums[i]+=nums[i-1];
        }
        return nums;
    }
};