#include "conto.h"
#include <fstream>
#include <sstream>

Conto::Conto() : saldo_(0.0) {}

void Conto::aggiungiTransazione(const Transazione& transazione) {
    transazioni_.push_back(transazione);
    saldo_ += transazione.getImporto();
}

double Conto::getSaldo() const {
    return saldo_;
}

size_t Conto::getNumeroTransazioni() const {
    return transazioni_.size();
}

const std::vector<Transazione>& Conto::getTransazioni() const {
    return transazioni_;
}

bool Conto::salvaSuFile(const std::string& filename) const {
    std::ofstream file(filename);
    if (!file.is_open()) return false;

    for (const auto& t : transazioni_) {
        file << t.getTimestamp() << ";" << t.getImporto() << ";" << t.getDescrizione() << "\n";
    }

    file.close();
    return true;
}

bool Conto::caricaDaFile(const std::string& filename) {
    std::ifstream file(filename);
    if (!file.is_open()) return false;

    transazioni_.clear();
    saldo_ = 0.0;

    std::string linea;
    while (std::getline(file, linea)) {
        std::istringstream iss(linea);
        std::string ts_str, imp_str, desc;

        if (!std::getline(iss, ts_str, ';')) continue;
        if (!std::getline(iss, imp_str, ';')) continue;
        if (!std::getline(iss, desc)) continue;

        std::time_t ts = std::stoll(ts_str);
        double importo = std::stod(imp_str);

        Transazione t(importo, desc, ts);
        aggiungiTransazione(t);
    }

    file.close();
    return true;
}
