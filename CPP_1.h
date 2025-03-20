#ifndef CPP_1_H
#define CPP_1_H

#include <iostream>
#include <fstream>
#include <cmath>
#include <string>
#include <iomanip>
#include <vector>

#define example 10 // Количество примеров

double Diskriminant(double a, double b, double c);
void prov(double a, double b, double c, int& flag, double* pairs);
void dis0(double* pairs, double a, double b);
void dis_ok(double* pairs, double dis, double a, double b);
void Result(double a, double b, double c, double* pairs);

class Teacher {
public:
    double** pairs;

    Teacher();
    ~Teacher();
    void readEquationsFromFile(const std::string& filename);
};

class Student {
public:
    double** pairs;
    int correctAnswersCount = 0;

    Student(std::string name);
    virtual ~Student();
    virtual void countCorrectAnswers(Teacher& teacher);
    void printCorrectAnswers();

protected:
    std::string name;
};

class ExelentStudent : public Student {
public:
    ExelentStudent(std::string name);
    void readEquationsFromFile(const std::string& filename);
};

class GoodStudent : public Student {
public:
    GoodStudent(std::string name);
    void readEquationsFromFile(const std::string& filename);
};


class BadStudent : public Student {
public:
    BadStudent(std::string name);
    void readEquationsFromFile(const std::string& filename);
};

#endif
