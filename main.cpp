#include <iostream>
#include <algorithm>
#include "homework3.h"

using namespace std;

StudentStruct *students = nullptr;
int numOfStudent = 0;

void printStudentList(){
   int idx = 0;
   for(idx = 0; idx < numOfStudent; ++idx){
        std::cout << "ID: " << students[idx].id 
                  << ",\t Name: " << students[idx].name
                  << ",\t Midterm: " << students[idx].record.midterm 
                  << ",\t Final: " << students[idx].record.final
                  << ",\t Total: " << students[idx].record.midterm + 
                                    students[idx].record.final << std::endl;
   }
   cout << "---------------------------" << endl;
}


// ID순으로 정렬하기 위한 Functor (SortByID) 정의 
struct SortByID{
    int operator()(const StudentStruct& a, const StudentStruct& b) const{
        return a.id < b.id;
    }
};


// 이름순으로 정렬하기 위한 Functor (SortByName) 정의 
/* TODO */

// 중간고사 성적 높은 순서로 정렬하기 위한 Functor (SortByMidterm) 정의 
/* TODO */

// 기말고사 성적 높은 순서로 정렬하기 위한 Functor (SortByFinal) 정의 
/* TODO */

// 중간+기말 성적 높은 순서로 정렬하기 위한 Functor (SortByTotal) 정의 
/* TODO */


void doTest1(){
    cout << "---------------------------" << endl;
    cout << "Test 1" << endl;

    printStudentList();

    // SortByID를 이용해 ID 순서로 정렬
    cout << "Sort by ID" << endl;
    std::sort(students, students + numOfStudent, SortByID{});
    printStudentList();

    // SortByName을 이용해 알파벳 순으로 이름 정렬 
    cout << "Sort by Name" << endl;
    /* TODO */
    for(int i = 0; i < numOfStudent - 1; i++){
        for(int j = 0; j < numOfStudent - i - 1; j++){
            if(students[j].name > students[j+1].name){
                std::swap(students[j], students[j+1]);
            }
        }
    }
    printStudentList();

    // SortByMidterm을 이용해 중간고사 성적 높은 순으로 정렬
    cout << "Sort by Midterm" << endl;
    /* TODO */
    std::sort(students, students + numOfStudent, [] (const StudentStruct& x, const StudentStruct& y) {
        return x.record.midterm > y.record.midterm;
    });
    printStudentList();

    // SortByFinal을 이용해 기말고사 성적 높은 순으로 정렬
    cout << "Sort by Final" << endl;
    /* TODO */
    std::sort(students, students + numOfStudent, [] (const StudentStruct& x, const StudentStruct& y) {
        return x.record.final > y.record.final;
    });
    printStudentList();

    // SortByTotal을 이용해 중간 + 기말 고사 높은 순으로 정렬
    cout << " Sort by Total" << endl;
    /* TODO */
    std::sort(students, students + numOfStudent, [] (const StudentStruct& x, const StudentStruct& y) {
        return (x.record.midterm + x.record.final) > (y.record.midterm + y.record.final);
    });
    printStudentList();
}


void doTest2(){
    cout << "---------------------------" << endl;
    cout << "Test 2" << endl;

    // StudentStruct의 ID 필드를 기준으로 알파벳 순으로 정렬하는 lambda 함수 정의 및 std::sort를 이용해 정렬하기
    cout << "Sort by ID" << endl;
    auto sortid = [](StudentStruct &x, StudentStruct &y) -> int {
        return x.id < y.id;
    };
    std::sort(students, students + numOfStudent, sortid);
    printStudentList();

    // StudentStruct의 name 필드를 기준으로 알파벳 순으로 정렬하는 lambda 함수 정의 및 std::sort를 이용해 정렬하기
    cout << "Sort by Name" << endl;
    /* TODO */
    auto sortname = [](StudentStruct &x, StudentStruct &y) -> int {
        return x.name < y.name;
    };
    std::sort(students, students + numOfStudent, sortname);
    printStudentList();

    // StudentStruct의 midterm 점수를 기준으로 높은순으로 정렬하는 lambda 함수 정의 및 std::sort를 이용해 정렬하기
    cout << "Sort by Midterm" << endl;
    auto sortmid = [](StudentStruct &x, StudentStruct &y) -> int {
        return x.record.midterm > y.record.midterm;
    };
    std::sort(students, students + numOfStudent, sortmid);
    /* TODO */
    printStudentList();


    // StudentStruct의 final 점수를 기준으로 높은순으로 정렬하는 lambda 함수 정의 및 std::sort를 이용해 정렬하기
    cout << "Sort by Final" << endl;
    auto sortfinal = [](StudentStruct &x, StudentStruct &y) -> int {
        return x.record.final > y.record.final;
    };
    std::sort(students, students + numOfStudent, sortfinal);
    /* TODO */
    printStudentList();

    // StudentStruct의 midterm+final 점수를 기준으로 알파벳 순으로 정렬하는 lambda 함수 정의 및 std::sort를 이용해 정렬하기
    cout << " Sort by Total" << endl;
    auto sorttotal = [](StudentStruct &x, StudentStruct &y) -> int {
        return (x.record.midterm + x.record.final) > (y.record.midterm + y.record.final);
    };
    std::sort(students, students + numOfStudent, sorttotal);
    /* TODO */
    printStudentList();

}

int main(int argc, char **argv) {
    const int MAX_STUDENTS = 100;
    students = new StudentStruct[MAX_STUDENTS];

    /* FIXME: parameter numOfStudent를 reference 타입으로 바꿔보기 */
    fillStudentRecord(students, &numOfStudent);


    if(argc == 2){
        int select = atoi(argv[1]);
        switch(select){
            case 1:
                doTest1();
                delete[] students;
                return 0;
            case 2:
                doTest2();
                delete[] students;
                return 0;
        }
    }

    doTest1();
    doTest2();


    delete[] students;
    return 0;
}