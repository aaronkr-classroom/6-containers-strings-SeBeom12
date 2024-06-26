
#include <vector>
#include<stdexcept>    
#include<algorithm>

using std::vector;
using std::domain_error;
using std::sort;


double median(vector<double> vec){
    // 과제 점수의 입력 유무를 확인
    typedef vector<double>::size_type vec_sz;
    vec_sz size = vec.size();
    if (size == 0) {
        throw domain_error("Median of empty vector");
    }

    sort(vec.begin(), vec.end());

    vec_sz mid = size / 2;
return size % 2 == 0
? (vec[mid] + vec[mid - 1]) / 2 : vec[mid];