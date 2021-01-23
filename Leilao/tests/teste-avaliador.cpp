#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "Avaliador.hpp"

Leilao emOrdemCrescente()
{
    Lance primeiroLance(Usuario("Vinicius Dias"), 1000);
    Lance segundoLance(Usuario("Ana Maria"), 2000);
    Leilao leilao("Fiat 147 0Km");
    leilao.recebeLance(primeiroLance);
    leilao.recebeLance(segundoLance);
    
    return leilao;
}

Leilao emOrdemDecrescente()
{
    Lance primeiroLance(Usuario("Vinicius Dias"), 2000);
    Lance segundoLance(Usuario("Ana Maria"), 1000);
    Leilao leilao("Fiat 147 0Km");
    leilao.recebeLance(primeiroLance);
    leilao.recebeLance(segundoLance);
    
    return leilao;
}

TEST_CASE("Deve recuperar maior lance de leilão em ordem crescente") {
    // Arrange - Given
    Leilao leilao = emOrdemCrescente();
    Avaliador leiloeiro;

    // Act - When
    leiloeiro.avalia(leilao);

    // Assert - Then
    REQUIRE(2000 == leiloeiro.recuperaMaiorValor());
}

TEST_CASE("Deve recuperar maior lance de leilão em ordem decrescente") {
    // Arrange - Given
    Leilao leilao = emOrdemDecrescente();
    Avaliador leiloeiro;

    // Act - When
    leiloeiro.avalia(leilao);

    // Assert - Then
    REQUIRE(2000 == leiloeiro.recuperaMaiorValor());
}

TEST_CASE("Deve recuperar menor lance de leilão em ordem decrescente") {
    // Arrange - Given
    Leilao leilao = emOrdemDecrescente();
    Avaliador leiloeiro;

    // Act - When
    leiloeiro.avalia(leilao);

    // Assert - Then
    REQUIRE(1000 == leiloeiro.recuperaMenorValor());
}

TEST_CASE("Deve recuperar menor lance de leilão em ordem crescente") {
    // Arrange - Given
    Leilao leilao = emOrdemCrescente();
    Avaliador leiloeiro;

    // Act - When
    leiloeiro.avalia(leilao);

    // Assert - Then
    REQUIRE(1000 == leiloeiro.recuperaMenorValor());
}

TEST_CASE("Deve recuperar os 3 maiores lances") {
    // Arrange - Given
    Lance primeiroLance(Usuario("Vinicius Dias"), 1000);
    Lance segundoLance(Usuario("Ana Maria"), 2000);
    Lance terceiroLance(Usuario("Pedro Paulo"), 1500);
    Lance quartoLance(Usuario("Patricia Roberta"), 2500);
    
    Leilao leilao("Fiat 147 0Km");
    leilao.recebeLance(primeiroLance);
    leilao.recebeLance(segundoLance);
    leilao.recebeLance(terceiroLance);
    leilao.recebeLance(quartoLance);

    Avaliador leiloeiro;

    // Act - When
    leiloeiro.avalia(leilao);

    // Assert - Then
    auto maiores3Lances = leiloeiro.recupera3MaioresLances();
    REQUIRE(3 == maiores3Lances.size());
    REQUIRE(2500 == maiores3Lances[0].recuperaValor());
    REQUIRE(2000 == maiores3Lances[1].recuperaValor());
    REQUIRE(1500 == maiores3Lances[2].recuperaValor());
}
