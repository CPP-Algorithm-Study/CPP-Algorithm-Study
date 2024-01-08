class Solution {
public:
    int search(vector<int>& nums, int target) {
        if(!binary_search(nums.begin(),nums.end(),target)) return -1; //없으면
        
        int a=lower_bound(nums.begin(),nums.end(),target)-nums.begin();// 인덱스 구하는 코드
        
        return a;
    }
};
