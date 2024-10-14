#include <iostream>
#include <cctype>
#include <cstdlib>
#include <ctime>
#include <string>
#include <chrono>
#include <thread>

using namespace std;

void printLetraPorLetra(const string& texto, int intervalo) {
    for (char c : texto) {
        cout << c;
        cout.flush(); // Limpa o buffer de saída para garantir que a letra seja mostrada imediatamente
        std::this_thread::sleep_for(std::chrono::milliseconds(intervalo)); // Intervalo entre cada letra
    }
}

struct Personagem {
    string nome;
    float HP;
    int vidas;
    float attack;
    int defesa;
};

struct Inimigo {
    string nome;
    float HP;
    int attack;
    int defesa;
};

int lancarDado() {
    srand(time(0));
    return rand() % 6 + 1;
}

bool contemApenasLetras(string texto) {
    for (char c : texto) {
        if (!isalpha(c)) {
            return false;
        }
    }
    return true;
}

void ataqueEspada(Personagem &jogador, Inimigo &inimigo) {
    int dado = lancarDado();
    jogador.attack *= dado; // Aumenta o dano do jogador baseado no valor do dado
    inimigo.HP -= jogador.attack;
    cout << "Voce atacou o " << inimigo.nome << " com a espada causando " << jogador.attack << " de dano!" << endl;
    cout << "Voce tirou o numero " << dado << " do dado." << endl;
}

void ataqueMagiaFogo(Personagem &jogador, Inimigo &inimigo) {
    int dano = 30; // Dano base da magia de fogo
    inimigo.HP -= dano;
    cout << "Voce lançou uma bola de fogo no " << inimigo.nome << " causando " << dano << " de dano!" << endl;
    cout << "O " << inimigo.nome << " sofreu queimaduras adicionais!" << endl;
    // Implemente aqui a porcentagem adicional de dano por queimadura, se necessário
}

void ataqueMagiaTrovao(Personagem &jogador, Inimigo &inimigo) {
    int dano = 20; // Dano base da magia de trovão
    inimigo.HP -= dano;
    cout << "Voce lancou um raio de trovao no " << inimigo.nome << " causando " << dano << " de dano!" << endl;
    cout << "O " << inimigo.nome << " foi atordoado!" << endl;
    // Implemente aqui o efeito de atordoamento, se necessário
}

void tentarFugir(Personagem &jogador, Inimigo &inimigo) {
    int dado = lancarDado();
    if (dado == 6) {
        cout << "Voce conseguiu fugir!" << endl;
    } else {
        cout << "Voce nao conseguiu fugir e sofreu danos do " << inimigo.nome << "!" << endl;
        jogador.HP -= inimigo.attack; // Jogador sofre danos do inimigo
    }
    cout << "Voce tirou o numero " << dado << " do dado." << endl;
}

void combate(Personagem &jogador, Inimigo &inimigo) {
    cout << "Voce encontrou um " << inimigo.nome << "!" << endl;

    while (jogador.HP > 0 && inimigo.HP > 0) {
        int opcao;
        cout << "Escolha sua acao:" << endl;
        cout << "1. Atacar com espada" << endl;
        cout << "2. Lancar magia de fogo" << endl;
        cout << "3. Lancar magia de trovao" << endl;
        cout << "4. Tentar fugir" << endl;
        cin >> opcao;

        switch (opcao) {
            case 1:
                ataqueEspada(jogador, inimigo);
                break;
            case 2:
                ataqueMagiaFogo(jogador, inimigo);
                break;
            case 3:
                ataqueMagiaTrovao(jogador, inimigo);
                break;
            case 4:
                tentarFugir(jogador, inimigo);
                break;
            default:
                cout << "Opcao invalida. Tente novamente." << endl;
        }

        if (inimigo.HP <= 0) {
            cout << "Você derrotou o " << inimigo.nome << "!" << endl;
            break;
        }

        // Ataque do inimigo
        jogador.HP -= inimigo.attack; // Reduz HP do jogador baseado no ataque do inimigo
        cout << "O " << inimigo.nome << " atacou você causando " << inimigo.attack << " de dano!" << endl;

        if (jogador.HP <= 0) {
            cout << "Voce foi derrotado pelo " << inimigo.nome << "!" << endl;
            break;
        }
    }
}

