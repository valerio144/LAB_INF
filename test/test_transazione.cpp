#include <gtest/gtest.h>
#include "transazione.h"
#include <ctime>

TEST(TransazioneTest, CreazioneEDati) {
    std::time_t ora = std::time(nullptr);
    Transazione t(100.0, "Test", ora);

    EXPECT_DOUBLE_EQ(t.getImporto(), 100.0);
    EXPECT_EQ(t.getDescrizione(), "Test");
    EXPECT_EQ(t.getTimestamp(), ora);
}
