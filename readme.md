# Multiple Choice Quiz in C

Similar to the Multiple Choice Quiz in C++, the program is rewritten in C language.

progress:


31.12. controller.c:
+ 31.12: additional options<br />
    => set name by user input<br />
    => input validation (y/n)
    => enable,disable shuffling (order of questions, positions of answers)<br />
    => restart game (y/n)<br />
+ 30.12. input validation:<br /> 
    => letter checking: if user enters char(s) that don't consist in a set of solution possibilities e.g. AXCB of ABCD, so X is not in ABCD, repeat user input<br />
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
Enter your name: Joe
Shuffle order of questions (y/n): n
Shuffle order of answer possibilities, each question (y/n): y
Name: Joe, Score: 0.00
Q: 99 is equal to:
A: 11*9
B: 2*33
C: 3*30+3²
ac
Solution:
A
C
2 answer(s) right, 0 answer(s) wrong
Joe achieved 0.50 pts for this question
Joe's score: 0.50pts


Q: Which color component(s) contain(s) the RGB color space?
A: red
B: grey
C: green
D: rose
E: ruby
F: blue
fac
Solution:
A
C
F
3 answer(s) right, 0 answer(s) wrong
Joe achieved 0.75 pts for this question
Joe's score: 1.25pts


Q: What is the meaning of "x++"/"x--"?
A: it's equal to x=x+2/x=x-2
B: it's equal to x=x+1/x=x-1
C: it is also known as increment/decrement operator
D: it adds/subtracts x by 2
E: it adds/subtracts x by 1
eaf
f is not in ABCDE, repeat input
bce
Solution:
B
C
E
3 answer(s) right, 0 answer(s) wrong
Joe achieved 0.75 pts for this question
Joe's score: 2.00pts


Q: What do you know about the C-Language?
A: C is nowadays still used for OS-Development
B: the successor of C is the D language
C: it was developed by Bjarne Stroustrup
D: it's a programming language with object orientation
E: it's an imperative programming language
F: the "hello world" program gains popularity within the C-language
G: it was developed by Dennis Ritchie
gfab
Solution:
A
E
F
G
3 answer(s) right, 1 answer(s) wrong
Joe achieved 0.50 pts for this question
Joe's score: 2.50pts


Q: What does the "%" operator in a programming language?
A: it is supposed to use for percentage calculation
B: it is also known as the "modulo" operator
C: it calculates the remainder of a division
D: 1%100=1/100
E: 1%100=100
dab
Solution:
B
C
E
1 answer(s) right, 2 answer(s) wrong
Joe achieved 0.00 pts for this question
Joe's score: 2.50pts


Restart game? (y/n): y
Enter your name: Jane
Shuffle order of questions (y/n): y
Shuffle order of answer possibilities, each question (y/n): n
Name: Jane, Score: 0.00
Q: What is the meaning of "x++"/"x--"?
A: it is also known as increment/decrement operator
B: it adds/subtracts x by 2
C: it's equal to x=x+2/x=x-2
D: it adds/subtracts x by 1
E: it's equal to x=x+1/x=x-1
ace
Solution:
A
D
E
2 answer(s) right, 1 answer(s) wrong
Jane achieved 0.25 pts for this question
Jane's score: 0.25pts


Q: What do you know about the C-Language?
A: the successor of C is the D language
B: it's a programming language with object orientation
C: it's an imperative programming language
D: it was developed by Dennis Ritchie
E: it was developed by Bjarne Stroustrup
F: the "hello world" program gains popularity within the C-language
G: C is nowadays still used for OS-Development
acdfg
Solution:
C
D
F
G
4 answer(s) right, 1 answer(s) wrong
Jane achieved 0.75 pts for this question
Jane's score: 1.00pts


Q: What does the "%" operator in a programming language?
A: it is supposed to use for percentage calculation
B: it calculates the remainder of a division
C: it is also known as the "modulo" operator
D: 1%100=1/100
E: 1%100=100
ecv
v is not in ABCDE, repeat input
ecb
Solution:
B
C
E
3 answer(s) right, 0 answer(s) wrong
Jane achieved 0.75 pts for this question
Jane's score: 1.75pts


Q: 99 is equal to:
A: 3*30+3²
B: 2*33
C: 11*9
ac
Solution:
A
C
2 answer(s) right, 0 answer(s) wrong
Jane achieved 0.50 pts for this question
Jane's score: 2.25pts


Q: Which color component(s) contain(s) the RGB color space?
A: red
B: rose
C: ruby
D: green
E: grey
F: blue
fad
Solution:
A
D
F
3 answer(s) right, 0 answer(s) wrong
Jane achieved 0.75 pts for this question
Jane's score: 3.00pts


Restart game? (y/n): n
```