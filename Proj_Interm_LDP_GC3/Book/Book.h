#ifndef BOOK_H
#define BOOK_H

#include "Date.h"
#include "Isbn.h"

class Book{
public:
    Book(const std::string& n = "", const std::string& c = "", const std::string& t = "",
                const std::string& isbn = "", const Date& date = Date{}, bool disp = true); 
                //si presume che un libro inserito sia in magazzino
    bool isDataCValid() const;
    bool isIsbnValid() const;
    bool isValid() const;   //la validità di un libro si basa arbitrariamente sull'inserimento di data e ISBN validi;
    void setDisp();         //set disp = true
    void setnDisp();        //set disp = false
    std::string getTitolo() const;
    std::string getNomeA() const;
    std::string getCognomeA() const;
    Date getDataC() const;
    std::string getIsbn() const;
    bool getDisp() const;

    void setTitolo(const std::string&);
    void setNomeA(const std::string&);
    void setCognomeA(const std::string&);
    void setDataC(const Date&);
    void setIsbn(const std::string&);
    
private:
    std::string nomeA;
    std::string cognomeA;
    std::string titolo;
    Date dataC;
    std::string isbn;
    bool disp;
};

std::ostream& operator<<(std::ostream& os, const Book& b);
bool operator==(const Book& b1, const Book& b2);
bool operator!=(const Book& b1, const Book& b2);

#endif