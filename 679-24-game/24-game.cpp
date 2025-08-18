class Solution {
public:
    double epsilon = 0.1;
    bool solve(vector<double>& nums){
        if(nums.size() == 1){
            return abs(24 - nums[0]) <= epsilon;
        }

        for(int i=0; i<nums.size(); i++){
            for(int j=0; j<nums.size(); j++){
                if(i == j) continue;

                vector<double>rem;
                for(int k=0; k<nums.size(); k++){
                    if(k != i && k != j){
                        rem.push_back(nums[k]);
                    }
                }

                double a = nums[i];
                double b = nums[j];
                vector<double>possible = {a+b, a-b, a*b};
                if(b != 0.0){
                    possible.push_back(a/b);
                }
                // if(a != 0.0){
                //     possible.push_back(b/a);
                // }

                for(double& num: possible){
                    rem.push_back(num);
                    if(solve(rem)){
                        return true;
                    }
                    rem.pop_back();
                }
            }
        }
        return false;
    }
    bool judgePoint24(vector<int>& cards) {
        vector<double> nums(cards.size(), 0);
        for(int i=0; i<cards.size(); i++){
            nums[i] = (1.0 * cards[i]);
        }
        return solve(nums);
    }
};