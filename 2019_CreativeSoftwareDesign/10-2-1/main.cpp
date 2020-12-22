#include<iostream>
#include<vector>
#include"clock_time.h"
#include"clock.h"
using namespace std;

vector<Clock*>v;

int main() {
	int ildan;
	cin >> ildan;
	
	v.push_back(new SundialClock(0, 0, 0));
	v.push_back(new CuckooClock(0, 0, 0));
	v.push_back(new GrandFatherClock(0, 0, 0));
	v.push_back(new WristClock(0, 0, 0));
	v.push_back(new AtomicClock(0, 0, 0));

	for (int i = 0; i < v.size(); i++) {
		v[i]->reset();
	}

	cout << "Reported clock times after resetting"<<endl;
	cout << "\n";
	for (int i = 0; i < v.size(); i++) {
		v[i]->displayTime();
	}

	cout << "\nRunning the clocks..." << endl;
	
	cout << "\nReported clock times after running:" << endl;

	for (int i = 0; i < v.size(); i++) {
		for (int j = 0; j < ildan; j++) {
			v[i]->tick();
		}
		
	}
	for (int i = 0; i < v.size(); i++) {
		v[i]->displayTime();
	}

	for (int i = 0; i < v.size(); i++) {
		delete v[i];
	}
	return 0;
}