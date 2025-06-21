#include <gtest/gtest.h>
#include "conto.h"
#include <ctime>

TEST(ContoTest, AggiungiTransazioniESaldo) {
    Conto c;
    std::time_t ora = std::time(nullptr);

    c.aggiungiTransazione(Transazione(200.0, "Deposito", ora));
    c.aggiungiTransazione(Transazione(-50.0, "Prelievo", ora));

    EXPECT_EQ(c.getNumeroTransazioni(), 2);
    EXPECT_DOUBLE_EQ(c.getSaldo(), 150.0);
}

TEST(ContoTest, SalvaECarica) {
    Conto c;
    std::time_t ora = std::time(nullptr);

    c.aggiungiTransazione(Transazione(123.45, "SalvaCarica", ora));
    std::string filename = "test_conto.txt";

    ASSERT_TRUE(c.salvaSuFile(filename));

    Conto c2;
    ASSERT_TRUE(c2.caricaDaFile(filename));

    EXPECT_EQ(c2.getNumeroTransazioni(), 1);
    EXPECT_DOUBLE_EQ(c2.getSaldo(), 123.45);
    EXPECT_EQ(c2.getTransazioni()[0].getDescrizione(), "SalvaCarica");
}
