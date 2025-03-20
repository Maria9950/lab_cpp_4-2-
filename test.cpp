#include "CPP_1.h"


int main()
{
    setlocale(LC_CTYPE, "Russian");

    Teacher correctAnswers;

    std::vector<Student*> students = {
        new ExelentStudent("Vasya"),
        new GoodStudent("Petya"),
        new GoodStudent("Kate"),
        new BadStudent("Masha"),
        new ExelentStudent("Eva"),
        new BadStudent("Maksim")
    };

    for (Student* student : students) {
        student->countCorrectAnswers(correctAnswers);
    }

    for (Student* student : students) {
        student->printCorrectAnswers();
    }

    for (Student* student : students) {
        delete student;
    }

    return 0;
}