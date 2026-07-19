/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_piscine.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshimots <sshimots@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/19 14:09:39 by sshimots          #+#    #+#             */
/*   Updated: 2026/07/19 15:46:28 by sshimots         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <stdbool.h>

static int	is_delimiter(char c, char const *charset)
{
	while (*charset)
	{
		if (*charset == c)
			return (1);
		charset++;
	}
	return (0);
}

static int	tokens_count(char const *str, char const *charset)
{
	int		count;
	bool	in_delimiter;
	int		i;

	count = 0;
	in_delimiter = true;
	i = 0;
	while (str[i])
	{
		if (in_delimiter && !is_delimiter(str[i], charset))
		{
			in_delimiter = false;
			count++;
		}
		else if (!in_delimiter && is_delimiter(str[i], charset))
			in_delimiter = true;
		i++;
	}
	return (count);
}

static bool	tokens_add_token(char ***tokens_cursor, char const **str_cursor, char const *charset)
{
	char const	*start;
	int			len;

	start = *str_cursor;
	len = 0;
	while (**str_cursor && !is_delimiter(**str_cursor, charset))
	{
		len++;
		(*str_cursor)++;
	}
	**tokens_cursor = ft_strndup(start, len);
	if (!**tokens_cursor)
		return (false);
	(*tokens_cursor)++;
	return (true);
}

char	**ft_split_piscine(char const *str, char const  *charset)
{
	char	**tokens;
	char	**tokens_cursor;
	int		n_tokens;

	n_tokens = tokens_count(str, charset);
	tokens = malloc(sizeof(char *) * (n_tokens + 1));
	if (!tokens)
		return (NULL);
	tokens_cursor = tokens; 
	while (*str)
	{
		if (is_delimiter(*str, charset))
			str++;
		else if (!tokens_add_token(&tokens_cursor, &str, charset))
		{
			ft_strs_free(tokens);
			return (NULL);
		}
	}
	*tokens_cursor = NULL;
	return (tokens);
}
