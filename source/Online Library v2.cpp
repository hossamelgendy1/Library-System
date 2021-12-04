/*
This program was developed by modaser abdelhamid and hossam elgendy from FCAI-CU.
The program is a demo for an online library system that contains data about books and authers.
*/


#include "BookList.h"
#include "UserList.h"

void mainMenu() {
    cout << "Select one of the following choices:\n"
        << "1- Books Menu\n"
        << "2- Users Menu\n"
        << "3- Exit\n";
}

void usersMenu() {
    cout << "USERS MENU\n"
        << "1- Create a USER and add it to the list\n"
        << "2- Search for a User\n"
        << "3- Display all users\n"
        << "4- Back to the main Menu\n";
}

void userSearchMenu() {
    cout << "SEARCH FOR A USER\n"
        << "1- Search by name\n"
        << "2- Search by id\n"
        << "3- Return to Users Menu\n";
}

void searchedUserMenu() {
    cout << "1- Delete user\n"
        << "2- Return to Users Menu\n";
}

void booksMenu() {
    cout << "BOOKS MENU\n"
        << "1- Create a book and add it to the list\n"
        << "2- Search for a book\n"
        << "3- Display all books (with book rating)\n"
        << "4- Get the highest rating book\n"
        << "5- Get all books of a user\n"
        << "6- Copy the current Book List to a new Book List and switch to it\n"
        << "7- Back to the main menu\n";
}

void bookSearchMenu() {
    cout << "SEARCH FOR A BOOK\n"
        << "1- Search by name\n"
        << "2- Search by id\n"
        << "3- Return to Books Menu\n";
}

void searchedBookMenu() {
    cout << "1- Update author\n"
        << "2- Update name\n"
        << "3- Update category\n"
        << "4- Delete Book\n"
        << "5- Rate book\n"
        << "6- Get back to Books Menu\n";
}

void invalidChoice() {
    cout << "ERROR: Invalid choice.\n";
}

