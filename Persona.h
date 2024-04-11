#ifndef PERSONA_H_INCLUDED
#define PERSONA_H_INCLUDED

#include <string>

using namespace std;

class Persona{
    protected:
        int codigo;
        string nombre;
        string apellido;
    public:
        Persona(){
            this -> codigo = 0;
        }
        Persona(int c, string nom, string ape){
            this -> codigo = c;
            this -> nombre = nom;
            this -> apellido = ape;
        }
        int getCodigo(){
            return this -> codigo;
        }
        string getNombre(){
            return this -> nombre;
        }
        string getApellido(){
            return this -> apellido;
        }
};

#endif // PERSONA_H_INCLUDED
