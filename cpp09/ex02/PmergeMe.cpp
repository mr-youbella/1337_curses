/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youbella <youbella@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/09 14:47:28 by youbella          #+#    #+#             */
/*   Updated: 2026/03/09 21:23:00 by youbella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe &other) : _vec(other._vec), _deq(other._deq) {}

PmergeMe& PmergeMe::operator=(const PmergeMe &other)
{
	if (this != &other)
	{
		_vec = other._vec;
		_deq = other._deq;
	}
	return (*this);
}

std::vector<int> PmergeMe::jacobsthal(int n)
{
	std::vector<int> seq;
	seq.push_back(0);
	seq.push_back(1);
	while ((int)seq.back() < n)
		seq.push_back(seq[seq.size() - 1] + 2 * seq[seq.size() - 2]);
	std::vector<int> order;
	for (size_t i = 1; i < seq.size(); i++)
	{
		int curr = seq[i];
		int prev = seq[i - 1];
		for (int j = curr; j > prev && j <= n; j--)
			order.push_back(j);
	}
	return (order);
}

void PmergeMe::insertVector(std::vector<int> &chain, int val)
{
	std::vector<int>::iterator it = std::lower_bound(chain.begin(), chain.end(), val);
	chain.insert(it, val);
}

void PmergeMe::sortVector()
{
	if (_vec.size() <= 1)
		return ;
	std::vector<std::pair<int, int> > pairs;

	for (size_t i = 0; i + 1 < _vec.size(); i += 2)
	{
		int a = _vec[i];
		int b = _vec[i + 1];
		if (a > b)
			std::swap(a, b);
		pairs.push_back(std::make_pair(a, b));
	}
	bool has_straggler = _vec.size() % 2 != 0;
	int straggler = has_straggler ? _vec.back() : -1;
	for (size_t i = 0; i < pairs.size(); i++)
	{
		for (size_t j = i + 1; j < pairs.size(); j++)
		{
			if (pairs[i].second > pairs[j].second)
				std::swap(pairs[i], pairs[j]);
		}
	}
	std::vector<int> main_chain;
	std::vector<int> pend;
	for (size_t i = 0; i < pairs.size(); i++)
	{
		main_chain.push_back(pairs[i].second);
		pend.push_back(pairs[i].first);
	}
	insertVector(main_chain, pend[0]);
	std::vector<int> order = jacobsthal(pend.size());
	for (size_t i = 0; i < order.size(); i++)
	{
		int idx = order[i] - 1;
		if (idx > 0 && idx < (int)pend.size())
			insertVector(main_chain, pend[idx]);
	}
	if (has_straggler)
		insertVector(main_chain, straggler);
	_vec = main_chain;
}

void PmergeMe::insertDeque(std::deque<int> &chain, int val)
{
	std::deque<int>::iterator it = std::lower_bound(chain.begin(), chain.end(), val);
	chain.insert(it, val);
}

void PmergeMe::sortDeque()
{
	if (_deq.size() <= 1)
		return ;
	std::vector<std::pair<int, int> > pairs;

	for (size_t i = 0; i + 1 < _deq.size(); i += 2)
	{
		int a = _deq[i];
		int b = _deq[i + 1];
		if (a > b)
			std::swap(a, b);
		pairs.push_back(std::make_pair(a, b));
	}
	bool has_straggler = _deq.size() % 2 != 0;
	int straggler = has_straggler ? _deq.back() : -1;
	for (size_t i = 0; i < pairs.size(); i++)
	{	
		for (size_t j = i + 1; j < pairs.size(); j++)
		{
			if (pairs[i].second > pairs[j].second)
				std::swap(pairs[i], pairs[j]);
		}
	}
	std::deque<int> main_chain;
	std::deque<int> pend;
	for (size_t i = 0; i < pairs.size(); i++)
	{
		main_chain.push_back(pairs[i].second);
		pend.push_back(pairs[i].first);
	}
	insertDeque(main_chain, pend[0]);
	std::vector<int> order = jacobsthal(pend.size());
	for (size_t i = 0; i < order.size(); i++)
	{
		int idx = order[i] - 1;
		if (idx > 0 && idx < (int)pend.size())
			insertDeque(main_chain, pend[idx]);
	}
	if (has_straggler)
		insertDeque(main_chain, straggler);
	_deq = main_chain;
}

void PmergeMe::run()
{
	std::cout << "Before: ";
	for (size_t i = 0; i < _vec.size(); i++)
		std::cout << _vec[i] << " ";
	std::cout << '\n';
	clock_t startVec = clock();
	sortVector();
	clock_t endVec = clock();
	double timeVec = (double)(endVec - startVec) / CLOCKS_PER_SEC * 1000000;
	clock_t startDeq = clock();
	sortDeque();
	clock_t endDeq = clock();
	double timeDeq = (double)(endDeq - startDeq) / CLOCKS_PER_SEC * 1000000;
	std::cout << "After: ";
	for (size_t i = 0; i < _vec.size(); i++)
		std::cout << _vec[i] << " ";
	std::cout << '\n';
	std::cout << "Time to process a range of " << _vec.size()
		<< " elements with std::vector : " << timeVec << " us\n";
	std::cout << "Time to process a range of " << _deq.size()
		<< " elements with std::deque  : " << timeDeq << " us\n";
}

void PmergeMe::parseInput(int argc, char **argv)
{
	for (int i = 1; i < argc; i++)
	{
		std::istringstream iss(argv[i]);
		std::string num_str;
		while (iss >> num_str)
		{
			for (size_t j = 0; j < num_str.size(); j++)
			{
				if (!std::isdigit(num_str[j]))
				{
					std::cerr << "Error\n";
					exit(1);
				}
			}
			long num = std::strtol(num_str.c_str(), NULL, 10);
			if (num <= 0 || num > INT_MAX)
			{
				std::cerr << "Error\n";
				exit(1);
			}
			_vec.push_back((int)num);
			_deq.push_back((int)num);
		}
	}
}

PmergeMe::~PmergeMe() {}
