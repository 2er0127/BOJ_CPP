#include <iostream>
#include <vector>

// 잔돈 500 100 50 10 5 1

using namespace std;

int main() {
    vector<int> coin = {500, 100, 50, 10, 5, 1}; // 배열로 정리
    int x;
    int result = 0;
    int count = 0;
    
    cin >> x;
    
    result = 1000 - x; // 받아야할 돈
    
    for(int i = 0; i < 6; i++) {
        for(;;) { // = while(true)
            if(result >= coin[i]) { // 받아야할 돈이 더 크면 잔돈을 빼고 count++
                result -= coin[i];
                count++;
            }
            else
                break;
        }
    }
    cout << count << endl;
}
