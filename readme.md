# Multiple Choice Quiz in C

Similar to the Multiple Choice Quiz in C++, the program is rewritten in C language.

progress:

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
$ gcc main.c filereader.c question.c -std=c99 -o main
$ ./main
Q: 99 is equal to:
A: 3*30+3²
B: 11*9
C: 2*33
Solution:
A
B

Q: Which color component(s) contain(s) the RGB color space?
A: grey
B: red
C: ruby
D: rose
E: blue
F: green
Solution:
B
E
F

Q: What is the meaning of "x++"/"x--"?
A: it's equal to x=x+2/x=x-2
B: it adds/subtracts x by 1
C: it is also known as increment/decrement operator
D: it's equal to x=x+1/x=x-1
E: it adds/subtracts x by 2
Solution:
B
C
D

Q: What do you know about the C-Language?
A: it was developed by Bjarne Stroustrup
B: the "hello world" program gains popularity within the C-language
C: the successor of C is the D language
D: C is nowadays still used for OS-Development
E: it's an imperative programming language
F: it's a programming language with object orientation
G: it was developed by Dennis Ritchie
Solution:
B
D
E
G

Joe achieved 1.500000 points
$ ./main
Q: 99 is equal to:
A: 11*9
B: 3*30+3²
C: 2*33
Solution:
A
B

Q: Which color component(s) contain(s) the RGB color space?
A: grey
B: red
C: rose
D: ruby
E: green
F: blue
Solution:
B
E
F

Q: What is the meaning of "x++"/"x--"?
A: it's equal to x=x+2/x=x-2
B: it adds/subtracts x by 2
C: it is also known as increment/decrement operator
D: it adds/subtracts x by 1
E: it's equal to x=x+1/x=x-1
Solution:
C
D
E

Q: What do you know about the C-Language?
A: it was developed by Bjarne Stroustrup
B: C is nowadays still used for OS-Development
C: it was developed by Dennis Ritchie
D: the "hello world" program gains popularity within the C-language
E: the successor of C is the D language
F: it's a programming language with object orientation
G: it's an imperative programming language
Solution:
B
C
D
G

Joe achieved 1.500000 points
$ ./main
Q: 99 is equal to:
A: 11*9
B: 2*33
C: 3*30+3²
Solution:
A
C

Q: Which color component(s) contain(s) the RGB color space?
A: blue
B: rose
C: red
D: green
E: grey
F: ruby
Solution:
A
C
D

Q: What is the meaning of "x++"/"x--"?
A: it's equal to x=x+2/x=x-2
B: it is also known as increment/decrement operator
C: it's equal to x=x+1/x=x-1
D: it adds/subtracts x by 1
E: it adds/subtracts x by 2
Solution:
B
C
D

Q: What do you know about the C-Language?
A: the "hello world" program gains popularity within the C-language
B: it was developed by Bjarne Stroustrup
C: the successor of C is the D language
D: C is nowadays still used for OS-Development
E: it's a programming language with object orientation
F: it was developed by Dennis Ritchie
G: it's an imperative programming language
Solution:
A
D
F
G

Joe achieved 1.500000 points




```