#include "question.h"

qStruct **str2Question(strStruct str){
    
    char *linesOfStr[str.numOfLine];
    int k = 0;
    int j =0;
    char *ptr;
    char *ptr2;
    char delimiterRow[] = "\n";
    char delimiterCol[] = ",";
    ptr = strtok(str.line, delimiterRow);
    while(ptr != NULL){
        linesOfStr[k] = malloc(strlen(ptr)+1);
        strcpy(linesOfStr[k], ptr);      
        ptr = strtok(NULL, delimiterRow);
        k++; 
    }
    //cols of all questions in 2d char arr   
    qStruct **questions = malloc(str.numOfLine*sizeof(qStruct*));
    //size_t qSize[line]; 
    for(int m = 0; m < str.numOfLine; m++){
        char *colOfStr[strlen(linesOfStr[m])];
        ptr2 = strtok(linesOfStr[m], delimiterCol);
        questions[m] = malloc(str.numOfLine*strlen(linesOfStr[m])*sizeof(qStruct));
        j=0;        
        while(ptr2 != NULL){            
            colOfStr[j] = malloc(strlen(ptr2)+1);
            strcpy(colOfStr[j], ptr2);      
            ptr2 = strtok(NULL, delimiterCol);        
            questions[m][j].question = colOfStr[j];
            questions[m][0].line = str.numOfLine;            
            j++; 
        }
        questions[m][0].qSize = j;       
    }
    return questions;
}