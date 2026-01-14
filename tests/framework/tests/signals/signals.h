/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tghnassi <tghnassi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/11 19:12:56 by flinguen          #+#    #+#             */
/*   Updated: 2026/01/12 12:30:20 by tghnassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SIGNALS_H
# define SIGNALS_H

# include "../../libunit.h"

int	signal_launcher(t_count *final_count);
int	signal_ok_test(void);
int	signal_ko_test(void);
int	signal_segmentation_fault_test(void);
int	signal_bus_error_test(void);

#endif
