#ifndef DATE_H
#define DATE_H

#include "Month.h"
#include <iostream>

class Date{
    int day;
    Month month;
    int year;
public:
    Date(int, Month, int);
    Date();

    int getDay() const;
    int getYear() const;
    Month getMonth() const;
        
    bool isValid() const;
    
    void addDays(int);
    void addMonths(int);
    void addYears(int);
    
    Date& operator+=(const Date&);  //es: "5 anni, 2 mesi e 15 giorni dopo"
};

std::ostream& operator<<(std::ostream& os, const Date& d);
//Date operator+(const Date& d1, const Date& d2);   //poco sensato, poco utile

#endif