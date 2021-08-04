#include <iostream>
#include <fstream>
#include "student.pb.h"
#include <gtest/gtest.h>
using namespace std;

    class IRepository {
        virtual void Open() = 0; // бинарная десериализация в файл
        virtual void Save() = 0; // бинарная сериализация в файл
    };
    class IMethods {
        virtual double GetAverageScore(const FullName& name) = 0;
        virtual string GetAllInfo(const FullName& name) = 0;
        virtual string GetAllInfo() = 0;
    };
    class StudentGroup : public IRepository, public IMethods
    {
        StudentsGroup _group;
    public:
        StudentGroup(StudentsGroup group) { _group.CopyFrom(group); }
        StudentGroup() {};
        void Open() override
        {
            ifstream in("Group.bin", ios_base::binary);
            _group.ParseFromIstream(&in);
            cout << _group.mutable_group(0)->DebugString();
        }
        void Save() override
        {
            ofstream out("Group.bin", ios_base::binary);
            _group.SerializeToOstream(&out);
        }
        string GetAllInfo() override
        {
              return  _group.DebugString();
        }
        string GetAllInfo(const FullName& name) override
        {
            for (size_t i = 0; i < _group.group_size(); i++)
                if (_group.mutable_group(i)->mutable_fio()->name() == name.name() &&
                    _group.mutable_group(i)->mutable_fio()->surname() == name.surname())
                {
                     return  _group.mutable_group(i)->DebugString();
                }
            cout << "The student with the given name does not exist" << endl;
            return "-1";
        }
        double GetAverageScore(const FullName& name) override
        {
            for(size_t i = 0; i < _group.group_size(); i++)
                if (_group.mutable_group(i)->mutable_fio()->name() == name.name() &&
                    _group.mutable_group(i)->mutable_fio()->surname() == name.surname())
                {
                    return _group.mutable_group(i)->avg();
                }
            cout << "The student with the given name does not exist" << endl;
            return -1;
        }
    };
    TEST(Save, StudentGroup) {
        FullName fioa;
        fioa.set_name("asd");
        fioa.set_surname("bcd");
        FullName aasd;
        aasd.set_name("asd");
        aasd.set_surname("a");
        Student Alex;
        Alex.mutable_fio()->CopyFrom(fioa);
        Alex.add_grade(5);
        Alex.add_grade(3);
        Alex.add_grade(4);
        Alex.set_avg(4);
        StudentsGroup group;
        group.add_group();
        group.mutable_group(0)->CopyFrom(Alex);
        group.add_group();
        group.mutable_group(1)->CopyFrom(Alex);
        StudentGroup a(group);
        ASSERT_NO_THROW(a.Save());
    }
    TEST(Avg, StudentGroup) {
        StudentGroup a;
        ASSERT_NO_THROW(a.Open());
        FullName fioa;
        fioa.set_name("asd");
        fioa.set_surname("bcd");
        FullName aasd;
        aasd.set_name("asd");
        aasd.set_surname("a");
        ASSERT_LT(0, a.GetAverageScore(fioa));
        ASSERT_TRUE(-1 == a.GetAverageScore(aasd));
    }
    TEST(Info, StudentGroup) {
        StudentGroup a;
        ASSERT_NO_THROW(a.Open());
        FullName fioa;
        fioa.set_name("asd");
        fioa.set_surname("bcd");
        FullName aasd;
        aasd.set_name("asd");
        aasd.set_surname("a");
        ASSERT_NO_THROW(a.GetAllInfo());
        ASSERT_NO_THROW(a.GetAllInfo(fioa));
    }
int main() {
    
    testing::InitGoogleTest();
    return RUN_ALL_TESTS();

}