#include <gtest/gtest.h> // Include la libreria Google Test per scrivere test automatici
#include "conto.h"

// Test per verificare che l'aggiunta di transazioni funzioni correttamente
TEST(ContoTest, AggiuntaTransazioni) {
    Conto c; // Creo un oggetto Conto vuoto
    c.aggiungiTransazione(Transazione(200.0, "Deposito"));
    c.aggiungiTransazione(Transazione(-50.0, "Prelievo"));

    EXPECT_EQ(c.getNumeroTransazioni(), 2);   // Controllo che ci siano 2 transazioni nel conto
    EXPECT_DOUBLE_EQ(c.getSaldo(), 150.0);    // Controllo che il saldo sia 200-50=150
}

// Test per verificare il salvataggio su file e il caricamento da file
TEST(ContoTest, SalvataggioECaricamento) {
    Conto c;  // Creo un oggetto Conto vuoto
    c.aggiungiTransazione(Transazione(123.45, "SalvaCarica"));  // Aggiungo una transazione

    std::string filename = "testfile.txt";
    ASSERT_TRUE(c.salvaSuFile(filename));  // Verifico che il salvataggio su file abbia successo, se fallisce il test si ferma qui

    Conto c2; // Creo un nuovo oggetto Conto vuoto
    ASSERT_TRUE(c2.caricaDaFile(filename));  // Verifico che il caricamento da file abbia successo, se fallisce il test si ferma qui

    EXPECT_EQ(c2.getNumeroTransazioni(), 1);
    EXPECT_DOUBLE_EQ(c2.getSaldo(), 123.45);
    EXPECT_EQ(c2.getTransazioni()[0].getDescrizione(), "SalvaCarica"); // Controllo che la descrizione sia corretta
}
