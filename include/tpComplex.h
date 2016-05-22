#ifndef TPCOMPLEX_H
#define TPCOMPLEX_H

#include <ostream>
#include <type_traits>

#include <../debug.h>

template<class T>
constexpr bool isIntorDouble = std::is_same<T,int>::value|| std::is_same<T,double>::value;
template<class T>
class tpComplex
{
public:
    static_assert(isIntorDouble<T>,"Wrong Type"); //Ошибка комптляции
    T Re;
    T Im;
    tpComplex() :Re(0),Im(0) {}; //explicit ???
    explicit tpComplex(T real, T img):Re(real),Im(img) {}; //????
    tpComplex(const tpComplex &cmx): Re(cmx.Re),Im(cmx.Im) {};
    tpComplex sum(const tpComplex &oth) const;
    tpComplex sub(const tpComplex &oth) const;
    tpComplex mul(const tpComplex &oth) const;
    tpComplex operator+(const tpComplex &oth) const;
    tpComplex operator-(const tpComplex &oth) const;
    tpComplex operator*(const tpComplex &oth) const;

    template<class U>
    friend std::ostream& operator<< (std::ostream& out,const tpComplex<U>& val);
};
template<class T>
std::ostream& operator<< (std::ostream& out,const tpComplex<T>& val)
{
    try
    {
        out << val.Re;
        out << ((val.Im >= 0)?"+":"");
        out << val.Im;
        out <<"i"<<std::endl;;
        return out;
    }
    catch(...)
    {

        throw;
    }
}
template<typename T>
tpComplex<T> tpComplex<T>::sum(const tpComplex &oth) const
{

    tpComplex temp(Re+oth.Re,Im+oth.Im);

    LOG("temp",temp);

    return temp;
}

template<class T>
tpComplex<T> tpComplex<T>::sub(const tpComplex &oth) const
{
    tpComplex temp(Re-oth.Re,Im-oth.Im);

    LOG("temp",temp);

    return temp;
}
template<class T>
tpComplex<T> tpComplex<T>::mul(const tpComplex &oth) const
{
    tpComplex temp(Re*oth.Re-Im*oth.Im, Im*oth.Re+Re*oth.Im);

    LOG("temp",temp);

    return temp;
}
template<class T>
tpComplex<T> tpComplex<T>::operator+(const tpComplex &oth) const
{
    return this->sum(oth);
}
template<class T>
tpComplex<T> tpComplex<T>::operator-(const tpComplex &oth) const
{
    return this->sub(oth);
}
template<class T>
tpComplex<T> tpComplex<T>::operator*(const tpComplex &oth) const
{
    return this->mul(oth);
}

#endif // TPCOMPLEX_H

