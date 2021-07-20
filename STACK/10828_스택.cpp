#include <iostream>
#include <cstring>

using namespace std;
 
//push(data):스택에 데이터를 넣음. 스택의 맨 위(top)에 차지
//top():스택의 맨 위에 위치한 데이터에 접근. 스택이 비어있는 경우 런타임 에러
//pop():스택의 맨 위에 위치한 데이터를 빼냄. 스택이 비어있는 경우 런타임 에러
//size():스택에 현재 저장되어 있는 데이터의 갯수를 반환
//empty():스택이 비어있는지 확인. 비어있다면 true, 데이터가 남아있으면 false를 반환.
struct stack{
    int arr[10000];
    int ttop; //top에 해당하는 위치를 가리킴.
    
    void init(){
        ttop=-1;
    }
    
    void push(int data){
        arr[++ttop]=data;
    }
    
    bool empty(){
        return (ttop<0);
    }
    
    int pop(){
        if(empty()){
            return -1; //비어있다면 -1을 출력.
        }
        return arr[ttop--];
    }
    
    int size(){
        return ttop+1;
    }
    
    int top(){
        if(empty()){
            return -1; //비어있다면 -1을 출력.
        }
        return arr[ttop];
    }
};

int main(void){
    int n;
    
    cin>>n;
    
    stack s;
    s.init();
    for(; n--; ){
        string str;
        int num;
        cin>>str;
        if(str=="push"){
            cin>>num;
            s.push(num);
        }
        if(str=="pop"){
            cout<<s.pop()<<endl;
        }
        if(str=="size"){
            cout<<s.size()<<endl;
        }
        if(str=="empty"){
            cout<<s.empty()<<endl;
        }
        if(str=="top"){
            cout<<s.top()<<endl;
        }
    }
}
