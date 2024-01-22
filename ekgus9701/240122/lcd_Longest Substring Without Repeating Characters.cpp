class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        map<char,int> m;
        vector<int> v;
        int cnt=0;

        if(s.length()==0) return 0;
        if(s.length()==1) return 1;
        for(int j=0;j<s.length();j++){
            for(int i=j;i<s.length();i++){
                m[s[i]]++;
                
                if(m[s[i]]>1) {
                    v.push_back(cnt);
                    cnt=0;
                    m.clear();
                    break;
                }
                else{
                    cnt++;
                }
            }

            v.push_back(cnt);
        }

        sort(v.begin(),v.end());

        return v[v.size()-1];
        
    }
};
