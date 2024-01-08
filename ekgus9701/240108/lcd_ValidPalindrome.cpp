class Solution {
public:
    bool isPalindrome(string s) {
        string result="";
        for(int i=0;i<s.length();i++){
            if(isalnum(s[i])){
                result+=s[i];
            }
        }

        string result2="";

        for(int i=result.length()-1;i>=0;i--){
            result2+=result[i];
        }

        for(int i=0;i<result.length();i++){
            result[i]=tolower(result[i]);
            result2[i]=tolower(result2[i]);
        }
        

        cout<<result<<endl<<result2;

        if(result==result2) return true;
        return false;
    }
};
