/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youbella <youbella@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/09 14:40:39 by youbella          #+#    #+#             */
/*   Updated: 2026/03/09 19:50:59 by youbella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <vector>
# include <deque>
# include <string>
# include <iostream>
# include <ctime>
# include <cstdlib>
# include <sstream>
# include <algorithm>
# include <climits> 

class PmergeMe
{
	private:
		std::vector<int>	_vec;
		std::deque<int>		_deq;
		void				sortVector();
		void				insertVector(std::vector<int> &chain, int val);
		std::vector<int>	jacobsthal(int n);
		void				sortDeque();
		void				insertDeque(std::deque<int> &chain, int val);
	public:
		PmergeMe();
		PmergeMe(const PmergeMe &other);
		PmergeMe &operator=(const PmergeMe &other);
		void	parseInput(int argc, char **argv);
		void	run();
		~PmergeMe();
};

#endif
