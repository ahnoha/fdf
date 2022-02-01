#ifndef SPLIT_H
#define SPLIT_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char	*ft_substr(char const *s, unsigned int start, size_t len);
size_t	ft_strlen(const char *s);
char	*ft_strncpy(char *dest, const char *src, size_t n);
char	**ft_split(char const *s, char c);
size_t	ft_strclen(const char *s, int param);
#endif