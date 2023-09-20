#include <iostream>
#include <vector>
#include <conio.h>
#include <ctime>
#include <unistd.h>
#include <stdio.h>
#define cima 72 // definido as setas
#define baixo 80
#define esquerda 75
#define direita 77

using namespace std;

int i = 0, j = 0; // declarando as variáveis que serão utilizadas.
char position[12][12];
char nave = '^';
char estrela = 'X';
char asteroide = 'O';
int estx = 0, esty = 0;                         // Posição das estrelas.
int astx1 = 0, astx2 = 0, astx3 = 0, astx4 = 0; // Posição dos asteroides
int asty1 = 0, asty2 = 0, asty3 = 0, asty4 = 0;
int astlim1 = 0, astlim2 = 0, astlim3 = 0, astlim4 = 0; // Serão utilizadas para limpar a posição anterior
int navex = 10, navey = 0;
int escolha;
char input;
int estrelaanterior = 0;
int pontos = 0;
int vidas;
int jogadas = 0;
int dificuldade = 0;
// As funções a seguir possuem comentários explicando.
// Não se assuste com a quantidade de funções!

void menuinicial() // Exibe o meno inicial.
{
    cout << "Seja bem vindo(a) ao Coletando Estrelas!" << endl;
    cout << endl;
    cout << "Escolha o modo de jogo que preferir." << endl;
    cout << "1. Coletar Estrelas" << endl;
    cout << "2. Desviar de asteroides." << endl;
    cout << "Qualquer outra tecla fecha o jogo." << endl;
    cout << endl;
    cout << "Controles: " << endl;
    cout << endl;
    cout << "Pressione as teclas WASD e as setas para controlar a nave." << endl;
    cin >> escolha;
    cout << "Escolha a dificuldade." << endl;
    cout << "1. Facil" << endl;
    cout << "2. Medio" << endl;
    cout << "3. IMPOSSIVEL (NAO RECOMENDADO NEM PARA O MAIS GAMERS)" << endl;
    cin >> dificuldade;
}

void gerarmatriz() // função que irá gerar a matriz.
{

    for (i = 0; i < 12; i++)
    {
        for (j = 0; j < 12; j++)
        {
            position[i][j] = ' ';
        }
    }
}

void exibirmatriz() // função que exibirá a matriz.
{
    for (i = 0; i < 12; i++)
    {
        for (j = 0; j < 12; j++)
        {
            cout << position[i][j] << ' ';
        }
        cout << endl;
    }
}

void gerarestrela() // função que gera a estrela, na primeira linha, em uma coluna aleatória.
{
    esty = rand() % 12;

    asty1 = rand() % 12;

    asty2 = rand() % 12;

    asty3 = rand() % 12;

    asty4 = rand() % 12;
}

void direcao()
{ // Verifica o input inserido, utilizando as setas ou o wasd. Limpa e cria a nave.
    switch ((input = _getch()))
    {
    case cima:
        position[navex][navey] = ' ';
        navex--;
        break;
    case baixo:
        position[navex][navey] = ' ';
        navex++;
        break;
    case direita:
        position[navex][navey] = ' ';
        navey++;
        break;
    case esquerda:
        position[navex][navey] = ' ';
        navey--;
        break;
    case 'w':
        position[navex][navey] = ' ';
        navex--;
        break;
    case 's':
        position[navex][navey] = ' ';
        navex++;
        break;
    case 'a':
        position[navex][navey] = ' ';
        navey--;
        break;
    case 'd':
        position[navex][navey] = ' ';
        navey++;
        break;
    case 'p':
        pontos = 150;
        break;
    }
}

void gerarasteroides() // retorna os asteroides a primeira linha.
{
    if (astx1 == 11)
    {
        astx1 = 1;
        gerarestrela();
    }
    if (astx2 == 11)
    {
        astx2 = 1;
        gerarestrela();
    }
    if (astx3 == 11)
    {
        astx3 = 1;
        gerarestrela();
    }
    if (astx4 == 11)
    {
        astx4 = 1;
        gerarestrela();
    }
}

void colisaocoletar()
{
    if (position[navex][navey] == position[estx][esty])
    {
        pontos += 10;
        estx = 0;
        gerarestrela();
    }
}
void colisaodesviar()
{
    if (position[navex][navey] == position[astx1][asty1])
    {
        vidas--;
    }
    else if (position[navex][navey] == position[astx2][asty2])
    {
        vidas--;
    }
    else if (position[navex][navey] == position[astx3][asty3])
    {
        vidas--;
    }
    else if (position[navex][navey] == position[astx4][asty4])
    {
        vidas--;
    }
}

void definirmatriz()
{
    position[astx1][asty1] = asteroide;
    position[astx2][asty2] = asteroide;
    position[astx3][asty3] = asteroide;
    position[astx4][asty4] = asteroide;
    position[navex][navey] = nave;
}

void limparanterior()
{ // Avança os asteroides uma linha e remove o da linha anterior.

    astx1++;
    astx2++;
    astx3++;
    astx4++;

    astlim1 = astx1 - 1;
    astlim2 = astx2 - 1;
    astlim3 = astx3 - 1;
    astlim4 = astx4 - 1;

    position[astlim1][asty1] = ' ';
    position[astlim2][asty2] = ' ';
    position[astlim3][asty3] = ' ';
    position[astlim4][asty4] = ' ';
}

int main()
{
    menuinicial();
    srand(time(NULL));
    gerarmatriz();

    if (escolha == 1) // Caso o modo de coletar tenha sido escolhido.
    {
        estx = 0;
        pontos = 0;
        cout << "Colete 150 pontos!" << endl;
        while (pontos < 150)
        {
            gerarmatriz();
            if (estx == 0)
            { // Gerando a estrela de volta à primeira linha.
                gerarestrela();
            }
            position[estx][esty] = estrela;
            position[navex][navey] = nave;
            if (estx == 11)
            {
                estx = 0;
                pontos -= 5;
            }
            cout << "Pontos: " << pontos << endl;
            exibirmatriz();
            if (kbhit())
            {
                direcao();
            }
            colisaocoletar();
            estx++;
            estrelaanterior = estx - 1;
            if (estrelaanterior < 0)
                estrelaanterior = 0;
            position[estrelaanterior][esty] = ' ';
              if(dificuldade == 1){
             usleep(110000);
            }
            if(dificuldade == 2){
             usleep(95000);
            }
             if(dificuldade == 3){
             usleep(35000);
            };
            system("CLS");
        }
        return main();
    }

    if (escolha == 2) // Caso o modo de desviar tenha sido escolhido.
    {
        vidas = 3;
        pontos = 0;
        cout << "Desvie dos Asteroides!" << endl;
        while (pontos < 150)
        {
            gerarmatriz();
            definirmatriz();

            cout << "Vidas " << vidas << endl;
            cout << "Pontos " << pontos << endl;

            exibirmatriz();
            if (vidas <= 0)
            {
                cout << "Perdeu tudo! Os pontos nao serao contabilizados." << endl;
                cout << "Pressione P para sair" << endl;
                pontos = 0;
            }
            if (kbhit())
            {
                direcao();
            }
            colisaodesviar();

            pontos += 1;
            limparanterior();
            gerarasteroides();
            if(dificuldade == 1){
             usleep(110000);
            }
            if(dificuldade == 2){
             usleep(95000);
            }
             if(dificuldade == 3){
             usleep(15000);
            }
           
            system("CLS");
        }
        return main();
    }

    return 0;
}