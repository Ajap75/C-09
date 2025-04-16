/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anastruc <anastruc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 15:46:30 by anastruc          #+#    #+#             */
/*   Updated: 2025/04/16 17:03:03 by anastruc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <list>
#include <deque>

#ifndef PMERGEME_HPP
#define PMERGEME_HPP

class FordJ
{
    public :
        FordJ(char **sequence);
        ~FordJ();
        FordJ(const FordJ &other);
        FordJ& operator =(const FordJ &other);
        
        // void sort_using_list();
        // void sort_using_deque();
        void print_datas();
        
        private :
        
        // float get_list_algo_timer();
        // float get_deque_algo_timer();
        
        // float list_algo_timer;
        // float deque_algo_timer;
        std::list<unsigned> list_origin;
        std::list<unsigned> list_sorted;
        std::deque<unsigned> deque_origin;
        std::deque<unsigned> deque_sorted;

        // debug

        void print_list(std::list<unsigned> &list) const;
        void print_deque(std::deque<unsigned> &deque) const;



};

#endif