#pragma once

#include <iostream>
using namespace std;

class Account {	//구조체 느낌으로 Account
public:
	int id, balance;

	Account();
	Account(int idd, int balancee);

};
class AccountManager {
public:
	int num_accounts;
	Account accounts[10];	//Account 자체로 배열 만들기
	
	AccountManager();
	AccountManager(int whatacc, int howmuch);
	void depositing(int whatacc, int howmuch,int deposit[]);
	void withdrawing(int whatacc, int howmuch,int withdraw[]);
	void transferring(int whatacc, int toacc,int howmuch,int transfer[]);
	void checking_balance(int num);



};
