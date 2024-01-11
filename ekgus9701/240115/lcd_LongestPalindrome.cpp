class Solution {
public:
    int longestPalindrome(string s) {
        vector<char> v; //중복 제거할 배열
        vector<int> cnt;
        int ans=0;

        for(int i=0;i<s.length();i++){
            v.push_back(s[i]);
        }
        //중복 제거
        sort(v.begin(),v.end());
        v.erase(unique(v.begin(),v.end()),v.end());

        //각 character가 몇개 있는지 count
        for(int i=0;i<v.size();i++){
            cnt.push_back(count(s.begin(),s.end(),v[i]));
        }

        //각 character 짝수개있는민큼 *2해서 더하기
        for(int i=0;i<cnt.size();i++){
                ans+=cnt[i]/2*2;
                cnt[i]=cnt[i]%2;
        }

        //홀수개 있는 것이 있다면 한번 쓸 수 있으니까 1더해주기
         for(int i=0;i<cnt.size();i++){
            if(cnt[i]==1){
                ans++;
                break;
            }
            
        }

        return ans;


    }
};
