%{
    #include<stdio.h>
    int yylex();
    int yyerror();
%}
%token digit
%%
start: E { printf("%d\n", $1); }
;
E: E '+' T { $$ = $1 + $3; }
| E '-' T { $$ = $1 - $3; }
|T
;
T: T '*' F { $$ = $1 * $3; }
| T '/' F{ if($3) $$ = $1 / $3;
            else return yyerror("Divide by zero"); }
|F
;
F: '(' E ')' { $$ = $2; }
| digit { $$ = $1; }
;
%%
int yyerror(char* s) {
fprintf(stderr, "%s\n", s);
return 0;
}
int main() {
printf("Input the expression: ");
yyparse();
}