// // // class Solution {
// // // public:
// // //     int largestRectangleArea(vector<int>& heights) {
// // //         int n=heights.size();
// // //         vector<int> width(n);
// // //         int Area=1;
// // //         vector<int> l(n),r(n);
// // //         stack<int> st;
// // //         for(int i=0;i<n;i++){
// // //             while(!st.empty() && heights[st.top()]>=heights[i]){
// // //                 st.pop();
// // //             }
// // //             if(st.empty())  l[i]=-1;
// // //             else l[i] = st.top();

// // //             st.push(i);
// // //         }
// // //         while(!st.empty())  st.pop();

// // //         for(int i=n-1;i>=0;i--){
// // //             while(!st.empty() && heights[st.top()]>=heights[i]){
// // //                 st.pop();
// // //             }
// // //             if(st.empty())  r[i]=n;
// // //             else r[i]= st.top();

// // //             st.push(i);
// // //         }
// // //         for(int i=0;i<n;i++){
// // //             int max;
// // //             width[i]=r[i]-l[i]-1;
// // //             max=heights[i]*width[i];
// // //             if (Area<max){
// // //                 Area = max;
// // //             }
// // //         }
// // //         return Area;
// // //     }
// // // };


// // class Solution {
// // public:
// //     int largestRectangleArea(vector<int>& heights) {
// //         int n = heights.size();
// //         int ans = 0;

// //         for (int i = 0; i < n; i++) {
// //             int minimum = INT_MAX;

// //             for (int j = i; j < n; j++) {
// //                 minimum = min(minimum, heights[j]);
// //                 ans = max(ans, minimum * (j - i + 1));
// //             }
// //         }

// //         return ans;
// //     }
// // };

// class Solution {
// public:
//     int largestRectangleArea(vector<int>& heights) {
//         int n = heights.size();
//         vector<int> left(n);
//         vector<int> right(n);
//         stack<int> st;

//         for (int i = 0; i < n; i++) {
//             while (!st.empty() && heights[st.top()] >= heights[i]) {
//                 st.pop();
//             }

//             left[i] = st.empty() ? -1 : st.top();
//             st.push(i);
//         }

//         while (!st.empty()) {
//             st.pop();
//         }

//         for (int i = n - 1; i >= 0; i--) {
//             while (!st.empty() && heights[st.top()] >= heights[i]) {
//                 st.pop();
//             }

//             right[i] = st.empty() ? n : st.top();
//             st.push(i);
//         }

//         int ans = 0;

//         for (int i = 0; i < n; i++) {
//             int width = right[i] - left[i] - 1;
//             ans = max(ans, heights[i] * width);
//         }

//         return ans;
//     }
// };

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> st;
        int n = heights.size();
        int ans = 0;

        for (int i = 0; i <= n; i++) {
            int current = i == n ? 0 : heights[i];

            while (!st.empty() && heights[st.top()] > current) {
                int height = heights[st.top()];
                st.pop();

                int left = st.empty() ? -1 : st.top();
                int width = i - left - 1;

                ans = max(ans, height * width);
            }

            st.push(i);
        }

        return ans;
    }
};