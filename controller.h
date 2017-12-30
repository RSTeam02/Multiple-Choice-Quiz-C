#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "filereader.h"
#include "question.h"
#include "player.h"
#include "shuffle.h"
#include "qStruct.h"
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

void start(qStruct **questions);
int countAnswer(int qNo, qStruct **questions);
char *validation(char *input, size_t size);
void printQuestion(qStruct **questions);
bool findLetter(size_t aSize, char *input);
void checkAnswer(char *input, char *solution);