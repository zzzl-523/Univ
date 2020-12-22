#include<iostream>
#include"accounts.h"
using namespace std;
Account::Account() {
	id = 0;
	balance = 0;
}
Account::Account(int idd, int balancee) {	//Account �ʱ�ȭ
	id = idd;
	balance = balancee;
}


AccountManager::AccountManager() {//�ʱ�ȭ
	num_accounts = 0;
	for (int i = 0; i < 10; i++) {
		accounts[i].id = 0;
		accounts[i].balance = 0;
	}
	
};
AccountManager::AccountManager(int whatacc, int howmuch) {//�ʱ�ȭ
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
void AccountManager:: withdrawing(int whatacc, int howmuch,int withdraw[]) {	//�ܾ��� howmuch���� ������ error
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
void AccountManager::transferring(int whatacc, int toacc, int howmuch, int transfer[]) {//whatacc�� balance<howmuch�� error
	if (transfer[whatacc] != 0|| accounts[whatacc].balance < howmuch) {
		cout << "Failure: Transfer from user " << whatacc << " to user " << toacc << " " << howmuch << "\n";
	}

	else if (accounts[toacc].balance+howmuch <= 1000000 && accounts[whatacc].balance-howmuch >= 0) {	//T�� �Ŀ� 0�̻� 100�� ����
		cout << "Success: Transfer from user " << whatacc << " to user " << toacc << " " << howmuch << "\n";
		accounts[whatacc].id = whatacc;
		accounts[toacc].id = toacc;
		accounts[toacc].balance += howmuch;
		accounts[whatacc].balance -= howmuch;

		transfer[whatacc] = 1;//limit(���� ��)
		transfer[toacc] = 1;
	}
}
void AccountManager::checking_balance(int num) {//T�� �ƴϳĿ� ���� ������ �� ���ϱ�
	cout<<"Balance of user "<<num<<": "<<accounts[num].balance<<"\n";
}

