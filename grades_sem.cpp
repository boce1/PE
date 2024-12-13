/*
Да се дефинира производен клас за успех зададен с динамичен масив от оценките по всички дисциплини до момента
(дължината на масива зависи от курса – счита се, че за семестър броят на оценките е 5)
*/

/*
NOTE: If i give default parameter value to parameter of a constructor it give an error
grades_sem.cpp:89:19: error: call of overloaded 'GradeSemester()' is ambiguous
     GradeSemester g1;

The compiler cannot decide which constructor to use 
since the second constructor has a default argument (semester = 1) 
that allows it to also handle calls with no arguments.
*/

#include <iostream>
#include <memory>

#define GRADES_SEMESTER 5

class GradeSemester {
    private:
        int semester;
        double* grades;
        int size;
    public:
        GradeSemester() {
            semester = 1;
            size = GRADES_SEMESTER;
            grades = new double[size];
            for(int i = 0; i < size; i++) {
                grades[i] = 0;
            }    
        }

        GradeSemester(int semester) {
            if(semester < 1) {
                semester = 1;
            }
            this->semester = semester;
            size = GRADES_SEMESTER * semester;
            grades = new double[size];  
            for(int i = 0; i < size; i++) {
                grades[i] = 0;
            }   
        }

        GradeSemester(double* newGrades, const int size) {
            if(size % GRADES_SEMESTER == 0) {
                this->size = size;
                semester = this->size / GRADES_SEMESTER;
                grades = new double[this->size];
                for(int i = 0; i < this->size; i++) {
                    grades[i] = newGrades[i];
                }

            }
        }

        GradeSemester(const GradeSemester& other) {
            this->size = other.size;
            this->semester = other.semester;
            grades = new double[this->size];
            for(int i = 0; i < this->size; ++i) {
                grades[i] = other.grades[i];
            }
        }

        void changeSemester(int newSemester) {
            if(newSemester >= 1) {
                int newSize = newSemester * GRADES_SEMESTER;
                double* newPtr = new double[newSize];
                if(newPtr != nullptr) {
                    for(int i = 0; i < size; i++) {
                        newPtr[i] = grades[i];
                    }

                    for(int i = size; i < newSize; i++) {
                        newPtr[i] = 0;
                    }

                    delete[] grades;
                    grades = newPtr;
                    size = newSize;
                }

            }
        }

        void insertGrade(double grade, int index) {
            if(0 <= index && index < size && 2 <= grade <= 6) {
                grades[index] = grade;
            }
        }

        int getSize() const {
            return size;
        }

        ~GradeSemester() {
            delete[] grades;
        }

        double operator[](int index) {
            if(0 <= index && index < size) {
                return grades[index];
            }
            return 0;
        }

        GradeSemester& operator=(const GradeSemester& other) {
            *this = GradeSemester(other);
            
        }

        friend std::ostream& operator<<(std::ostream& os, const GradeSemester& gradeSem);
};

std::ostream& operator<<(std::ostream& os, const GradeSemester& gradeSem) {
    os << "{ ";
    for(int i = 0; i < gradeSem.size; i++) {
        os << gradeSem.grades[i] << " ";
        if((i + 1) % GRADES_SEMESTER == 0 && i != 0) {
            os << "| ";
        }
    }
    os << "}\n";
}

int main() {
    GradeSemester g1;
    for(int i = 0; i < g1.getSize(); ++i) {
        g1.insertGrade(3.0 + (double)i / 10, i);
    }
    std::cout << g1;

    double test[] = {2,6,4,5,4,3,6,6,3,2};
    GradeSemester g2(test, sizeof(test) / sizeof(test[0]));
    std::cout << g2;

    GradeSemester g3(g2);
    std::cout << g3;
    std::cout << g3[3] << std::endl;

    GradeSemester g4 = g1;
    std::cout << g4;
    return 0;
}