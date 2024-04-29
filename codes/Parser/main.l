%{
int chars;
int lines;
%}

%%
\n 	{lines++;}
. 	{chars++;}
%%

int yywrap(){}
int main(){
	yylex();
	printf("number of char is %d and lines is %d",chars,lines);
	return 0;
}