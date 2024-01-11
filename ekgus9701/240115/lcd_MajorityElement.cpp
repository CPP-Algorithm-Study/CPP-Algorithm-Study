class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n=nums.size();
        map<int,int> m;
    
        for(int i=0;i<n;i++){
            m[nums[i]]++;
        }

         for(auto i=m.begin();i!=m.end();i++){
            if((i->second)>n/2){
                return i->first;
            }
        }

        return 0;
        
    }
};
