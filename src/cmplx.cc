/*
cmplx.cc

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

//
#include "cmplx.h" 

/* constructors */
ff::Complex::Complex(){
    real=0;
    imag=0;
}
ff::Complex::Complex(const double &_real, const double &_imag){
    real=_real;
    imag=_imag;
}
ff::Complex::Complex(const double &o){
    real=o;
    imag=0;
}
ff::Complex::Complex(const ff::Complex &o){
    real = o.Real();
    imag = o.Imag();
}

/* matematical operators */
ff::Complex ff::Complex::operator+(const ff::Complex &o)const{
    return ff::Complex(real + o.Real(),imag + o.Imag());
}
ff::Complex ff::Complex::operator+(const double &o)const{
    return ff::Complex(real + o, imag);
}
ff::Complex ff::Complex::operator-(const ff::Complex &o)const{
    return ff::Complex(real + o.Real(),imag + o.Imag());
}
ff::Complex ff::Complex::operator-(const double &o)const{
    return ff::Complex(real - o,imag);
}
ff::Complex ff::Complex::operator*(const ff::Complex &o)const{
    return ff::Complex(real*o.Real() - imag*o.Imag(), real*o.Imag() + imag*o.Real());
}
ff::Complex ff::Complex::operator*(const double &o)const{
    return ff::Complex(real * o, imag*o);
}
ff::Complex ff::Complex::operator/(const ff::Complex &o)const{
    return ((*this)*o.conj())/o.abs();
}
ff::Complex ff::Complex::operator/(const double &o)const{
    return ff::Complex(real/o,imag/o);
}
ff::Complex ff::Complex::operator^(const double &o)const {
    double r = (*this).abs();
    double tita = (*this).angle();
    std::cout << "r value: " << r << " tita value: " << tita << "\n"; 
    return pow(r,o) * (cos(tita*o) + i*sin(tita*o));
}
ff::Complex ff::Complex::operator^(const Complex &o)const {
    double r = (*this).abs();
    double tita = (*this).angle();
    return ((*this)^(o.Real()))*pow(E,-tita*o.Imag())*ff::Complex(cos(o.Imag()*log(r)) , sin(o.Imag()*log(r)));
}

/* assingment operators */
ff::Complex ff::Complex::operator=(const ff::Complex &o){
     real = o.Real();
     imag = o.Imag();
     return *this;
}
ff::Complex ff::Complex::operator=(const double &o){
    real = o;
    imag = 0;
    return *this;
}
ff::Complex ff::Complex::operator+=(const ff::Complex &o){
    real += o.Real();
    imag += o.Imag();
    return *this;
}
ff::Complex ff::Complex::operator+=(const double &o){
    real += o;
    return *this;
}
ff::Complex ff::Complex::operator-=(const ff::Complex &o){
    real -= o.Real();
    imag -= o.Imag();
    return *this;
}
ff::Complex ff::Complex::operator-=(const double &o){
    real -= o;
    return *this;
}
ff::Complex ff::Complex::operator*=(const ff::Complex &o){
    (*this) = (*this) * o;
    return *this;
}
ff::Complex ff::Complex::operator*=(const double &o){
    (*this) = (*this) * o;
    return *this;
}
ff::Complex ff::Complex::operator/=(const ff::Complex &o){
    (*this) = (*this) / o;
    return *this;
}
ff::Complex ff::Complex::operator/=(const double &o){
    (*this) = (*this) / o;
    return *this;
}

/* comparing operators */
bool ff::Complex::operator==(const ff::Complex &o)const{
    return ((*this).Real() == o.Real() && (*this).Imag() == o.Imag());
}
bool ff::Complex::operator==(const double &o)const{
    return (*this).Real() == o;
}
bool ff::Complex::operator!=(const ff::Complex &o)const{
    return !((*this)==o); 
}
bool ff::Complex::operator!=(const double &o)const{
    return !((*this)==o);
}
bool ff::Complex::operator>(const ff::Complex &o)const{
    return ((*this).abs() > o.abs());    
}
bool ff::Complex::operator>(const double &o)const{
    return ((*this).abs() > o);
}
bool ff::Complex::operator<(const ff::Complex &o)const{
    return (*this).abs() < o.abs();
}
bool ff::Complex::operator<(const double &o)const{
    return (*this).abs() < o;
}
bool ff::Complex::operator>=(const ff::Complex &o)const{
    return (*this).abs() >= o.abs();
}
bool ff::Complex::operator>=(const double &o)const{
    return (*this).abs() >= o;
}
bool ff::Complex::operator<=(const ff::Complex &o)const{
    return (*this).abs() <= o.abs();
}
bool ff::Complex::operator<=(const double &o)const{
    return (*this).abs() <= o;
}

/* printing operators */
std::string ff::Complex::operator<<(const Complex &o)const{
    return (*this).toString() + " " +o.toString();
}
std::string ff::Complex::operator<<(const double &o)const{
    return (*this).toString() + " " + std::to_string(o);
}

/* accessing data operators */
double ff::Complex::Real()const{
    return real;
}
double ff::Complex::Imag()const{
    return imag;
}
double ff::Complex::abs()const{
    return sqrt(pow(real,2) + pow(imag,2));
}
double ff::Complex::angle()const{
    return atan(imag/real);
}
double ff::Complex::angleDeg()const{
    return 180*(*this).angle()/PI;
}
ff::Complex ff::Complex::conj()const{
    return ff::Complex(real, -imag);
}

/* converting to String */ 
std::string ff::Complex::toString()const{
    std::string ret = "";
    if(imag > 0){
        ret +=  std::to_string(real) + " + " +std::to_string(imag) + "i";
    }else {
        ret += std::to_string(real) + " " + std::to_string(imag) + "i";
    }
    return ret;
}
