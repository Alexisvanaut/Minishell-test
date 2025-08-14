/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucorrei <lucorrei@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 15:07:00 by lucorrei          #+#    #+#             */
/*   Updated: 2025/05/10 18:28:11 by lucorrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# define NEEDS_ALIGN 1
# define ALIGN_LEFT 2
# define ZERO_PAD 4
# define NUMBER_PLUS 8
# define NUMBER_SPACE 16
# define HEX_SIGNAL 32
# define TO_UPPER 64
# define IS_NEG 128
# define FORMAT_ERROR 256
# define IS_CHAR 512
# define INT_MIN_FTPF -2147483648

# define FLAGS "-0# +%"
# include "../libft.h"
# include <stdarg.h>

typedef struct s_format
{
	size_t	min;
	size_t	max;
	char	*string;
	short	formatting;
}	t_format;

void	format_string(void *ptr);
void	save_regular_str(char **s, char **cursor, t_list **lst);
int		ft_printf(const char *s, ...);
int		check_and_print(t_list *lst);
char	*prepend(short formatting);
void	ft_toupper_iter(unsigned int i, char *c);
char	*align_left(t_format *item);
char	*align_right(t_format *item);
void	handle_width(void *fmt_ptr);
void	handle_max(t_format *item);
char	chr_in_str(char c, char *str);
void	parse_flags(char cursor, t_format *format);
void	handle_ints(char type, t_format *to_add, int integer);
void	save_regular_str(char **s, char **cursor, t_list **lst);
void	handle_pointers(va_list *args, t_format *to_add);

#endif // FT_PRINTF_H
