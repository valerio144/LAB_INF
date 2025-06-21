#ifndef CONTO_H
#define CONTO_H

#include "transazione.h"
#include <vector>
#include <string>

class Conto {
public:
    Conto();

    void aggiungiTransazione(const Transazione& transazione);
    double getSaldo() const;
    size_t getNumeroTransazioni() const;

    bool salvaSuFile(const std::string& filename) const;
    bool caricaDaFile(const std::string& filename);

    const std::vector<Transazione>& getTransazioni() const;

private:
    std::vector<Transazione> transazioni_;
    double saldo_;
};

#endif // CONTO_H
