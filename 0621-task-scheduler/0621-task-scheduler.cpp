class Solution{
public:
    int leastInterval(vector<char>& tasks,int n){
        vector<int> freq(26,0);
        for(char task : tasks) {
            freq[task - 'A']++;
        }
        priority_queue<int> pq;
        for(int i=0;i<26;i++){
            if(freq[i]>0){
                pq.push(freq[i]);
            }
        }
        int time=0;
        while(!pq.empty()){
            vector<int> temp;
            int cycle=n+1;
            for(int i = 0; i < n + 1; i++){
                if(!pq.empty()){
                    int current=pq.top();
                    pq.pop();
                    current--;
                    if(current>0){
                        temp.push_back(current);
                    }
                    time++;
                }else{
                    if(temp.empty()){
                        break;
                    }
                    time++;
                }
            }
            for(int x :temp){
                pq.push(x);
            }
        }
        return time;
    }
};