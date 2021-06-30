#include <iostream>
#include <string>
#include <utility>
#include <vector>
#include <fstream>
#include <tuple>
#include <algorithm>
#include <optional>
using namespace std;

struct Person
{
    string surname;
    string name;
    string patronymic;

   friend ostream& operator<<(ostream& os, const Person& fio);
};
ostream& operator<<(ostream& os, const Person& fio)
{
    os << fio.surname << " " << fio.name << " " << fio.patronymic ? fio.patronymic : "";
    return os;
}
struct PhoneNumber
{
    int codeCountry;
    int codeCity;
    string num;
    string additionalNum;
    PhoneNumber() {}
    PhoneNumber(int cC, int cCity,const string num, string additional = ""): codeCountry(cC), codeCity(cCity),num(num),additionalNum(additional){}
    friend ostream& operator<<(ostream& os, const PhoneNumber& phone);
};
ostream& operator<<(ostream& os, const PhoneNumber& phone)
{
    os << "+" << phone.codeCountry << "(" << phone.codeCity << ")" << phone.num << " " << phone.additionalNum ? phone.additionalNum : "";
    return os;
}
class PhoneBook
{
private:
    vector <pair<Person, PhoneNumber>> _book;

public:
    void SortByName()
    {
        auto sortStr = ([](const pair<Person, PhoneNumber>& p1, const pair<Person, PhoneNumber>& p2)
        {
            return tie(p1.first.surname, p1.first.name, p1.first.patronymic) < tie(p2.first.surname, p2.first.name, p2.first.patronymic);
        });
        sort(_book.begin(), _book.end(), sortStr);
    }
    void SortByPhone()
    {
        auto sortPhone = ([](const pair<Person, PhoneNumber>& p1, const pair<Person, PhoneNumber>& p2)
            {
                return tie(p1.second.codeCountry, p1.second.codeCity, p1.second.num, p1.second.additionalNum)
                    < tie(p2.second.codeCountry, p2.second.codeCity, p2.second.num, p2.second.additionalNum);
            });
        sort(_book.begin(), _book.end(), sortPhone);
    }
    PhoneBook(ifstream &filename)
    { 
        if (filename.is_open())
        {
            string str;
            vector<string> words;
            string word = "";
            auto parser = ([&]()
                {
                    pair<Person, PhoneNumber> p = make_pair(Person(),PhoneNumber());
                    for (const char& symb : str)
                    {
                        if (symb == '(')
                        {
                            words.push_back(word);
                            word = "";
                            continue;
                        }
                        if (symb == ')')
                        {
                            words.push_back(word);
                            word = "";
                            continue;
                        }
                        if (symb == '+')
                        {
                            if (words.size() == 2)
                            {
                                words.push_back("");
                                word = "";
                            }
                            continue;
                        }
                        if (symb == ' ')
                        {
                            words.push_back(word);
                            word = "";
                        }
                        else
                        {
                            word += symb;
                        }
                    }
                    words.push_back(word);
                    p.first.surname = words[0];
                    p.first.name = words[1];
                    p.first.patronymic = words[2];
                    p.second.codeCountry = stoi(words[3]);
                    p.second.codeCity = stoi(words[4]);
                    p.second.num = words[5];
                    if (words.size() == 6)
                        p.second.additionalNum = "";
                    else
                        p.second.additionalNum = words[6];
                    word = "";
                    return p;
                });
            while (!filename.eof())
            {
                getline(filename, str);
                _book.push_back(parser());
                words.clear();
            }
        }
        filename.close();
    }
    friend ostream& operator<<(ostream& os, const PhoneBook& book);
    optional <PhoneNumber> GetPhoneNumber(const string &surname)
    {
        for (const auto &[name, number] : _book)
        {
            if (surname == name.surname)
                return number;
        }
        return nullopt;
    }
    void ChangePhoneNumber(Person p, PhoneNumber phone)
    {
        for (auto& [name, number] : _book)
        {
            if (tie(p.surname, p.name, p.patronymic) == tie(name.surname, name.name, name.patronymic))
            {
                number.codeCountry = phone.codeCountry;
                number.codeCity = phone.codeCity;
                number.num = phone.num;
                number.additionalNum = phone.additionalNum;
            }
        }
        return;
    }
};
ostream& operator<<(ostream& os, const PhoneBook& book)
{
    for (const auto contact : book._book)
    {
        os << contact.first << " " << contact.second << endl;
    }
    return os;
}
int main()
{
    ifstream file("C:\\Users\\dodon\\source\\repos\\ConsoleApplication8\\Debug\\asd.txt");
    PhoneBook book(file);
    cout << book;

    cout << "------SortByPhone-------" << endl;
    book.SortByPhone();
    cout << book;

    cout << "------SortByName--------" << endl;
    book.SortByName();
    cout << book;
    cout << "-----GetPhoneNumber-----" << endl;
    auto num = book.GetPhoneNumber("Morozov");
    if(num)
        cout << *num;
    num = book.GetPhoneNumber("Petrov");
    if (num)
        cout << *num;
    cout << "----ChangePhoneNumber----" << endl;
    book.ChangePhoneNumber(Person{ "Kotov", "Vasilii", "Eliseevich" }, PhoneNumber{ 7, 123, "15344458" });
    book.ChangePhoneNumber(Person{ "Morozov", "Vladimir", "Mikhailovich" }, PhoneNumber{ 16, 465, "9155448", "13" });
    cout << book;
    return 0;
}
