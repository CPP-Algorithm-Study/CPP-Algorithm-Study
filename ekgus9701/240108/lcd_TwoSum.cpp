class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) { 
        vector<int> ans;
        for(int i=0;i<nums.size();i++){
            int sum=nums[i];
            for(int j=i+1;j<nums.size();j++){
                sum+=nums[j];
                if(sum==target){
                    ans.push_back(i);
                    ans.push_back(j);
                    return ans;
                }
                sum-=nums[j];
            }
        }

        return ans;
    }
};
