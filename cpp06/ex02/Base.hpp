/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeier <mmeier@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 11:17:47 by mmeier            #+#    #+#             */
/*   Updated: 2025/02/05 16:10:28 by mmeier           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BASE_HPP
# define BASE_HPP

#include <iostream>

class Base {
	private:
		
	public:	
		virtual ~Base();
		//methods
		Base*	generate(void);
		void	identify(Base* p);
		void	identify(Base& p);
		
};

#endif