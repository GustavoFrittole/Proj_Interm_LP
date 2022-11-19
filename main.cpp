//Progetto intermedio gruppo casuale3 
//19/11/22

#include <iostream>
#include <vector>
#include "Book.h"

int main()
{
    Date date{1,jan,1}; //controllo funzionalità aggiuntive di date
    date.addDays(-32);
    date.addDays(32+365*2021 + 2022/4 - 20*3/4); 
    date += Date{18, Month(10), 0};
    std::cout << date << std::endl;
    
    Book book{"Robert","Thorrion", "VIAGGIO DI NOZZE... VERSO L'ALDILA'", "3498-6-23-h", Date{1,jan,2015}, false};
    //std::cout << checkISBN("1-1--a");
    book.setnDisp();
    std::cout << book << "disp: " << book.getDisp() << "\nvalidita': " << book.isValid() << std::endl;
    std::vector<Book> shelf(10);
    std::cout << shelf[0] << "disp: " << shelf[0].getDisp() << "\nvalidita': " << shelf[0].isValid() << std::endl;
    Book book1{book};
    if(book==book1)std::cout << "operatori == != y ";
    if(book!=shelf[0])std::cout << "y\n";
    Book my_favourite_book("David", "Foster Wallace", "Una cosa divertente che non farò mai più", "887-521-837-4");
    std::cout << my_favourite_book << "disp: " << my_favourite_book.getDisp() << "\nvalidita': " << my_favourite_book.isValid() << std::endl;
    shelf[1] = Book{"Contadino", "Mesopotamico", "Zappare nella mezzaluna a mezzanotte", "7346298347-6-234-b", Date{1,jan,-4500}};
    std::cout << shelf[1] << "disp: " << shelf[1].getDisp() << "\nvalidita' data: " << shelf[1].isDataCValid() << "\nvalidita' isbn: " << shelf[1].isIsbnValid() << std::endl;
    
	return 0;
}

