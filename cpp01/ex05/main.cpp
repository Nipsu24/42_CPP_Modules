/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeier <mmeier@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 11:57:55 by mmeier            #+#    #+#             */
/*   Updated: 2024/11/29 12:23:14 by mmeier           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int	main(void)
{
	Harl harlBot;
	
	harlBot.complain("DEBUG");
	harlBot.complain("INFO");
	harlBot.complain("WARNING");
	harlBot.complain("ERROR");
	harlBot.complain("random Level");
	harlBot.complain("");
	return (0);
}