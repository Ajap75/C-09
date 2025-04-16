/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ford_Johnson_list.cpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anastruc <anastruc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 17:45:25 by anastruc          #+#    #+#             */
/*   Updated: 2025/04/16 18:40:19 by anastruc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/PmergeMe.hpp"


// list : 5 6 3 7 9 1 5 3;
// Pairing -> [5 6], [3 7], [9 1], [5 3]
// Sort each Pair -> [5 6], [3 7], [1 9], [3 5]
void sort_each_pair(std::list<unsigned> &list_origin, std::list<unsigned> &list_sorted)
{
    (void) list_sorted;
    // std::list<unsigned>::iterator it_left = list_origin.begin();
    std::list<unsigned>::iterator it = list_origin.begin();
    
    for ( ; it != list_origin.end() ; std::advance(it, 2))
    {
        if (*it > ++*it)
        // {
        //     unsigned tmp;
        //     tmp = *it_left;
        //     *it_left = *it_right;
        //     *it_right = tmp; 
        // }
    }
    
}
