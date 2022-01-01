#ifndef _STATE_H_
#define _STATE_H_
#include <iostream> 

class Context;

class State {
public:
	State();
	virtual ~State();
	virtual void OperationInterface(Context*) = 0;
	virtual void OperationChangeState(Context*) = 0;
protected:
	bool ChangeState(Context* con, State* st);
};

class ConcreteStateA :public State {
public:
	ConcreteStateA();
	virtual ~ConcreteStateA();
	virtual void OperationInterface(Context*);
	virtual void OperationChangeState(Context*);
};

class ConcreteStateB :public State {
public:
	ConcreteStateB();
	virtual ~ConcreteStateB();
	virtual void OperationInterface(Context*);
	virtual void OperationChangeState(Context*);
};


class Context {
public:
	Context();
	Context(State* state);
	~Context();
	void OprationInterface();
	void OperationChangState();
private:
	friend class State; 
	bool ChangeState(State* state);
	State* _state;
};
#endif


using namespace std;

State::State() {

}

State::~State() {

}

void State::OperationInterface(Context* con) {
	cout << "State::.." << endl;
}

bool State::ChangeState(Context* con, State* st) {
	con->ChangeState(st);
	return true;
}

void State::OperationChangeState(Context* con) {

}

ConcreteStateA::ConcreteStateA() {

}

ConcreteStateA::~ConcreteStateA() {

}

void ConcreteStateA::OperationInterface(Context* con) {
	cout << "ConcreteStateA::OperationInterface ......" << endl;
}

void ConcreteStateA::OperationChangeState(Context* con) {
	OperationInterface(con);
	this->ChangeState(con, new ConcreteStateB());
}

ConcreteStateB::ConcreteStateB() {

}

ConcreteStateB::~ConcreteStateB(){

}

void ConcreteStateB::OperationInterface(Context* con) { 
	cout << "ConcreteStateB::OperationInterface......" << endl;
}

void ConcreteStateB::OperationChangeState(Context* con) {
	OperationInterface(con);
	this->ChangeState(con, new ConcreteStateA());
}

Context::Context() {

}
Context::Context(State* state) { 
	this->_state = state;
}

Context::~Context() { 
	delete _state; 
}

void Context::OprationInterface() { 
	_state->OperationInterface(this); 
}

bool Context::ChangeState(State* state) 
{  
	this->_state = state;
	return true;
}
void Context::OperationChangState() {
	_state->OperationChangeState(this);
}