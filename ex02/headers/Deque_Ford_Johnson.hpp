/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Deque_Ford_Johnson.hpp                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anastruc <anastruc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 12:06:24 by anastruc          #+#    #+#             */
/*   Updated: 2025/04/17 17:27:07 by anastruc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <cstdlib>
#include <limits.h>
#include <deque>


#ifndef DEQUE_FORD_JOHNSON_HPP
#define DEQUE_FORD_JOHNSON_HPP


void create_pairs(std::deque<unsigned> &deque_origin, std::deque<unsigned> &deque_sorted);
int end_of_deque(std::deque<unsigned>::iterator &curr, std::deque<unsigned>::iterator &next, std::deque<unsigned> &deque_origin);
void empty_origin_deque(std::deque<unsigned> &deque_origin);
void create_high_element_new_pairs(std::deque<unsigned> &deque_origin, std::deque<unsigned> &deque_sorted);
void insert(std::deque<unsigned> &deque_origin, std::deque<unsigned> &deque_sorted);



#endif