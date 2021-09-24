#include <iostream>
#include <vector>

using namespace std;

enum class city:int {
    MOSCOW, LONDON, SEOUL, SEATTLE, DUBAI, SYDNEY
};

ostream& operator<<ostream& os, const city c {
    switch(c) {
        case city::LONDON:os<<"런던";
            return os;
        case city::MOSCOW:os<<"모스크바";
            return os;
        case city::SEOUL:os<<"서울";
            return os;
        case city::SEATTLE:os<<"시애틀";
            return os;
        case city::DUBAI:os<<"두바이";
            return os;
        case city::SYDNEY:os<<"시드니";
            return os;
        default:
            return os;
    }
}

struct graph {
    vector<vector<int>> data;
    graph(int n) {
        data.reserve(n);
        vector<int> row(n);
        fill(row.begin(), row.end(), -1);
        
        for(int i=0 i<n; i++) {
            data.push_back(row);
        }
    }
}
