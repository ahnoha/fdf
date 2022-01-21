#include "list.h"


int ft_strlen(const char *str)
{
	int i;

	i =0;
	while (str[i])
	{
		i++;
	}
	return i;
}

static	char	*ft_strcpy(char *dst, const char *src)
{
	int	i;

	i = 0;
	while (src[i])
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}

char	*ft_strdup(const char *s)
{
	int		len;
	char	*dst;

	len = ft_strlen(s);
	dst = (char *)malloc(sizeof(char) * (len + 1));
	if (!dst)
		return (NULL);
	ft_strcpy(dst, s);
	return (dst);
}

int main()
{
	t_list *list;
	t_element *elm;

	list = list_new();
	add_back(list, ft_strdup("3"));
	add_back(list, ft_strdup("1"));
	add_back(list, ft_strdup("2"));
	// add_front(list, ft_strdup("2"));
	// add_front(list, ft_strdup("3"));
	printf("%d\n",list->size);
	elm = list->head;

	while (elm)
	{
		printf("%s\n",elm->content);
		elm = elm->next ;
	}
	return 0;
}