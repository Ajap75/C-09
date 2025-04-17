/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anastruc <anastruc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 15:46:30 by anastruc          #+#    #+#             */
/*   Updated: 2025/04/17 18:25:59 by anastruc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/Colors.hpp"
#include "../headers/PmergeMe.hpp"
#include "../headers/List_Ford_Johnson.hpp"
#include "../headers/Deque_Ford_Johnson.hpp"
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <ctime>



//C&D
FordJ::FordJ(char **sequence)
{
    for(int i = 1; sequence[i] ; i++)
    {
        list_origin.push_back(atol(sequence[i]));
        deque_origin.push_back(atol(sequence[i]));
    }
    sequence_size = list_origin.size();
}

FordJ::~FordJ() {}

FordJ::FordJ(const FordJ &other) : list_origin(other.list_origin), list_sorted(other. list_sorted), deque_origin(other.deque_origin), deque_sorted(other.deque_sorted) {}

FordJ& FordJ::operator =(const FordJ &other)
{
    if (this != &other)
    {
        list_origin = other.list_origin;
        list_sorted = other. list_sorted;
        deque_origin = other.deque_origin;
        deque_sorted =other.deque_sorted;
    }
    return(*this);
}




// APPLY ALGO ON TWO DIFFERENT CONTAINERS

void FordJ::sort_using_list()
{
    float clock_start;
    float clock_end;
    
    clock_start = std::clock();
    
    // Create pairs, and push them in the list_sorted in the correct order
    create_pairs(list_origin, list_sorted);

    // Empty list_origin (keep the last elem if it's an odd list)
    empty_origin_list(list_origin);

    // Push back in the origin_list every lowest elem of each sorted pair of sorted_list;
    create_high_element_new_pairs(list_origin, list_sorted);
    
    // Use of the built_in function sort, to sort the high elements new pairs in the list_sorted;
    list_sorted.sort();

    // insert pending value from the list_origin, 
    insert(list_origin, list_sorted);
    
    clock_end = std::clock();
    list_algo_timer = ((clock_end - clock_start) * 1000000) / CLOCKS_PER_SEC;
    
}

void FordJ::sort_using_deque()
{

    float clock_start;
    float clock_end;
    
    clock_start = std::clock();
    // Create pairs, and push them in the deque_sorted in the correct order
    create_pairs(deque_origin, deque_sorted);

    // Empty deque_origin (keep the last elem if it's an odd deque)
    empty_origin_deque(deque_origin);
    
    // Push back in the origin_deque every lowest elem of each sorted pair of sorted_deque;
    create_high_element_new_pairs(deque_origin, deque_sorted);
        
    // Use of the built_in function sort, to sort the high elements new pairs in the deque_sorted;
    std::sort(deque_sorted.begin(), deque_sorted.end());
    
    // insert pending value from the deque_origin, 
    insert(deque_origin, deque_sorted);

    clock_end = std::clock();
    deque_algo_timer = ((clock_end - clock_start) * 1000000) / CLOCKS_PER_SEC;        
}


void FordJ::print_list(std::list<unsigned> &list) const
{
    std::list<unsigned>::iterator it = list.begin();
    for ( ; it != list.end() ; ++it)
        std::cout << *it << " ";
    std::cout << std::endl;
}

void FordJ::print_deque(std::deque<unsigned> &deque) const 
{
    std::deque<unsigned>::iterator it = deque.begin();
    for( ; it != deque.end() ; ++it)
        std::cout << *it << " ";
    std::cout << std::endl;
}



void FordJ::print_algo_results()
{
    std::cout << "Before: ";
    print_list(list_origin);
    std::cout << "After: ";
    print_list(list_sorted);

    std::cout << "After: ";
    print_deque(deque_sorted);
    
    std::cout << std::endl;
    std::cout << "Time to process a range of " << sequence_size << BLUE << " elements with std::list : " << list_algo_timer << " μs"  RESET << std::endl;
    std::cout << "Time to process a range of " << sequence_size << MAGENTA << " elements with std::deque : " <<  deque_algo_timer << " μs" RESET << std::endl;
    
}




// getter
// float FordJ::get_deque_algo_timer()
// {
//     return(deque_algo_timer);
// }

// float FordJ::get_list_algo_timer()
// {
//     return(list_algo_timer);
// }