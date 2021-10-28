#include "Intervalle.h"
#include <stdio.h>
#include <iostream>
using namespace std; 
Intervalle::Intervalle(double a)
{
	if (a < 0) {
		this->borneInf = a; 
		this->borneSup = 0;
	}
	else {
		this->borneInf = 0;
		this->borneSup = a;
	}
		
}
Intervalle::Intervalle(double a, double b)
{
	if (a <= b)
	{
		this->borneInf = a;
		this->borneSup = b; 
	}
	else {
		this->borneInf = b;
		this->borneSup = a;
	}
}

double Intervalle::Max() const
{
	return this->borneSup;
}

double Intervalle::Min() const 
{
	return this->borneInf;
}

bool Intervalle::operator[](double number) const
{
	return (this->borneInf <= number && number <= this->borneSup);
}

bool Intervalle::operator()(Intervalle& Inter) const
{
	return false;
}

Intervalle& Intervalle::operator|(Intervalle& Inte)
{
	Intervalle* ResIntervalle = new Intervalle(0); 
	if (Inte.Min() > this->Min())
		ResIntervalle->borneInf = this->Min();
	else
		ResIntervalle->borneInf = Inte.Min();
	
	if (Inte.Max() > this->Max())
		ResIntervalle->borneSup = Inte.Max();
	else
		ResIntervalle->borneSup = Inte.Max();


	return *ResIntervalle; 
}

Intervalle& Intervalle::operator&(Intervalle& Inte)
{
	if (Inte[this->borneInf] && Inte[this->borneSup])
		return *this; 

	if ((*this)[Inte.borneInf] && (*this)[Inte.borneSup])
		return Inte; 

	Intervalle* result = new Intervalle(0, 0);
	if (this->borneInf < Inte.borneSup && Inte.borneInf < this->borneSup)
	{
		result->borneInf = (this->borneInf > Inte.borneInf) ? this->borneInf : Inte.borneInf;
		result->borneSup = (this->borneSup < Inte.borneSup) ? this->borneSup : Inte.borneSup;

		return *result; 
	}
	if (this->borneSup == Inte.borneInf) {
		Intervalle* re = new Intervalle(this->borneSup, this->borneSup); 
		return *re; 
	}
	if (this->borneInf == Inte.borneSup) {
		Intervalle* re = new Intervalle(this->borneInf, Inte.borneSup);
		return *re;
	}

	
	cout << "\nPas d'intersection\n" << endl; 
	return *result; 
	
}

void Intervalle::consulter() const
{
	cout << "[" << this->borneInf << ", " << this->borneSup << "]" << endl;
}
