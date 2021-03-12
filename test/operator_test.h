//
// Created by Vsion Chiou on 2021/2/28.
//

#ifndef STUDY_OPERATOR_TEST_H
#define STUDY_OPERATOR_TEST_H

#endif //STUDY_OPERATOR_TEST_H

class Time{
private:
    int hours;
    int minutes;
public:
    Time();
    Time(int h,int m);
    Time operator+(const Time &t) const;
    void Show() const;
};

