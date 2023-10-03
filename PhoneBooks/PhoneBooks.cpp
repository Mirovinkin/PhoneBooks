// PhoneBooks.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
#include <iostream>
#include <string>
#include <math.h>
#include <windows.h>
#include <locale.h>
#include <string.h>
#include <typeinfo>
#include <stdlib.h>
#include <stdio.h>
#include <algorithm>
//#include <cstdlib>
#include <ctype.h>
#include <vector>
#include <fstream>

using namespace std;
class User
{
private:
    string _name;
    string _landline;
    string _workNumber;
    string _mobilePhone;
    string _contactAdditionalInfo;

public:
    User() {};
    User(const string& Name,
        const string& Landline,
        const string& WorkNumber,
        const string& MobilePhone,
        const string& ContactAdditionalInfo) :
        _name(Name),
        _landline(Landline),
        _workNumber(WorkNumber),
        _mobilePhone(MobilePhone),
        _contactAdditionalInfo(ContactAdditionalInfo) {};
    ~User() 
    {
        //Можно уведомить об удалении
    };

    inline string GetName() {
        return _name;
    }

    inline void SetName(const string& Name) {
        _name = Name;
    }

    inline string GetLandline() {
        return _landline;
    }

    inline void SetLandline(const string& Landline) {
        _landline = Landline;
    }

    inline string GetWorkNumber() {
        return _workNumber;
    }

    inline void SetWorkNumber(const string& WorkNumber) {
        _workNumber = WorkNumber;
    }


    inline string GetMobilePhone() {
        return _mobilePhone;
    }

    inline void SetMobilePhone(const string& MobilePhone) {
        _mobilePhone = MobilePhone;
    }

    inline string GetContactAdditionalInfo() {
        return _contactAdditionalInfo;
    }

    inline void SetContactAdditionalInfo(const string& ContactAdditionalInfo) {
        _contactAdditionalInfo = ContactAdditionalInfo;
    }

    inline string PrintUser() {
        return "Имя:"+_name +
            "\nДомашний телефон - "+ _landline + 
            "\nРабочий телефон - "+_workNumber +
            "\nМобильный телефон - "+_mobilePhone +
            "\nДополнительная информация - "+_contactAdditionalInfo;
    }
};


class PhoneBook 
{
private:
    vector<User> users;

public:
    PhoneBook() {};//Можно добавлять абонентов и через конструктор, но я методами написал

    inline void AddUser(const User& user) {
        users.push_back(user);
    }
    inline void DeleteUser(const string& Name) {
        for (int i = 0; i < users.size(); i++)
        {
            if (users[i].GetName() == Name) {
                users.erase(users.begin() + i);
            }
        }
    }

    inline void FindUser(const string& UserName) {
        for (int i = 0; i < users.size(); i++)
        {
            if (users[i].GetName() == UserName) {
                cout << users[i].PrintUser();
            }
            else {
                cout << "Such User has not been added";
            }
        }
    }

    inline void PrintAllUsers() {
        if (users.size() > 0) {
            for (int i = 0; i < users.size(); i++)
            {
                cout << users[i].PrintUser() << endl <<
                    "///////////////////////////////////////////////////////////////////\n\n";
            }
        }
        else {
            cout << "Список контактов пуст";
        }
    }

    inline void FileSave(const string& FileName) {
        ofstream out;
        out.open(FileName + ".txt");
        if (out.is_open()) {
            for (int i = 0; i < users.size(); i++)
            {
                out << users[i].PrintUser();
            }
        }
        out.close();
        cout << "Все контакты записаны в файл " << FileName << ".txt";
    }

    inline void FileOpen(const string& FileName) {
        ifstream in;
        string line;
        in.open(FileName +".txt");
        if (in.is_open()) {
            while (getline(in,line))
            {
                cout << line << endl;
            }
        }

        in.close();
    }
};
int main()
{
    setlocale(LC_ALL, "RUS");
    /*vector<int> numbers;
    for (int i = 1; i <=10; i++)
    {
        numbers.push_back(i);
        cout << numbers[i-1];
    }
    numbers.erase(numbers.begin() + 5);
    cout << endl;

    for (int i = 1; i <= 9; i++)
    {
        cout << numbers[i - 1];
    }
    Экспериментировал с удалением элемента
    */

    PhoneBook phonebook;
    User user1;
    User user2;
    user1.SetName("Viktor");
    user1.SetLandline("89224901009");
    user1.SetMobilePhone("10125478536");
    user1.SetWorkNumber("2536415789");
    user1.SetContactAdditionalInfo("Balance: $400");

    user2.SetName("Daniel");
    user2.SetLandline("89224901009");
    user2.SetMobilePhone("10125478536");
    user2.SetWorkNumber("2536415789");
    user2.SetContactAdditionalInfo("Balance: $400");

    phonebook.AddUser(user1);
    phonebook.AddUser(user2);

    phonebook.FindUser("Viktor");
    cout << endl << endl;
    phonebook.PrintAllUsers();
    phonebook.DeleteUser("Daniel");
    phonebook.PrintAllUsers();

    phonebook.FileSave("Contacts");

}