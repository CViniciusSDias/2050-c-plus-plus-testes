#include "Avaliador.hpp"
#include <iostream>

int main() {
    Lance primeiroLance(Usuario("Vinicius Dias"), 1000);
    Lance segundoLance(Usuario("Ana Maria"), 2000);
    Leilao leilao("Fiat 147 0Km");
    leilao.recebeLance(segundoLance);
    leilao.recebeLance(primeiroLance);

    Avaliador leiloeiro;
    leiloeiro.avalia(leilao);

    std::cout << leiloeiro.recuperaMaiorValor() << std::endl;

    return 0;
}
