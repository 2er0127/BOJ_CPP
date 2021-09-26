#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

enum class city : int {
    MOSCOW, LONDON, SEOUL, SEATTLE, DUBAI, SYDNEY
};

ostream& operator<<(ostream& os, const city c) {
    switch (c) {
        case city::LONDON:os << "런던";
            return os;
        case city::MOSCOW:os << "모스크바";
            return os;
        case city::SEOUL:os << "서울";
            return os;
        case city::SEATTLE:os << "시애틀";
            return os;
        case city::DUBAI:os << "두바이";
            return os;
        case city::SYDNEY:os << "시드니";
            return os;
        default:
            return os;
    }
}

//실제 데이터를 저장할 graph 구조체 정의
struct graph {
    vector<vector<pair<int, int>>> data;
    
    graph(int n) {
        data=vector<vector<pair<int, int>>>(n, vector<pair<int, int>>());
    }
    
}
