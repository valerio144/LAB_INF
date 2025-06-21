#include <iostream>
#include <ctime>
#include "conto.h"

int main() {
    Conto mioConto;

    std::time_t ora = std::time(nullptr);

    mioConto.aggiungiTransazione(Transazione(1500.0, "Stipendio", ora));
    mioConto.aggiungiTransazione(Transazione(-200.0, "Spesa", ora));

    std::cout << "Saldo attuale: " << mioConto.getSaldo() << " euro\n";

    if (mioConto.salvaSuFile("conto_dati.txt")) {
        std::cout << "Dati salvati correttamente.\n";
    } else {
        std::cout << "Errore nel salvataggio.\n";
    }

    Conto contoCaricato;
    if (contoCaricato.caricaDaFile("conto_dati.txt")) {
        std::cout << "Caricate " << contoCaricato.getNumeroTransazioni() << " transazioni.\n";
        std::cout << "Saldo caricato: " << contoCaricato.getSaldo() << " euro\n";
    } else {
        std::cout << "Errore nel caricamento.\n";
    }

    return 0;
}
