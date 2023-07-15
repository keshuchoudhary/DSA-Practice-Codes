#include<iostream>
using namespace std;
#include<stack>

bool isParanthesisBalanced(string str){
    stack<char> s;
    for(int i=0; i<str.size(); i++){
        if(str[i]==40 || str[i]==91 ||str[i]==123){
            s.push(str[i]);
        }
        else if(str[i]==41 || str[i]==93 || str[i]==125){
            if(str[i]==41 && s.top()==40){
                s.pop();
            }
            else if(str[i]==93 && s.top()==91){
                s.pop();
            }
            else if(str[i]==125 && s.top()==123){
                s.pop();
            }
            else{
                return false;
            }
        }
    }
    return s.empty();
}

int main(){
    string str;
    getline(cin, str);

    cout << isParanthesisBalanced(str) << endl;


}