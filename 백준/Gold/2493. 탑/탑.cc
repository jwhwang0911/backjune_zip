#include<iostream>
#include<stack>

using namespace std;

int main(void) {
    int N;
    cin >> N;
    int *tops = new int [N];
    for(int i = 0; i < N; i++) {
        cin >> tops[i];
    }

    int *result = new int [N];
    stack<int> st;
    
    for(int i = 0; i < N; i++) {
        if(st.empty()) {
            st.push(i);
            result[i] = -1;
        } else{
            if(tops[st.top()] > tops[i]) {
                result[i] = st.top();
                st.push(i);
            } else {
                while(!st.empty() && tops[st.top()] < tops[i]) {
                    st.pop();
                }
                result[i] = st.empty() ? -1 : st.top();
                st.push(i);
            }
        }
    }

    for(int i = 0; i< N; i++) {
        cout << result[i] + 1 << " ";
    }
}