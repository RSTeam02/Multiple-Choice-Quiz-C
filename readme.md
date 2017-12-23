# Multiple Choice Quiz in C

Similar to the Multiple Choice Quiz in C++, the program is rewritten in C language.

progress:

structs:

+ player type struct: name and score
+ strStruct type: char array with number of row information
+ qStruct type struct => single question with question size and row information 

filereader.c:

+ step1: store the whole text in a char array, count number of lines

question.c:

+ step2: delimit the whole string by row "\n" (set of questions)
+ step3: store all questions in a 2-dim qStruct array, then delimit every column of a row by "," (question, answer and solution possibilities) 
+ print question, answer, solution of right answer(s) in letters (A-Z) 

```
$ gcc main.c filereader.c question.c -std=c99 -o main
$ ./main
Q: 99 is equal to:
A: 3*30+3²
B: 2*33
C: 11*9
Solution:
A
C

Q: Which color component(s) contain(s) the RGB color space?
A: red
B: rose
C: ruby
D: green
E: grey
F: blue
Solution:
A
D
F

Q: What is the meaning of "x++"/"x--"?
A: it is also known as increment/decrement operator
B: it adds/subtracts x by 2
C: it's equal to x=x+2/x=x-2
D: it adds/subtracts x by 1
E: it's equal to x=x+1/x=x-1
Solution:
A
D
E

Q: What do you know about the C-Language?
A: the successor of C is the D language
B: it's a programming language with object orientation
C: it's an imperative programming language
D: it was developed by Dennis Ritchie
E: it was developed by Bjarne Stroustrup
F: the "hello world" program gains popularity within the C-language
G: C is nowadays still used for OS-Development
Solution:
C
D
F
G

Joe achieved 1.500000 points


```