#ifndef GRAFO_H
#define GRAFO_H

#include <iostream>
#include <sstream>
#include <string>
#include <fstream>
#include <stack>
#include <list>
#include <queue>

#include "No.h"
#include "Aresta.h"

using namespace std;

/**
*   Universidade Federal de Juiz de Fora
*   Criador: Renan Nunes da Costa Gonçalves e Luan Reis Ciribelli
*   versão: 2.0
*/
class Grafo{

    public:
        Grafo();
        Grafo(int ordem);
        Grafo(int ordem, bool direcionado,bool ponderado_aresta,bool ponderado_no);
        virtual ~Grafo();

        int getOrdem();
        int getNumeroArestas();
        bool getDirecionado();
        bool getPonderadoAresta();
        bool getPonderadoNo();

        No* getPrimeiroNo();
        No* getUltimoNo();

        void setOrdem(int ordem);
        void setNumeroArestas(int numeroArestas);
        void aumentaNumArestas();
        void diminuiNumArestas();

        /*Funções do Grafo*/
        No* getNo(int id);
        bool existeNo(int id);
        void inserirNo(int id);
        void inserirNo(int id,int peso);
        void removerNo(int id);
        void inserirAresta(int id,int id_alvo,int peso);

        int grauMedioPorSomatorio();
        int grauMedioPorAdjacencia();
        int frequenciaRelativa(int d);
        int grauDoGrafo();

        string imprimir();
        string imprimirMatriz();
        bool verificaAdjacencia(int i,int j);


        bool depthFirstSearch(int id_inicial);
        bool depthFirstSearchFile(int id_inicial,fstream &outputFile);

        void breathFirstSearch();
        void breathFirstSearchFile(fstream& output_file);

        bool ehConexo();
        void iniciaMatriz();
        void deleteMatriz();
    private:
        int ordem;
        int numero_arestas;
        bool direcionado,ponderado_no,ponderado_aresta;
        No* primeiro_no;
        No* ultimo_no;

        bool** matriz_adjacencia;

        void alocaMatriz();

        void depthFirstSearchF(No* no, bool* vetor_coloracao, No* pai, int nivel);
        void depthFirstSearchFFile(No* no, bool* vetor_coloracao, No* pai, int nivel,fstream &outputFile);


        void percorre(No * u);



        //bool ehCiclo();
        //bool ehCicloAux(No* v,bool visitado[],No* pai);
};

#endif // GRAFO_H
