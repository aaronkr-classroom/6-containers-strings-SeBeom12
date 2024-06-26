//student_info.cpp
#include "Student_info.h"

bool compare(const Student_info& x, const Student_info& y)
{
    return x.name < y.name; // T/F
}


#include <iostream>
#include <string>


istream& read(istream& is, Student_info& s) {
    //학생의 이름, 중간고사 점수, 기말고사 점수 읽어 저장
    is >> s.name >> s.midterm >> s.final;
    read_hw(is, s.homework);
    return is;
}
istream& read(istream& is, Student_info& s){

    is >> s.name >> s.midterm >> s.final;

    read_hw(is, s.homework);
    return is;
    }

istream& read_hw(istream& in, vector<double>& hw) {
    if (in) {
        hw.clear();
        double x;
        while (in >> x) {
            hw.push_back(x);
        }
        in.clear();
        return in;
    }
}