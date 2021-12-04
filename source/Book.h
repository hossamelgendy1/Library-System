// Copyrights go to Modaser Abdelhamid and Hossam Elgendy from FCAI-CU.

#pragma once
#ifndef BOOK_H
#define BOOK_H
#include<cstring>
#include<iostream>
#include "User.h"
using namespace std;
class Book
{
private:
    string title;
    string isbn;
    int id; // Make sure that the id is incremental. First id is 1, second is 2 and so on
    string category;

    // this variable should contain the average rating for the book, rateBook function
    // should update this attribute with the new average rating for the book
    double averageRating;

    // this variable contains the number of ratings given to a book, in order to calculate the average rating.
    int ratingsCount;

    // this variable contains the total sum of all ratings given to a book, in order to calculate the average rating.
    double ratingsSum;

    User author;

    // this variable indicates whether the book has an author or not.
    bool hasAuthor;
public:
    static int count;
    Book();
    Book(string title, string isbn, string category);
    Book(const Book& book);
    void setTitle(string title);
    string getTitle() const;
    void setISBN(string isbn);
    string getISBN() const;
    void setId(int id);
    int getId() const;
    void setCategory(string category);
    string getCategory() const;
    void setAuthor(User& user);
    User getAuthor() const;
    // returns the value of hasAuthor, to indicate whether the book has an author or not.
    bool getHasAuthor();
    // this function should update averageRating attribute as a new rating is
    // introduced to the book so the average rating should be affected.
    // Check the main screenshot to know more information
    void rateBook(int rating);
    double getAverageRating() const;
    bool operator==(const Book& book);
    void operator=(int par); // used to delete a Book from a BookList.
    void printWithAuthorName();
    friend ostream& operator<<(ostream& output, const Book& book);
    friend istream& operator>>(istream& input, Book& book);
};
#endif // BOOK_H