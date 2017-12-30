# Multiple Choice Quiz in C

Similar to the Multiple Choice Quiz in C++, the program is rewritten in C language.

progress:


28.12. controller.c:
+ 30.12. input validation consists of:<br /> 
    => letter checking: if user enters char(s) that don't consist in the set of solutions (e.g. AXCB in ABCD), repeat user input<br />
    => check Answer: convert to upper case, sort string, remove duplicates, when user enters e.g. ccaabba will be ABC

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
Q: What is the meaning of "x++"/"x--"?
A: it is also known as increment/decrement operator
B: it adds/subtracts x by 2
C: it adds/subtracts x by 1
D: it's equal to x=x+1/x=x-1
E: it's equal to x=x+2/x=x-2
cad
Solution:
A
C
D
3 answer(s) right, 0 answer(s) wrong
Joe achieved 0.750000 pts for this question
Joe's score: 0.750000pts


Q: 99 is equal to:
A: 11*9
B: 3*30+3²
C: 2*33
XABZ       
X is not in ABC, repeat input
Z is not in ABC, repeat input
Ba
Solution:
A
B
2 answer(s) right, 0 answer(s) wrong
Joe achieved 0.500000 pts for this question
Joe's score: 1.250000pts


Q: Which color component(s) contain(s) the RGB color space?
A: green
B: red
C: rose
D: grey
E: ruby
F: blue
gF 
G is not in ABCDEF, repeat input
fab
Solution:
A
B
F
3 answer(s) right, 0 answer(s) wrong
Joe achieved 0.750000 pts for this question
Joe's score: 2.000000pts


Q: What do you know about the C-Language?
A: it's a programming language with object orientation
B: C is nowadays still used for OS-Development
C: it was developed by Bjarne Stroustrup
D: it was developed by Dennis Ritchie
E: the successor of C is the D language
F: the "hello world" program gains popularity within the C-language
G: it's an imperative programming language
ghb
H is not in ABCDEFG, repeat input
bdcfg
Solution:
B
D
F
G
4 answer(s) right, 1 answer(s) wrong
Joe achieved 0.750000 pts for this question
Joe's score: 2.750000pts


Q: What does the "%" operator in a programming language?
A: 1%100=1/100
B: it is supposed to use for percentage calculation
C: 1%100=100
D: it calculates the remainder of a division
E: it is also known as the "modulo" operator
cde
Solution:
C
D
E
3 answer(s) right, 0 answer(s) wrong
Joe achieved 0.750000 pts for this question
Joe's score: 3.500000pts

```