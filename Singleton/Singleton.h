#ifndef _SINGLETON_H_
#define _SINGLETON_H_
#include "Singleton.h"
#include <iostream> 
#include <mutex> 

class Singleton 
{ 
public: 
	static Singleton* Instance();
protected:
	Singleton();
private: 
	static Singleton* _instance;
};

std::mutex mtx;

using namespace std;
Singleton* Singleton::_instance = nullptr;
Singleton::Singleton() 
{ 
	cout<<"Singleton...."<<endl; 
}
Singleton* Singleton::Instance() 
{ 	
	std::unique_lock<std::mutex> lock(mtx);
	if (_instance == nullptr) 
	{ 
			_instance = new Singleton(); 
	}
	return _instance; 
}


#endif