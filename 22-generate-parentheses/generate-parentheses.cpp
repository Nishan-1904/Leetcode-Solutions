class Solution {
public:
    void generate(int open,int close,int n,string& output,vector<string>& ans){
        if(open==n && close==n){
            ans.push_back(output);
            return;
        }
        if(open<n){
            output.push_back('(');
            generate(open+1,close,n,output,ans);
            output.pop_back();
        }
        if(close<open){
            output.push_back(')');
            generate(open,close+1,n,output,ans);
            output.pop_back();
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string output;
        if(n==0) return ans;
        generate(0,0,n,output,ans);
        return ans;
    }
};