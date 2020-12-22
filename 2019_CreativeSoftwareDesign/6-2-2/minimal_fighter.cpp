#include<iostream>
#include"minimal_fighter.h"
using namespace std;

MinimalFighter::MinimalFighter() { mHp = 0, mPower = 0, mStatus = Invalid; }
MinimalFighter::MinimalFighter(int _hp, int _power) {
	mHp = _hp, mPower = _power;
	if (_hp <= 0) {
		mStatus = Dead ;
	}
	else {
		mStatus = Alive;
	}
}
int MinimalFighter::hp() {	//hp값 받아오기
	return mHp;
}
int MinimalFighter::power() {
	return mPower;
}
FighterStatus MinimalFighter::status() {
	return mStatus;
}
void MinimalFighter::setHp(int _hp) {	//hp값 설정하기
	mHp = _hp;
}
void MinimalFighter::hit(MinimalFighter *_enemy) {
	_enemy->setHp(_enemy->hp() - this->power());
	this->setHp(this->hp() - _enemy->power());
	if (_enemy->hp() <= 0) {
		_enemy->mStatus = Dead;
	}
	if (this->hp() <= 0) {
		this->mStatus = Dead;
	}
}
void MinimalFighter::attack(MinimalFighter *_enemy) {
	_enemy->setHp(_enemy->hp() - this->power());
	this->mPower = 0;
	if (_enemy->hp() <= 0) {
		_enemy->mStatus = Dead;
	}
	if (this->hp() <= 0) {
		this->mStatus = Dead;
	}

}
void MinimalFighter::fight(MinimalFighter *_enemy) {
	while (1) {
		_enemy->setHp(_enemy->hp() - this->power());
		this->setHp(this->hp()-_enemy->power());
		if (_enemy->hp() <= 0) {
			_enemy->mStatus = Dead;
		}
		if (this->hp() <= 0) {
			this->mStatus = Dead;
		}
		if (_enemy->status() == Dead||this->status()==Dead) {
			break;
		}
	}
}
