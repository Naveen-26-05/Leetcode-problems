class Solution {
public:
    string reversePrefix(string word, char ch) {
        bool exist = false;
        string res = "";
        int i=0;
        for(i=0;i<word.size();i++){
            if(word[i]==ch){
                exist = true;
                res = word[i]+res;
                i++;
                break;
            }else{
                res = word[i]+res;
            }
        }
        if (exist){
            for(;i<word.size();i++){
                res = res + word[i];
            }
        }else return word;
        return res;
    }
};
