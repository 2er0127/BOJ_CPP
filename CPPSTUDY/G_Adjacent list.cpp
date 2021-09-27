// 각 노드에 인접한 노드를 리스트로 저장하기 때문에 인접 리스트라고 한다.
// 데이터 저장을 위해 벡터의 벡터를 사용하고, 안쪽 벡터의 크기는 해당 노드에 연결된 노드 개수와 같다.
// 인접 리스트에 의한 그래프 표현은 전체 에지 개수 E에 비례한 크기의 메모리를 사용한다.

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
    
    void addEdge(const city c1, const city c2, int dis) {
        cout<<"에지 추가: "<<c1<<"-"<<c2<<"="<<dis<<endl;
        
        auto n1=static_cast<int>(c1);
        auto n2=static_cast<int>(c2);
        data[n1].push_back({n2, dis});
        data[n2].push_back({n1, dis});
    }
    
    void removeEdge(const city c1, const city c2) {
        cout<<"에지 삭제: "<<c1<<"-"<<c2<<endl;
        
        auto n1=static_cast<int>(c1);
        auto n2=static_cast<int>(c2);
        remove_if(data[n1].begin(), data[n1].end(), [n2](const auto& pair) {
            return pair.first==n2;
        });
        remove_if(data[n2].begin(), data[n2].end(), [n1](const auto& pair) {
            return pair.first==n1;
        });
    }
};

int main() {
    graph g(6);
    
    g.addEdge(city::LONDON, city::MOSCOW, 2500);
    g.addEdge(city::LONDON, city::SEOUL, 9000);
    g.addEdge(city::LONDON, city::DUBAI, 5500);
    g.addEdge(city::SEOUL, city::MOSCOW, 6600);
    g.addEdge(city::SEOUL, city::SEATTLE, 8000);
    g.addEdge(city::SEOUL, city::DUBAI, 7000);
    g.addEdge(city::SEOUL, city::SYDNEY, 8000);
    g.addEdge(city::SEATTLE, city::MOSCOW, 8400);
    g.addEdge(city::SEATTLE, city::SYDNEY, 12000);
    g.addEdge(city::DUBAI, city::SYDNEY, 1200);

    g.addEdge(city::SEATTLE, city::LONDON, 8000);
    g.removeEdge(city::SEATTLE, city::LONDON);
    
    return 0;
}
