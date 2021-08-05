#include <iostream>

using namespace std;

int main(void) {
    int num; //스위치 갯수
    scanf("%d\n", &num);

    int Switch[101];
    for(int index=1; index<=num; index++) { //1부터 시작
        cin>>Switch[index]; //스위치 상태 배열에 넣기
        //cout<<Switch[index]<<" ";
    }
    
    int stuNum; //학생 수
    scanf("%d\n", &stuNum);
    
    int gender, n; //성별, 번호
    for(int index=0; index<stuNum; index++) {
        cin>>gender>>n;
        //cout<<gender<<" "<<n;
        
        if(gender==1) { //남학생일 경우
            for(int i=1; i<=num; i++) {
                if(i%n==0)
                    Switch[i]=!Switch[i]; //스위치 상태 바꾸기
            }
        }
        else { //여학생일 경우
            Switch[n]=!Switch[n]; //n(번호, 중심)의 상태 바꾸기
            for(int y=1; Switch[n+y]==Switch[n-y]; y++) { //앞뒤가 같을 때까지 실행
                if(n+y>num||n-y<1) //Switch 범위를 벗어나면 멈추기
                    break;
                Switch[n+y]=!Switch[n+y];
                Switch[n-y]=!Switch[n-y];
            }
        }
    }
    
    for(int i=1; i<=num; i++) { //1부터 시작
        cout<<Switch[i]<<" ";
        if(i%20==0) //숫자가 20개일 경우
            cout<<"\n"; //줄바꿈
    }

    return 0;
}
