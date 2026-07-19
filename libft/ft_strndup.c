/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshimots <sshimots@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/19 15:47:27 by sshimots          #+#    #+#             */
/*   Updated: 2026/07/19 16:02:59 by sshimots         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strndup(char const *s, size_t n)
{
	size_t	len;
	char	*copy;

	len = 0;
	while (len < n && s[len])
		len++;
	copy = malloc(len + 1);
	if (!copy)
		return (NULL);
	ft_memmove(copy, s, len);
	copy[len] = '\0';
	return (copy);
}
