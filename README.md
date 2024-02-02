# Working with  structures and files on C.

This code is for analysing a structure of data. Its task is to find the city where the cheapest book is published. 
The code uses special functions to input the data (with secure checking), output, calculating the result and creating an answer-array.



## Installation. Task 1

On the file ***"Task 1"*** the code works only with a **concole** (so you can just copy and paste it in any compiler and it will work).


```bash
copy
paste
```

## Installation. Task 2

On the file ***"Task 2"*** the code works with two files.
You have to create a file named ***"input_data.txt"*** which contains an information about all books you have (the example of this file is also provided in this repository).
Then run the code.
You will see console asking for a number of books. Put the exact number of whose you've added in ***"input_data.txt"***. Then press **enter**.
A new file ***"output_data.txt"*** will be created. It will include a message and a list of cities where the cheapest books are published.

You may use this code in CodeBlocks, VisualStudioCode or even in online C :) [the best site of the entire world]([onlinegdb.com](https://www.onlinegdb.com/online_c_compiler))



## The shape of the structure

```c
struct izdatel {
    int god;
    char naz[100];
    char gor[100];
};

struct Book {
    char title[100];
    int price;
    int numPages;
    char author[100];
    struct izdatel publisherInfo;
};

```
So, you need an ***"input_data.txt"*** file like that:
```
TITLE (only symbols)
PRICE (only numbers)
NUMBER OF PAGES (only numbers)
AUTHOR (only symbols)
YEAR OF PUBLICATION (only numbers)
NAME OF THE PUBLISHER COMPANY (only symbols)
THE CITY WHERE THE BOOK IS PUBLISHED (only symbols)

```


## Contributing

Please make sure to add an "input_data.txt" file on the same directory as the code ("Task 1" or "Task 2").

