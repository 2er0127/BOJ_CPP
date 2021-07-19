#include <iostream>

using namespace std;

int main(void){
    int n;
    int a, b;
    
    scanf("%d\n", &n);
    
    for(int i=1; i<=n; i++){
        scanf("%d %d\n", &a, &b);
        printf("Case #%d: %d + %d = %d\n", i, a, b, a+b);
    }
}
