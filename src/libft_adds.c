/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_adds.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdehne <tdehne@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 16:34:20 by tdehne            #+#    #+#             */
/*   Updated: 2022/08/18 08:04:17 by tdehne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static char	*ft_strdup2(const char *s)
{
	char	*arr;
	int		i;

	arr = (char *) malloc(sizeof(char) * ft_strlen(s) + 2);
	if (!arr)
		return (NULL);
	i = 0;
	while (s[i])
	{
		arr[i] = s[i];
		i++;
	}
	arr[i] = ' ';
	arr[i + 1] = '\0';
	return (arr);
}

char	*ft_strjoin_better(char *s1, char *s2)
{
	char	*str_concat;
	int		i;
	int		j;

	if (!s1)
		return (ft_strdup2(s2));
	str_concat = (char *) malloc((ft_strlen(s1) + ft_strlen(s2)) + 2);
	if (!str_concat)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		str_concat[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j])
	{
		str_concat[j + i] = s2[j];
		j++;
	}
	str_concat[i + j] = ' ';
	str_concat[i + j + 1] = '\0';
	free(s1);
	s1 = NULL;
	return (str_concat);
}

void	ft_lstclear2(t_list **lst)
{
	t_list	*tmp;

	tmp = *lst;
	while (*lst)
	{
		tmp = *lst;
		*lst = (*lst)->next;
		free(tmp);
	}
	*lst = NULL;
}
