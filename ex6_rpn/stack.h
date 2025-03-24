// stack.h: interface for simple floating-point number stack

#ifndef _stack_h
#define _stack_h

// push number onto stack, returning pushed value
double push(double number);

// pop top value from stack
double pop();

// reset stack to be empty
void clear_stack();

#endif