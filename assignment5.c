// online C compiler to run C program online - programiz
/*
<expression> ::= <term> { ("+" | "-") <term> }
<term> ::= <factor> { ("*" | "/") <factor> }
<factor> ::= <number>
| "(" <expression> ")"
<number> ::= [ "-" ] <digit> { <digit> } [ "." <digit> { <digit> } ]
<digit> ::= "0" | "1" | "2" | "3" | "4" | "5" | "6" | "7" | "8" | "9"
*/
//YOU HAVE 4 TASKS TO COMPLETE
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
char *input; // Pointer to track the input string
char token; // Current character being processed
// Move to the next token (skipping spaces)
//nothing to change in nextToken
void nextToken() {
while (*input == ' ') input++;
token = *input;
if (token) input++;
}
// Function declarations-- nothing to change
double expr(); // Handles + and -
double term(); // Handles * and /
double factor(); // Handles numbers and parentheses
double number(); // Parses multi-digit and floating-point numbers
// Evaluate expressions with addition and subtraction
// nothing to change in expr()
double expr() {
double result = term();
while (token == '+' || token == '-') {
char op = token;
nextToken();
result = (op == '+') ? result + term() : result - term();
}
return result;
}
// Evaluate terms with multiplication and division
// 1 TASK TO DO HERE
double term() {
double result = factor();
while (token == '*' || token == '/') {
char op = token;
nextToken();
double nextFactor = factor();
// TASK 1: print an error message if the operator is '/' and we divide by 0
//so we are going to check if the operator is division and the next factor in the pointer is a zero we are going to do a simple print statement saying its an error and to break essentially 
if (op == '/' && nextFactor == 0) {
            printf("Error: Division by zero!\n");
            exit(1); // Exit or return an error code
        }
result = (op == '*') ? result * nextFactor : result / nextFactor;
}
return result;
}
// Handle numbers and expressions inside parentheses
double factor() {
if (token == '(')
{
nextToken();
double result = expr();
//TASK 2: Complete other cases where token is ')' or,
// otherwise, you handle an error message
if (token != ')') {  // If there's no closing parenthesis print its an error and break/ exit 
            printf("Error: Mismatched parentheses!!\n");
            exit(1); // Exit or handle error
        }

        nextToken(); // move past ')' to next char in pointer
        
return result;
}
//case where it isnt expected like if theres an extra closing etc
 if (token == ')') {
        printf("Error: Unexpected closing parenthesis!\n");
        exit(1); // Exit or handle error
    }

return number(); //returning number in case if it isnt parenthesis
}
// Parse integer and floating-point numbers
double number() {
double result = 0.0, fraction = 0.1;
int isFloat = 0, sign = 1;
if (token == '-') { sign = -1; nextToken(); }
while (isdigit(token) || token == '.') {
    //first check if token has a decimal
if (token == '.') {
            isFloat = 1;  // marking the number as floating and has fraction 
        } else if (isFloat) {
            result += (token-'0') * fraction; // calculate fractional part
            fraction *= 0.1; //decrease the place value
        } else {
            result = result*10+(token-'0'); //handle integer part
        }
        nextToken();
    }

    return sign * result; // returning result and if positive or negative 
}//Done, Good Job!
/////////////////
// Main function to read and evaluate an expression
int main() {
char expression[100];
printf("Enter an expression: ");
fgets(expression, sizeof(expression), stdin);
input = expression;
nextToken();
printf("Result: %lf\n", expr());
return 0;
}