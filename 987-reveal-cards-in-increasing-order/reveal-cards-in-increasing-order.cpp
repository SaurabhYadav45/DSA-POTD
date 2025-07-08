class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        sort(deck.begin(), deck.end());
        deque<int>dq;
        for(int i=deck.size()-1; i>=0; i--){
            if(!dq.empty()){
                dq.push_front(dq.back());
                dq.pop_back();
            }
            dq.push_front(deck[i]);
        }
        return vector<int>(dq.begin(), dq.end());
    }
};



// class Solution {
// public:
//     vector<int> deckRevealedIncreasing(vector<int>& deck) {
//         sort(deck.begin(), deck.end());
//         queue<int>q;
//         vector<int>ans(deck.size());
//         for(int i=0; i< ans.size(); i++){
//             q.push(i);
//         }

//         for(int i=0; i<deck.size(); i++){
//             // 1.Reveal
//             ans[q.front()] = deck[i];
//             q.pop();

//             // 2.go to bottom
//             if(!q.empty()){
//                 q.push(q.front());
//                 q.pop();
//             }
//         }
//         return ans;
//     }
// };