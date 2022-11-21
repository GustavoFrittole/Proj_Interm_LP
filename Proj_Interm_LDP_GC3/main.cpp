//Progetto intermedio LDP gruppo casuale 3 
//21/11/22
//Principali scelte arbitrarie: la classe Date lancia un eccezione nel caso
//la data sia priva di senso; tale eccezione non è gestita da Book (voluto);
//un oggetto libro è invalido se il suo codice ISBN è invalido o la data di 
//copyright appartiene alla preistoria; tale invalidità non comporta il lancio 
//di eccezioni ma può essere verificata tramite la member function "isValid()";
//è contamplata l'evenienza per cui un libro può non avare data di c., qundi se il campo 
//è lasciato al valore di default, si presuppone che questa sia una scelta intenzionale
//che quindi non invalida il libro (a differenza del mancato inserimento del codice ISBN).
//Per maggiori dettagli sono presenti specifici commenti nel codice

#include <iostream>
#include <vector>
#include "Book.h"

int main()
{
    Date date{1,jan,1}; //controllo funzionalità aggiuntive di date
    date.addDays(-32);
    date.addDays(32+365*2021 + 2022/4 - 20*3/4); 
    date += Date{18+4, Month(10), 0};
    std::cout << date << std::endl;
    
    Book book{"Robert","Thorrion", "VIAGGIO DI NOZZE... VERSO L'ALDILA'", "777-678-293-66", Date{1,jan,2015}, false};
    //std::cout << checkISBN("1-1--a");
    book.setnDisp();
    std::cout << "\n-------------------------------\n" << book << "disp: " << book.getDisp() << "\nvalidita': " << book.isValid() << std::endl;
    std::vector<Book> shelf(10);
    std::cout << "\n-------------------------------\n" << shelf[0] << "disp: " << shelf[0].getDisp() << "\nvalidita': " << shelf[0].isValid() << std::endl;
    Book book1{book};
    if(book==book1)std::cout << "operatori == != y ";
    if(book!=shelf[0])std::cout << "y\n";
    Book my_favourite_book("David", "Foster Wallace", "Una cosa divertente che non farò mai più", "88-527-666-x");
    std::cout << "\n-------------------------------\n" << my_favourite_book << "disp: " << my_favourite_book.getDisp() << "\nvalidita': " << my_favourite_book.isValid() << std::endl;
    shelf[1] = Book{"Contadino", "Mesopotamico", "Zappare nella mezzaluna a mezzanotte", "213-132-123-b", Date{1,jan,-4500}};
    std::cout << "\n-------------------------------\n" <<  shelf[1] << "disp: " << shelf[1].getDisp() << "\nvalidita' data: " << shelf[1].isDataCValid() << "\nvalidita' isbn: " << shelf[1].isIsbnValid() << std::endl;
    shelf[1].setTitolo("Paperopoleggiando");
    shelf[1].setNomeA("Pippo");
    shelf[1].setCognomeA("Pluto");
    shelf[1].setIsbn("3746_85_23_9");
    shelf[1].setDataC(Date{1,feb,6000});
    std::cout << "\n-------------------------------\n" << shelf[1] << "disp: " << shelf[1].getDisp() << "\nvalidita' data: " << shelf[1].isDataCValid() << "\nvalidita' isbn: " << shelf[1].isIsbnValid() << std::endl;
	return 0;
}

