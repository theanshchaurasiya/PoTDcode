class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int>st;

        for(int i=0;i<tokens.size();i++)
        {
            string x=tokens[i];

            if(x=="+"||x=="-"||x=="/"||x=="*")
            {
                int b=st.top();
                st.pop();
                int a=st.top();
                st.pop();

                if(x=="+")st.push(a+b);
                if(x=="-")st.push(a-b);
                if(x=="/")st.push(a/b);
                if(x=="*")st.push(a*b);
            }

            else st.push(stoi(x));
        }

        return st.top();
    }
};