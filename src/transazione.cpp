#include "transazione.h"

Transazione::Transazione(double importo, const std::string& descrizione, std::time_t timestamp)
    : importo_(importo), descrizione_(descrizione), timestamp_(timestamp) {}

double Transazione::getImporto() const {
    return importo_;
}

std::string Transazione::getDescrizione() const {
    return descrizione_;
}

std::time_t Transazione::getTimestamp() const {
    return timestamp_;
}
