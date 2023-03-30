
#include "Account.hpp"
#include <ctime>
#include <iostream>
#include <iomanip>

Account::Account( int initial_deposit )
{
	this->_nbDeposits = 1;
	this->_amount = initial_deposit;
	this->_accountIndex = _nbAccounts;
	_nbAccounts++;
}


Account::~Account( void )
{
}

void	Account::_displayTimestamp( void )
{
	time_t	t = time(0);
	tm	*tm = std::localtime(&t);

	const char originalFill = std::cout.fill();
	const int originalWidth = std::cout.width();

	std::cout << "[" << 1900 + tm->tm_year;
	std::cout << std::setfill('0') <<  std::setw(2) << (int)1 + tm->tm_mon;
	
	std::cout << tm->tm_mday;
	std::cout << "_" << tm->tm_hour;
	std::cout << tm->tm_min << tm->tm_sec << "]";
	std::cout << std::setfill(originalFill) << std::setw(originalWidth);
}

void	Account::displayStatus (void) const {
	std::cout << " index:" << this->_accountIndex << std::endl;
}

void	Account::displayAccountsInfos( void ){
	Account::_displayTimestamp();

	
}

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;