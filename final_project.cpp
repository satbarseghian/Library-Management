//TEAM: ALIZA,SAT,ANI

// SAT COMMENT
#include <iostream>
#include <string>
using namespace std;

//This code defines the structure called Book = represents a book object. It has member variables which store information about a book. The "* next" member is a pointer to the next book in the linked list
struct Book {
  string title;
  string author;
  string ISBN;
  int numCopies;
  Book* next;
};

// defines the LinkedList class. this contains two member functions: addBook and removeBook
class LinkedList {
public:
  LinkedList() :head(nullptr) {} // By initializing head to nullptr, it ensures that the head pointer initially points to nothing, indicating an empty linked list.
//The addBook function adds a new book to the end of the linked list. parameters = title, author, ISBN, numCopies and creates a new Book object dynamically using new. If the list is empty (head == nullptr), the new book becomes the head. Otherwise, it iterates through the list until it finds the last book and appends the new book to the end. A success message is printed to the console.
  void addBook(string title, string author, string ISBN, int numCopies) {
    Book* newBook = new Book{title, author, ISBN, numCopies, nullptr};
    if (head == nullptr) {
      head = newBook;
    } else {
      Book* curr = head;
      while (curr->next != nullptr) {
        curr = curr->next;
      }
      curr->next = newBook;
    }
    cout << "Book added successfully." << endl;
  }

  // The removeBook function removes a book from the linked list based on its title. It starts by initializing pointers curr and prev to traverse the list. If a book with a matching title is found, it handles cases where the book is the head or in the middle of the list, updates the pointers accordingly, and deletes the book. A success message is printed if the book is found and removed; otherwise, a message indicating that the book was not found is displayed.
  void removeBook(string title) {
    Book* curr = head;
    Book* prev = nullptr;
    while (curr != nullptr) {
      if (curr->title == title) {
        if (prev == nullptr) {
          head = curr->next;
        } else {
          prev->next = curr->next;
        }
        delete curr;
        cout << "Book removed successfully." << endl;
        return;
      }
      prev = curr;
      curr = curr->next;
    }
    cout << "Book not found." << endl;
  }
//ALIZA comment
  // Search for book by title
  void searchByTitle(string title) { //declaring searchbyTitle 
    Book* curr = head; //assigning the value of the head pointer to curr pointer
    while (curr != nullptr) { // Creating a loop to iterate through the linked list
      if (curr->title == title) { // Checking if the current book's title matches the search title
        cout << "Title: " << curr->title << endl; //printing the title
        cout << "Author: " << curr->author << endl;//printing author 
        cout << "ISBN: " << curr->ISBN << endl; //printing ISBN
        cout << "Number of copies: " << curr->numCopies << endl;
        return; //Printing number of copies of the found book 
      }
      curr = curr->next; //updating curr to point towards next pointer
    }
    cout << "Book not found." << endl; //Printing the message 
  }

  // Display all books in library
  void displayAllBooks() {
    // sorting the list alphabetically by title
    Book* curr = head;
    while (curr != nullptr) {
        Book* min = curr;
        Book* temp = curr->next;
        while (temp != nullptr) {
            if (temp->title < min->title) {
                min = temp;
            }
            temp = temp->next;
        }
        // swap the nodes
        swap(curr->title, min->title);
        swap(curr->author, min->author);
        swap(curr->ISBN, min->ISBN);
        swap(curr->numCopies, min->numCopies);
        curr = curr->next;
    }

    // display the sorted list
    curr = head;
    while (curr != nullptr) {
        cout << "Title: " << curr->title << endl;
        cout << "Author: " << curr->author << endl;
        cout << "ISBN: " << curr->ISBN << endl;
        cout << "Number of copies: " << curr->numCopies << endl;
        cout << endl;
        curr = curr->next;
    }
}

// LinkedList class is defined with two access specifiers: public and private. The head member variable is declared as private,
private: 
  Book* head; // Declaring a pointer to the head of the linked list
};

// Add book to library
void addBook(LinkedList& library) {
  string title, author, ISBN;
  int numCopies;
  cout << "Enter book title: ";
  getline(cin, title); //Reading the title of the book from the user's input
  cout << "Enter book author: ";
  getline(cin, author); //Reading the author of the book from the user's input
  cout << "Enter book ISBN: ";
  getline(cin, ISBN); //Reading the ISBN of the book from the user's input
  cout << "Enter number of copies: ";
  cin >> numCopies;
  library.addBook(title, author, ISBN, numCopies);  // Adding the book to the library using the addBook function of the LinkedList class
}

// ANI COMMENT
// Remove book from library
void removeBook(LinkedList& library) {
  string title;
  cout << "Enter title of book to remove: ";
  getline(cin, title);
  library.removeBook(title);
}
// Search for book by title
//Searches for a book in the linked list based on its title. It iterates through the list, comparing the title of each book with the given title. If a match is found, it displays the book with all details
void searchByTitle(LinkedList& library) {
  string title;
  cout << "Enter title of book to search: ";
  getline(cin, title);
library.searchByTitle(title);
}

// Display all books in library
// Iterates through the linked list and prints the details of each book, including its title, author, ISBN, and number of copies. Note that the books are displayed in the order they are stored in the list.
void displayAllBooks(LinkedList& library) {
library.displayAllBooks();
}

// Display menu and get user input
//This function displays a menu of options to the user and reads their choice. It prompts the user to enter a choice (1, 2, 3, 4, or 5) and returns the choice as an integer.
int getMenuChoice() {
cout << "Menu:" << endl;
cout << "1. Add book" << endl;
cout << "2. Remove book" << endl;
cout << "3. Search by title" << endl;
cout << "4. Display all books" << endl;
cout << "5. Exit" << endl;
int choice;
cout << "Enter choice: ";
cin >> choice;
cin.ignore(); // Ignore newline character in input buffer
cout << endl;
return choice;
}


//The main function serves as the entry point of the program. It creates an instance of the LinkedList named library and repeatedly displays the menu, gets the user's choice, and performs the corresponding action until the user chooses to exit (choice 5). The functions addBook, removeBook, searchByTitle, and displayAllBooks are called based on the user's choice, and the library object is passed as a parameter to manipulate the linked list accordingly.

int main() {
LinkedList library;

int choice;
do {
choice = getMenuChoice();
switch (choice) {
  case 1:
    addBook(library);
    break;
  case 2:
    removeBook(library);
    break;
  case 3:
    searchByTitle(library);
    break;
  case 4:
    displayAllBooks(library);
    break;
  case 5:
    cout << "Goodbye!" << endl;
    break;
  default:
    cout << "Invalid choice." << endl;
    break;
}

cout << endl;
}
while (choice != 5);

return 0;
}
// thank you Sravya, great class!