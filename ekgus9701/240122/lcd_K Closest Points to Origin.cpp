#include<iostream>
class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<vector<int>> ans;
        
        vector<pair<long long, int>> ve;
        for(int i=0;i<points.size();i++){
            
            long long a=pow(points[i][0],2)+pow(points[i][1],2);
            ve.push_back({a,i});
        }

        sort(ve.begin(),ve.end());
        

        for(int i=0;i<k;i++){
            vector<int> temp;

            int num=ve[i].second;
            for(int j=0;j<2;j++){
                temp.push_back(points[num][j]);

            }
            ans.push_back(temp);
        }

        return ans;
    }
};
