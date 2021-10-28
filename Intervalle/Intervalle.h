#pragma once

class Intervalle
{
private:
	double borneInf; 
	double borneSup; 
public:
	Intervalle(double); 
	Intervalle(double, double);
	double Max() const; 
	double Min() const; 
	
	//si number appartient a l intervalle 
	bool operator[](double number) const;

	//union 
	Intervalle& operator| (Intervalle& Inte); 

	//Intersection 
	Intervalle& operator& (Intervalle& Inte);
	void consulter() const; 
	


};
