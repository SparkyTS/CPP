#include <stdio.h>
#include <ctype.h>
#include <string.h>

char Operator[20]  = {'\0'}; int Opcount = 0 ;
char singleChars[10] = {'\0'}; int sccount = 0;
char Variable[20][20]; int line = 0 ,col = 0 ;
char Keywords[32][10]; int keycount = 0 ;
char Function[10][20]; int funcount = 0 ;
int isoperator(const char c){return (c == '+' || c=='-' || c == '*' || c == '/' || c == '%' || c == '=' || c == '<' || c == '>');}
int isrepetedop(const char op){ int i = 0 ; for(;i<Opcount;i++) if (op == Operator[i]) return 1; return 0;}
int isrepetedvar(const char* var ){ int i = 0 ; for (;i < line     ; i++) if(!strcmp(var,Variable[i])) return 1; return 0;}
int isrepetedkey(const char* key) { int i = 0 ; for (;i < keycount ; i++) if(!strcmp(key,Keywords[i])) return 1; return 0;}
int isKeyword(const char *str){
if (!strcmp(str, "if")      || !strcmp(str, "else")     || !strcmp(str, "while")    || !strcmp(str, "do")     ||
    !strcmp(str, "break")   || !strcmp(str, "continue") || !strcmp(str, "int")      || !strcmp(str, "double") ||
    !strcmp(str, "float")   || !strcmp(str, "return")   || !strcmp(str, "char")     || !strcmp(str, "case")   ||
    !strcmp(str, "char")    || !strcmp(str, "sizeof")   || !strcmp(str, "long")     || !strcmp(str, "short")  ||
    !strcmp(str, "typedef") || !strcmp(str, "switch")   || !strcmp(str, "unsigned") || !strcmp(str, "void")   ||
    !strcmp(str, "static")  || !strcmp(str, "struct")   || !strcmp(str, "goto")     || !strcmp(str, "enum")   ||
    !strcmp(str, "extern")  || !strcmp(str, "union")    || !strcmp(str, "const")    || !strcmp(str, "signed")    )
        return 1;
    return 0;
}

int main(){
    char Exp[] = " #include<stdio.h> \n \
                   #include <conio.h> \n \
                   #define def 100     \n \
                   printf(\"Hello\");   \n \
                   int a = 10 ;          \n \
                   int b = 20 ;           \n \
                   swap(a,b);              \n \
                   char z = 'z'             \n \
                   static const char character = 'c' ; \n \
                   //adding a and b                     \n \
                   int c = a + b ;                       \n \
                   /*End of code*/";
    int Constant[20] = {0} , ccount = 0 ;
    int ExpLength = strlen(Exp);
    int i = 0;
    printf("Headers and Definitions : \n\n ");
    while( i < ExpLength){

         if(Exp[i]=='#'){
            while(Exp[i]!='\n')
                printf("%c",Exp[i++]);
            printf(", ");
         }

        if(isdigit(Exp[i])){
            int num = 0 ;
            do{
                num = num * 10 + Exp[i++]-'0';
            }while(isdigit(Exp[i]));
        Constant[ccount++] = num;
        }

        if( (Exp[i]=='/') && (Exp[i+1]=='*'))
        {
            i++;
            while(!((Exp[++i]=='*') && (Exp[i+1]=='/')));
            i=i+2;
        }
        else if( (Exp[i]=='/') && (Exp[i+1]=='/'))
        {
            i=i+2;
            while(Exp[i]!='\n')i++;
            i++;
        }

        if(isoperator(Exp[i]) && !isrepetedop(Exp[i])){
            Operator[Opcount++] = Exp[i++];
        }
        if(Exp[i]=='\'' && Exp[i+2]=='\''){
            singleChars[sccount++] = Exp[i+1];
            i = i + 3;
        }
        if(isalnum(Exp[i])){
                int col = 0 ;
            do{
                Variable[line][col++] = Exp[i++];
            }while(isalnum(Exp[i]));
            Variable[line][col] = '\0';

            if(isKeyword(Variable[line])){

                if(!isrepetedkey(Variable[line])){
                    strcpy(Keywords[keycount++],Variable[line]);
                    Variable[line][0]='\0';
                }
            }
            else if(Exp[i]=='(') {strcpy(Function[funcount++],Variable[line]); Variable[line][0] = '\0';}
            else if(!isrepetedvar(Variable[line])) line++;

            else Variable[line][0] = '\0';


        i--;}


i++;}

    printf("\n\nPrinting encountered %d Keywords : \n\n ",keycount);
    for (i = 0 ; i<keycount ; i++)
        printf("%s, ",Keywords[i]);
    printf("\n\nPrinting encountered %d Constants : \n\n ",ccount);

    for(i = 0; i < ccount ; i++)
        printf("%d, ",Constant[i]);

    printf("\n\nPrinting encountered %d single characters :\n\n ",sccount);
    for(i = 0 ; i<sccount ; i++)
            printf("\'%c\', ",singleChars[i]);

    printf("\n\nPrinting encountered %d Operators : \n\n ",Opcount);

    i = 0 ;
    while(Operator[i])
        printf("%c, ",Operator[i++]);

    printf("\n\nPrinting encountered %d Function Names :\n\n ",funcount);
    for(i = 0 ; i<sccount ; i++)
            printf("%s, ",Function[i]);

    printf("\n\nPrinting encountered %d Variables , Function Names and row string literals : \n\n ",line);
    for(i = 0 ; i < line ; i++)
            printf("%s, ",Variable[i]);
return 0 ;
}
