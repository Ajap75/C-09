/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   List_Ford_Johnson.cpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anastruc <anastruc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 17:45:25 by anastruc          #+#    #+#             */
/*   Updated: 2025/04/17 16:55:32 by anastruc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/PmergeMe.hpp"
#include <iostream>
#include "../headers/List_Ford_Johnson.hpp"


// list : 5 6 3 7 9 1 5 3;
// Pairing -> [5 6], [3 7], [9 1], [5 3]
// Sort each Pair -> [5 6], [3 7], [1 9], [3 5]
// A list has a size of minimum 3. So if we move by 2 elems each time. In a even list, the "curr" iterator will
// be the one to end on the list.end() iterator, and in an odd list, it will be the next iterator to end on the list.end() iterator.



void create_pairs(std::list<unsigned> &list_origin, std::list<unsigned> &list_sorted)
{
    std::list<unsigned>::iterator curr = list_origin.begin();
    std::list<unsigned>::iterator next = list_origin.begin();
    ++next;
    
    while (!end_of_list(curr, next, list_origin))
    {
        std::cout << "curr = " << *curr << "|  nest = " << *next << std::endl;
        if (*next > *curr)
        {
            list_sorted.push_back(*curr);
            list_sorted.push_back(*next);
        }
        else 
        {
            list_sorted.push_back(*next);
            list_sorted.push_back(*curr);
        }
        std::advance(curr, 2);
        std::advance(next, 2);
    }
}

int end_of_list(std::list<unsigned>::iterator &curr, std::list<unsigned>::iterator &next, std::list<unsigned> &list_origin)
{
    if (list_origin.size() % 2 != 0) // odd
    {
        if (next != list_origin.end())
            return(0);
        else
            return (1);
    }
    else // even
    {
        if (curr != list_origin.end())
            return(0);
        else
            return (1);
    }
}

void empty_origin_list(std::list<unsigned> &list_origin)
{
    // If the list is odd, the last element has been paired with any other element and is not in the sorted list.
    // So I need to keep it in the origin_list
    if (list_origin.size() % 2 != 0) // odd
    {
        //keep the last elem :
        list_origin.erase(list_origin.begin(), --list_origin.end());
    }
    else // even
    list_origin.erase(list_origin.begin(), list_origin.end());
    
    std::list<unsigned>::iterator it = list_origin.begin();
    for ( ; it != list_origin.end() ; ++it)
        std::cout << *it << " ";
    std::cout << std::endl;
}

void create_high_element_new_pairs(std::list<unsigned> &list_to_be_insert, std::list<unsigned> &list_sorted)
{
    //List_origin becomes list_to_be_sorted, because it will contains every elems needing to be inserted in the main list. 
    std::list<unsigned>::iterator it = list_sorted.begin();
    std::list<unsigned>::iterator tmp_it;
    
    for ( ; it != list_sorted.end() ; ++it)
    {
        // I push every lowest elem to the other list. And I erase it from the sorted list. The list is resize and the  function return the nezt iterator (that's why I store it in tmp_it and reassign it) 
        // iterator point now to the ne in the list (the second pair elem), 
        // I need to increment the iterator only once to end up on the lowest elem of the pair
        list_to_be_insert.push_back(*it);
        tmp_it = list_sorted.erase(it);   
        it = tmp_it;
    }
}

void insert(std::list<unsigned> &list_to_be_insert, std::list<unsigned> &list_sorted)
{
    std::list<unsigned>::iterator it_tbi = list_to_be_insert.begin();
    std::list<unsigned>::iterator it_sorted;
    int insertion_done;
    
    for (; it_tbi != list_to_be_insert.end(); ++it_tbi)
    {
        it_sorted = list_sorted.begin();
        insertion_done = 0;
        for(; it_sorted != list_sorted.end() ; ++it_sorted)
        {
            if (*it_tbi < *it_sorted)
            {
                list_sorted.insert(it_sorted, *it_tbi);
                insertion_done = 1;
                break;
            }
        }
        if (!insertion_done)
            list_sorted.insert(list_sorted.end(), *it_tbi);
    }
}





