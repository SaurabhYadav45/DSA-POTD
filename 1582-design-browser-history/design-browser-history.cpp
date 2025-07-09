class BrowserHistory {
public:
    stack<string>backward, fwdStack;
    BrowserHistory(string homepage) {
        backward.push(homepage);
    }
    
    void visit(string url) {
        backward.push(url);
        while(!fwdStack.empty()){
            fwdStack.pop();
        }
    }
    
    string back(int steps) {
        while(backward.size() > 1 && steps > 0){
            fwdStack.push(backward.top());
            backward.pop();
            steps--;
        }
        return backward.top();
    }
    
    string forward(int steps) {
        while(!fwdStack.empty() && steps > 0){
            backward.push(fwdStack.top());
            fwdStack.pop();
            steps--;
        }
        return backward.top();
    }
};





// class BrowserHistory {
// public:
//     stack<string>browserStack, fwdStack;
//     BrowserHistory(string homepage) {
//         browserStack.push(homepage);
//     }
    
//     void visit(string url) {
//         while(!fwdStack.empty()){
//             fwdStack.pop();
//         }
//         browserStack.push(url);
//     }
    
//     string back(int steps) {
//         while(steps--){
//             if(browserStack.size() > 1){
//                 fwdStack.push(browserStack.top());
//                 browserStack.pop();
//             }
//             else{
//                 // only homepage present , back not possible
//                 break;
//             }
//         }
//         return browserStack.top();
//     }
    
//     string forward(int steps) {
//         while(steps--){
//             if(fwdStack.size() > 0){
//                 browserStack.push(fwdStack.top());
//                 fwdStack.pop();
//             }
//             else{
//                 break;
//             }
//         }
//         return browserStack.top();
//     }
// };

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */