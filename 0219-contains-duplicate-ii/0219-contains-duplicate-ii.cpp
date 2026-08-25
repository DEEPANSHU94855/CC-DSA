// // class Solution {
// // public:
// //     bool containsNearbyDuplicate(vector<int>& nums, int k) {
// //         unordered_map<int,int> mp;
// //         for(int i=0;i<nums.size();i++){
// //             if(mp.count(nums[i])){
// //                 if((i-mp[nums[i]])<=k)
// //                     return true;
// //             }
// //             mp[nums[i]]=i;
// //         }
// //         return false;
// //     }
// // };

// class Solution {
// public:
//     bool containsNearbyDuplicate(vector<int>& nums, int k) {
//         int n = nums.size();

//         for (int i = 0; i < n; i++) {
//             for (int j = i + 1; j < n; j++) {
//                 if (nums[i] == nums[j] && j - i <= k) {
//                     return true;
//                 }
//             }
//         }

//         return false;
//     }
// };

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_set<int> st;

        for (int i = 0; i < nums.size(); i++) {
            if (st.count(nums[i])) {
                return true;
            }

            st.insert(nums[i]);

            if (st.size() > k) {
                st.erase(nums[i - k]);
            }
        }

        return false;
    }
};