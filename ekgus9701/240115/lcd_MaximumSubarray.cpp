class Solution {
public:

    long long dp[100000];

    long long max(long long a, int b){
        if(a>b) return a;
        else return (long long)b;
    }

    long long maxx(long long a, long long b){
        if(a>b) return a;
        else return b;
    }
    int maxSubArray(vector<int>& nums) {
        dp[0]=nums[0];

        
        long long maxnum=-INT_MAX;

        for(int i=1;i<nums.size();i++){

            dp[i]=max(dp[i-1]+nums[i],nums[i]);
            maxnum=maxx(dp[i],maxnum);
        }
        maxnum=max(dp[0],maxnum);

        return maxnum;
       
        
    }
};
