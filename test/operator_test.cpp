//
// Created by Vsion Chiou on 2021/2/28.
//

#include "operator_test.h"

#include <iostream>

using namespace std;

Time::Time() {
    hours = minutes = 0;
}
Time::Time(int h, int m) {
    hours = h;
    minutes = m;
}

Time Time::operator+(const Time &t) const {
    Time sum;
    sum.minutes = minutes+t.minutes;
    sum.hours = hours+t.hours+sum.minutes/60;
    sum.minutes%=60;
    return sum;
}
void Time::Show() const {
    cout<<hours<<" "<<minutes;
}
/*

int main(){
    Time a1(3,40);
    Time a2(2,30);
    Time total;
    total = a1+a2;
    total.Show();
    return 0;
}
*/
