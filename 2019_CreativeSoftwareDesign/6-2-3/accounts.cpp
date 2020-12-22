#include<iostream>
#include"accounts.h"
using namespace std;
Account::Account() {
	id = 0;
	balance = 0;
}
Account::Account(int idd, int balancee) {	//Account 초기화
	id = idd;
	balance = balancee;
}


AccountManager::AccountManager() {//초기화
	num_accounts = 0;
	for (int i = 0; i < 10; i++) {
		accounts[i].id = 0;
		accounts[i].balance = 0;
	}
	
};
AccountManager::AccountManager(int whatacc, int howmuch) {//초기화
	num_accounts = whatacc+1;
	accounts[whatacc].id = whatacc;
	accounts[whatacc].balance= howmuch;
}

void AccountManager::depositing(int whatacc, int howmuch,int deposit[]) {
	if (deposit[whatacc] != 0||howmuch<0||howmuch>1000000) {
		cout << "Failure: Deposit to user " << whatacc << " " << howmuch << "\n";
	}
	else {
		cout << "Success: Deposit to user " << whatacc << " " << howmuch << "\n";
		accounts[whatacc].id = whatacc;
		accounts[whatacc].balance += howmuch;
		deposit[whatacc] = 1;	//limit
	}
	
}
void AccountManager:: withdrawing(int whatacc, int howmuch,int withdraw[]) {	//잔액이 howmuch보다 적으면 error
	if (withdraw[whatacc] != 0) {
		cout << "Failure: Withdraw from user " << whatacc << " " << howmuch << "\n";
	}
	else if (howmuch > accounts[whatacc].balance||accounts[whatacc].balance-howmuch<0) {
		cout << "Failure: Withdraw from user " << whatacc <<" "<< howmuch<<"\n";
	}
	
	else {
		cout << "Success: Withdraw from user " << whatacc << " " << howmuch << "\n";
		accounts[whatacc].id = whatacc;
		accounts[whatacc].balance -= howmuch;
		withdraw[whatacc] = 1;//limit
	}
}
void AccountManager::transferring(int whatacc, int toacc, int howmuch, int transfer[]) {//whatacc의 balance<howmuch면 error
	if (transfer[whatacc] != 0|| accounts[whatacc].balance < howmuch) {
		cout << "Failure: Transfer from user " << whatacc << " to user " << toacc << " " << howmuch << "\n";
	}

	else if (accounts[toacc].balance+howmuch <= 1000000 && accounts[whatacc].balance-howmuch >= 0) {	//T한 후에 0이상 100만 이하
		cout << "Success: Transfer from user " << whatacc << " to user " << toacc << " " << howmuch << "\n";
		accounts[whatacc].id = whatacc;
		accounts[toacc].id = toacc;
		accounts[toacc].balance += howmuch;
		accounts[whatacc].balance -= howmuch;

		transfer[whatacc] = 1;//limit(양쪽 다)
		transfer[toacc] = 1;
	}
}
void AccountManager::checking_balance(int num) {//T냐 아니냐에 따라서 보여줄 것 정하기
	cout<<"Balance of user "<<num<<": "<<accounts[num].balance<<"\n";
}

