class Solution {
public:
    bool isMatch(string s, string p) {
        // Base Case
        if(p.length() == 0){
            if(s.length() == 0){
                return true;
            }
        }

        bool first_char_matched = false;
        if(s.length() > 0 && (s[0] == p[0] || p[0] == '.')){
            first_char_matched = true;
        }

        if(p.length() >= 2 && p[1] == '*'){
            bool not_take = isMatch(s, p.substr(2));
            bool take = first_char_matched && isMatch(s.substr(1), p);
            return not_take || take;
        }
        else{
            return first_char_matched && isMatch(s.substr(1), p.substr(1));
        }
    }
};