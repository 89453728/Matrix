/*
cmplx.h

Copyright (C) 2020-2021 Yassin Achengli <0619883460@uma.es>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program; see the file COPYING.  If not, see
<https://www.gnu.org/licenses/>.

======================================================================
*/

#ifndef CMPLX_F
#define CMPLX_F
#define PI 3.141592653589793
#define E 2.718281828459045
#include <cmath>
#include <iostream>
#include <ostream>
#include <string>

namespace ff {
    class Complex {
        private: 
            double real;
            double imag;
        public: 
            /* Constructors */
            Complex();
            Complex(const double &real, const double &imag);
            Complex(const Complex &o);
            Complex(const double &o);

            /* Arithmetic operators */
            Complex operator+(const Complex &o)const;
            Complex operator+(const double &o)const;
            Complex operator-(const Complex &o)const;
            Complex operator-(const double &o)const;
            Complex operator*(const Complex &o)const;
            Complex operator*(const double &o)const;
            Complex operator/(const Complex &o)const;
            Complex operator/(const double &o)const;
            Complex operator^(const Complex &o)const;
            Complex operator^(const double &o)const;

            /* assignment operators */
            Complex operator=(const Complex &o);
            Complex operator=(const double &o);
            Complex operator+=(const Complex &o);
            Complex operator+=(const double &o);
            Complex operator-=(const Complex &o);
            Complex operator-=(const double &o);
            Complex operator*=(const Complex &o);
            Complex operator*=(const double &o);
            Complex operator/=(const Complex &o);
            Complex operator/=(const double &o);

            /* compare operators */
            bool operator==(const Complex &o)const;
            bool operator==(const double &o)const;
            bool operator!=(const Complex &o)const;
            bool operator!=(const double &o)const;
            bool operator>(const Complex &o)const;
            bool operator>(const double &o)const;
            bool operator<(const Complex &o)const;
            bool operator<(const double &o)const;
            bool operator>=(const Complex &o)const;
            bool operator>=(const double &o)const;
            bool operator<=(const Complex &o)const;
            bool operator<=(const double &o)const;
            
            /* printing in screen methods join two Complex numbers */
            std::string operator<<(const Complex &o)const;
            std::string operator<<(const double &o)const;

            /* data accessing methods */
            double Real()const;
            double Imag()const;
            double abs()const;
            double angle()const;
            double angleDeg()const;
            Complex conj()const;
            std::string toString() const;
            
            /* friend operators to solve the order of the operands */
            friend std::ostream & operator<<(std::ostream &out, const Complex &o) {
            	out << o.toString();
            	return out;
            }
            friend Complex operator+(const double &a, const Complex &c){
            	return c + a;
            }
            friend Complex operator-(const double &a, const Complex &c){
            	return c - a;
            }
            friend Complex operator*(const double &a, const Complex &c){
            	return c *a;
            }
            friend Complex operator/(const double &a, const Complex &c){
            	return c / a;
            }  
            friend ff::Complex operator^(const double &a, const ff::Complex &c) {
	            double cte = pow(a,c.Real());
	            double _real = cte*cos(c.Imag() * log(a));
	            double _imag = cte*sin(c.Imag() * log(a));
	            return ff::Complex(_real,_imag);
            };

            friend Complex operator+(const int &a, const Complex &c){
            	return c + (int)a;
            }
            friend Complex operator-(const int &a, const Complex &c){
            	return c - (int)a;
            }
            friend Complex operator*(const int &a, const Complex &c){
            	return c *(int)a;
            }
            friend Complex operator^(const int &a, const Complex &c){
                Complex ret = Complex(pow(a,c.Real()) + cos(c.Imag() * log(a)), sin(c.Imag()*log(a))); 
                return ret;
            }
            friend Complex operator/(const int &a, const Complex &c){
            	return c / (int)a;
            }
    };
}

const ff::Complex i = ff::Complex(0,1);
const ff::Complex j = ff::Complex(0,1);

#endif

