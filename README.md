# Rudimentary-Shell
A Rudimentary Shell in C
1. MakeFile :- I have implemented a makefile which will generate all the executables file.
2. a) Fork : Used to make a copy of another process and then applied wait which will wait
for child to terminate.
b) Exec : System call used to replace a child process with the process that we want to
run.
3. Correct Handling Of Commands :-
1. Ls : implemented ls and ls -a and ls -a will print even files starting with .a and ls -i which
will print the inode of the files.
2. Exit : No option implemented , it will simply return from the process and will stop
terminal.
3. Cd : two options implemented including cd - and cd .. , one will take you to home
directory and the other will take you to one directory above.
4. Pwd : two options implemented one -L and other -P . One is going to give your address
while other is going to give you your symbolic resolved physical address.
5. History -n will print the histories along with their numbers while history -c will delete the
histories.
6. Rm for rm two options are implemented , one is rm -i which will basically ask you
whether you want to delete a file and rm -v which will print the message after deletion.
7. Cat -E and cat -n are implemented which will basically append $ at end of each line of
first and in second will print the line number along with the lines.
8. Mkdir which will basically have two options -m which will help to set the mode of the
directory and -p which will help to create hierarchies o subdirectories.
9. Date which has two options -u for GMT based time and -R for local time settings.
10. Echo :- two options are implemented and -n and -E which will ignore a newline and
ignore backslash escapes.
Successfully Handling at least Two corner cases :-
1. For each of the test case one corner case that I handled is wrong input or not giving
enough arguments.
2. Furthermore in other functions I have handled the corner case when there is error in
opening or closing file.
3. Also in most of the cases the pointers can go out of bound so i handled all those cases
too.
4. Furthermore I have handled all the states in which write and read are happening to
pointers or in files and cases when there are no files or no directories or files deleting are
not directories.
5. Also Null pointers and segmentation faults were quite common in this assignment which
I fixed.
6. I have taken into account multiple flag for some vertices in which multiple flag makes
sense .
Assumptions :
1. In echo I have not removed double quotes .
2. In pwd if there is symbolic link then it can be resolved with -L , however I haven’t updated environment variable so it won’t change of we change the directory.
3. In CD I haven’t taken into account multiple directories in one go.
4. In history I have not skipped the white space line like commands when there is
no input
5. I haven’t taken into account directories separated with space.
6. In cat command I won’t deal with multiple files opening at one go.
7. I haven’t taken into account multiple flags for all the vertices.
