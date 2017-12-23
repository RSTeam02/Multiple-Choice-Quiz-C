#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "filereader.h"
#include "question.h"
#include "player.h"
#include "shuffle.h"
#include <stdbool.h>

int main(void){   
    printQuestion(str2Question(readFile()));
    player p1;
    p1.name = "Joe";
    p1.score = .75;
    p1.score += .25;
    p1.score += .25;
    p1.score += .25;
    printf("%s achieved %f points\n", p1.name, p1.score); 
    

}