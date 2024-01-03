class Solution {
public:
    bool isValid(string s) {

        stack<char> stk;

        for(int i=0;i<s.size();i++){
            if(s[i]=='('||s[i]=='['||s[i]=='{'){
                stk.push(s[i]);
                continue;
            }

            if(!stk.empty()){

                if(stk.top()=='('&&s[i]==')'){
                    stk.pop();
                }
                else if(stk.top()=='{'&&s[i]=='}'){
                    stk.pop();
                }
                else if(stk.top()=='['&&s[i]==']'){
                    stk.pop();
                }
                else{
                    return false;
                }
                
            }

            else{
                if(s[i]==']'||s[i]==')'||s[i]=='}') return false;
            }
        }

        if(!stk.empty()) return false;
        return true;

        
    }
};
