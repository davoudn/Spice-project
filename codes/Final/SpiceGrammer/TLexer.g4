lexer grammar TLexer;
COMMENT : '*' (~'\n')* '\n';
WHITESPACE : (' ' | '\t');
NEWLINE             : ('\r'? '\n' | '\r')+ ;

RESISTOR_NAME : 'R' TEXT+;
CAPACITOR_NAME : 'C' TEXT+;
INDUCTOR_NAME : 'L' TEXT+;
MUTUAL_INDUCTOR_NAME : 'K'TEXT+;
DIOD_NAME : 'D'TEXT+;
BJT_NAME : 'Q'TEXT+;
MOSFET_NAME : 'M'TEXT+;
JFET_NAME : 'J'TEXT+;
VOLTAGE_SOURCE_NAME : 'V'TEXT+;
CURRENT_SOURCE_NAME : 'I'TEXT+;
PALSE : 'PULSE';
SIN : 'SIN';
EXP : 'EXP';
PWL : 'PWL';
MODEL : '.model';
OFF : 'OFF';






COMPONENT_VALUE : NUMERIC_VALUE+('P' | 'T' |'G' | 'M' |'k' | 'm' |'u' | 'n' |'p' | 'f' |'a');
NUMERIC_VALUE : NUMBERS ('.' | 'e-'|'E-')* NUMBERS*;
NUMBERS : [0-9]+;
END : '.end';
PARAMS: TEXT+ WHITESPACE* '=' TEXT+ WHITESPACE* ;
TEXT :(~('\n'| ' ' | '\t'))(~('\n'| ' ' | '\t'))* ;


