/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arguilla <arguilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/23 00:04:47 by arguilla          #+#    #+#             */
/*   Updated: 2021/10/09 01:40:24 by arguilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INT_H
# define INT_H

int		ft_atoi(const char *str);
char	*ft_itoa(int n);
int		ft_strtol(const char *nptr, char **endptr, int base, int *err);
int		ft_abs(int i);

#endif
