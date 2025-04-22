/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Deque_Ford_Johnson.cpp                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anastruc <anastruc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 17:45:25 by anastruc          #+#    #+#             */
/*   Updated: 2025/04/22 17:04:26 by anastruc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/PmergeMe.hpp"
#include <iostream>
#include "../headers/Deque_Ford_Johnson.hpp"


void create_pairs(std::deque<unsigned> &deque_origin, std::deque<unsigned> &deque_sorted)
{
    std::deque<unsigned>::iterator curr = deque_origin.begin();
    std::deque<unsigned>::iterator next = deque_origin.begin();
    ++next;
    
    while (!end_of_deque(curr, next, deque_origin))
    {
        // std::cout << "curr = " << *curr << "|  nest = " << *next << std::endl;
        if (*next > *curr)
        {
            deque_sorted.push_back(*curr);
            deque_sorted.push_back(*next);
        }
        else 
        {
            deque_sorted.push_back(*next);
            deque_sorted.push_back(*curr);
        }
        std::advance(curr, 2);
        std::advance(next, 2);
    }
}

int end_of_deque(std::deque<unsigned>::iterator &curr, std::deque<unsigned>::iterator &next, std::deque<unsigned> &deque_origin)
{
    if (deque_origin.size() % 2 != 0) // odd
    {
        if (next != deque_origin.end())
            return(0);
        else
            return (1);
    }
    else // even
    {
        if (curr != deque_origin.end())
            return(0);
        else
            return (1);
    }
}


void empty_origin_deque(std::deque<unsigned> &deque_origin)
{
    // If the deque is odd, the last element has been paired with any other element and is not in the sorted deque.
    // So I need to keep it in the origin_deque
    if (deque_origin.size() % 2 != 0) // odd
    {
        //keep the last elem :
        deque_origin.erase(deque_origin.begin(), --deque_origin.end());
    }
    else // even
    deque_origin.erase(deque_origin.begin(), deque_origin.end());
}

void create_high_element_new_pairs(std::deque<unsigned> &deque_to_be_insert, std::deque<unsigned> &deque_sorted)
{
    //deque_origin becomes deque_to_be_sorted, because it will contains every elems needing to be inserted in the main deque. 
    std::deque<unsigned>::iterator it = deque_sorted.begin();
    std::deque<unsigned>::iterator tmp_it;
    
    for ( ; it != deque_sorted.end() ; ++it)
    {
        // I push every lowest elem to the other deque. And I erase it from the sorted deque. The deque is resize and the  function return the nezt iterator (that's why I store it in tmp_it and reassign it) 
        // iterator point now to the ne in the deque (the second pair elem), 
        // I need to increment the iterator only once to end up on the lowest elem of the pair
        deque_to_be_insert.push_back(*it);
        tmp_it = deque_sorted.erase(it);   
        it = tmp_it;
    }
}

void insert(std::deque<unsigned> &deque_to_be_insert, std::deque<unsigned> &deque_sorted)
{
    std::deque<unsigned>::iterator it_tbi = deque_to_be_insert.begin();
    
    for (; it_tbi != deque_to_be_insert.end(); ++it_tbi)
    {
        std::deque<unsigned>::iterator pos = std::lower_bound(deque_sorted.begin(), deque_sorted.end(), *it_tbi);
        deque_sorted.insert(pos, *it_tbi);
    }
}

