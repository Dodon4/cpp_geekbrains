#include <iostream>
#include <fstream>
#include "student.pb.h"
using namespace std;
namespace third {
    class IRepository {
        virtual void Open() = 0; // бинарная десериализация в файл
        virtual void Save() = 0; // бинарная сериализация в файл
    };
    class IMethods {
        virtual double GetAverageScore(const FullName& name) = 0;
        virtual string GetAllInfo(const FullName& name) = 0;
        virtual string GetAllInfo() = 0;
    };
    class StudentsGroup : public IRepository, public IMethods
    {
        vector<Student> sg;
        StudentsGroup()
        void Open() override
        {

        }
        double GetAverageScore(const FullName& name) override
        {
            for(auto grade: name.)
        }
    };
}
int main() {
    
    FullName *fioa = new FullName;
    fioa->set_name("asd");
    fioa->set_surname("bcd");
    Student *Alex = new Student;
    Alex->set_allocated_fio(fioa);
    Alex->add_grade(5);
    Alex->add_grade(3);
    Alex->add_grade(4);
    Alex->set_avg(4);
    StudentsGroup *group = new StudentsGroup;
    group->add_group();
}