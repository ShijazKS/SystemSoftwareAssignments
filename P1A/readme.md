# Library Management System

This project is a simple C program to manage the details of books in a library system. The project demonstrates basic data structures, pointer usage, file operations, and function definitions in C.

## Objective

The objective of this project is to learn and apply the following concepts:

- Basic data structuring facilities like arrays and structs.
- Use of pointers in C programming.
- File operations to read from and write to files.
- Function definitions and their usage in C.

## Features

The program supports the following features:

1. **[Storing ISBN Numbers](./part1.c):**
   - The program reads in the 5-digit ISBN of each book and stores them in an array of integers.

2. **[Storing Book Titles](./part2.c):**
   - The program modifies the array to store the complete title of each book.

3. **[Book Details Management](./part3.c):**
   - The program declares a `struct Book` with fields for the title, author, ISBN, year of publication, and price.
   - A function `createBookList()` is used to read in and store book details in an array of `struct Book`.
   - A function `getBookByISBN()` retrieves the title of a book by its ISBN.

4. **[Saving to a File](./part4.c):**
   - The program includes a function `saveToFile()` that saves the array of books to a text file named `booklist.txt`, with each book's details on a new line. The fields are separated by a comma.

5. **[Dynamic Memory Allocation](./part5.c):**
   - The program stores book details in an array of pointers to `struct Book` and reads in book details from a text file (filename provided as a command line argument).
   - Memory for each book struct is dynamically allocated.
   - The `getBookByISBN()` function is modified to work with this array of pointers.

## Usage

1. **Compile the Program:**
   - Use a C compiler to compile the program:
     ```bash
     gcc -o library_management <CFileName>.c   ```

2. **Run the Program:**
   - Run the compiled program and provide the required filename as a command line argument:
     ```bash
     ./library_management <filename>
     ```

3. **Input and Operations:**
   - Follow the prompts to input book details and perform operations such as retrieving book titles by ISBN and saving book details to a file.


## Requirements

- Basic understanding of C programming.
- Familiarity with arrays, structures, pointers, and file operations in C.
