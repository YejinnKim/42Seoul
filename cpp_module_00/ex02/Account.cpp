#include "Account.hpp"
#include <iostream>
#include <string>
#include <ctime>

int Account::getNbAccounts(void)
{
	return (_nbAccounts);
}

int Account::getTotalAmount(void)
{
	return (_totalAmount);
}

int Account::getNbDeposits(void)
{
	return (_totalNbDeposits);
}

int Account::getNbWithdrawals(void)
{
	return (_totalNbWithdrawals);
}

void Account::displayAccountsInfos(void)
{
	_displayTimestamp();
}

Account::Account(int initial_deposit)
{

}

Account::~Account(void)
{

}

void Account::makeDeposit(int deposit)
{

}

bool Account::makeWithdrawal(int withdrawal)
{
	return (true);
}

int Account::checkAmount(void) const
{
	return (0);
}

void Account::displayStatus(void) const
{

}

void Account::_displayTimestamp(void)
{
	time_t timer = time(NULL);
	struct tm* t = localtime(&timer);

	std::cout << "[" << t->tm_year + 1900 << "] " << std::endl;
}

Account::Account(void)
{

}
