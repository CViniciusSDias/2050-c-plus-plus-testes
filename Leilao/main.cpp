#include <iostream>
#include <string>
#include <memory>
#include "Usuario.hpp"

/*void* operator new(size_t bytes)
{
    std::cout << "Alocando " << bytes << " bytes" << std::endl;
    return malloc(bytes);
}*/

void ExibeNome(std::string_view nome)
{
    std::cout << nome << std::endl;
}

void ExibeNomeUsuario(std::shared_ptr<Usuario> usuario)
{
    std::cout << usuario->recuperaNome() << std::endl;
}

int main2() {
    std::cout << "------------------" << std::endl;
    std::string casal = "Carlos Vinicius dos Santos Dias & Patricia Freitas Graça";
    
    std::string_view meuNome(casal.c_str(), casal.find('&') - 1);
    std::string_view nomeEsposa(casal.c_str() + casal.find('&') + 2);
    
    ExibeNome(meuNome);
    ExibeNome(nomeEsposa);
    ExibeNome("Um nome qualquer sem estar na heap");

    std::shared_ptr<Usuario> usuario = std::make_shared<Usuario>("Vinicius Dias");
    //Usuario* usuario = new Usuario("Vinicius Dias");
    ExibeNomeUsuario(usuario);

    return 0;
}
