// CS311 Yoshii
// INSTRUCTION:
// Look for ** to complete this program (Use control-S)
// The output should match my hw1stackDemo.out

//=========================================================
// HW#: HW1P1 stack application (post-fix evaluation)
// Your name: Neal Archival
// Complier:  g++ stack.cpp client1.cpp
// File type: client program client1.cpp
//===========================================================

#include <iostream> // std::cout, std::cerr
#include <string> // std::string
#include <cstdlib> // exit(1)

#include "stack.h" // stack object

using namespace std;

bool isOperator(char ch);
bool isDigit(char ch);

// Purpose of the program: Enter a postfix expression to be evaluated and get the result
// Algorithm: Postfix Evaluation. Loop through expression, push numbers into stack, if an operator is encountered, pop twice and do math
int main() {
    stack postfixstack;  // integer stack
    string expression;   // user entered expression

    cout << "type a postfix expression: ";
    cin >> expression;

    int i = 0;  // character position within expression
    char item;  // one char out of the expression

    int box1;  // receive things from pop
    int box2;  // receive things from pop

    while (expression[i] != '\0') { // iterate through expresion until null termination of string
        try {
            item = expression[i++];  // current char // increment i after reading
            if(isOperator(item)) { // check if char is an operator by calling isOperator function
              postfixstack.pop(box2);
              postfixstack.pop(box1); 
              switch(item) { // determine the correct mathematical operation and push into the stack
                case('+'):
                  postfixstack.push(box1 + box2);
                  break;
                case('-'):
                  postfixstack.push(box1 - box2);
                  break;
                case('*'):
                  postfixstack.push(box1 * box2);
                  break;
                case('/'):
                  postfixstack.push(box1 / box2);
                  break;
              }
            } else if (isDigit(item)) { // if char is in between digit ascii values
                postfixstack.push(item - '0'); // convert item from char -> int by - '0' or 48 ascii val
            } else { // if unidentified char ('?', '&', etc)
              throw "Invalid Element";
            }
            postfixstack.displayAll();
            // ** do all the steps in the algorithm given in Notes-2
        }  // this closes try
        // Catch exceptions and report problems and quit the program now
        // (exit(1)). Error messages describe what is wrong with the expression.
        catch (stack::StackOverflow_Error) { 
          cerr << "Error: Stack Overflow. Too Many Operands" << endl;
          exit(1);
        } catch (stack::StackUnderflow_Error) {
          cerr << "Error: Stack Underflow. Too Few Operands" << endl;
          exit(1);
        } catch (char const* errormsg) { /* for invalid item case */
          cerr << errormsg << endl;
          exit(1);
        }
    }  // end of while loop

    // After the loop successfully completes:
    // Pop the result and show it.
    int result;
    postfixstack.pop(result);
    // if the postfix stack is not empty after popping the last element, expression is missing additional operators (too many operands)
    if(!postfixstack.isEmpty()) {
      cout << "Error: Incomplete Expression" << endl;
    } else {
      cout << "The result was: " << endl;
      cout << result << endl;
    }
    return 0;
}  // end of the program

// Purpose: Check if a character is a math operator (plus, minus, multiply, divide)
bool isOperator(char ch) {
  switch(ch) {
    case('+'):
    case('-'):
    case('*'):
    case('/'):
      return true;
  }
  return false;
}

// Purpose: Check if a character is a digit if it is in between 0 - 9 ASCII value
bool isDigit(char ch) { return ch >= 48 && ch <= 57 ? true : false; }