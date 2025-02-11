/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeier <mmeier@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 13:48:35 by mmeier            #+#    #+#             */
/*   Updated: 2025/02/11 15:03:29 by mmeier           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

#include <vector>
#include <set>

class Span {
	private:
		unsigned int		mElements;
		std::set<int>		mArray;

	public:
		Span();
		Span(unsigned int N);
		Span(const Span& other);
		Span& operator=(const Span& other);
		~Span();

		//methods
		void			addNumber(const int singleNumber);
		void			addSpan(int start, int end);
		int				shortestSpan();
		int				longestSpan();
		
		//exceptions
		class ArrayFullException : public std::exception {
			public:
				const char* what() const noexcept override;
		};

		class NotEnoughElementsException : public std::exception {
			public:
				const char* what() const noexcept override;
		};
};

#endif