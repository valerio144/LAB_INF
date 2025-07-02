#include <iostream>
#include "conto.h"

int main() {
    Conto mioConto;

    mioConto.aggiungiTransazione(Transazione(1500.0, "Stipendio"));
    mioConto.aggiungiTransazione(Transazione(-200.0, "Spesa"));

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

        // Qui aggiungi il ciclo per stampare ogni transazione
        for (const auto& t : contoCaricato.getTransazioni()) {
            std::cout << "Descrizione: " << t.getDescrizione() << ", Importo: " << t.getImporto() << "\n";
        }

    } else {
        std::cout << "Errore nel caricamento.\n";
    }
};
