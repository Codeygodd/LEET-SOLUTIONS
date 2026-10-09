class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int maxlen=0;
        for(int i=0;i<s.length();i++){
            string temp="";
            for(int j=i;j<s.length();j++){
                if (temp.find(s[j])!=string::npos){
                    break;
                }
                temp+=s[j];
                maxlen=max(maxlen,(int)temp.length());
            }
        }
        return maxlen;
    }
};