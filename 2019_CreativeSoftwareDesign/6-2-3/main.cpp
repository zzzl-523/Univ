#include<iostream>
#include"accounts.h"
using namespace std;

int main() {
	char menu;
	int whatacc = 0, howmuch = 0,toacc=0;
	int check = 0;
	Account gaejwa(whatacc, howmuch);
	AccountManager gaejwa_man;
	gaejwa_man.accounts[whatacc] = gaejwa;

	int deposit[10] = { 0, };
	int withdraw[10] = { 0, };
	int transfer[10] = { 0, };

	while (1) {
		cout << "Job?" << "\n";
		cin >> menu;
		if (menu == 'Q') {
			break;
		}

		if (menu == 'N') {
			if (check > 9) {	//10개까지만 받도록
				cout << "Failure: create an account\n\n";
			}
			else {
				gaejwa_man.accounts[check].id = check;
				gaejwa_man.accounts[check].balance = 0;
				cout << "Account for user " << check << " registered" << "\n";
				gaejwa_man.checking_balance(check);
				check++;
				cout << "\n";
			}
		}
		else if (menu == 'T') {	//입력받기
			cin >> whatacc >> toacc >> howmuch;
		}
		else {
			cin >> whatacc >> howmuch;
		}


		if (check == 0) {	//계좌 존재하는지 확인
			cout << "Account does not exist\n";//없으면
		}
		else {
			
			if (menu == 'D') {
				gaejwa_man.depositing(whatacc, howmuch,deposit);
				gaejwa_man.checking_balance(whatacc);
				

			}
			else if (menu == 'W') {
				gaejwa_man.withdrawing(whatacc, howmuch,withdraw);
				gaejwa_man.checking_balance(whatacc);
				
			}
			else if (menu == 'T') {
				gaejwa_man.transferring(whatacc,toacc,howmuch,transfer );
				
				int temp = 0;	//정렬
				int list[2] = { whatacc,toacc };
				for (int i = 0; i < 2; i++) {
					if (whatacc > toacc) {
						temp = whatacc;
						whatacc = toacc;
						toacc = whatacc;
					}
				}
				for (int i = 0; i < 2; i++) {
					gaejwa_man.checking_balance(list[i]);
				}

			}
			else {
				continue;
			}
			
		}
		cout << "\n";
	
	}
	
	
	return 0;

}