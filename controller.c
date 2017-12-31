/**
 @sakaijun
 controls gaming procedure: 
 + create player with name, per right answer: +0.25pts, per wrong answer: -0.25pts, non-checked: 0pts 
 + input validation: case, order insensitive, remove double chars eg. aaabAbCc => ABC
 + sum score, calculate end result
*/

#include "controller.h"

player p1;

void start(qStruct **questions){
    int yn =0;
    do{
        p1.name = malloc(100 * sizeof(char)); 
        printf("Enter your name: ");
        scanf("%s", p1.name);   
        p1.score = 0;    
        printQuestion(questions);
        printf("Restart game? (y/n): ");
        yn = checkYN();
    }while(yn == 1);
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
    /*
        + convert input to upper case
        + sort string by alphabet e.g. with bubble sort
    */
    for (int i =0; i<strlen(input); i++){
        input[i] = toupper(input[i]);               
    }   
    for(int i = 0; i < strlen(input); i++){
        for(int j = i; j < strlen(input); j++){
            if(input[i] >input[j]){               
                char tmp = input[i];
                input[i] =input[j];
                input[j] = tmp;                      
            }                          
        }
    }
    input[strlen(input) + 1] = '\0';    
    char *nonDoubles = malloc(size + 1);
    /*
        + remove duplicates e.g. aaabAbCc => ABC       
    */
    int k =0;
    for(int j = 0; j< strlen(input); j++){
        if(input[j] != input[j+1]){                
            nonDoubles[k] = input[j];            
            k++;
        }          
    }
    nonDoubles[k + 1] = '\0';    
    return nonDoubles;
}


bool findLetter(size_t aSize, char *input){    
    char beginChar = 'A';   
    bool found = true;  
    char *str = malloc(aSize + 1);
    int i = 0;

    do{
        str[i] = beginChar;         
        beginChar++;        
        i++;
    }while(i < aSize); 
    str[i+1] = '\0';

    for (int i = 0; i < strlen(input); i++){
        if(!strchr(str, toupper(input[i]))){
            printf("%c is not in %s, repeat input\n", input[i], str);
            found = false;
        }
    }
    return found;
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
    printf("%s achieved %.2f pts for this question\n%s's score: %.2fpts\n\n", p1.name,result, p1.name, p1.score);
    
}

int checkYN(){
    char input;
    int io =0;
     do{
        scanf(" %c", &input);			
        if (toupper(input) != 'Y' && toupper(input) != 'N'){
            printf("enter y or n\n");                               
        }else{
            io = ('Y' == toupper(input)) ? 1 : 0;
            break;
        }
    }while(1);   	
    return io;
}


void printQuestion(qStruct **questions){
    char shuffleQ, shuffleA;    
    printf("Shuffle order of questions (y/n): ");
    shuffleQ = checkYN();
    printf("Shuffle order of answer possibilities, each question (y/n): ");
    shuffleA = checkYN();    
    printf("Name: %s, Score: %.2f\n", p1.name, p1.score);       
    int *rndQuestion = randomPos(questions[0][0].line, shuffleQ);
    for(int k =0; k<questions[0][0].line; k++){
        int rndQ = rndQuestion[k];        
        char beginChar = 'A';        
        int numAnswer = countAnswer(rndQ, questions);       
        char *input = malloc(100 * sizeof(char));        
        size_t solutionIdx= 0;
        size_t aSize = 0;        
        int *rndAnswer = randomPos(numAnswer, shuffleA);
        printf("Q: %s\n", questions[rndQ][0].question); 
        for(int l =0; l < numAnswer; l++){                 
            printf("%c: %s\n",beginChar, questions[rndQ][rndAnswer[l]+1].question);                       
            beginChar++;
            aSize++;                     
        }
        do{
            scanf("%s", input);
        }while(!findLetter(aSize, input));
        
        char *solutionStr = malloc(aSize + 1);
        beginChar = 'A';
        for(int l =0; l < numAnswer; l++){                           
            if(beginChar == 'A'){
                printf("Solution:\n");
            }             
            if(strcmp(questions[rndQ][rndAnswer[l]+1+numAnswer].question, "+") == 0){
                printf("%c\n",beginChar);
                solutionStr[solutionIdx] = beginChar;
                solutionIdx++;                   
            }           
            beginChar++;                     
        }        
        solutionStr[solutionIdx + 1] = '\0';              
        checkAnswer(input, solutionStr);
        printf("\n");         
    }
}