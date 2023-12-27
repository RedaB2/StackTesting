Reda Boutayeb
rboutayeb

In order to compile the program: 

- Open the terminal
- Make sure all the files are in the directory you are in, if not access it using cd. 
- Enter "make" in order to execute the makefile
- Enter "make docs" in order to make sure the webpage will work.
- Then, the program should be compiled, you can execute any program just by using the commands indicated.
- If you want to delete all the files, "make clean".

In this file, we have two programs: 

 - stacktest
 - stacktest2

 stacktest: 

 The program read all strings until EOF then print the strings back in reverse order. You can dynamically allocate memory by giving it a size. 

 Example: 

 ./stacktest 10 

 stacktest2: 

 This program reads strings from standard input, then pushes each string onto a stack and also pushes each character in the string onto another stack. 
 The program then pops the strings from the string stack, and for each string, it creates a new stack with the characters in reverse order
 , and pops them to print the characters in reverse order. 
 Finally, the program pops the characters from the character stack to print them out with spaces in between.
 You can dynamically allocate memory by giving it a size. 

 Example:

 ./stacktest2 10
