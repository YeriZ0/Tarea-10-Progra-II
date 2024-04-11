#include <iostream>
#include <string>

#include "Trabajador.h"

#define LIST 5

using namespace std;

char menu(){
    char op;
    cout << "******** Menu de Planilla de Sueldos ********\n" << endl;
    cout << "1. Agregar empleado" << endl;
    cout << "2. Imprimir planilla" << endl;
    cout << "3. Salir" << endl;
    cout << "Seleccione una opcion: "; cin >> op;

    return op;
}

Trabajador agregarEmpleado(){
    int codigo;
    float sueldoMensual;
    string nombre, apellido;

    cout << "******** Datos del Empleado ********\n" << endl;
    cout << "Digite el codigo: "; cin >> codigo;
    cout << "Digite el nombre: "; cin >> nombre;
    cout << "Digite el apellido: "; cin >> apellido;
    cout << "Ingrese el salario mensual: "; cin >> sueldoMensual;

    Trabajador infoTrabajador(codigo, nombre, apellido, sueldoMensual);
    return infoTrabajador;
}

void imprimirPlanilla(Trabajador lstEmp[], int c){
    if (c == 0){
        cout << "\nNo hay trabajadores agregados." << endl;
    }else{
        cout << "\nCodigo \tNombre \tApellido \tSueldo Mensual \tISSS \tAFP \tISR \tSueldo Total " << endl;
        for (int i = 0; i < c; i++){
            cout << lstEmp[i].getCodigo() << " \t";
            cout << lstEmp[i].getNombre() << " \t";
            cout << lstEmp[i].getApellido() << " \t\t";
            cout << lstEmp[i].getSueldoMensual() << " \t\t";
            cout << lstEmp[i].getDescuentoIsss() << " \t";
            cout << lstEmp[i].getDescuentoAfp() << " \t";
            cout << lstEmp[i].getDescuentoIsr() << " \t";
            cout << lstEmp[i].getTotalPagar() << "\n";
        }
    }
}

int main(){
    char opcion;
    Trabajador planilla[LIST];
    int contador = 0;

    do{
        system("cls");
        opcion = menu();
        switch(opcion){
            case '1':
                //Agregar empleados a la planilla
                system("cls");
                if (contador < LIST){
                    planilla[contador] = agregarEmpleado();
                    contador++;
                    cout << "\nSe ha agregado a la planilla con exito!" << endl;
                }else{
                    cout << "\nEspacios de planilla agotados." << endl;
                }
                break;
            case '2':
                system("cls");
                //imprimir planilla de sueldos
                imprimirPlanilla(planilla, contador);
                break;
            case '3':
                cout << "\nCerrando programa..." << endl;
                break;
            default:
                cout << "\nSeleccione una opcion valida en el menu." << endl;
                break;
        }
        system("pause");
    }while(opcion != '3');

    return 0;
}
