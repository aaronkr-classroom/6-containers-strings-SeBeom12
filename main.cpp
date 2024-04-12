// chp4ex0.cpp
// 중간고사, 기말고사, 그리고 과제 점수 몇개를 받고
// 마지막 평균 결과 점수를 계산하기.
#include <algorithm>
#include <ios>
#include <fstream>
#include <iomanip>
#include <iostream> // cin/cout을 사용하기 위해
#include <stdexcept>
#include <string>
#include <vector>
#include "grade.h"
#include "student_info.h"

using namespace std;

// 중간시험 점수, 기말시험 점수, 종합 과제 점수에서
// 학생의 종합 점수를 가함
double grade(double mt, double ft, double hw) {
    return 0.2 * mt + 0.4 * ft + 0.4 * hw;
}
// 점수를 정렬


// 과제 점수의 중앙값을 구함

int main() {
    ifstream student_file("grades.txt");

    vector <Student_info> students;
    string::size_type maxlen = 0;

    while (read(student_file, record)) {
        maxlen = max(maxlen, record.name.size());// 과제 점수를 일음
        students.push_back(record);
    }
        //학생 정보를 알파벳 순으로 정렬

        sort(students.begin(), students.end(), compare);

        for (vector<Student_info>::size_type i = 0;
            i != students.size(); ++i) {
            //이름과 오른쪽 공백을 포함하여 maxlen+1개의 문자를 출력
            cout << students[i].name
                << string(maxlen + 1) - students[i].name.size(), ' ');

                // 종합 점수를 계산해 생성
                try {
                    double final_grade = grade(students[i]);
                    // 결과를 출력
                    streamsize prec = cout.precision(); // 지금 cout precision
                    cout << "Final grade: " << setprecision(3)
                        << final_grade << setprecision(prec) << endl;
                }
                catch (domain_error e) {
                    cout << e.what();

                }
        }

        return 0;
    } // main 끝
