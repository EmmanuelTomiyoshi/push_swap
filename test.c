#include <stdio.h>

enum e_stacks
{
    A,
    B,
    C
}	t_stacks;

enum e_operations_a
{
    pa,
    sa,
    ra,
    rra
};

enum e_operations_b
{
    pb,
    sb,
    rb,
    rrb
};


enum e_operations_c
{
    ss,
    rr,
    rrr
};

int main (void)
{
	enum e_stacks stack;

	stack = 4;

	printf("stack: %d\n", stack);
}