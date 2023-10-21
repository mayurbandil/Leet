
class Solution {
    public:
        bool backspaceCompare(string s, string t) {
                vector<char> sv;
                        for(auto i : s){
                                    if(i=='#' && !sv.empty()){
                                                    sv.pop_back();

                                                                }else if(i!='#'){
                                                                                sv.push_back(i);
                                                                                            }
                                                                                                    }
                                                                                                            s.clear();

                                                                                                                    for(auto i : sv){
                                                                                                                                s.push_back(i);

                                                                                                                                        }
                                                                                                                                                vector<char> sv1;
                                                                                                                                                        for(auto i : t){
                                                                                                                                                                    if(i=='#' && !sv1.empty()){
                                                                                                                                                                                    sv1.pop_back();

                                                                                                                                                                                                }else if(i!='#'){
                                                                                                                                                                                                                sv1.push_back(i);
                                                                                                                                                                                                                            }
                                                                                                                                                                                                                                    }
                                                                                                                                                                                                                                            t.clear();

                                                                                                                                                                                                                                                    for(auto i : sv1){
                                                                                                                                                                                                                                                                t.push_back(i);

                                                                                                                                                                                                                                                                        }

                                                                                                                                                                                                                                                                                return s==t;

                                                                                                                                                                                                                                                                                        
                                                                                                                                                                                                                                                                                            }
                                                                                                                                                                                                                                                                                            };



      

