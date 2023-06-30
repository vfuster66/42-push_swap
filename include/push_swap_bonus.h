/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfuster- <vfuster-@student.42perpignan.fr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 13:56:20 by vfuster-          #+#    #+#             */
/*   Updated: 2023/06/30 08:51:40 by vfuster-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_BONUS_H
# define PUSH_SWAP_BONUS_H

# include "../libft/libft.h"
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

//-_-_-_-_-_-_-_-_-_-_- Structures
typedef struct s_node
{
	int				value;
	int				index;
	int				position;
	struct s_node	*next;
	struct s_node	*previous;
}	t_node;

typedef struct s_stack
{
	struct s_node	*a;
	struct s_node	*b;
	int				len_a;
	int				len_b;
	int				total_len;
}	t_stack;

#endif
