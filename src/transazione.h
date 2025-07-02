#ifndef TRANSAZIONE_H
#define TRANSAZIONE_H
#include <string>

class Transazione {
private:
    double importo_;
    std::string descrizione_;
public:
    Transazione(double importo, const std::string& descrizione); // Costruttore

    double getImporto() const; // Metodo pubblico che restituisce l'importo della transazione
    std::string getDescrizione() const; // Metodo pubblico che restituisce la descrizione della transazione

};

#endif // TRANSAZIONE_H



