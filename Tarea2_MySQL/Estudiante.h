#pragma once
#include<mysql.h>
#include <iostream>
#include <string>
#include "ConexionBD.h"
#include "tipo_sangre.h"
using namespace std;

class Estudiante : Tipo_sangre {
private: string codigo, nombres, apellidos, direccion,fecha_nacimiento, id_tipo_sangre;
	   int telefono;
	   //Constructor

public:
	Estudiante() {}
	Estudiante(string cod, string nomb, string ape, string dir, int tel, string fn) : Tipo_sangre(id_tipo_sangre) {
		
	}

	//Metodos set (modificar)
	void setCod(string cod) { codigo=cod; }
	void setNombres(string nom) { nombres = nom; }
	void setApellidos(string ape) { apellidos = ape; }
	void setDireccion(string dir) { direccion = dir; }
	void setTelefono(int tel) { telefono = tel; }
	void setFecha_nacimiento(string fn) {fecha_nacimiento = fn;}
	void setId_tipo_sangre(string ts) { id_tipo_sangre = ts; }

	// Metodo get (Mostrar)
	string getCod() { return codigo; }
	string getNombres() { return nombres;  }
	string getApellidos() { return apellidos; }
	string getDireccion() { return direccion; }
	int getTelefono() { return telefono; }
	string getFecha_nacimiento() { return fecha_nacimiento; }
	string getId_tipo_sangre() { return id_tipo_sangre; }

	void crear() {
		int q_estado;
		string t = to_string(telefono);
		ConexionBD cn = ConexionBD();
		cn.abrir_conexion();

		if (cn.getConectar()) {
			string insert = "insert into estudiantes(codigo, nombres,apellidos, direccion, telefono, fecha_nacimiento, id_tipo_sangre) values ('" + codigo + "','" + nombres + "', '" + apellidos +"','" + direccion + "','" + telefono + "','" + fecha_nacimiento + "','" + id_tipo_sangre + "')";
			const char* i = insert.c_str();
			q_estado = mysql_query(cn.getConectar(), i);
			if (!q_estado) {
				cout << "Ingreso Exitoso..." << endl;
			}
			else {
				cout << "XXXX Error al ingresar XXXX" << endl;
			}
		}
		else {
			cout << "XXX Error en la Conexion XXX" << endl;
		}
		cn.cerrar_conexion();
	}

	void leer() {
		int q_estado;
		ConexionBD cn = ConexionBD();
		MYSQL_ROW fila;
		MYSQL_RES* resultado;
		cn.abrir_conexion();

		if (cn.getConectar()) {
			cout << "______________Datos de los Estudiantes______________" << endl;
			string consulta = "select* from estudiantes";
			const char* c = consulta.c_str();
			q_estado = mysql_query(cn.getConectar(), c);

			if (!q_estado) {
				resultado = mysql_store_result(cn.getConectar());
				while (fila = mysql_fetch_row(resultado)) {
					cout << fila[0] << "," << fila[1] <<","<< fila [2] << "," << fila[3] << "," << fila[4] << "," << fila[5] << "," << fila[6] << "," << fila[7] << endl;
				}
			}
			else {
				cout << "XXXX Error al consultar XXXX" << endl;
			}
		}
		else {
			cout << "XXX Error en la Conexion XXXX" << endl;
		}
		cn.cerrar_conexion();
	}

	void actualizar() {
		int q_estado;
		ConexionBD cn = ConexionBD();

		cn.abrir_conexion();
		string tipo_sangre;
		if (cn.getConectar()) {
			string  actualizar =
				"update clientes set tipo_sangre = '" + tipo_sangre + "'";
			const char* i = actualizar.c_str();
			// executar el query
			q_estado = mysql_query(cn.getConectar(), i);
			if (!q_estado) {
				cout << "Actualizacion Exitosa ..." << endl;
			}
			else {
				cout << " xxx Error al Ingresar  xxx" << endl;
			}
		}
		else {
			cout << " xxx Error en la Conexion xxxx" << endl;
		}
		cn.cerrar_conexion();
	}

	void borrar() {
		int q_estado;
		ConexionBD cn = ConexionBD();

		cn.abrir_conexion();
		if (cn.getConectar()) {
			string  borrar =
				"delete from clientes  where id_tipo_sangre = " + ii + "";
			const char* i = borrar.c_str();
			// executar el query
			q_estado = mysql_query(cn.getConectar(), i);
			if (!q_estado) {
				cout << "Eliminacion Exitosa ..." << endl;
			}
			else {
				cout << " xxx Error al Ingresar  xxx" << endl;
			}
		}
		else {
			cout << " xxx Error en la Conexion xxxx" << endl;
		}
		cn.cerrar_conexion();
	}

};


