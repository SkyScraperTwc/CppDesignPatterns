#include <string>
#include <iostream>


//  build with: g++  -Wall main.cpp -o simple_factory

using namespace std;

class Api
{
public:
	virtual void Operation(string& str) const = 0;
	virtual  ~Api(){cout << "Api::~Api()" << endl;};
	Api(){
		cout << "Api::Api()" << endl;
	}
};

class ImplA: public Api
{
public:
	ImplA(){
		cout << "ImplA::ImplA()" << endl;
	}
	~ImplA(){
		cout << "ImplA::~ImplA()" << endl;
	}

	void Operation(string& str) const {
		cout << "ImplA::Operation():" + str  << endl;
	}
	
};


class ImplB: public Api
{
public:
	ImplB(){
		cout << "ImplB::ImplB()" << endl;
	}
	~ImplB(){
		cout << "ImplB::ImplB()" << endl;
	}

	void Operation(string& str) const {
		cout << "ImplB::Operation():" + str  << endl;
	}
};

class Factory{
public:
	static Api* CreateApi(std::string type) {
		if (type == "A") {
   		  return new ImplA();
		} else if (type == "B") {
		  return new ImplB();
		}
		return nullptr;
	}
};

int main(int argc, char const *argv[])
{
	Api* api = Factory::CreateApi("A");
	string str("test");
	api->Operation(str);
	delete api;
	return 0;
}
