/**
 @sakaijun
 + conversion of text file into string 
 + every row indicated with '\n'
 + end with '\0'

*/

#include "filereader.h"

strStruct readFile(){
    FILE *file;
    file=fopen("quizfile.txt", "r");
    strStruct str;
    str.line = malloc(1);    
    int c;   
    str.numOfLine = 1;
    int i =0;
    
    //file to string (char array)    
    
    while((c = getc(file)) != EOF){        
        str.line[i] =c;
        str.line = realloc(str.line, i+2);    
        if(c == '\n'){              
            str.numOfLine++;
        }
        i++;
    }   

    fclose(file);
    str.line[i] ='\0';

    return str;
    
}