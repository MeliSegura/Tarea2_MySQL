#pragma once
#include "Estudiante.h"
#include <iostream>
using namespace std;

int main()
{
	string codigo, nombres, apellidos, direccion, fecha_nacimiento, id_tipo_sangre;
	int telefono;

	cout << "Ingrese el codigo: ";
	getline(cin, codigo);
	cout << "Ingrese Nombres: ";
	getline(cin, nombres);
	cout << "Ingrese Direccion: ";
	getline(cin, direccion);
	cout << "Ingrese Apellidos: ";
	getline(cin, apellidos);
	cout << "Ingrese Fecha de Nacimiento: ";
	getline(cin, fecha_nacimiento);
	cout << "Ingrese el Id del tipo de sangre: ";
	getline(cin, id_tipo_sangre);

	Estudiante E = Estudiante(nombres, apellidos, direccion, fecha_nacimiento, id_tipo_sangre);

}

