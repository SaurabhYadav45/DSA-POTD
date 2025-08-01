class Solution {
public:
    int minMutation(string startGene, string endGene, vector<string>& bank) {
        vector<char>chars = {'A', 'C', 'G', 'T'};
        unordered_set<string>st{bank.begin(), bank.end()};

        queue<pair<string, int>>q;
        q.push({startGene, 0});

        while(!q.empty()){
            string gene = q.front().first;
            int mutation_count = q.front().second;
            q.pop();

            if(gene == endGene) return mutation_count;

            for(int i=0; i<gene.length(); i++){
                char original = gene[i];
                for(char& ch: chars){
                    gene[i] = ch;
                    if(st.find(gene) != st.end()){
                        q.push({gene, mutation_count+1});
                        st.erase(gene);
                    }
                }
                gene[i] = original;
            }
        }
        return -1;
    }
};