#include"Date.h"
#include <stdexcept>

Date::Date(int d, Month m, int y)
    :day{d}, month{m}, year{y} {
        if(!isValid()) throw std::invalid_argument("Data non valida.");
    }

Date::Date()
    :day{1}, month{Month(1)}, year{-4000} {}  //Data che figurerà come "non inserita" in Book

int Date::getDay() const { return day; }
int Date::getYear() const { return year; }
Month Date::getMonth() const { return month; }
    
bool Date::isValid() const{
    if(day<1 || day>daysInM(month, year)) return false;
    return true;
}
void Date::addDays(int d){
    
    day += d;
    
    while(day > daysInM(month, year)){
        day -= daysInM(month, year);
        addMonths(1);
    }
    while(day <= 0){
        addMonths(-1);
        day += daysInM(month, year);
    }
}
void Date::addMonths(int m){
    
    m += (int)month;
    
    if (m <= 0){
        year += -1 + (m-1)/12;
        m = (m-1)%12 + 12 + 1;
            //std::cout << month << " ";
    }
    else{
        year += (m-1)/12;
        m = (m-1)%12 + 1;
            //std::cout << month << " ";
    }
    month = Month(m);
}
void Date::addYears(int y){ year += y; }

Date& Date::operator+=(const Date& d){ 
    addYears(d.getYear());
    addMonths(d.getMonth());
    addDays(d.getDay());
    return *this; 
}
std::ostream& operator<<(std::ostream& os, const Date& d){ 
    return os << d.getDay() << "/" << (int)d.getMonth() << "/" << d.getYear();
}
/*Date operator+(const Date& d1, const Date& d2){ 
    Date r{d1};
    r.addYears(d2.getYear());
    r.addMonths(d2.getMonth());
    r.addDays(d2.getDay());
    return r; 
}*/

