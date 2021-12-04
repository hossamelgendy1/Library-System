// Copyrights go to Modaser Abdelhamid and Hossam Elgendy from FCAI-CU.

#include "BookList.h"

// copy constructor: used to copy a bookList to another bookList.
BookList::BookList(const BookList& anotherList)
{
	capacity = anotherList.capacity;
	booksCount = anotherList.booksCount;
	books = new Book[capacity];
	for (int i = 0; i < booksCount; i++)
	{
		books[i] = anotherList.books[i];
	}
}

// parameterized constructor: allocates books array with the given capacity.
BookList::BookList(int capacity)
{
	this->capacity = capacity;
	if (capacity <= 0)
	{
		cout << "ERROR: Invalid size.\n";
		exit(0);
	}
	books = new Book[capacity];
	booksCount = 0;
}

// this function adds a book to the end of the array.
// this function does not set the id of books in the bookList as the id is given when initializing the books array in the constructor
void BookList::addBook(Book book)
{
	if (booksCount < capacity) // to check if there is storage to add the book
	{
		books[booksCount].setTitle(book.getTitle());
		books[booksCount].setCategory(book.getCategory());
		books[booksCount].setISBN(book.getISBN());

		if (book.getHasAuthor()) //to check if the given book has an author
		{
			books[booksCount].setAuthor(*&(book.getAuthor()));
		}
		booksCount++;
	}
	else
	{
		cout << "*Can't add this book to the list (Reached full capacity)*\n";
	}	
}

// searches for a book by name 
// returns a pointer to the wanted book if found. If not, returns a nullptr.
Book* BookList::searchBook(string name)
{
	for (int i = 0; i < booksCount; i++)
	{
		if (books[i].getTitle() == name)
			return &books[i];
	}
	return nullptr;
}

// searches for a book by ID 
// returns a pointer to the wanted book if found. If not, returns a nullptr.
Book* BookList::searchBook(int id)
{
	for (int i = 0; i < booksCount; i++)
	{
		if (books[i].getId() == id)
			return &books[i];
	}
	return nullptr;
}

// deletes a book from the bookList
void BookList::deleteBook(int id)
{
	int deletedIndex = 0;
	for (int i = 0; i < booksCount; i++) //to iterate on all books
	{
		if (books[i].getId() == id) //to find the wanted user
		{
			books[i] = NULL; //this uses the overloaded operator= to set all members of the book to the default values.
			deletedIndex = i; //used to shift the books to the left if the deleted book isn't at the end of the array.
			break;
		}
	}
	if (deletedIndex < booksCount - 1) //the last index of the array = usersCount - 1
	{
		for (int i = deletedIndex; i < booksCount - 1; i++)
		{
			books[i] = books[i + 1];
			books[i].setId(books[i].getId() - 1); // To keep the ID incremental by 1 in the list, and avoid gaps when shifting all the books to the left.
		}
		books[booksCount - 1] = NULL;
	}
	booksCount--;
}

// returns the book with the highest rating
Book BookList::getTheHighestRatedBook()
{
	Book* highestRatedBook = &books[0]; // to start comparing
	for (int i = 1; i < booksCount; i++)
	{
		if (books[i].getAverageRating() > highestRatedBook->getAverageRating())
		{
			highestRatedBook = &books[i];
		}
	}
	return *highestRatedBook;
}

// returns a pointer to an array of all the books assignd to the given user
Book* BookList::getBooksForUser(User user)
{
	int numofbooks = user.getNumberOfBooks();
	Book* booksForUser = new Book[user.getNumberOfBooks()];
	int index = 0; //index of booksForUser array.
	for (int i = 0; i < booksCount; i++)
	{
		if (books[i].getAuthor() == user)
		{
			booksForUser[index++] = books[i];
		}
	}
	return booksForUser;
}

//returns the value of booksCount, used to know how many books are stored in the list.
int BookList::getBooksCount()
{
	return booksCount;
}

// this function overloads the []operator, to be able to access the books array using the userList object name.
Book& BookList::operator[](int position)
{
	if (position < 0 || position > capacity)
	{
		cout << "ERROR: subscript out of range.\n";
		exit(0);
	}
	else
	{
		return books[position];
	}

}

//destructor: frees the memory that was dinamically allocated in the constructor
BookList::~BookList()
{	
	delete[] books;
}

// this function overloads the "<<" operator, so that we can use the "cout" function to print the BookList.
ostream& operator<<(ostream& output, BookList& booklist)
{
	for (int i = 0; i < booklist.booksCount; i++)
	{
		output << booklist.books[i];
	}
	return output;
}
