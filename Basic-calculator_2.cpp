// Time Complexity: O(n)
// Space Complexity: O(n), where n is the length of the input string.
// Did this code run successfully on LeetCode? Yes

// Approach:
// 1. We use a stack to store the intermediate results.
// 2. We iterate through the string character by character.
// 3. If we encounter a digit, we build the number until we hit a non-digit character.
// 4. When we hit a non-digit character, we check the previous sign and perform the corresponding operation.
// 5. We handle multiplication and division immediately by popping the top of the stack.
// 6. For addition and subtraction, we push the number onto the stack.
// 7. Finally, we sum up all the values in the stack to get the final result.


class Solution {
public:
    int calculate(string s) {
        stack<int> st;
        int i = 0; 
        char sign = '+';
        int temp = 0;
        while(i < s.size()){
            char c = s[i];
            if(isdigit(c)){
                temp = temp * 10 + (c - '0');
            }
            if((!isdigit(c) && c != ' ') || i == s.size() - 1){
                if(sign == '+'){
                    st.push(+temp);
                }else if(sign == '-'){
                    st.push(-temp);
                }else if(sign == '*' || sign == '/'){
                    int p = st.top();
                    st.pop();
                    if(sign == '*'){
                        st.push(+(p * temp));
                    }else{
                        st.push(+(p/temp));
                    }
                    
                }
                temp = 0; 
                sign = c;
                
            }
            i++;
            
        }
        int ans = 0;
        while(!st.empty()){
            ans += st.top();
            st.pop();
        }
        return ans;
    }
};