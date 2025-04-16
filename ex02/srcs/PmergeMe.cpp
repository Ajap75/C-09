/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anastruc <anastruc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 15:46:30 by anastruc          #+#    #+#             */
/*   Updated: 2025/04/16 18:13:52 by anastruc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/Colors.hpp"
#include "../headers/PmergeMe.hpp"
#include <cstdlib>
#include <iostream>


//C&D
FordJ::FordJ(char **sequence)
{
    
    for(int i = 1; sequence[i] ; i++)
    {
        list_origin.push_back(atol(sequence[i]));
        deque_origin.push_back(atol(sequence[i]));
    }
    // print_deque(deque_origin);
    // std::cout << RED << "ooooooooooooooooooo" << RESET << std::endl;
    // print_list(list_origin);
    print_datas();
    sort_using_list();

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




// // apply algo
void FordJ::sort_using_list()
{
    sort_each_pair(list_origin, list_sorted);
}

// // apply algo
// void FordJ::sort_using_deque()
// {
    
// }

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


void FordJ::print_datas()
{
    std::cout << "Before: ";
    print_list(list_origin);
    std::cout << "After: ";
    print_list(list_origin);
    std::cout << std::endl;
    std::cout << "Time to process a range of " << list_origin.size() << BLUE << " elements with std::list : " << RESET << std::endl;
    std::cout << "Time to process a range of " << deque_origin.size() << MAGENTA << " elements with std::deque : " << RESET << std::endl;
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