#include <iostream>

using namespace std;

int fac(int);

int main() {
    int n;
    scanf("%d\n", &n);
    
    printf("%d\n", fac(n));
}

int fac(int num) {
    if(num<=1) //범위 중요
        return 1;
    return num*fac(num-1);
}
