#include <iostream>

using namespace std;

bool num[10001];

int d(int);
void self();

int main() {
    self();
    for(int i=1; i<10000; i++) {
        if(!num[i])
            cout<<i<<endl;
    }
}

int d(int n) {
    int temp;
    temp=n + n/1000 + n%1000/100 + n%100/10 + n%10;
    return temp;
}
void self() {
    int temp;
    num[1]=false;

    for(int index=0; index<10000; index++) {
        if(index<10000) {
            temp=d(index);
            if(temp<10000) {
                num[temp]=true;
            }
        }
    }
}
