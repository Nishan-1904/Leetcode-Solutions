class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        stack<int> st;
        int maxarea = 0;
        for(int i=0;i<n;i++){
            while(!st.empty() && heights[st.top()] > heights[i]){
                int element = heights[st.top()];
                st.pop();
                int nse=i;
                int pse = st.empty()?-1:st.top();
                maxarea = max(element*(nse-pse-1),maxarea);
            }
            st.push(i);
        }
        while(!st.empty()){
            int nse=n;
            int element = heights[st.top()];
            st.pop(); 
            int pse=st.empty()?-1:st.top();
            maxarea = max(element*(nse-pse-1),maxarea);
        }
        return maxarea;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        int maxarea = 0;
        int n = matrix.size();
        if(n==0) return 0;
        int m = matrix[0].size();
        vector<int> psum(m,0);
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(matrix[i][j]=='0') psum[j]=0;
                if(matrix[i][j]=='1') psum[j]++;
            }
            maxarea = max(maxarea,largestRectangleArea(psum));
        }
        return maxarea;
    }
};