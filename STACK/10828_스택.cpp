#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main() {
    int num, n;
    string str;
    stack<int> s;
    
    cin >> num;
    
    for(int i = 0; i < num; i++) {
        cin >> str;
        if(str == "push") {
            cin >> n;
            s.push(n);
        }
        else if(str == "pop") {
            if(s.empty())
                cout << -1 <<"\n";
            else {
                cout << s.top() << "\n";
                s.pop();
            }
        }
        else if(str == "size") {
            cout << s.size() << "\n";
        }
        else if(str == "empty") {
            if(s.empty())
                cout << 1 << "\n";
            else
                cout << 0 <<"\n";
        }
        else if(str == "top") {
            if(s.empty())
                cout << -1 << "\n";
            else
                cout << s.top() << "\n";
        }
    }
}

