# List Comparison
Compares pre-season fantasy football rankings from 2 different sources.

<strong>Usage</strong>

FFCheatSheet.c is a C program that compares two text lists of ranked fantasy football players. The purpose is to group together players that are either over- or undervalued. The return file (ordered.csv) can be opened in excel for easy viewing.

fantasystruct.h contains the structs used in the program. Each struct stores the players name and ranking from their respective source.

harrisranks.txt and espnranks.txt were the lists used. Each list contains 164 players, formatted with only first initial and no spaces.


<strong>Desciption</strong>

This program was created solely for fun, and to practice using structs and pointers before I began learning Python. Many improvments could be made to the program (described below), but I have since learned better ways to accomplish my end goal. More than anything else, this program demonstrates my ability to come up with a solution to a problem using code approximately one month into learning. I also demonstrated my ability to use pointers, linked lists, arrays, loops, structs, sorting methods, file operations, data gathering, data manipulation, and comparing operations.


<strong>Improvements</strong>

Improvements could include entering the specific document to read at the command line, allowing any number of players in the list (more or less than 164), moving the functions outside of main, condensing the program from needing 2 structs to one, and putting players that only exist on one list in an entirely different block of memory. The most difficult, but perhaps most worthwhile improvement would be making the program run faster by using merge sort (probably sorting a struct array) instead of linear search. 


