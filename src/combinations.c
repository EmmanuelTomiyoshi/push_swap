/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   combinations.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etomiyos <etomiyos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 10:32:21 by etomiyos          #+#    #+#             */
/*   Updated: 2022/10/24 10:16:26 by etomiyos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

#define INT_MAX 2147483647

long long unsigned int factorial(int n)
{
    int                     i;
    long long unsigned int  fact;
    long long unsigned int  bound;
    
    i = 1;
    fact = 1;
    bound = INT_MAX / n;
    if (n < 0)
        return (printf("error! number is negative\n"));
    if (n == 0)
        return (1);
    else
    {
        while (i <= n)
        {
            if (fact > bound)
            {
                printf("Integer Overflow! Number is too big\n");
                exit(135);
            }
            fact *= i;
            i++;
        }
    }
    return (fact);
}

int simple_combination(int n, int p)
{
    int combination;
    int denominator;
    int numerator;

    if (p > n || n < 0 || p < 0 || p == 0 || n == 0 || (n == 0 && p == 0))
    {
        printf("Error! Floating point exception\n");
        return (1);
    }
    if (p == n)
    {
        printf("combination is: 1\n");
        return (0);
    }
    numerator = factorial(n);
    denominator = factorial(p) * factorial(n - p);
    combination = numerator / denominator;
    printf("combination is: %d\n", combination);
    return (0);
}

// int main(void)
// {
//     int                     n;
//     int                     p;

//     n = 10;
//     p = 4;
//     simple_combination(n, p);
// }