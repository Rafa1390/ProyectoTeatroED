#pragma once
#ifndef NODOCOLA_H
#define NODOCOLA_H
#include <string>
#include <iostream>
using namespace std;
class NodoCola
{
private:
	string cliente;
	NodoCola * sig;
public:
	NodoCola();
	NodoCola(string);
	void SetCliente(string);
	string GetCliente(void);
	void SetSig(NodoCola*);
	NodoCola *GetSig(void);
};
#endif // !NODOCOLA_H