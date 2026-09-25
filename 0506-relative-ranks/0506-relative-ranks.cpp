class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {

        int n=score.size();
        vector<string> ans(n);
        priority_queue<pair<int,int>> pq;

        for(int i=0;i<n;i++){
            pq.push({score[i],i});
        }
        int rank=1;
        int index;
        for(rank=1;rank<=n;rank++){
            index=pq.top().second;
            pq.pop();
            if(rank==1){
                ans[index]="Gold Medal";
            }else if(rank==2){
                ans[index]="Silver Medal";
            }else if(rank==3){
                ans[index]="Bronze Medal";
            }else{
                ans[index]=to_string(rank);
            }
        }
        return ans;


        // using vector of pair approach adn time complexity is O(n log n) and space is O(n).

        // vector<pair<int,int>> v;
        // int n=score.size();
        // vector<string> ans(n);
        // for(int i=0;i<n;i++){
        //     v.push_back({score[i],i});
        // }
        // sort(v.begin(),v.end(),greater<>());
        // for(int rank=0;rank<n;rank++){
        //     int index=v[rank].second;
        //     if(rank==0){
        //         ans[index]="Gold Medal";
        //     }else if(rank==1){
        //         ans[index]="Silver Medal";
        //     }else if(rank==2){
        //         ans[index]="Bronze Medal";
        //     }else{
        //         ans[index]=to_string(rank+1);
        //     }
        // }
        // return ans;
    }
};