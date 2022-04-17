/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   play_memmove.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkomeno <tkomeno@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 21:51:09 by tkomeno           #+#    #+#             */
/*   Updated: 2022/04/16 21:20:01 by tkomeno          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

void *ft_memmove(void *dst, const void *src, size_t n) {
  size_t i;

  i = 0;
  if (dst < src) {
    while (i < n) {
      ((unsigned char *)dst)[i] = ((unsigned char *)src)[i];
      i++;
    }
    return (dst);
  }
  if (dst > src)
    while (n > 0) {
      ((unsigned char *)dst)[n - 1] = ((unsigned char *)src)[n - 1];
      n--;
    }
  return (dst);
}

int main(void) {
#define STR "WATERMELONJUICE"
  char str[] = STR;
  char aaa[] = STR;

  // dst < src
  printf("%s\n", str);
  memmove(str, str + 5, 10);
  printf("%s\n\n", str);
  printf("%s\n", aaa);
  ft_memmove(aaa, aaa + 5, 10);
  printf("%s\n", aaa);

  // dst > src
  /* printf("%s\n", str); */
  /* memmove(str + 10, str, 5); */
  /* printf("%s\n\n", str); */
  /* printf("%s\n", aaa); */
  /* ft_memmove(aaa + 10, aaa, 5); */
  /* printf("%s\n", aaa); */

  // src == dst
  /* printf("%s\n", str); */
  /* memmove(str, str, 5); */
  /* printf("%s\n\n", str); */
  /* printf("%s\n", aaa); */
  /* ft_memmove(aaa, aaa, 5); */
  /* printf("%s\n", aaa); */
}
