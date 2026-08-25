// class Solution {
// public:
//     vector<vector<int>> subsets(vector<int>& nums) {
//         int n = nums.size();
//         vector<vector<int>> ans;

//         for (int mask = 0; mask < (1 << n); mask++) {
//             vector<int> subset;

//             for (int i = 0; i < n; i++) {
//                 if (mask & (1 << i)) {
//                     subset.push_back(nums[i]);
//                 }
//             }

//             ans.push_back(subset);
//         }
//         return ans;
//     }
// };

class Solution {
public:
    void solve(int start, vector<int>& nums, vector<int>& current, vector<vector<int>>& ans) {
        ans.push_back(current);

        for (int i = start; i < nums.size(); i++) {
            current.push_back(nums[i]);
            solve(i + 1, nums, current, ans);
            current.pop_back();
        }
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> current;

        solve(0, nums, current, ans);

        return ans;
    }
};