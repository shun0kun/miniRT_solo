/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl_internal.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shimotsukasashunsuke <shimotsukasashuns    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 11:05:42 by sshimots          #+#    #+#             */
/*   Updated: 2026/07/18 17:51:51 by shimotsukas      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GNL_INTERNAL_H
# define GNL_INTERNAL_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include "../libft.h"
# include <stdbool.h>
# include <unistd.h>
# include <stdlib.h>

char	*if_has_nl_get_line(char **p_stash);
char	*get_last_line(char **p_stash);
char	*buf_join(char **p_stash, char **p_buf);
char	*free1_and_return_null(char **p);
char	*free2_and_return_null(char **p1, char **p2);
bool	has_nl(char *s);

#endif
