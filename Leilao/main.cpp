#include <iostream>
#include <string>
#include "Usuario.hpp"

void* operator new(size_t bytes)
{
    std::cout << "Alocando " << bytes << " bytes" << std::endl;
    return malloc(bytes);
}

void ExibeNome(std::string_view nome)
{
    std::cout << nome << std::endl;
}

int main() {
    std::cout << "------------------" << std::endl;
    std::string casal = "Carlos Vinicius dos Santos Dias & Patricia Freitas Graça";
    
    std::string_view meuNome(casal.c_str(), casal.find('&') - 1);
    std::string_view nomeEsposa(casal.c_str() + casal.find('&') + 2);
    
    ExibeNome(meuNome);
    ExibeNome(nomeEsposa);
    ExibeNome("Um nome qualquer sem estar na heap");
    
    Usuario* usuario = new Usuario("Vinicius Dias");
    
    std::cout << usuario->recuperaNome() << std::endl;

    delete usuario;

    return 0;
}
