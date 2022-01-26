#include <iostream>
#include <string>
#include <string_view>
#include <algorithm>

using namespace std;

string_view TRUE = "O";
string_view FALSE = "X";

int main() {
    int num;
    string S;
    int bonus = 0;
    int score = 0;
    
    cin >> num;
    cin >> S;
    
    for(int i = 0; i < num; ++i) {
        if(S[i] == *(TRUE.data()))
            score += (i + 1) + bonus++;
        else
            bonus = 0;
    }
    
    cout << score << "\n";
}

