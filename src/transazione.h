#ifndef TRANSAZIONE_H
#define TRANSAZIONE_H

#include <string>
#include <ctime>

class Transazione {
public:
    Transazione(double importo, const std::string& descrizione, std::time_t timestamp);

    double getImporto() const;
    std::string getDescrizione() const;
    std::time_t getTimestamp() const;

private:
    double importo_;
    std::string descrizione_;
    std::time_t timestamp_;
};

#endif // TRANSAZIONE_H
