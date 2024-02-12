/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssghioua <ssghioua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 21:16:08 by ssghioua          #+#    #+#             */
/*   Updated: 2024/01/18 21:16:09 by ssghioua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./lib/ft_printf.h"

int	ft_print_str(t_printf *props, char *str)
{
	int		i;
	char	*new;

	i = 0;
	if (!str)
		return (ft_print_str(props, ft_strjoin("(null)", "")));
	if (*str || props->flags->width)
	{
		if ((props->flags_len || props->negative_nbr)
			&& !props->updated
			&& !props->error_format)
		{
			new = ft_update_str(props, str);
			return (ft_print_str(props, new));
		}
	}
	if (ft_strchr("csdiupxX%", props->specifier)
		|| props->error_format || *str == '%')
		while (str[i] != '\0')
			props->format_len += write(1, &str[i++], 1);
	free(str);
	return (props->format_len);
}

char	*ft_update_str(t_printf *props, char *str)
{
	char	*new;

	if (props->flags_len)
		new = ft_flags_processing(props, str);
	else
		new = ft_append_prefix(props, str);
	props->updated = 1;
	return (new);
}

char	*ft_flags_processing(t_printf *props, char *str)
{
	char	*new;
	char	*infill;
	int		width;
	int		precision;

	precision = props->flags->precision;
	width = props->flags->width;
	infill = ft_strjoin("", "");
	if (precision == -1 || (precision
			&& ft_strchr("sc", props->specifier)))
		str = ft_slice_str(props, str);
	if (width > precision || precision)
	{
		if (width > precision)
			infill = ft_generate_infill(props, infill, str, width);
		else if (precision < (int)ft_strlen(str) || props->specifier != 's')
			infill = ft_generate_infill(props, infill, str, precision);
	}
	if (props->flags->minus)
		new = ft_justify_infill_right(str, infill);
	else
		new = ft_justify_infill_left(str, infill);
	if (props->flags->plus || props->negative_nbr || props->flags->blank)
		new = ft_append_prefix(props, new);
	return (new);
}

char	*ft_generate_infill(t_printf *props, char *infill, char *str, int size)
{
	char	*temp;
	int		i;
	int		str_len;

	i = 0;
	str_len = (int)ft_strlen(str);
	if (props->flags->plus || (props->negative_nbr && !props->flags->precision))
		size--;
	if (props->flags->blank)
		size--;
	size -= str_len;
	while (i < size)
	{
		temp = ft_strjoin(infill, "");
		free(infill);
		if (!ft_strchr("sc", props->specifier)
			&& (props->flags->zero
				|| props->flags->precision))
			infill = ft_strjoin(temp, "0");
		else
			infill = ft_strjoin(temp, " ");
		free(temp);
		i++;
	}
	return (infill);
}