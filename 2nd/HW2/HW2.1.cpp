#include <iostream>
#include <string>
using namespace std;

class Person 
{
protected:
    string _name;
    const string _gender;
    unsigned short _age;
    float _weight;

public:
    Person (string name,const string &gender, unsigned short age, float weight) : 
    _name(name), _gender(gender), _age(age), _weight(weight) {}
    void setName (string name) 
    {
        _name = name;
    }
    void setAge (unsigned short age) 
    {
        _age = age;
    }
    void setWeight (float weight) 
    {
        _weight = weight;
    }
};

class Student : public Person
{
private:

    unsigned short _years;
public:
    static int count;
    Student (string name, string gender, unsigned short age, float weight, unsigned short years) :
    Person(name, gender, age, weight), _years(years)
    {
        count++;
    }
    ~Student()
    {
        count--;
    }
    void getStudent() const
    {
        cout << "Name:" << _name << endl;
        cout << "Gender:" << _gender << endl;
        cout << "Age:" << _age << endl;
        cout << "Weight:" << _weight << endl;
        cout << "Yeats:" << _years << endl;
    }
    void setYears(unsigned short years) 
    {
        _years = years;
    }
    void increaseYears()
    {
        _years++;
    }
    int getCount() const
    {
       return this->count;
    }
};
int Student::count = 0;
int main()
{
    Student a("Sasha","Man",23, 84.3, 4);
    Student b("Igor","Man",22, 70.7, 6);
    a.getStudent();
    cout << endl;
    b.getStudent();
    cout << a.getCount();
    return 0;

}