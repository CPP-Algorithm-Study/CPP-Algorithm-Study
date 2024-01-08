class Solution {
public:

    int maxProfit(vector<int>& prices) {
        int max=-1;
        int maxPt,minPt;
        int min=1000000;
        vector<int> v;

        for(int i=0;i<prices.size();i++){
            

            if(max<prices[i]){
                max=prices[i];
                maxPt=i;
            }

            if(min>prices[i]){
                min=prices[i];
                minPt=i;
                //가장 작은게 새로 나타났으니까 앞에서 구했던 큰 것 초기화 
                maxPt=-1;
                max=-1;
            }

            if(minPt<maxPt){
              
                v.push_back(max-min);
            }
        }

            if(v.empty()){
                return 0;
            }

            sort(v.begin(),v.end());
            return v[v.size()-1];




        
    }
};
