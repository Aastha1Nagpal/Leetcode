class Solution {
public:
    int lengthOfLastWord(string s) {
        int n = s.length();
        int i = n-1;
        string substring;
        while(i>=0 && s[i] == ' '){
                i--;
            }
        for(; i>=0; i--){
            if(s[i] != ' '){
                substring += s[i];
            }
            
            else break;
        }
        return substring.length();
    }
};