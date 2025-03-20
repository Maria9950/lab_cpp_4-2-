#include "CPP_1.h"


double Diskriminant(double a, double b, double c) {
	return (b * b - 4 * a * c);
}

void prov(double a, double b, double c, int& flag, double* pairs) {
    if (a == 0 && b == 0 && c == 0) {
        pairs[0] = pairs[1] = NAN;  // любое число
        flag = 1;
    }
    else if (a == 0 && c == 0 && b != 0) {
        pairs[0] = pairs[1] = 0;  // x = 0
        flag = 1;
    }
    else if (a == 0 && b == 0 && c != 0) {
        pairs[0] = pairs[1] = NAN;  // уравнение не существует
        flag = 1;
    }
    else if (b == 0 && c == 0 && a != 0) {
        pairs[0] = pairs[1] = 0;  // x = 0
        flag = 1;
    }
    else if (a == 0 && b != 0 && c != 0) {
        pairs[0] = pairs[1] = -c / b;
        flag = 1;
    }
    else if (b == 0 && c != 0 && a != 0) {
        pairs[0] = -sqrt(fabs(c / a));
        pairs[1] = sqrt(fabs(c / a));
        flag = 1;
    }
    else if (c == 0 && b != 0 && a != 0) {
        pairs[0] = 0;
        pairs[1] = -b / a;
        flag = 1;
    }
}

void dis0(double* pairs, double a, double b) {
    pairs[0] = pairs[1] = -b / (2 * a);
}

void dis_ok(double* pairs, double dis, double a, double b) {
    pairs[0] = (-b + sqrt(dis)) / (2 * a);
    pairs[1] = (-b - sqrt(dis)) / (2 * a);
}

void Result(double a, double b, double c, double* pairs) {
    int flag = 0;
    prov(a, b, c, flag, pairs);

    if (flag != 0) return;

    double dis = Diskriminant(a, b, c);
    if (dis > 0) {
        dis_ok(pairs, dis, a, b);
    }
    else if (dis == 0) {
        dis0(pairs, a, b);
    }
    else {
        pairs[0] = pairs[1] = NAN; // Нет решений
    }
}

Teacher::Teacher() {
        pairs = new double* [example];
        for (int i = 0; i < example; ++i) {
            pairs[i] = new double[2] { 0 };
        }
        readEquationsFromFile("inp.txt");
}

Teacher::~Teacher() {
    for (int i = 0; i < example; ++i) {
        delete[] pairs[i];
    }
    delete[] pairs;
}

void Teacher::readEquationsFromFile(const std::string& filename) {
    std::ifstream inputFile(filename);
    if (!inputFile.is_open()) {
        std::cerr << "Ошибка открытия файла " << filename << std::endl;
        return;
    }

    double a, b, c;
    for (int i = 0; i < example; ++i) {
        inputFile >> a >> b >> c;
        Result(a, b, c, pairs[i]);
    }
    inputFile.close();
}

Student::Student(std::string name) {
    this->name = name;
    pairs = new double*[example];
    for (int i = 0; i < example; ++i) {
        pairs[i] = new double[2]{0};
    }
}

Student::~Student() {
    for (int i = 0; i < example; ++i) {
        delete[] pairs[i];
    }
    delete[] pairs;
}

void Student::countCorrectAnswers(Teacher& teacher) {
    for (int i = 0; i < example; ++i) {
        if ((pairs[i][0] == teacher.pairs[i][0] && pairs[i][1] == teacher.pairs[i][1]) ||
            (pairs[i][0] == teacher.pairs[i][1] && pairs[i][1] == teacher.pairs[i][0])) {
            correctAnswersCount++;
        }
    }
}

void Student::printCorrectAnswers() {
    static bool headerPrinted = false;
    if (!headerPrinted) {
        std::cout << std::left << std::setw(10) << "Student"
            << " | " << std::right << std::setw(7) << "p/n"
            << std::endl << std::string(24, '-') << std::endl;
        headerPrinted = true;
    }

    std::cout << std::left << std::setw(10) << name
        << " | " << std::right << std::setw(5) << correctAnswersCount << "/" << example
        << std::endl;
}
    

ExelentStudent::ExelentStudent(std::string name) : Student(name) {
    readEquationsFromFile("inp.txt");
}

void ExelentStudent::readEquationsFromFile(const std::string& filename) {
    std::ifstream inputFile(filename);
    if (!inputFile.is_open()) {
        std::cerr << "Ошибка открытия файла " << filename << std::endl;
        return;
    }

    double a, b, c;
    for (int i = 0; i < example; ++i) {
        inputFile >> a >> b >> c;
        Result(a, b, c, pairs[i]);
    }
    inputFile.close();
}


GoodStudent::GoodStudent(std::string name) : Student(name) {
    readEquationsFromFile("inp.txt");
}

void GoodStudent::readEquationsFromFile(const std::string& filename) {
    std::ifstream inputFile(filename);
    if (!inputFile.is_open()) {
        std::cerr << "Ошибка открытия файла " << filename << std::endl;
        return;
    }

    double a, b, c;
    for (int i = 0; i < example; ++i) {
        inputFile >> a >> b >> c;
        if ((rand() % 10) < 5) { // Вероятность 40%
            Result(a, b, c, pairs[i]);
        }
        else {
            pairs[i][0] = pairs[i][1] = 0;
        }
    }
    inputFile.close();
}

BadStudent::BadStudent(std::string name) : Student(name) {
    readEquationsFromFile("inp.txt");
}

void BadStudent::readEquationsFromFile(const std::string& filename) {
    std::ifstream inputFile(filename);
    if (!inputFile.is_open()) {
        std::cerr << "Ошибка открытия файла " << filename << std::endl;
        return;
    }

    double a, b, c;
    for (int i = 0; i < example; ++i) {
        inputFile >> a >> b >> c;
        pairs[i][0] = pairs[i][1] = 0;
    }
    inputFile.close();
}