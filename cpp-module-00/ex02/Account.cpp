#include "Account.hpp"
#include <iostream>
#include <unistd.h>
#include <sys/time.h>

#define RED ""
#define GREEN ""
#define YELLOW ""
#define RESET ""

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

int	Account::getNbAccounts( void )
{
	return _nbAccounts;
}

int	Account::getTotalAmount( void )
{
	return _totalAmount;
}

int	Account::getNbDeposits( void )
{
	return _totalNbDeposits;
}
int	Account::getNbWithdrawals( void )
{
	return _totalNbWithdrawals;
}
void	Account::displayAccountsInfos( void )
{
	_displayTimestamp();
	std::cout	<< RED " accounts:" << getNbAccounts()
				<< ";total:" << getTotalAmount()
				<< ";deposits:" << getNbDeposits()
				<< ";withdrawals:" << getNbWithdrawals()
				<< RESET << std::endl;
	;return ;
}

//For creating an object of this class
Account::Account( int initial_deposit )
{
	static int index = 0;
	_amount = initial_deposit;
	_accountIndex = index++;
	_nbAccounts = index;
	_totalAmount += initial_deposit;
	_displayTimestamp();
	std::cout	<< " index:" << _accountIndex
				<< ";amount:" << _amount
				<< ";created" << std::endl;
	return ;
}

//For destroying a member of this class
Account::~Account( void )
{
	std::cout	<< YELLOW ;
	_displayTimestamp();
	std::cout	<< " index:" << _accountIndex
				<< ";amount:" << _amount
				<< ";closed" RESET << std::endl;
	return ;
}

void	Account::makeDeposit( int deposit )
{
	_totalNbDeposits++;
	_nbDeposits++;
	_displayTimestamp();
	std::cout
	<< " index:" << _accountIndex
	<< ";p_amount:" << _amount
	<<";deposit:" << deposit
	<< ";amount:" << _amount + deposit
	<< ";nb_deposits:" << _nbDeposits << std::endl;
	_totalAmount += deposit;
	_amount += deposit;
	return ;
}

bool	Account::makeWithdrawal( int withdrawal )
{
	_displayTimestamp();
	if (withdrawal > _amount)
	{
		std::cout
		<< " index:" << _accountIndex
		<< ";p_amount:" << _amount
		<< ";withdrawal:refused" << std::endl;
		return false;
	}
	_nbWithdrawals++;
	_totalNbWithdrawals++;
	std::cout
	<< " index:" << _accountIndex
	<< ";p_amount:" << _amount
	<< ";withdrawal:" << withdrawal
	<< ";amount:" << _amount - withdrawal
	<< ";nb_withdrawals:" << _nbWithdrawals
	<< std::endl;
	_amount -= withdrawal;
	_totalAmount -= withdrawal;
	return true;
}

int		Account::checkAmount( void ) const
{
	return _amount;
}

void	Account::displayStatus( void ) const
{
	_displayTimestamp();
	std::cout << " ";
	std::cout	<< "index:" <<_accountIndex
				<< ";amount:" << _amount
				<< ";deposits:" << _nbDeposits 
				<< ";withdrawals:" << _nbWithdrawals 
				<< std::endl;
}

void	Account::_displayTimestamp( void )
{
	struct timeval t;

	gettimeofday(&t, NULL);
	long long sec = t.tv_sec;
	long long usec = t.tv_usec;
	std::cout << "[" <<  sec << "_" << usec << "]";
	return ;
}
