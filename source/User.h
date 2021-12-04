// Copyrights go to Modaser Abdelhamid and Hossam Elgendy from FCAI-CU.

#ifndef USER_H
#define USER_H
#include<cstring>
#include<iostream>
using namespace std;
class User
{
private:
    string name;
    int age;
    int id; // Make sure that the id is incremental. First id is 1, second is 2 and so on
    string password;
    string email;
    int numberOfBooks; // holds the number of books this user is assigned to
public:
    static int count;
    User();
    User(string name, int age, string email, string password);
    User(const User& user);
    bool operator==(const User& user);
    void setName(string name);
    string getName() const;
    void setPassword(string password);
    string getPassword() const;
    void setEmail(string email);
    string getEmail() const;
    void setAge(int age);
    int getAge() const;
    void setId(int id);
    int getId() const;
    void incrementNumOFBooks(); // increments the numberOfBooks by 1 when a book is assigned to this user.
    int getNumberOfBooks() const; // returns the numberOfBooks which are assigned to this user.
    void operator=(int par); // used to delete a user from a UserList.
    friend ostream& operator<<(ostream& output, const User& user);
    friend istream& operator>>(istream& input, User& user);
};
#endif // USER_H