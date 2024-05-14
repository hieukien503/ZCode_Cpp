grammar ZCode;

@lexer::header {
#include "./lexererr.hpp"
}

options {
    language = Cpp;
}

/* Keywords */
BREAK: 'break';
CONTINUE: 'continue';
IF: 'if';
ELSE: 'else';
ELIF: 'elif';
FOR: 'for';
UNTIL: 'until';
BY: 'by';
TRUE: 'true';
FALSE: 'false';
NUMBER: 'number';
BOOL: 'bool';
STRING: 'string';
RETURN: 'return';
DYNAMIC: 'dynamic';
NOT: 'not';
AND: 'and';
VAR: 'var';
OR: 'or';
BEGIN: 'begin';
END: 'end';
FUNC: 'func';

/* Operators */
ADD: '+';
SUB: '-';
MUL: '*';
DIV: '/';
MOD: '%';
STR_EQ: '==';
EQ: '=';
NOT_EQ: '!=';
REV_ARROW: '<-';
LT: '<';
LTE: '<=';
GT: '>';
GTE: '>=';
CONCAT: '...';

/* Separators */
LR: '(';
RR: ')';
LS: '[';
RS: ']';
COMMA: ',';

/* Identifiers */
ID: [A-Za-z_][A-Za-z0-9_]*;

/* Literals */
fragment DOT: '.';
fragment FInt: [0-9]+;
fragment FDec: DOT [0-9]*;
fragment FExp: [Ee][+-]?[0-9]+;
fragment CHAR: (~[\\\n"]) | ('\\' [bntrf'\\]) | '\'"';

NUM_LIT: FInt FDec? FExp?;
STR_LIT: '"' CHAR* '"' {
this->_text = this->getText();
this->_text.erase(this->_text.begin(), this->_text.begin() + 1);
this->_text.pop_back();
};

/* Newline */
NEWLINE: '\r'?'\n' {this->_text = "\n";};

/* Program */
program: NEWLINE* decl (NEWLINE | decl)* EOF;
decl: (var_decl | func_decl) NEWLINE+;

/* Variable declaration */
var_decl: ((vartype | DYNAMIC) ID (REV_ARROW expr)?)
        | (VAR ID REV_ARROW expr)
        | (vartype ID LS num_list RS (REV_ARROW expr)?);

num_list: NUM_LIT COMMA num_list | NUM_LIT;

vartype: NUMBER | BOOL | STRING;

/* Function declaration */
func_decl: FUNC ID LR params? RR NEWLINE* (return_stmt | block_stmt)?;
params: param COMMA params | param; // BNF way
/* Or you can write:
params: param (COMMA param)*; // EBNF way
*/
param: (vartype ID)
    | (vartype ID LS num_list RS);

/* Statement */
stmt: (var_decl | if_stmt | assign_stmt | for_stmt | break_stmt 
    | continue_stmt | func_call_stmt | return_stmt | block_stmt);
if_stmt: (IF LR expr RR NEWLINE* stmt) (NEWLINE ELIF LR expr RR NEWLINE* stmt)* (NEWLINE ELSE stmt)?;
assign_stmt: lhs REV_ARROW expr;
lhs: ID | elem_array;
elem_array: ID LS expr_list RS;
for_stmt: FOR ID UNTIL expr BY expr NEWLINE* stmt;
break_stmt: BREAK;
continue_stmt: CONTINUE;
return_stmt: RETURN expr?;
func_call_stmt: ID LR expr_list? RR;
block_stmt: BEGIN NEWLINE+ (stmt* NEWLINE+)* END;

/* Expressions */
expr: expr1 CONCAT expr1 | expr1;
expr1: expr2 (EQ | NOT_EQ | LT | GT | LTE | GTE | STR_EQ) expr2 | expr2;
expr2: expr2 (AND | OR) expr3 | expr3;
expr3: expr3 (ADD | SUB) expr4 | expr4;
expr4: expr4 (MUL | DIV | MOD) expr5 | expr5; 
expr5: NOT expr5 | expr6;
expr6: (ADD | SUB) expr6 | expr7;
expr7: array_cell | operands;
array_cell: (ID | func_call) LS expr_list RS;
func_call: ID LR expr_list? RR;
operands: ID | (LR expr RR) | literals | func_call;
literals: NUM_LIT | STR_LIT | TRUE | FALSE | array_lit;
array_lit: LS expr_list RS;
expr_list: expr (COMMA expr)*; // EBNF way
/* Or you can write:
expr_list: expr COMMA expr_list | expr;
*/

/* Comment */
CMT: '##' ~[\r\n]* -> skip;
WS: [ \b\f\t]+ -> skip; // Skip tabs, spaces and carriage return

/* Errors */
ERROR_CHAR: . {
throw ErrorToken(this->_text);
};
UNCLOSED_STRING: '"' CHAR* ('\n')? {
this->_text = this->getText();
this->_text.erase(this->_text.begin(), this->_text.begin() + 1);
if (this->_text.back() == '\n') {
    this->_text.pop_back();
    if ((int)this->_text.length() > 0 and this->_text.back() == '\r') {
        this->_text.pop_back();
    }
}

throw UncloseString(this->_text);
};
ILLEGAL_ESCAPE: '"' CHAR* ('\\' ~[bnftr'\\]) {
this->_text = this->getText();
this->_text.erase(this->_text.begin(), this->_text.begin() + 1);
throw UncloseString(this->_text);
};