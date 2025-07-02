#include <gtest/gtest.h>      // Include la libreria Google Test
#include "transazione.h"

// Definisce un test chiamato 'CostruttoreEGetter' nel test case 'TransazioneTest'
TEST(TransazioneTest, CostruttoreEGetter) {
    Transazione t(100.0, "Test");  // Crea un oggetto Transazione (t) con importo 100.0 e descrizione "Test"

    EXPECT_EQ(t.getImporto(), 100.0);       // Verifica che getImporto() ritorni 100.0
    EXPECT_EQ(t.getDescrizione(), "Test");  // Verifica che getDescrizione() ritorni "Test"
}

