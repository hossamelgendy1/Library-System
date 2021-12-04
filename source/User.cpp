// Copyrights go to Modaser Abdelhamid and Hossam Elgendy from FCAI-CU.

#include "User.h"

// counter used to give each object an id, it gets incremented automatically in the class connstructors.
int User::count = 1;

// Default constructor: gets called automatically when an object of the class is created given no paramiters.
User::User()
{
    this->id = count++;
    this->name = "";
    this->numberOfBooks = 0;
}

// parameterized constructor: gets called automatically when an object of the class is created given 4 paramiters.
User::User(string name, int age, string email, string password)
{
    this->id = count++;
    this->name = name;
    this->age = age;
    this->email = email;
    this->password = password;
    numberOfBooks = 0;
}

// copy constructor: takes another object as an argument and assigns all member variables with the values of the other object.
User::User(const User& user)
{
    this->id = user.id;
    this->age = user.age;
    this->name = user.name;
    this->email = user.email;
    this->password = user.password;
    this->numberOfBooks = user.numberOfBooks;
}

// this function overloads the "==" operator to check if two users are equal.
bool User::operator==(const User& user)
{
    return (this->id == user.id) && (this->name == user.name) &&
        (this->age == user.age) && (this->email == user.email);
}

// sets the name of the user to the value of the given parameter.
void User::setName(string name)
{
    this->name = name;
}

// returns the name of the user.
string User::getName() const
{
    return this->name;
}

// sets the password of the user to the value of the given parameter.
void User::setPassword(string password)
{
    this->password = password;
}

// returns the password of the user.
string User::getPassword() const
{
    return this->password;
}

// sets the email of the user to the value of the given parameter.
void User::setEmail(string email)
{
    this->email = email;
}

// returns the email of the user.
string User::getEmail() const
{
    return this->email;
}

// sets the age of the user to the value of the given parameter.
void User::setAge(int age)
{
    if (age > 0)
        this->age = age;
}

// returns the age of the user.
int User::getAge() const
{
    return this->age;
}

// sets the id of the user to the value of the given parameter.
void User::setId(int id)
{
    this->id = id;
}

// returns the id of the user.
int User::getId() const
{
    return this->id;
}

// increments the numberOfBooks by 1 when a book is assigned to this user.
void User::incrementNumOFBooks()
{
    numberOfBooks++;
}

// returns the numberOfBooks which are assigned to this user.
int User::getNumberOfBooks() const
{
	return numberOfBooks;
}

// used to delete a user from a UserList.
void User::operator=(int par)
{
    if (par == NULL)
    {
        name = "";
        age = 0;
        password = "";
        email = "";
        numberOfBooks = 0;
    }
}

// this function overloads the "<<" operator, so that we can use the "cout" function to print the book attributes.
ostream& operator<<(ostream& output, const User& user)
{
    output
        << "========User " << user.id << " info ========" << endl
        << "Name : " << user.name << endl
        << "Age: " << user.age << endl
        << "Id: " << user.id << endl
        << "Email: " << user.email << endl
        << "==============================================" << endl;
    return output;
}

// this function overloads the ">>" operator, so that we can use the "cin" function to insert the book attributes.
istream& operator>>(istream& input, User& user)
{
        cout << " Enter the user information in this order \n";
        cout << "Name Age Email Password (Space Seperated) \n";
        input >> user.name >> user.age >> user.email >> user.password;
        return input;
}

