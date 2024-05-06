lexer grammar TLexer;
//0
COMMENT : '*' (~'\n')* '\n';
//1
WHITESPACE : (' ' | '\t');
//2
NEWLINE             : ('\r'? '\n' | '\r')+ ;

RESISTOR_NAME : 'R' NUMBERS+;
CAPACITOR_NAME : 'C' NUMBERS+;
INDUCTOR_NAME : 'L' NUMBERS+;



// WHITESPACE COMPONENT_VALUE* WHITESPACE (PARAMS*WHITESPACE*) NEWLINE;
// RNAME : 'R' NUMBERS+;
// 5
COMPONENT_VALUE : (NUMERIC_VALUE+'P') |
                  (NUMERIC_VALUE+'T') |
                  (NUMERIC_VALUE+'G') |
                  (NUMERIC_VALUE+'M') |
                  (NUMERIC_VALUE+'k') |
                  (NUMERIC_VALUE+'m') |
                  (NUMERIC_VALUE+'u') |
                  (NUMERIC_VALUE+'n') |
                  (NUMERIC_VALUE+'p') |
                  (NUMERIC_VALUE+'f') |
                  (NUMERIC_VALUE+'a');
// 6
NUMERIC_VALUE : (NUMBERS '.' NUMBERS)   | 
                (NUMBERS)               |
                (NUMBERS'e''-'NUMBERS)  |
                (NUMBERS'E''-'NUMBERS)    ;
// 7
NUMBERS : [0-9]+;
// 8
END : '.end';
// 9
PARAMS: TEXT+ WHITESPACE* '=' TEXT+ WHITESPACE* ;
// 10
TEXT :(~('\n'| ' ' | '\t'))(~('\n'| ' ' | '\t'))* ;


