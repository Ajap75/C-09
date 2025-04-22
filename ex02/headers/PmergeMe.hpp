/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anastruc <anastruc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 15:46:30 by anastruc          #+#    #+#             */
/*   Updated: 2025/04/22 17:21:57 by anastruc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <deque>
#include <list>

#ifndef PMERGEME_HPP
#define PMERGEME_HPP

class FordJ
{
    public :
    
        FordJ(char **sequence);
        ~FordJ();
        FordJ(const FordJ &other);
        FordJ& operator =(const FordJ &other);
        
        void sort_using_list();
        void sort_using_deque();

        void print_algo_results();

        float list_algo_timer;
        float deque_algo_timer;
        
        private :

        FordJ();
        std::list<unsigned> input;
        std::size_t sequence_size;
        std::list<unsigned> list_origin;
        std::list<unsigned> list_sorted;
        std::deque<unsigned> deque_origin;
        std::deque<unsigned> deque_sorted;

        // debug

        void print_list(std::list<unsigned> &list) const;
        void print_deque(std::deque<unsigned> &deque) const;
};


#endif