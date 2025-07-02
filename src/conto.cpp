#include "conto.h"
#include <fstream>
#include <sstream>

Conto::Conto() : saldo_(0.0) {};

void Conto::aggiungiTransazione(const Transazione & transazione) {
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
    if (!file.is_open()) return false; // se il file non si apre

    for (const auto& t : transazioni_) { // scrive tutte le transazioni sul file
        file << t.getImporto() << ";" << t.getDescrizione() << "\n";
    }
    file.close();
    return true;
}

// Legge le transazioni da un file di testo e le carica dentro il programma
bool Conto::caricaDaFile(const std::string& filename) {
    std::ifstream file(filename);
    if (!file.is_open()) return false; // Se il file non esiste o non può essere aperto

    transazioni_.clear();
    saldo_ = 0.0;

    std::string linea; // Variabile che conterrà ogni riga letta dal file
    while (std::getline(file, linea)) { // riga per riga
        std::istringstream iss(linea); // Serve per analizzare la riga come se fosse un piccolo file ISS = variabile
        std::string imp_str, desc; // imp_str = importo, desc = descrizione

        if (!std::getline(iss, imp_str, ';')) continue; // Legge da iss fino al punto e virgola ;, e lo mette in imp_str
        if (!std::getline(iss, desc)) continue; // Legge il resto della riga dopo il ; e lo salva in desc

        double importo = std::stod(imp_str); // Converte l'importo da stringa a numero
        Transazione t(importo, desc); // Crea un oggetto Transazione
        aggiungiTransazione(t);
    }
    file.close();
    return true;
}

