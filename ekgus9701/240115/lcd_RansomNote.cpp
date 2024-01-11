class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        for(int i=0;i<magazine.size();i++){
            if(ransomNote!=""){
                if (ransomNote.find(magazine[i]) != string::npos) {
                    int index=ransomNote.find(magazine[i]);
                    ransomNote.erase(ransomNote.begin()+index,ransomNote.begin()+index+1);
                }
            }
        }

        if(ransomNote!="") return false;
        else return true;
    }
};
