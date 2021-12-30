#include "AbstractFactory.h"
#include <iostream>

using namespace std;
AbstractProductA::AbstractProductA() 
{
	cout<<"AbstractProductA"<<endl;
}

AbstractProductA::~AbstractProductA() 
{
	cout<<"~AbstractProductA"<<endl;
}

AbstractProductB::AbstractProductB() 
{
	cout<<"AbstractProductB"<<endl;
}

AbstractProductB::~AbstractProductB()
{
	cout<<"~AbstractProductB"<<endl;
}

ProductA1::ProductA1() 
{
	cout<<"ProductA1..."<<endl; 
}

ProductA1::~ProductA1() 
{
	cout<<"~ProductA1"<<endl;
}
ProductA2::ProductA2() 
{ 
	cout<<"ProductA2..."<<endl; 
}
ProductA2::~ProductA2() 
{
	cout<<"~ProductA2..."<<endl; 
}
ProductB1::ProductB1()
{
	cout<<"ProductB1..."<<endl; 
}
ProductB1::~ProductB1() 
{
	cout<<"~ProductB1..."<<endl;
}
ProductB2::ProductB2() 
{
	cout<<"ProductB2..."<<endl; 
}
ProductB2::~ProductB2()
{
	cout<<"~ProductB2..."<<endl;
}
AbstractFactory::AbstractFactory() 
{
	cout<<"AbstractFactory"<<endl;
}
AbstractFactory::~AbstractFactory()
{
	cout<<"~AbstractFactory"<<endl;
}
ConcreteFactory1::ConcreteFactory1() 
{
	cout<<"ConcreteFactory1"<<endl;
}
ConcreteFactory1::~ConcreteFactory1() 
{
	cout<<"~ConcreteFactory1"<<endl;
}
AbstractProductA* ConcreteFactory1::CreateProductA() 
{ 
	return new ProductA1(); 
}
AbstractProductB* ConcreteFactory1::CreateProductB() 
{ 
	return new ProductB1(); 
}
ConcreteFactory2::ConcreteFactory2()
{
	cout<<"ConcreteFactory2"<<endl;
}
ConcreteFactory2::~ConcreteFactory2() 
{
	cout<<"~ConcreteFactory2"<<endl;
}
AbstractProductA* ConcreteFactory2::CreateProductA() 
{ 
	return new ProductA2(); 
}
AbstractProductB* ConcreteFactory2::CreateProductB() 
{ 
	return new ProductB2(); 
}

using namespace std;
int main(int argc,char* argv[]) 
{ 
	AbstractFactory* cf1 = new ConcreteFactory1();
	delete cf1->CreateProductA(); 
	delete cf1->CreateProductB();
	delete cf1;

	AbstractFactory* cf2 = new ConcreteFactory2(); 
	delete cf2->CreateProductA(); 
	delete cf2->CreateProductB();
	delete cf2;
	
    return 0; 
}