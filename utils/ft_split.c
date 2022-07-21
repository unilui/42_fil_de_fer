/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lufelip2 <lufelip2@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 04:55:46 by lufelip2          #+#    #+#             */
/*   Updated: 2022/07/21 04:56:43 by lufelip2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	word_count(char const *s, char c);
static char	*new_str(char const *s, int len);
static int	next_break(char const *s, char c);

char	**ft_split(char const *s, char c)
{
	char	**arr;
	char	*str;
	char	*start;
	int		i;
	int		words;

	i = 0;
	str = ft_strtrim(s, &c);
	start = str;
	words = word_count(str, c);
	arr = (char **) malloc((words + 1) * sizeof(char *));
	if (arr == NULL)
		return (NULL);
	while (i < words)
	{
		arr[i++] = new_str(str, next_break(str, c));
		str += (next_break(str, c));
		while (*str == c)
			str++;
	}
	arr[i] = NULL;
	free(start);
	return (arr);
}

static int	word_count(char const *s, char c)
{
	int	i;
	int	words;

	i = 0;
	words = 1;
	if (ft_strlen(s) == 0)
		return (0);
	while (s[i])
	{
		if (s[i] == c && s[i - 1] != c)
			words++;
		i++;
	}
	return (words);
}

static int	next_break(char const *s, char c)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == c)
			return (i);
		i++;
	}
	return (i);
}

static char	*new_str(char const *s, int len)
{
	char	*str;
	int		i;

	i = 0;
	str = malloc(len + 1);
	while (i < len)
	{
		str[i] = s[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}
