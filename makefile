all : shell cat date ls mkdir rm

shell : shell.c
	gcc -o shell shell.c
cat : cat.c
	gcc -o cat cat.c
date : date.c
	gcc -o date date.c
ls : ls.c
	gcc -o ls ls.c
mkdir : mkdir.c
	gcc -o mkdir mkdir.c
rm : rm.c
	gcc -o rm rm.c
clear :
	rm shell cat date ls mkdir rm 


