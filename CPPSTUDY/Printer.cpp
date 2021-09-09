#include <iostream>
#include <queue>

using namespace std;

class Job {
    int id; //작업 아이디
    string user; //인쇄 요청을 한 사용자 이름
    int pages; //인쇄 페이지 수
    
    static int count;
    
public:
    Job(const string& u, int p) : user(u), pages(p), id(++count) {}
    
    friend ostream& operator<<(ostream& os, const Job& j) {
        os<<"id: "<<j.id<<", 사용자: "<<j.user<<", 페이지수: "<<j.pages<<"장";
        return os;
    }
};

int Job::count=0;

