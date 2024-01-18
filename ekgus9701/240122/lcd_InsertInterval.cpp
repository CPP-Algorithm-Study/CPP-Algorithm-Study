class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int x=newInterval[0];
        int y=newInterval[1];
        int a;
        int b;
        for(int i=0;i<intervals.size();i++){
            a=intervals[i][0];
            b=intervals[i][1];

            if(a>=x&&b<=y){
                intervals.erase(intervals.begin()+i);
                i--;
            }
            
            else if(x<=a&&a<=y&&a<=y&&y<=b){
                y=b;
                intervals.erase(intervals.begin()+i);
                i--;
            }
            else if(a<=x&&x<=b&&b<=y){
                x=a;
                intervals.erase(intervals.begin()+i);
                i--;
            }

            else if(a<=x&&y<=b){
                x=a;y=b;
                intervals.erase(intervals.begin()+i);
                i--;

            }


        }
        
        vector<int> v;
        v.push_back(x);
        v.push_back(y);

        intervals.push_back(v);

        sort(intervals.begin(),intervals.end());

        return intervals;

    }
};