Personagem criarPersonagem() {
    Personagem jogador;

    cout << "Digite o nome do seu personagem:" << endl;
    cin >> jogador.nome;

    while (!contemApenasLetras(jogador.nome)) {
        cout << "Seu nome não é válido. Favor escolher outro nome" << endl;
        cin >> jogador.nome;
    }

    cout << "Nome selecionado: " << jogador.nome << endl << endl;

    // Definindo as estatísticas iniciais do personagem
    jogador.HP = 200;
    jogador.vidas = 5;
    jogador.attack = 20;
    jogador.defesa = 10;

    return jogador;
}

void lore(Personagem &jogador) {
    Inimigo soldadoFraco;
    soldadoFraco.nome = "Soldado Fraco";
    soldadoFraco.HP = 100;
    soldadoFraco.attack = 10;
    soldadoFraco.defesa = 0;

    combate(jogador, soldadoFraco);

    // Verificar se o jogador tem vidas restantes
    if (jogador.vidas <= 0) {
        cout << "Um zumbi surge das trevas!" << endl;
        Inimigo zumbi;
        zumbi.nome = "Boss Divino"; // Alteração do nome para "Boss Divino"
        zumbi.HP = jogador.HP * 10; // Zumbi com 10 vezes mais HP
        zumbi.attack = jogador.attack * 2; // Zumbi com ataque dobrado
        zumbi.defesa = jogador.defesa; // Zumbi com mesma defesa

        cout << "Prepare-se para enfrentar o " << zumbi.nome << "!" << endl;
        combate(jogador, zumbi);
    }
}

void loreFalas(Personagem &jogador) {

    printLetraPorLetra("Depois dela eu conheci seu pai, quando ele começou falar comigo\n", 50);
    printLetraPorLetra("REI: Nosso reino vai ser invadido por outras nações e precisamos da sua ajuda\n", 50);
    printLetraPorLetra("REI: Por favor nos ajude, grande herói\n", 50);
    printLetraPorLetra(jogador.nome + ": Por que eu faria isso?\n", 50);
    printLetraPorLetra(jogador.nome + ": Vocês me invocaram aqui sem nem me pedir e ainda querem que os ajude?\n", 50);
    printLetraPorLetra(jogador.nome + ": ME LEVEM DE VOLTA AO MEU MUNDO\n", 50);
    printLetraPorLetra("REI: Me desculpe por isso mas no momento não iremos conseguir leva-lo de volta ao seu mundo\n", 50);
    printLetraPorLetra("REI: Ainda não temos energia o suficiente para conseguirmos leva-lo de volta\n", 50);
    printLetraPorLetra("REI: Mas só iremos leva-lo de volta se você nos ajudar.... então você ve ai o que quer fazer\n", 50);
    printLetraPorLetra(jogador.nome + ": Ja que é assim eu irei tentar ajudá-los\n", 50);
    printLetraPorLetra("REI: Ja que você resolveu cooperar, iremos lhe conceder algumas bençãos\ne iremos ensinar-lhe a usar magia e a manejar uma espada\n", 50);
    printLetraPorLetra(jogador.nome + ": *pensando* - Um mês depois e já estou pronto para começar a participar da guerra\n", 50);
    printLetraPorLetra(jogador.nome + ": E ainda por cima recebi uma benção, eles disseram que iria ter algo como se fossem 5 vidas,\n", 50);
    printLetraPorLetra("como é algo dado diretamente da deusa desse mundo não tem porque eu duvidar\n", 50);
    printLetraPorLetra("E além de ter 5 vidas eu posso jogar algo como se fosse um dado imaginário, e dai meu dano seria multiplicado,\n", 50);
    printLetraPorLetra("a mesma coisa acontece com minha sorte. Acho que vai ser tranquilo sobreviver a essa invasão\n", 50);

}

int main() {
    Personagem jogador = criarPersonagem();
    printLetraPorLetra("", 20); // aqui você pode usar essa função para imprimir texto letra por letra
    loreFalas(jogador);
    lore(jogador);

    return 0;
}
