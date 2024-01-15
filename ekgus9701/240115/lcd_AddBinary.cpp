/*
class Solution {
public:

    int binaryToDecimal(string a){

        long long num=0;
        long long two=1;
        for(long long i=a.length()-1;i>=0;i--){
            num+=(a[i]-'0')*two;
            two*=2;
        }

        return num;
        
    }

    string decimalToBinary(long long a){
        stack<long long> st;
        while(true){
            if(a==1) {
                st.push(a); break;
            }
            st.push(a%2);
            a/=2;
        }

        string s="";

        while(!st.empty()){
            s+=to_string(st.top());
            st.pop();
        }
        return s;
    }

    string addBinary(string a, string b) {

        if(a=="0"&&b=="0") return "0";
        long long numA=binaryToDecimal(a);
        long long numB=binaryToDecimal(b);

        long long ans=numA+numB;

        return decimalToBinary(ans);

        
    }
};*/

class Solution {
 public:
  string addBinary(string a, string b) {
    string ans;
    int carry = 0;
    int i = a.length() - 1;
    int j = b.length() - 1;

    while (i >= 0 || j >= 0 || carry) {
      if (i >= 0)
        carry += a[i--] - '0';
      if (j >= 0)
        carry += b[j--] - '0';
      ans += carry % 2 + '0';
      carry /= 2;
    }

    reverse(ans.begin(), ans.end());
    return ans;
  }
};
