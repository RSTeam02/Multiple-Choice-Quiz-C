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

void printQuestion(qStruct **questions){
    
    for(int k =0; k<questions[0][0].line; k++){
        char cAnswer = 'A';
        char cSolution = 'A';
        for(int l =0; l<questions[k][0].qSize; l++){            
            if(strlen(questions[k][l].question) != 1){        
                if(l != 0){
                    printf("%c: %s\n",cAnswer, questions[k][l].question);
                    cAnswer++;
                }else{
                    printf("Q: %s\n", questions[k][l].question);
                }
            }else{
                if(cSolution == 'A'){
                    printf("Solution:\n");
                }             
                if(strcmp(questions[k][l].question, "+") == 0){
                    printf("%c\n",cSolution);                   
                }
                cSolution++;                
            }        
        }
        printf("\n");         
    }
}