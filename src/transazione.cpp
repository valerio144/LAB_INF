#include "transazione.h"

Transazione::Transazione(double importo, const std::string& descrizione)
    : importo_(importo), descrizione_(descrizione) {}

double Transazione::getImporto() const {
    return importo_;
}

std::string Transazione::getDescrizione() const {
    return descrizione_;
}
