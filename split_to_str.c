/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_to_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ademarti <ademarti@student.42berlin.de     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 11:43:27 by ademarti          #+#    #+#             */
/*   Updated: 2024/05/07 13:58:42 by ademarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

size_t	count_words(const char *str, char c)
{
	size_t	count;

	count = 0;
	while (*str)
	{
		if (*str != c)
		{
			count++;
			while (*str && *str != c)
				str++;
		}
		else
			str++;
	}
	return (count);
}

void	putstr(const char *s, char **strings, char c)
{
	const char	*start;
	int			j;

	j = 1;
	while (*s)
	{
		if (*s != c)
		{
			start = s;
			while (*s && *s != c)
				s++;
			strings[j] = ft_substr(start, 0, s - start);
			if (!strings[j++])
			{
				while (j-- >= 0)
					free(strings[j]);
				free(strings);
				return ;
			}
		}
		else
			s++;
	}
	strings[j] = NULL;
}

char	**ft_split(char const *s, char c)
{
	char	**strings;
	int		count;

	if (!s)
		return (NULL);
	count = count_words(s, c);
	strings = (char **)malloc(sizeof(char *) * (count + 2));
	if (!strings)
		return (NULL);
	strings[0] = malloc(sizeof(char));
	if (strings[0] == NULL)
		return (NULL);
	strings[0][0] = '\0';
	putstr(s, strings, c);
	strings[count + 1] = NULL;
	return (strings);
}
