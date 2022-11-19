#include "Book.h"
#include <iostream>

Book::Book(const std::string& n, const std::string& c, const std::string& t, 
                    const std::string& isbn, const Date& date, bool disp)
    :nomeA{n}, cognomeA{c}, titolo{t}, dataC{date}, isbn{isbn}, disp{disp}{}

    //non è banale stabilire una data minima per il Copyright. Possibili opzioni:
    //Berne Convention 1886, Statute of Anne 1710, invenzione stampa XI sec Cina...
    //in assenza di precisazioni, il limite ragionevole più lasco è la fine della preistoria
    //crediti per l'idea di iserire il limite minimo alla data ad un ragazzo di un altro gruppo 
bool Book::isDataCValid() const { return (dataC.getYear() >= -4000); } 
bool Book::isIsbnValid() const { return checkISBN(isbn); };
bool Book::isValid() const { return (isDataCValid() && isIsbnValid()); }
    //1/1/-4000 è considerata data non inserita

void Book::setDisp(){ disp = true; }
void Book::setnDisp(){ disp = false; }

std::string Book::getTitolo() const { return titolo; }
std::string Book::getNomeA() const { return nomeA; }
std::string Book::getCognomeA() const { return cognomeA; }
Date Book::getDataC() const { return dataC; }
std::string Book::getIsbn() const { return isbn; }
bool Book::getDisp() const { return disp; };

std::ostream& operator<<(std::ostream& os, const Book& b){
        os << "Autore: " << b.getNomeA() << " " << b.getCognomeA()
            <<  "\nTitolo: " << b.getTitolo()  << "\nCodice ISBN: " << b.getIsbn()<< "\n";
        if(b.getDataC().getYear() == -4000)  os << "Nessuna data di copyright" << std::endl; 
                    //se la data non è stata cambiata si presuppone il libro non abbia data di c.
        else os << "Data di copyright: " << b.getDataC() << std::endl;
        return os;
}
bool operator==(const Book& b1, const Book& b2){ return b1.getIsbn() == b2.getIsbn(); }
bool operator!=(const Book& b1, const Book& b2){ return b1.getIsbn() != b2.getIsbn(); }


