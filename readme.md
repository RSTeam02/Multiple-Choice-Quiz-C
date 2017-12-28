# Multiple Choice Quiz in C

Similar to the Multiple Choice Quiz in C++, the program is rewritten in C language.

progress:


controller.c:

+ controls gameplay: player type (name,score) show question, check answer, sum score (buggy)
+ input validation: check user input 

shuffle.c:

+ shuffle positions of answers and solutions 

structs:

+ player type struct: name and score
+ strStruct type struct: char array with number of row information
+ qStruct type struct => single question as char array with question size and row information 

filereader.c:

+ step1: store the whole text in a char array, count number of lines

question.c:

+ step2: delimit the whole string by row "\n" (set of questions)
+ step3: store all questions in a 2-dim qStruct array, then delimit every column of a row by "," (question, answer and solution possibilities) 
+ print question, answer, solution of right answer(s) in letters (A-Z) 

```
$ gcc main.c filereader.c question.c controller.c shuffle.c -std=c99 -o main
$ ./main
Name: Joe, Score: 0.000000
Q: What do you know about the C-Language?
A: it was developed by Bjarne Stroustrup
B: it's an imperative programming language
C: it was developed by Dennis Ritchie
D: it's a programming language with object orientation
E: the successor of C is the D language
F: C is nowadays still used for OS-Development
G: the "hello world" program gains popularity within the C-language
BCfg
Solution:
B
C
F
G
4 answer(s) right, 2 answer(s) wrong
Joe achieved 0.500000 pts for this question
Joe's score: 0.500000pts


Q: Which color component(s) contain(s) the RGB color space?
A: grey
B: blue
C: red
D: rose
E: ruby
F: green
bc
Solution:
B
C
F
2 answer(s) right, 0 answer(s) wrong
Joe achieved 0.500000 pts for this question
Joe's score: 1.000000pts


Q: 99 is equal to:
A: 2*33
B: 11*9
C: 3*30+3²
abc
Solution:
B
C
1 answer(s) right, 1 answer(s) wrong
Joe achieved 0.000000 pts for this question
Joe's score: 1.000000pts


Q: What is the meaning of "x++"/"x--"?
A: it adds/subtracts x by 1
B: it adds/subtracts x by 2
C: it is also known as increment/decrement operator
D: it's equal to x=x+2/x=x-2
E: it's equal to x=x+1/x=x-1
aec
Solution:
A
C
E
3 answer(s) right, 0 answer(s) wrong
Joe achieved 0.750000 pts for this question
Joe's score: 1.750000pts






```