//bfs로 풀려고했는데 시간초과..
class Solution {
public:
    vector<vector<int>> ans;
    set<vector<int>> sett;

    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size();i++){
            int j=i+1;
            int k=nums.size()-1;

            while(j<k){
                if(nums[i]+nums[j]+nums[k]==0){
                    sett.insert({nums[i],nums[j],nums[k]});
                    j++;
                    k--;
                }
                else if(nums[i]+nums[j]+nums[k]<0){
                    j++;
                }
                else{
                    k--;
                }

                

            }

        }

        for(auto iter:sett){
            ans.push_back(iter);
        }
        return ans;
    }
};
