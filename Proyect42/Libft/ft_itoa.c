/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvdelga <alvdelga@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 17:56:51 by alvdelga          #+#    #+#             */
/*   Updated: 2024/03/18 18:00:36 by alvdelga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stdio.h"
#include "stdlib.h"

int digit_counter(int n)
{
  int i;

  i = 0;

  if (n == 0)
    return (1);
  if (n == -2147483648)
    return (11);
  if (n < 0)
  {
    n = -n;
    i++;
  }
  while (n > 0)
  {
    n = n / 10;
    i++;
  }
  return (i);
}

int exp_counter(int n)
{
  int exp;
  int count;

  count = digit_counter(n);

  if (n == 0)
    return (1);
  if (n == -2147483648)
    return (1000000000);
  if (n < 0)
  {
    count--;
    n = -n;
  }
  exp = 1;
  while (--count > 0)
  {
    exp = exp * 10;
  }
  return (exp);

}

char *ft_itoa(int n)
{
  char *src;
  int copy;
  int i;
  int exp;

  copy = n;
  exp = exp_counter(n);
  i = 0;

  if (!(src = malloc(digit_counter(n) + 1)))
    return (0);
  if (copy < 0)
  {
    src[i++] = '-';
    copy = -copy;
  }
  while (exp > 0)
  {
    src[i] = (copy / exp) + 48;
    copy = copy % exp;
    exp = exp / 10;
    i++;
  }
  src[i] = '\0';
  return (src);
  
}

int main()
{
  int num;

  num = -2050700;
  printf("%s", ft_itoa(num));
  return (0);
}
