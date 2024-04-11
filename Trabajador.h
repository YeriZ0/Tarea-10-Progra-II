#ifndef TRABAJADOR_H_INCLUDED
#define TRABAJADOR_H_INCLUDED

#include "Persona.h"

class Trabajador : public Persona{
    private:
        float sueldoMensual;
        float descuentoIsss;
        float descuentoAfp;
        float descuentoIsr;
        float totalPagar;
        void calcular(){
            // antes del calculo los valores deben estar en cero
            this -> descuentoIsss = 0;
            this -> descuentoAfp = 0;
            this -> descuentoIsr = 0;
            this -> totalPagar = 0;

            this -> descuentoIsss = sueldoMensual * 0.03;
            if(this -> descuentoIsss > 30){
                this -> descuentoIsss = 30;
            }

            this -> descuentoAfp = sueldoMensual * 0.0725;
            if(this -> descuentoAfp > 543.75){
                this -> descuentoAfp = 543.75;
            }

            this -> totalPagar = this -> sueldoMensual - (this -> descuentoIsss + this -> descuentoAfp);

            float antesISR = this -> sueldoMensual -(this -> descuentoIsss + this -> descuentoAfp);
            if(antesISR <= 472){
                this -> descuentoIsr = 0;
            }else if(antesISR<= 895.24){
                this -> descuentoIsr = ((this -> sueldoMensual - 472) * 0.10) + 17.67;
            }else if(antesISR <= 2038.10){
                this -> descuentoIsr = ((this -> sueldoMensual - 895.24) * 0.20) + 60;
            }else if(antesISR >= 2038.11){
                this -> descuentoIsr = ((this -> sueldoMensual - 2038.10) * 0.30) + 288.57;
            }

            this -> totalPagar -= this -> descuentoIsr;
        }
    public:
        Trabajador(){
            this -> sueldoMensual = 0;
            this -> descuentoIsss = 0;
            this -> descuentoAfp = 0;
            this -> descuentoIsr = 0;
            this -> totalPagar = 0;
        }
        Trabajador(int c, string n, string a, float sM) : Persona(c, n, a){
            this -> sueldoMensual = sM;
            this -> calcular();
        }
        float getSueldoMensual(){
            return this -> sueldoMensual;
        }
        float getDescuentoIsss(){
            return  this -> descuentoIsss;
        }
        float getDescuentoAfp(){
            return this -> descuentoAfp;
        }
        float getDescuentoIsr(){
            return this -> descuentoIsr;
        }
        float getTotalPagar(){
            return this -> totalPagar;
        }
};

#endif // TRABAJADOR_H_INCLUDED
