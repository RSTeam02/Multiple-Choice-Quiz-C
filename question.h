#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "qStruct.h"
#include "strStruct.h"
#include "shuffle.h"



qStruct **str2Question(strStruct str);
int countAnswer(int qNo, qStruct **questions);
void printQuestion(qStruct **questions);