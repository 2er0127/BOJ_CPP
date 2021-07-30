#ifndef TIMEH
#define TIMEH

#include <iostream>

using namespace std;

class Time {
private:
    int hours;
    int mins;
    
public:
    Time();
    Time(int, int);
    void addHours(int);
    void addMins(int);
    Time operator+(Time&);
    void show();
    ~Time();
};

#endif /* time_hpp */
