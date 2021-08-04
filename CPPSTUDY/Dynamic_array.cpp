/*
 동적 크기 배열 구현.
 학교에서 학생 정보를 관리하는 간단한 응용 프로그램.
 */
#include <iostream>
#include <string>
#include <algorithm>
#include <sstream> //ostringstream 사용하는데 필요

using namespace std;

template <typename T>
class dynamic_array { //클래스 템플릿
    //주요 멤버 변수
    T* data;
    size_t n;
public:
    dynamic_array(int n) { //배열의 크기를 인자로 받는 생성자
        this->n=n;
        data=new T[n];
    }
    
    dynamic_array(const dynamic_array<T>& other) { //복사 생성자
        n=other.n;
        data=new T[n];
        
        for(int i=0; i<n; i++)
            data[i]=other[i];
    }
    
    T& operator[](int index) { //멤버 데이터에 직접 접근하기 위한 []연산자
        return data[index];
    }
    
    const T& operator[](int index) const {
        return data[index];
    }
    
    T& at(int index) { //멤버 데이터에 직접 접근하기 위한 at() 함수
        if(index<n)
            return data[index];
        throw "Index out of range";
    }
    
    size_t size() const { //배열의 크기를 반환하는 size() 멤버 함수
        return n;
    }
    
    ~dynamic_array() { //소멸자
        delete[] data; //메모리 릭 방지
    }
    
    //dynamic_array의 배열 원소를 순회할 때 사용할 반복자 관련 함수 정의
    T* begin() {return data;}
    const T* begin() const {return data;}
    T* end() {return data+n;}
    const T* end() const {return data+n;}
    
    //두 배열을 하나로 합치는 연산을 수행하는 + 연산자 함수 정의. friend로 선언
    friend dynamic_array<T> operator+(const dynamic_array<T>& arr1, dynamic_array<T>& arr2) {
        dynamic_array<T> result(arr1.size()+arr2.size());
        copy(arr1.begin(), arr1.end(), result.begin());
        copy(arr2.begin(), arr2.end(), result.begin()+arr1.size());
        
        return result;
    }
    
    //배열에 저장된 모든 데이터를 문자열로 반환하는 to_string() 멤버 함수.
    //데이터 구분을 위한 문자열 sep를 인자로 받고 sep의 기본값은 쉼표(", ")로 지정
    string to_string(const string& sep=", ") {
        if(n==0)
            return "";
        
        ostringstream os;
        os<<data[0];
        
        for(int i=1; i<n; i++)
            os<<sep<<data[i];
        
        return os.str();
    }
};

//학생 정보를 저장할 구조체 student 정의
//학생의 이름 name, 학생의 학급 정보 standard와 표준 출력 지원(<<)
struct student {
    string name;
    int standard;
};

ostream& operator<<(ostream& os, const student& s) {
    return (os<<"["<<s.name<<", "<<s.standard<<"]");
}

int main(void) {
    //dynamic_array를 사용하는 코드
    int nStudents;
    cout<<"1반 학생 수를 입력하세요 : ";
    cin>>nStudents;
    
    dynamic_array<student> class1(nStudents);
    for(int i=0; i<nStudents; i++) {
        string name;
        int standard;
        cout<<i+1<<"번째 학생 이름과 나이를 입력하세요 : ";
        cin>>name>>standard;
        class1[i]=student{name, standard};
    }
    
    //배열 크기보다 큰 인덱스의 학생에 접근할 때
    try {
        class1.at(nStudents)=student{"John", 8}; // 예외 발생
    }
    catch(...) {
        cout<<"예외 발생"<<endl;
    }
    
    //깊은 복사
    auto class2=class1;
    cout<<"1반을 복사하여 2반 생성 : "<<class2.to_string()<<endl;
    
    //두 학급을 합쳐서 새로운 큰 학급을 생성
    auto class3=class1+class2;
    cout<<"1반과 2반을 합쳐 3반 생성 : "<<class3.to_string()<<endl;
    
    return 0;
}

