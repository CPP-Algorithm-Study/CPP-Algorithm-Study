class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<string> st;
        int ans=0;
        if(tokens.size()==1){
            return stoi(tokens[0]);
        }
        for(int i=0;i<tokens.size();i++){
            if(tokens[i]=="+"||tokens[i]=="-"||tokens[i]=="*"||tokens[i]=="/"){
            
                ans=0;
                int a=stoi(st.top());
                st.pop();
                int b=stoi(st.top());
                st.pop();
                if(tokens[i]=="+"){
                    ans+=a+b;
                    

                }
                else if(tokens[i]=="*"){
                    ans+=a*b;
                    
                }
                else if(tokens[i]=="-"){
                    ans+=b-a;
                    
                }
                else if(tokens[i]=="/"){
                    ans+=b/a;
                   
                }
                st.push(to_string(ans));
                

            }
            else{
                st.push(tokens[i]);
            }


        }
        return ans;
        
    }
};
