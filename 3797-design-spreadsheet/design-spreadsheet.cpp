class Spreadsheet {
public:
    unordered_map<string, int>mp;

    int getOperandValue(string&s){
        if(isdigit(s[0])){
            return stoi(s);
        }
        if(mp.find(s) != mp.end()){
            return mp[s];
        }
        return 0;
    }

    Spreadsheet(int rows) {
        
    }
    
    void setCell(string cell, int value) {
        mp[cell] = value;
    }
    
    void resetCell(string cell) {
        mp[cell] = 0;
    }
    
    int getValue(string formula) {
        auto pos = formula.find('+');
        string left = formula.substr(1, pos-1);
        string right = formula.substr(pos+1);
        int val1 = getOperandValue(left);
        int val2 = getOperandValue(right);
        return val1 +  val2;
    }
};

/**
 * Your Spreadsheet object will be instantiated and called as such:
 * Spreadsheet* obj = new Spreadsheet(rows);
 * obj->setCell(cell,value);
 * obj->resetCell(cell);
 * int param_3 = obj->getValue(formula);
 */