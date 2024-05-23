#pragma once
#include <mysql.h>
#include <iostream>
#include <string>
#include "ConexionBD.h"
using namespace std;

class Tipo_sangre{
	//atributos
private:string tipo_sangre;
	   //constructor
public:
	Tipo_sangre() {}
    Tipo_sangre(string ts){
		tipo_sangre = ts;
	}

	void setTipo_sangre(string ts) { tipo_sangre = ts; }
	string getTipo_sangre() { return tipo_sangre; }

	void crear() {
		int q_estado;
		ConexionBD cn = ConexionBD();
		cn.abrir_conexion();

		if (cn.getConectar()) {
			string insert = "insert into tipos_sangre(tipo_sangre) values ('" + tipo_sangre + "')";
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

		if(cn.getConectar()){
			cout << "______________Datos de los Tipos de Sangre______________" << endl;
			string consulta = "select* from tipos_sangre";
			const char* c = consulta.c_str();
			q_estado = mysql_query(cn.getConectar(), c);

			if (!q_estado) {
				resultado = mysql_store_result(cn.getConectar());
				while (fila = mysql_fetch_row(resultado)) {
					cout << fila[0] << "," << fila[1] << endl;
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
		string ii = to_string(id);
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

