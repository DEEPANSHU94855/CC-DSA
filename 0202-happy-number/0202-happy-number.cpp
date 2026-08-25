class Solution {
public:
    int sq_sum(int n){
        int sum=0;
        while(n>0){
            int digit=n%10;
            sum += digit*digit;
            n= n/10;
        }
        return sum;
    }
    bool isHappy(int n) {
        int slow=sq_sum(n);
        int fast=sq_sum(sq_sum(n));
        while(slow!=fast){
            slow = sq_sum(slow);
            fast= sq_sum(sq_sum(fast));
        }
        return slow == 1;
    }
};