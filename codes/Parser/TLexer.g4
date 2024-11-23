lexer grammar TLexer;
COMMENT : '*' (~'\n')* '\n';
WHITESPACE : (' ' | '\t');
NEWLINE    : ('\r'? '\n' | '\r')+ ;

RESISTOR_NAME : 'R' TEXT+;
CAPACITOR_NAME : 'C' TEXT+;
INDUCTOR_NAME : 'L' TEXT+;
VOLTAGE_SOURCE_NAME : 'V'TEXT+;
CURRENT_SOURCE_NAME : 'I'TEXT+;
DC : 'DC';


COMPONENT_VALUE : (NUMERIC_VALUE+ ('P' | 'T' |'G' | 'M' |'k' | 'm' |'u' | 'n' |'p' | 'f' |'a')) | NUMERIC_VALUE+;
NUMERIC_VALUE : NUMBERS ('.' | 'e-'|'E-')* NUMBERS*;
NUMBERS : [0-9]+;
END : '.end';
PARAMS: TEXT+ WHITESPACE* '=' TEXT+ WHITESPACE* ;
TEXT :(~('\n'| ' ' | '\t'))(~('\n'| ' ' | '\t'))* ;


