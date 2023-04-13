#include <stdio.h>

/* 3. Foi feita uma estatística em 5 cidades para coletar dados sobre
   acidentes de transito. Foram obtidos os seguintes dados:
   a) código da cidade;
   b) número de veículos de passeio;
   c) número de acidentes da transito com vítimas
   
   Deseja-se saber:
   a) Qual o maior e o menor índice de acidentes de transito e a que
      cidades pertencem;
   b) qual a média de veículos nas 5 cidades juntas;
   c) qual a média de acidentes nas 5 cidades juntas. */
   
struct cidade{
    int codigo;
    int n_veiculos_passeio;
    int n_acidentes_com_vitimas;
};

void tela_final(){
   printf("Pressione ENTER para continuar ...");
   getchar();
   system("clear");
}

int main(){
    
   struct cidade dados[5];
   int maior_acidentes = 0, menor_acidentes = 0;
   int som_veiculos = 0, som_acidentes = 0;
   
   for(int i = 0, j = 1; i < 5; i++, j++){
       
       printf("Insira os dados da cidade %i :\n\n ",j);
       printf("Código da cidade -> ");
       scanf("%i",&dados[i].codigo);
       
       printf("Número de veículos de passeio -> ");
       scanf("%i",&dados[i].n_veiculos_passeio);
       
       printf("Número de acidentes com vítimas -> ");
       scanf("%i",&dados[i].n_acidentes_com_vitimas);
       
       if(dados[i].n_acidentes_com_vitimas > dados[maior_acidentes].n_acidentes_com_vitimas){
           maior_acidentes = i;
       }
       else if(dados[i].n_acidentes_com_vitimas < dados[menor_acidentes].n_acidentes_com_vitimas){
           menor_acidentes = i;
       }
       
       som_veiculos += dados[i].n_veiculos_passeio;
       som_acidentes += dados[i].n_acidentes_com_vitimas;
       getchar();
       system("clear");
     
       
   }
   
   printf("Dados da cidade com maior número de acidentes: \n");
   printf("Código da cidade -> %i\n",dados[maior_acidentes].codigo);
   printf("Número de veículos de passeio -> %i\n",dados[maior_acidentes].n_veiculos_passeio);
   printf("Número de acidentes com vítimas -> %i\n\n",dados[maior_acidentes].n_acidentes_com_vitimas);
   tela_final();
   
   printf("Dados da cidade com menor número de acidentes: \n");
   printf("Código da cidade -> %i\n",dados[menor_acidentes].codigo);
   printf("Número de veículos de passeio -> %i\n",dados[menor_acidentes].n_veiculos_passeio);
   printf("Número de acidentes com vítimas -> %i\n\n",dados[menor_acidentes].n_acidentes_com_vitimas);
   tela_final();
   
   printf("Média de veículos das 5 cidades : %i\n",som_veiculos/5);
   printf("Média de acidentes das 5 cidades : %i\n\n",som_acidentes/5);
    
}