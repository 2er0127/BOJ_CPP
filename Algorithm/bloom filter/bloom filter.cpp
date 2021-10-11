#include <iostream>
#include <vector>

using namespace std;

class bloom_filter {
    vector<bool> data;
    int nBits;
    
    int hash(int num, int key) {
        switch(num) {
            case 0: return key%nBits;
            case 1: return (key/7)%nBits;
            case 2: return (key/11)%nBits;
        }
        
        return 0;
    }
    
public:
    bloom_filter(int n):nBits(n) {
        data=vector<bool>(nBits, false);
    }
}
