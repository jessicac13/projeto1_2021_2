//
// Created by jessi on 28/11/2021.
//

#ifndef PROJETO1_2021_2_PROJETO1_H
#define PROJETO1_2021_2_PROJETO1_H

#include <iostream>
#include <string>
#include <list>
#include <fstream>
#include <cerrno>
#include <sys/time.h>

using  namespace std;


struct senhas{
    string cod_Senha;
    int horario;
};

struct classes{
    string codigo;
    string descricao;
    int tempo;
    int cont=1;
    int nivel_prio;
};

struct dados_cliente{
    classes classe;
    senhas senha;
};


list<dados_cliente>  preenche_opcoes(string arquivo);
list<string> separa(const string & texto, const string & sep);
bool prioridade(const dados_cliente & s1, const dados_cliente & s2);
void menu_cliente(const list<dados_cliente> & menuOpc);
void gerar_senha(dados_cliente dados_aux);
void menu_atendente(list<dados_cliente> list);
void sleep(int milliseconds);

#endif //PROJETO1_2021_2_PROJETO1_H
