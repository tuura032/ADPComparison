# RankComparison
Compares pre-season fantasy football rankings from 2 different sources.
FFCheatSheet.c is a C program that compares two text lists of ranked fantasy football players. The purpose is to group together players that are either over- or undervalued. The return file (ordered.csv) can be opened in excel for easy viewing.

fantasystruc.h contains the structs used in the program.

harrisranks.txt and espnranks.txt were the lists used. Each list contains 164 players, formatted with only first initial and no spaces.

This was my first "code for fun" project outside of CS50. It runs, but it's not pretty looking. Simple improvements could include entering the specific document to read at the command line, allowing any number of players (more or less than 164), or learning how to merge sort a struct array. I could also take all of my functions outside of main, but since I've never done that before, I didn't take the time.
