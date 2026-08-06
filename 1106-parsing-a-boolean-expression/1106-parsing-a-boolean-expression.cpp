class Solution {
public:
    bool parseBoolExpr(string expression) {
        stack<char> st;
        for(char c : expression){
            if(c==',' || c=='(') continue;
            if(c!=')'){
                st.push(c);
            }else{
                bool hastrue = false;
                bool hasfalse = false;
                while(st.top()!='&' && st.top()!='|' && st.top()!='!'){
                    char val = st.top();
                    st.pop();
                    if(val=='t') hastrue = true;
                    else hasfalse = true;
                }
                char op = st.top();
                st.pop();
                bool result;
                if(op=='!'){
                    result = hasfalse;
                    result = !hastrue;
                }else if(op=='&'){
                    result = !hasfalse;
                }else{
                    result = hastrue;
                }
                st.push(result?'t':'f');
            }
        }
        return st.top()=='t';
    }
};