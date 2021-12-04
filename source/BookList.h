// Copyrights go to Modaser Abdelhamid and Hossam Elgendy from FCAI-CU.

#include "Book.h"
class BookList
{
private:
    Book* books;
    int capacity;
    int booksCount;
public:
    BookList(const BookList& anotherList);
    BookList(int capacity);
    void addBook(Book book); // at the end of the array.
    Book* searchBook(string name);
    Book* searchBook(int id);
    void deleteBook(int id); //delete a book
    Book getTheHighestRatedBook();
    Book* getBooksForUser(User); // get all books of this author
    int getBooksCount(); // returns the booksCount
    Book& operator [ ] (int position);
    friend ostream& operator<<(ostream& output, BookList& booklist); //to display all books
    ~BookList();
};

