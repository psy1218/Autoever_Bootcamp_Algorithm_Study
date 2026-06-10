#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <stack>

using namespace std;

int T,test_case;

int main(){
    while(cin>>T){
        test_case++;
        string s;
        char frt;
        int ans=1;
        stack<char> st;
        cin>>s;
        for(int i=0; i<T; i++){
            if(!st.empty()){
                frt=st.top();
            }
            if(s[i]=='(' || s[i]=='[' || s[i]=='{' || s[i]=='<'){
                st.push(s[i]);
            }
            else if(s[i]==')'){
                if(frt!='('){
                    ans=0;
                    break;
                }
                st.pop();
            }
            else if(s[i]==']'){
                if(frt!='['){
                    ans=0;
                    break;
                }
                st.pop();
            }
            else if(s[i]=='}'){
                if(frt!='{'){
                    ans=0;
                    break;
                }
                st.pop();
            }
            else if(s[i]=='>'){
                if(frt!='<'){
                    ans=0;
                    break;
                }
                st.pop();
            }
        }
        cout<<'#'<<test_case<<' '<<ans<<'\n';
    }
    return 0;
}