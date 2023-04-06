/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: touteiro <touteiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 16:46:30 by touteiro          #+#    #+#             */
/*   Updated: 2023/04/06 16:54:41 by touteiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <ctime>
#include <iostream>
#include <iomanip>

Account::Account( void )
{
	return ;
}

Account::Account( int initial_deposit )
{
	this->_nbDeposits = 0;
	this->_nbWithdrawals = 0;
	this->_amount = initial_deposit;
	this->_accountIndex = _nbAccounts;
	_nbAccounts++;
	_totalAmount += initial_deposit;
	this->_displayTimestamp();
	std::cout << " index:" << this->_accountIndex;
	std::cout << ";amount:" << this->checkAmount();
	std::cout << ";created" << std::endl;
}

Account::~Account( void )
{
	this->_displayTimestamp();
	std::cout << " index:" << this->_accountIndex;
	std::cout << ";amount:" << this->checkAmount();
	std::cout << ";closed" << std::endl;
}

void	Account::_displayTimestamp( void )
{
	time_t	t = time(0);
	tm	*tm = std::localtime(&t);

	std::cout << "[" << 1900 + tm->tm_year;
	std::cout << std::setfill('0') <<  std::setw(2) << (int)1 + tm->tm_mon;
	std::cout << std::setfill('0') <<  std::setw(2) << tm->tm_mday;
	std::cout << "_";
	std::cout << std::setfill('0') <<  std::setw(2) << tm->tm_hour;
	std::cout << std::setfill('0') <<  std::setw(2) << tm->tm_min << tm->tm_sec << "]";
}

void	Account::displayStatus (void) const {
	_displayTimestamp();
	std::cout << " index:" << this->_accountIndex;
	std::cout << ";amount:" << this->_amount;
	std::cout << ";deposits:" << this->_nbDeposits;
	std::cout << ";withdrawals:" << this->_nbWithdrawals << std::endl;
}

void	Account::displayAccountsInfos( void ){
	Account::_displayTimestamp();
	std::cout << " accounts:" << Account::getNbAccounts();
	std::cout << ";total:" << Account::getTotalAmount();
	std::cout << ";deposits:" << Account::getNbDeposits();
	std::cout << ";withdrawals:" << Account::getNbWithdrawals() << std::endl;
}

int	Account::getNbAccounts ( void )
{
	return Account::_nbAccounts;
}

int	Account::getTotalAmount ( void )
{
	return Account::_totalAmount;
}

int	Account::getNbDeposits ( void )
{
	return Account::_totalNbDeposits;
}

int	Account::getNbWithdrawals ( void )
{
	return Account::_totalNbWithdrawals;
}

void	Account::makeDeposit ( int deposit )
{
	_displayTimestamp();
	std::cout << " index:" << this->_accountIndex;
	std::cout << ";p_amount:" << this->_amount;
	this->_amount += deposit;
	_totalAmount += deposit;
	std::cout << ";deposit:" << deposit;
	std::cout << ";amount:" << this->_amount;
	this->_nbDeposits++;
	_totalNbDeposits++;
	std::cout << ";nb_deposits:" << this->_nbDeposits << std::endl;
}

bool	Account::makeWithdrawal ( int withdrawal )
{
	_displayTimestamp();
	std::cout << " index:" << this->_accountIndex;
	std::cout << ";p_amount:" << this->_amount;
	if (withdrawal > this->checkAmount())
	{
		std::cout << ";withdrawal:refused" << std::endl;
		return false;
	}
	this->_amount -= withdrawal;
	_totalAmount -= withdrawal;
	std::cout << ";withdrawal:" << withdrawal;
	std::cout << ";amount:" << this->_amount;
	this->_nbWithdrawals++;
	_totalNbWithdrawals++;
	std::cout << ";nb_withdrawals:" << this->_nbWithdrawals << std::endl;
	return true;
}

int	Account::checkAmount ( void ) const
{
	return this->_amount;
}

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;