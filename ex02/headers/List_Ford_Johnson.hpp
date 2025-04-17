/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   List_Ford_Johnson.hpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anastruc <anastruc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 12:06:24 by anastruc          #+#    #+#             */
/*   Updated: 2025/04/17 17:07:47 by anastruc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <cstdlib>
#include <limits.h>
#include <list>


#ifndef LIST_FORD_JOHNSON_HPP
#define LIST_FORD_JOHNSON_HPP

void create_pairs(std::list<unsigned> &list_origin, std::list<unsigned> &list_sorted);
int end_of_list(std::list<unsigned>::iterator &curr, std::list<unsigned>::iterator &next, std::list<unsigned> &list_origin);
void empty_origin_list(std::list<unsigned> &list_origin);
void create_high_element_new_pairs(std::list<unsigned> &list_origin, std::list<unsigned> &list_sorted);
void insert(std::list<unsigned> &list_origin, std::list<unsigned> &list_sorted);



#endif