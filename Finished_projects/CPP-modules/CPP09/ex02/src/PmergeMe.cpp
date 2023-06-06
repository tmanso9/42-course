/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: touteiro <touteiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 19:54:42 by touteiro          #+#    #+#             */
/*   Updated: 2023/06/06 13:27:29 by touteiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

std::vector<int>					PmergeMe::_vect;
std::vector<int>					PmergeMe::_sortedVect;
std::vector<std::pair<int, int> >	PmergeMe::_vectPairs;

std::list<int>						PmergeMe::_lst;
std::list<int>						PmergeMe::_sortedLst;
std::list<std::pair<int, int> > 	PmergeMe::_lstPairs;

PmergeMe::PmergeMe( void ){};

PmergeMe::~PmergeMe(){};

PmergeMe::PmergeMe( PmergeMe const & src )
{
	(void)src;
};

PmergeMe & PmergeMe::operator=( PmergeMe const & src )
{
	(void)src;
	return *this;
}

void	PmergeMe::sort( std::vector<std::string> sequence )
{
	
	parseInput(sequence);
	
	clock_t start = clock();
	mergeInsertVect();
	clock_t finishVector = clock() - start;
	
	start = clock();
	mergeInsertList();
	clock_t finishList = clock() - start;
	
	if (!checkSorted(_sortedVect) || !checkSorted(_sortedLst)) {
		std::cerr << "Error: not sorted properly" << std::endl;
		exit(2);
	}
	
	std::cout << "Before:\t";
	printSequence(_vect);
	std::cout << "After:\t";
	printSequence(_sortedVect);
	
	std::cout << "Time to process a range of " << _vect.size() << " elements with std::vector : " << \
		static_cast<float>(finishVector) / CLOCKS_PER_SEC * 1000 << " ms" << std::endl;
	std::cout << "Time to process a range of " << _vect.size() << " elements with std::list : " << \
		static_cast<float>(finishList) / CLOCKS_PER_SEC * 1000 << " ms" << std::endl;
}

void PmergeMe::parseInput( std::vector<std::string> sequence )
{
	std::vector<std::string>::iterator it = sequence.begin();
	for (; it != sequence.end(); it ++) {
		_lst.push_back(atoi((*it).c_str()));
		_vect.push_back(atoi((*it).c_str()));
		if (it->find_first_not_of("0123456789+") != std::string::npos || \
			it->find('+') != it->find_last_of('+') || \
			strtol((*it).c_str(), NULL, 10) > INT_MAX || \
			strtol((*it).c_str(), NULL, 10) < 1) {
			std::cerr << "Error" << std::endl;
			exit(2);
		}
	}
}

void PmergeMe::mergeInsertVect( void )
{
	_sortedVect.reserve(_vect.size());
	if (checkSorted(_vect)) {
		_sortedVect = _vect;
		return ;
	}
	std::vector<std::pair<int, int> > partitions;
	for (size_t i = 0; i < _vect.size(); i += 2) {
		std::pair<int, int> pair;
		pair.first = _vect[i];
		if (i + 1 < _vect.size()) {
			if (_vect[i + 1] > _vect[i]) {
				pair.first = _vect[i + 1];
				pair.second = _vect[i];
			} else {
				pair.second = _vect[i + 1];
			}
		}
		partitions.push_back(pair);
	}
	
	_vectPairs.reserve(partitions.size());
	for (size_t i = 0; i < partitions.size(); i++) {
		_vectPairs.insert(lower_bound(_vectPairs.begin(), _vectPairs.end(), partitions[i]), partitions[i]);
	}

	for (size_t i = 0; i < _vectPairs.size(); i++) {
		_sortedVect.push_back(_vectPairs[i].first);
	}

	for (size_t i = 0; i < _vectPairs.size(); i++) {
		if (_vectPairs[i].second) {
			_sortedVect.insert(lower_bound(_sortedVect.begin(), _sortedVect.end(), _vectPairs[i].second), _vectPairs[i].second);
		}
	}
}

void PmergeMe::mergeInsertList( void )
{
	if (checkSorted(_lst)) {
		_sortedLst = _lst;
		return ;
	}
	std::list<std::pair<int, int> > partitions;
	for (std::list<int>::iterator it = _lst.begin(); it != _lst.end(); it++) {
		std::pair<int, int> pair;
		pair.first = *it;
		if (++it != _lst.end()) {
			if (*it < pair.first) {
				pair.first = *it;
				pair.second = *(--it);
				++it;
			} else {
				pair.second = *it;
			}
		}
		partitions.push_back(pair);
		if (it == _lst.end()) {
			break ;
		}
	}

	for (std::list<std::pair<int, int> >::iterator it = partitions.begin(); it != partitions.end(); it ++) {
		_lstPairs.insert(lower_bound(_lstPairs.begin(), _lstPairs.end(), *it), *it);
	}
	
	for (std::list<std::pair<int, int> >::iterator it = _lstPairs.begin(); it != _lstPairs.end(); it ++) {
		_sortedLst.push_back(it->first);
	}

	for (std::list<std::pair<int, int> >::iterator it = _lstPairs.begin(); it != _lstPairs.end(); it ++) {
		if (it->second) {
			_sortedLst.insert(lower_bound(_sortedLst.begin(), _sortedLst.end(), (*it).second), (*it).second);
		}
	}
	
}