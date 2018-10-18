# RankComparison
Compares pre-season fantasy football rankings from 2 different sources.
FFCheatSheet.c is a C program that compares two text lists of ranked fantasy football players. The purpose is to group together players that are either over- or undervalued. The return file (ordered.csv) can be opened in excel for easy viewing.

fantasystruct.h contains the structs used in the program. Each struct stores the players name and ranking from their respective source.

harrisranks.txt and espnranks.txt were the lists used. Each list contains 164 players, formatted with only first initial and no spaces.

This was my first "code for fun" project outside of CS50. The good news is, it works! Simple improvements could include entering the specific document to read at the command line, allowing any number of players in the list (more or less than 164), moving some of the functions outside of main, condensing the program from needing 2 structs to one, and putting players that only exist on one list in an entirely different block of memory. The most difficult improvement would be making the program run faster by using merge sort (probably sorting a struct array) instead of linear search. Realistically, I would just write the program in Pyton instead and make it a web-app.

Finally, this program, while "slow" for C, happens to summarize much of what I've learned in C. I practiced a practical application for using pointers, linked lists, arrays, loops, structs, sorting methods (albeit a slow method), file operations, and comparing operations.
