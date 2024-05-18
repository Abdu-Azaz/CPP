#include <iostream>
#include <vector>
using namespace std;

class Book {
private:
    string title;
    string publication;
    int year;
    string isbn;

public:
    Book(string title, string publication, int year, string isbn)
    {
        this->title = title;
        this->publication = publication;
        this->year = year;
        this->isbn = isbn;
    }

    string getTitle() const {
        return title;
    }

    string getPublication() const {
        return publication;
    }

    int getYear() const {
        return year;
    }

    string getISBN() const {
        return isbn;
    }
};

class Library {
private:
    vector<Book*> store;

public:
    void addBook(Book* book)
    {
        store.push_back(book);
    }

    void deleteBook(string isbn)
    {
        for (auto it = store.begin(); it != store.end(); ++it) {
            if ((*it)->getISBN() == isbn) {
                delete *it;
                store.erase(it);
                break;
            }
        }
    }

    void displayBooks() const {
        cout << "Library Catalog:" << endl;
        for (const auto& book : store) {
            cout << "Title: " << book->getTitle() << endl;
            cout << "Publication: " << book->getPublication() << endl;
            cout << "Year: " << book->getYear() << endl;
            cout << "ISBN: " << book->getISBN() << endl;
            cout << "----------------------" << endl;
        }
    }

    ~Library() {
        for (auto book : store) {
            delete book;
        }
    }
};

int main()
{
    // Create book objects
    Book* book1 = new Book("Title 1", "Publication 1", 2021, "ISBN 1");
    Book* book2 = new Book("Title 2", "Publication 2", 2022, "ISBN 2");
    Book* book3 = new Book("Title 3", "Publication 3", 2023, "ISBN 3");

    // Create a library object
    Library library;

    // Add books to the library
    library.addBook(book1);
    library.addBook(book2);
    library.addBook(book3);

    // Display the books in the library
    library.displayBooks();

    // Delete a book from the library
    library.deleteBook("ISBN 1");

    // Display the books in the library after deletion
    library.displayBooks();

    // Remember to properly deallocate the book objects from memory
    delete book1;
    delete book2;
    delete book3;

    return 0;
}