// Copyrights go to Modaser Abdelhamid and Hossam Elgendy from FCAI-CU.

#include "Book.h"

// counter used to give each object an id, it gets incremented automatically in the class connstructors.
int Book::count = 1;

// Default constructor: gets called automatically when an object of the class is created given no paramiters.
Book::Book()
{
    this->id = count++;
    ratingsCount = 0;
    averageRating = 0.0;
    ratingsSum = 0.0;
    hasAuthor = false;
}

// parameterized constructor: gets called automatically when an object of the class is created given 3 paramiters.
Book::Book(string title, string isbn, string category)
{
    this->id = count++;
    ratingsCount = 0;
    averageRating = 0.0;
    ratingsSum = 0.0;
    hasAuthor = false;
    this->isbn = isbn;
    this->title = title;
    this->category = category;
}
// copy constructor: takes another object as an argument and assigns all member variables with the values of the other object.
Book::Book(const Book& book)
{
    this->id = book.id;
    this->isbn = book.isbn;
    this->title = book.title;
    this->category = book.category;
    this->averageRating = book.averageRating;
    this->ratingsCount = book.ratingsCount;
    this->ratingsSum = book.ratingsSum;
    this->author = book.author;
    this->hasAuthor = book.hasAuthor;
}

// sets the title of the book to the given parameter.
void Book::setTitle(string title)
{
    this->title = title;
}

// returns the title of the book.
string Book::getTitle() const
{
    return this->title;
}

// sets the ISBN of the book to the given parameter.
void Book::setISBN(string isbn)
{
    this->isbn = isbn;
}

// returns the ISBN of the book.
string Book::getISBN() const
{
    return this->isbn;
}

// sets the ID of the book to the given parameter.
void Book::setId(int id)
{
    this->id = id;
}

// returns the ID of the book.
int Book::getId() const
{
    return this->id;
}

// sets the category of the book to the given parameter.
void Book::setCategory(string category)
{
    this->category = category;
}

// returns the category of the book.
string Book::getCategory() const
{
    return this->category;
}

// sets the author of the book to the value of the given parameter.
void Book::setAuthor(User& user)
{
    this->author = user;
    user.incrementNumOFBooks();
    hasAuthor = true;
}

// returns the auther of the book.
User Book::getAuthor() const
{
    return this->author;
}

// returns the value of hasAuthor, to indicate whether the book has an author or not.
bool Book::getHasAuthor()
{
    return hasAuthor;
}

// computes the new averagre rating and updates the averageRating attribute with its value.
void Book::rateBook(int rating)
{
    ratingsSum += rating; //add the new rating to the previous sum.
    ratingsCount++; //increament the ratings count.
    this->averageRating = ratingsSum / ratingsCount; //calculates the average.
}

// returns the average rating of the book
double Book::getAverageRating() const
{
    return averageRating;
}

// this function overloads the "==" operator to check if two books are equal.
bool Book::operator==(const Book& book)
{
    return
        (this->title == book.title) && (this->isbn == book.isbn) &&
        (this->category == book.category) && (this->id == book.id) && (this->author == book.author);
}

// used to delete a Book from a BookList.
void Book::operator=(int par)
{
    if (par == NULL)
    {
        title = "";
        isbn = "";
        category = "";
        ratingsCount = 0;
        averageRating = 0.0;
        ratingsSum = 0.0;
        hasAuthor = false;
        author = NULL;
    }
}

// used to print the book in different format than the overloaded operator<<
// it prints the book info with only the author name not all the author info.
void Book::printWithAuthorName()
{
    cout << "========Book " << id << " info ========" << endl
        << "Title : " << title << endl
        << "ISBN: " << isbn << endl
        << "Id: " << id << endl
        << "Category: " << category << endl
        << "Avg Rating: " << averageRating << endl
        << "Author: " << author.getName() << endl << endl;
}

// this function overloads the "<<" operator, so that we can use the "cout" function to print the user attributes.
ostream& operator<<(ostream& output, const Book& book)
{
    output
        << "========Book " << book.id << " info ========" << endl
        << "Title : " << book.title << endl
        << "ISBN: " << book.isbn << endl
        << "Id: " << book.id << endl
        << "Category: " << book.category << endl
        << "Avg Rating: " << book.averageRating << endl
        << "================================================" << endl;
    if (book.hasAuthor) 
    {
        output
            << "======== Author info ========" << endl
            << "Name : " << book.author.getName() << endl
            << "Age: " << book.author.getAge() << endl
            << "Id: " << book.author.getId() << endl
            << "Email: " << book.author.getEmail() << endl
            << "==============================================" << endl;
    }
    return output;
}

// this function overloads the ">>" operator, so that we can use the "cin" function to insert the user attributes.
istream& operator>>(istream& input, Book& book)
{
        cout << " Enter the book information in this order\n ";
        cout << " Title   ISBN    Category (Space Seperated)\n ";
        input >> book.title >> book.isbn >> book.category;
        return input;
}