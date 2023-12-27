/** Header file for stack data structure implementation
 *
 * @author Blake Nelson
 *
 */
#ifndef STACK_H
#define STACK_H


typedef struct stack {
  void **elements; /**< These are the elements stored in the stack */
  int num_elements;         /**< Num elements in the stack - 0 when empty */
  void **top;               /**< Ptr to empty slot at current top of stack */
  void **base;              /**< Ptr to bottom (base) of the stack */
  int max_size;
} Stack;

/** Function prototypes for stack operations 
 */

void * peek (Stack *stack);
void * pop (Stack *stack);
void * push (Stack *stack, void *element);
int isempty (Stack *stack);
int numelements (Stack *stack);
int maxelements (Stack *stack);
Stack * create (int size);
void destroy (Stack *stack);

#endif
