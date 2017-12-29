# Multiple Choice Quiz in C

Similar to the Multiple Choice Quiz in C++, the program is rewritten in C language.

progress:


28.12. controller.c:
+ 29.12. fixed score bug (char arr termination)
+ 28.12. create player with name, score, print question, user input, check answer, sum score (buggy)
+ 28.12. input validation: check user input 

26.12. shuffle.c:

+ shuffle positions of answers and solutions 

26.12. structs:

+ player type struct: name and score
+ strStruct type struct: char array with number of row information
+ qStruct type struct => single question as char array with question size and row information 

24.12. filereader.c:

+ step1: store the whole text in a char array, count number of lines

24.12. question.c:

+ step2: delimit the whole string by row "\n" (set of questions)
+ step3: store all questions in a 2-dim qStruct array, then delimit every column of a row by "," (question, answer and solution possibilities) 
+ print question, answer, solution of right answer(s) in letters (A-Z) 

```
$ gcc main.c filereader.c question.c controller.c shuffle.c -std=c99 -o main
$ ./main
Name: Joe, Score: 0.000000
Q: What do you know about the C-Language?
A: it's a programming language with object orientation
B: it's an imperative programming language
C: it was developed by Dennis Ritchie
D: it was developed by Bjarne Stroustrup
E: the successor of C is the D language
F: the "hello world" program gains popularity within the C-language
G: C is nowadays still used for OS-Development
CgfB
Solution:
B
C
F
G
4 answer(s) right, 0 answer(s) wrong
Joe achieved 1.000000 pts for this question
Joe's score: 1.000000pts


Q: Which color component(s) contain(s) the RGB color space?
A: red
B: green
C: ruby
D: rose
E: blue
F: grey
eA
Solution:
A
B
E
2 answer(s) right, 0 answer(s) wrong
Joe achieved 0.500000 pts for this question
Joe's score: 1.500000pts


Q: 99 is equal to:
A: 2*33
B: 3*30+3²
C: 11*9
cBA
Solution:
B
C
2 answer(s) right, 1 answer(s) wrong
Joe achieved 0.250000 pts for this question
Joe's score: 1.750000pts


Q: What is the meaning of "x++"/"x--"?
A: it adds/subtracts x by 2
B: it adds/subtracts x by 1
C: it's equal to x=x+1/x=x-1
D: it's equal to x=x+2/x=x-2
E: it is also known as increment/decrement operator
BDE
Solution:
B
C
E
2 answer(s) right, 1 answer(s) wrong
Joe achieved 0.250000 pts for this question
Joe's score: 2.000000pts

```