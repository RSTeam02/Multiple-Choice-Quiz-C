#include "controller.h"

player p1;


void start(qStruct **questions){
    p1.name = "Joe";
    p1.score = 0;    
    printQuestion(questions);
}

int countAnswer(int qNo, qStruct **questions){
    int numOfLine =0;               
    for(int l =0; l<questions[qNo][0].qSize; l++){            
        if(strlen(questions[qNo][l].question) == 1){        
            numOfLine++;        
        }        
    }
    return numOfLine;
}


char *validation(char *input, size_t size){    
    //remove duplicates e.g. aaababcc => abc    
    char *inputChar = malloc(strlen(input)); 
    strcpy(inputChar, input);
    //sort string by char e.g. with bubble sort
    for(int i = 0; i < strlen(input); i++){
        for(int j = i; j < strlen(input); j++){
            if(inputChar[i] >inputChar[j]){               
                char tmp = inputChar[i];
                inputChar[i] =inputChar[j];
                inputChar[j] = tmp;                      
            }                          
        }
    }
    char *nonDoubles = malloc(size);
    //pick up only singles
    int k =0;
    for(int j = 0; j< strlen(input); j++){
        if(inputChar[j] != inputChar[j+1]){                
            nonDoubles[k] = inputChar[j];            
            k++;
        }          
    }
    
    char *upper = malloc(size); 

    //convert to upper case
    for (int i =0; i<size;i++){
        upper[i] = toupper(nonDoubles[i]);        
    }
    return upper;
}

void checkAnswer(char *input, char *solution){
    
    double result =0;
    double pts = .25;  
    int right = 0;
    int wrong = 0;
   
    char *validInput = validation(input, strlen(solution));
    for (int i =0; i<strlen(solution); i++){
        for (int j =0; j<strlen(validInput); j++){
            if(solution[i] == validInput[j]){
                right++;
            }
        }    
    }
    
    wrong = strlen(validInput) - right;
    printf("%d answer(s) right, %d answer(s) wrong\n", right, wrong);
    result = pts * right - pts * wrong;
    if(result < 0){
        result = 0;
    }
    p1.score += result;
    printf("%s achieved %f pts for this question\n%s's score: %fpts\n\n", p1.name,result, p1.name, p1.score);
    
}


void printQuestion(qStruct **questions){
    printf("Name: %s, Score: %f\n", p1.name, p1.score);    
    int *rndQuestion = randomPos(questions[0][0].line, true);
    for(int k =0; k<questions[0][0].line; k++){
        int rndQ = rndQuestion[k];
        
        char cAnswer = 'A';
        char cSolution = 'A';
        int numAnswer = countAnswer(rndQ, questions);       
        char *solutionStr = (char*)malloc(sizeof(char));
        char *input = (char*)malloc(sizeof(char));
        size_t solutionIdx= 0;        
        int *rndAnswer = randomPos(numAnswer, true); 
        for(int l =0; l < questions[rndQ][0].qSize; l++){                       
            if(strlen(questions[rndQ][l].question) != 1){        
                if(l != 0){
                    printf("%c: %s\n",cAnswer, questions[rndQ][rndAnswer[l%numAnswer]+1].question);                   
                    cAnswer++;
                }else{
                    printf("Q: %s\n", questions[rndQ][l].question);
                }                
            }                       
        }
        scanf("%s", input);
        for(int l =0; l < questions[rndQ][0].qSize; l++){                       
            if(strlen(questions[rndQ][l].question) == 1){                              
                if(cSolution == 'A'){
                    printf("Solution:\n");
                }             
                if(strcmp(questions[rndQ][rndAnswer[l%numAnswer]+numAnswer+1].question, "+") == 0){
                    printf("%c\n",cSolution);
                    solutionStr[solutionIdx] = cSolution;
                    solutionIdx++;                   
                }           
                cSolution++;                
            }                        
        }
        solutionStr[solutionIdx] = '\0';       
        checkAnswer(input, solutionStr);
        printf("\n");         
    }
}