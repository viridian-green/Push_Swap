/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ademarti <ademarti@student.42berlin.de     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 12:42:58 by ademarti          #+#    #+#             */
/*   Updated: 2024/05/07 12:43:02 by ademarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long	ft_atoi(const char *str)
{
	long	number;
	int		i;
	int		sign;

	i = 0;
	sign = 1;
	number = 0;
	while ((str[i] <= 13 && str[i] >= 9) || str[i] == 32)
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		number *= 10;
		number += str[i] - '0';
		i++;
	}
	return (number * sign);
}

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strdup(const char *s)
{
	char	*dest;
	size_t	i;

	i = 0;
	dest = malloc(ft_strlen(s)+1);
	if (!dest)
		return (NULL);
	while (i < ft_strlen(s))
	{
		dest[i] = s[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_substr(const char *str, unsigned int start, size_t len)
{
	size_t	i;
	size_t	len_str;
	size_t	len_sub;
	char	*substr;

	len_str = ft_strlen(str);
	if (str == NULL || len_str <= start)
		return (ft_strdup(""));
	len_sub = len_str - start;
	if (len_sub > len)
		len_sub = len;
	substr = (char *)malloc(len_sub +1);
	if (substr == NULL)
		return (NULL);
	i = 0;
	while (i < len_sub)
	{
		substr[i] = str[start + i];
		i++;
	}
	substr[i] = '\0';
	return (substr);
}
