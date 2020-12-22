#include<iostream>
#include<vector>
#include<map>
#include<string>
#include"message.h"
using namespace std;

MessageBook::MessageBook() {

}
MessageBook::~MessageBook() {

}
void MessageBook::AddMessage(int number,const string& message) {
	messages_[number] = message.substr(1,message.size()-1);
}
void MessageBook::DeleteMessage(int number) {
	messages_.erase(number);
}
vector<int> MessageBook::GetNumbers() {
	vector<int> num_list;
	for (map<int, string>::iterator it = messages_.begin(); it != messages_.end();++it) {
		num_list.push_back(it->first);
	}
	return num_list;
}
const string& MessageBook::GetMessage(int number) {
	const string& mes_list=messages_[number];
	return mes_list;
}
