/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeier <mmeier@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 11:57:55 by mmeier            #+#    #+#             */
/*   Updated: 2024/11/29 11:14:25 by mmeier           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int	main(void)
{
	Harl harlBot;
	
	harlBot.complain("debug");
	harlBot.complain("info");
	harlBot.complain("warning");
	harlBot.complain("error");
	harlBot.complain("random Level");
	harlBot.complain("");
	return (0);
}