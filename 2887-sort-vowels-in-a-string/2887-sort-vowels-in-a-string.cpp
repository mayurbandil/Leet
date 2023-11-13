class Solution {
public:
    bool check(char c){
        if(c=='a' || c=='A'){
            return true;
        }else if(c=='e' || c=='E'){
            return true;
        }else if(c=='i' || c=='I'){
            return true;
        }else if(c=='o' || c=='O'){
            return true;
        }else if(c=='u' || c=='U'){
            return true;
        }

        return false;
    }
    string sortVowels(string s) {
        map<int, char> mapp1;
        string ans;
        string vowels;
        for(int i = 0; i < s.length(); i++){
            if(!check(s[i])){
               mapp1[i] = s[i];
            }else{
                vowels.push_back(s[i]);
            }
        }

        sort(vowels.begin(), vowels.end());
        int vc = 0;
        for(int i = 0; i < s.length(); i++){
           if(mapp1.find(i)!=mapp1.end()){
               ans.push_back(mapp1[i]);
           }else{
               ans.push_back(vowels[vc]);
               vc++;
           }
        }

        return ans;
    }
};