
#include <bits/stdc++.h>
using namespace std;
#define LL          long long
#define ULL         unsigned long long
#define PII         pair<int,int>
#define PII         pair<int,int>
#define PLL         pair<LL,LL>
#define SORT(x)     sort(x.begin(),x.end())
#define SORTD(x)    sort(x.rbegin(),x.rend())
#define TEST()      cout<<"Wroking"<<endl
#define READ(x)    freopen(x,"r",stdin)
#define WRITE(x)   freopen(x,"w",stdout)
#define Fast_Input  ios_base :: sync_with_stdio(false);  cin.tie(NULL);
const int mod=1e9+7,mx=1e6+5,lim=25;

int prec(char c) {
    if(c == '^')
        return 3;
    else if(c == '*' || c == '/')
        return 2;
    else if(c == '+' || c == '-')
        return 1;
    else
        return -1;
}

void infixToPostfix(string s) {

    stack<char> st;
    st.push('N');
    int l = s.length();

    string ns;

    for(int i = 0; i < l; i++) {

        // If the scanned character is an operand, add it to output string.
        if((s[i] >= 'a' && s[i] <= 'z')||(s[i] >= 'A' && s[i] <= 'Z'))
            ns+=s[i];

        // If the scanned character is an �(�, push it to the stack.
        else if(s[i] == '(')
            st.push('(');

        // If the scanned character is an �)�, pop and to output string from the stack
        // until an �(� is encountered.
        else if(s[i] == ')') {

            while(st.top() != 'N' && st.top() != '(') {
                char c = st.top();
                st.pop();
                ns += c;
            }

            if(st.top() == '(') {
                char c = st.top();
                st.pop();
            }

        }

        //If an operator is scanned
        else {
            while(st.top() != 'N' && prec(s[i]) <= prec(st.top())) {
                char c = st.top();
                st.pop();
                ns += c;
            }
            st.push(s[i]);
        }

    }

    //Pop all the remaining elements from the stack
    while(st.top() != 'N') {
        char c = st.top();
        st.pop();
        ns += c;
    }

    cout << ns << endl;

}

int main() {
    Fast_Input
    int t;
    cin>>t;
    while(t--) {
        string str;
        cin>>str;
        infixToPostfix(str);
    }
    return 0;
}
