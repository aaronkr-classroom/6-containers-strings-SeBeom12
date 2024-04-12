// chp4ex0.cpp
// �߰����, �⸻���, �׸��� ���� ���� ��� �ް�
// ������ ��� ��� ������ ����ϱ�.
#include <algorithm>
#include <ios>
#include <fstream>
#include <iomanip>
#include <iostream> // cin/cout�� ����ϱ� ����
#include <stdexcept>
#include <string>
#include <vector>
#include "grade.h"
#include "student_info.h"

using namespace std;

// �߰����� ����, �⸻���� ����, ���� ���� ��������
// �л��� ���� ������ ����
double grade(double mt, double ft, double hw) {
    return 0.2 * mt + 0.4 * ft + 0.4 * hw;
}
// ������ ����


// ���� ������ �߾Ӱ��� ����

int main() {
    ifstream student_file("grades.txt");

    vector <Student_info> students;
    string::size_type maxlen = 0;

    while (read(student_file, record)) {
        maxlen = max(maxlen, record.name.size());// ���� ������ ����
        students.push_back(record);
    }
        //�л� ������ ���ĺ� ������ ����

        sort(students.begin(), students.end(), compare);

        for (vector<Student_info>::size_type i = 0;
            i != students.size(); ++i) {
            //�̸��� ������ ������ �����Ͽ� maxlen+1���� ���ڸ� ���
            cout << students[i].name
                << string(maxlen + 1) - students[i].name.size(), ' ');

                // ���� ������ ����� ����
                try {
                    double final_grade = grade(students[i]);
                    // ����� ���
                    streamsize prec = cout.precision(); // ���� cout precision
                    cout << "Final grade: " << setprecision(3)
                        << final_grade << setprecision(prec) << endl;
                }
                catch (domain_error e) {
                    cout << e.what();

                }
        }

        return 0;
    } // main ��
