/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.tpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeier <mmeier@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 13:48:35 by mmeier            #+#    #+#             */
/*   Updated: 2025/02/13 11:20:29 by mmeier           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_TPP
# define MUTANTSTACK_TPP

#include "MutantStack.hpp"
template<class T>
MutantStack<T>::MutantStack() : std::stack<T>() {}

template<class T>
MutantStack<T>::MutantStack(const MutantStack& other) : std::stack<T>(other) {}

template<class T>
MutantStack<T>& MutantStack<T>::operator=(const MutantStack& other) {
	if (this == &other)
		return (*this);
	std::stack<T>::operator=(other);
	return (*this);
}

template<class T>
MutantStack<T>::~MutantStack() {}

/*c.begin() accesses the protected container 'c' (typically a std::<deque>) in std::stack. Pre-requirement
  is that mutant stack class has inherited from std::stack, so that it can access the protected members.*/
template<class T>
typename MutantStack<T>::iterator MutantStack<T>::begin() { return this->c.begin(); }

template <class T>
typename MutantStack<T>::const_iterator MutantStack<T>::begin() const { return this->c.begin(); }

template<class T>
typename MutantStack<T>::iterator MutantStack<T>::end() { return this->c.end(); }

template <class T>
typename MutantStack<T>::const_iterator MutantStack<T>::end() const { return this->c.end(); }

#endif