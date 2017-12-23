#include "filereader.h"

strStruct readFile(){
    FILE *file;
    file=fopen("quizfile.txt", "r");
    strStruct str;
    str.line = malloc(1);    
    int c;   
    size_t numOfLine=0;
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