int main()
{
    UserList* userList1 = new UserList();
    int mainMenuChoice = 0;
    while (mainMenuChoice != 3)
    {
        mainMenu();
        cin >> mainMenuChoice;
        switch (mainMenuChoice)
        {
        case 1:
        {
            int bookListSize;
            cout << "How many books will be added?\n";
            cin >> bookListSize;
            BookList bookList1(bookListSize);
            int bookMenuChoice = 0;
            while (bookMenuChoice != 7)
            {
                booksMenu();
                cin >> bookMenuChoice;
                switch (bookMenuChoice)
                {
                case 1:
                {
                    Book book;
                    cin >> book;
                    int authorToBookChoice = 0;
                    while (authorToBookChoice != 2)
                    {
                        cout << "1- Assign author\n" << "2- continue\n";
                        cin >> authorToBookChoice;
                        switch (authorToBookChoice)
                        {
                        case 1:
                        {
                            int authorID;
                            cout << "Enter author (user) id:\n";
                            cin >> authorID;
                            User* authorToAssign;
                            authorToAssign = userList1->searchUser(authorID);
                            if (authorToAssign == nullptr)
                            {
                                cout << "No author found with id = " << authorID << endl;
                                break;
                            }
                            book.setAuthor(*authorToAssign);
                            authorToBookChoice = 2; // to break out of the while loop.
                            break;
                        }
                        case 2:
                            break;
                        default:
                            invalidChoice();
                            break;
                        }
                    }
                    bookList1.addBook(book);
                    break;
                }
                case 2:
                {
                    int bookSearchMenuChoice = 0;
                    while (bookSearchMenuChoice != 3)
                    {
                        bookSearchMenu();
                        cin >> bookSearchMenuChoice;
                        switch (bookSearchMenuChoice)
                        {
                        case 1:
                        {
                            string searchedBookName;
                            cout << "Enter Name\n";
                            cin >> searchedBookName;
                            Book* searchedBook = bookList1.searchBook(searchedBookName);
                            if (searchedBook == nullptr) {
                                cout << "Book not found!\n";
                                break;
                            }
                            searchedBook->printWithAuthorName();
                            int searchedBookMenuChoice = 0;
                            while (searchedBookMenuChoice != 6)
                            {
                                searchedBookMenu();
                                cin >> searchedBookMenuChoice;
                                switch (searchedBookMenuChoice)
                                {
                                case 1:
                                {
                                    int authorID;
                                    cout << "Enter author (user) id:\n";
                                    cin >> authorID;
                                    User* authorToAssign;
                                    authorToAssign = userList1->searchUser(authorID);
                                    if (authorToAssign == nullptr)
                                    {
                                        cout << "No author found with id = " << authorID << endl;
                                        break;
                                    }
                                    searchedBook->setAuthor(*authorToAssign);
                                    break;
                                }
                                case 2:
                                {
                                    string newBookTitle;
                                    cout << "Enter new Name:\n";
                                    cin >> newBookTitle;
                                    cout << endl;
                                    searchedBook->setTitle(newBookTitle);
                                    break;
                                }
                                case 3:
                                {
                                    string newBookCategory;
                                    cout << "Enter new Category:\n";
                                    cin >> newBookCategory;
                                    cout << endl;
                                    searchedBook->setCategory(newBookCategory);
                                    break;
                                }
                                case 4:
                                {
                                    bookList1.deleteBook(searchedBook->getId());
                                    searchedBookMenuChoice = 6; // to break out of the searched book menu loop, and go back to search Menu.
                                    bookSearchMenuChoice = 3; // to break out of the search menu loop, and go back to Books Menu.
                                    break;
                                }
                                case 5:
                                {
                                    int bookRating;
                                    cout << "Enter Rating Value:\n";
                                    cin >> bookRating;
                                    cout << endl;
                                    searchedBook->rateBook(bookRating);
                                    break;
                                }
                                case 6:
                                    bookSearchMenuChoice = 3; // to break out of the search menu loop, and go back to Books Menu.
                                    break;
                                default:
                                    invalidChoice();
                                    break;
                                }
                            }
                            break;
                        }
                        case 2:
                        {
                            int searchedBookId;
                            cout << "Enter Id:\n";
                            cin >> searchedBookId;
                            Book* searchedBook = bookList1.searchBook(searchedBookId);
                            if (searchedBook == nullptr) {
                                cout << "Book not found!\n";
                                break;
                            }
                            searchedBook->printWithAuthorName();
                            int searchedBookMenuChoice = 0;
                            while (searchedBookMenuChoice != 6)
                            {
                                searchedBookMenu();
                                cin >> searchedBookMenuChoice;
                                switch (searchedBookMenuChoice)
                                {
                                case 1:
                                {
                                    int authorID;
                                    cout << "Enter author (user) id:\n";
                                    cin >> authorID;
                                    User* authorToAssign;
                                    authorToAssign = userList1->searchUser(authorID);
                                    if (authorToAssign == nullptr)
                                    {
                                        cout << "No author found with id = " << authorID << endl;
                                        break;
                                    }
                                    searchedBook->setAuthor(*authorToAssign);
                                    break;
                                }
                                case 2:
                                {
                                    string newBookTitle;
                                    cout << "Enter new Name:\n";
                                    cin >> newBookTitle;
                                    cout << endl;
                                    searchedBook->setTitle(newBookTitle);
                                    break;
                                }
                                case 3:
                                {
                                    string newBookCategory;
                                    cout << "Enter new Category:\n";
                                    cin >> newBookCategory;
                                    cout << endl;
                                    searchedBook->setCategory(newBookCategory);
                                    break;
                                }
                                case 4:
                                {
                                    bookList1.deleteBook(searchedBook->getId());
                                    searchedBookMenuChoice = 6; // to break out of the searched book menu loop, and go back to search Menu.
                                    bookSearchMenuChoice = 3; // to break out of the search menu loop, and go back to Books Menu.
                                    break;
                                }
                                case 5:
                                {
                                    int bookRating;
                                    cout << "Enter Rating Value:\n";
                                    cin >> bookRating;
                                    cout << endl;
                                    searchedBook->rateBook(bookRating);
                                    break;
                                }
                                case 6:
                                    bookSearchMenuChoice = 3; // to break out of the search menu loop, and go back to Books Menu.
                                    break;
                                default:
                                    invalidChoice();
                                    break;
                                }
                            }
                            break;
                        }
                        case 3:
                            break;
                        default:
                            invalidChoice();
                            break;
                        }
                    }
                    break;
                }
                 case 3:
                {
                    cout << bookList1;
                    break;
                }
                case 4:
                {
                    cout << bookList1.getTheHighestRatedBook();
                    break;

                }
                case 5:
                {
                    int userId;
                    cout << "Enter User ID:\n";
                    cin >> userId;
                    User* wantedUser = userList1->searchUser(userId);
                    Book* booksForUser = bookList1.getBooksForUser(*wantedUser);
                    for (int i = 0; i < wantedUser->getNumberOfBooks(); i++)
                    {
                        booksForUser[i].printWithAuthorName();
                    }
                    break;
                }
                case 6:
                {
                    BookList bookList2(bookList1); // this will store bookList1 in a new list, and continue working on bookList1 as the new book list.
                    cout << "copied current list (" << bookList1.getBooksCount() << " books) to a new list and switched to it\n";
                    break;
                }
                case 7:
                    break;
                default:
                    invalidChoice();
                    break;
                }
            }
            break;
        }
        case 2:
        {
            int userListSize;
            cout << "How many users will be added?\n";
            cin >> userListSize;
            userList1 = new UserList(userListSize);
            int userMenuChoice = 0;
            while (userMenuChoice != 4) 
            {
                usersMenu();
                cin >> userMenuChoice;
                switch (userMenuChoice)
                {
                  case 1:
                  {
                      User user;
                      cin >> user;
                      userList1->addUser(user);
                      break;
                  }
                  case 2:
                  {
                      int userSearchMenuChoice = 0;
                      while (userSearchMenuChoice != 3)
                      {
                          userSearchMenu();
                          cin >> userSearchMenuChoice;
                          switch (userSearchMenuChoice)
                          {
                          case 1:
                          {
                              string searchedUserName;
                              cout << "Enter Name\n";
                              cin >> searchedUserName;
                              User* searchedUser = userList1->searchUser(searchedUserName);
                              if (searchedUser == nullptr) {
                                  cout << "User not found!\n";
                                  break;
                              }
                              cout << *searchedUser;
                              int searchedUserMenuChoice = 0;
                              searchedUserMenu();
                              cin >> searchedUserMenuChoice;
                              switch (searchedUserMenuChoice)
                              {
                              case 1:
                                  userList1->deleteUser(searchedUser->getId());
                                  userSearchMenuChoice = 3; // to break out of the search menu loop, and go back to Users Menu.
                                  break;
                              case 2:
                                  userSearchMenuChoice = 3; // to break out of the search menu loop, and go back to Users Menu.
                                  break;
                              default:
                                  invalidChoice();
                                  break;
                              }
                              break;
                          }
                          case 2:
                          {
                              int searchedUserId;
                              cout << "Enter Id\n";
                              cin >> searchedUserId;
                              User* searchedUser = userList1->searchUser(searchedUserId);
                              if (searchedUser == nullptr) {
                                  cout << "User not found!\n";
                                  break;
                              }
                              cout << *searchedUser;
                              int searchedUserMenuChoice = 0;
                              searchedUserMenu();
                              cin >> searchedUserMenuChoice;
                              switch (searchedUserMenuChoice)
                              {
                              case 1:
                                  userList1->deleteUser(searchedUser->getId());
                                  userSearchMenuChoice = 3; // to break out of the search menu loop, and go back to Users Menu.
                                  break;
                              case 2:
                                  userSearchMenuChoice = 3; // to break out of the search menu loop, and go back to Users Menu.
                                  break;
                              default:
                                  invalidChoice();
                                  break;
                              }
                              break;
                          }
                          case 3:
                              break;
                          default:
                              invalidChoice();
                              break;
                          }
                      }
                      break;
                  }
                  case 3:
                    cout << *userList1;
                    break;
                  case 4:
                    break;
                  default:
                    invalidChoice();
                    break;
                }
            }

            break;
        }
        case 3:
            break;
        default:
            invalidChoice();
        }
    }    
}

