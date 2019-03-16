
//Estrutura de cada elemento da lista
typedef struct pElemen PElemen;

//Estrutura geral da lista vetor e contador de elementos
typedef struct pLista PLista;

//Criar lista estática de elementos com vetores
PLista* plst_cria();

//Inserir dados na lista (desordenado)
PLista* plts_insere(PLista* pl, int info);

//retorna o número de elementos na lista
void plst_get_nElement(PLista* pl);

//Altera elemento da lista
PLista* plts_altera(PLista* pl, int info, int newInfo);

//Remove elemento da lista
PLista* plts_remove(PLista* pl, int info);

//imprimir valores na lista
void plts_imprime(PLista* pl, int a);

//Pega primeiro Elemento da Lista
void plst_get_inicio(PLista* pl);

//retorna valor randomico
int int_random(PLista* pl);

//pegar o inicio da lista
// void plst_get_inicio(PLista* pl);

//Lista Vazia
int plts_vazia(PLista* pl);

//busca elementos na lista percorrendo o vetor atraves de um for 0 até MAX
int plts_busca(PLista* pl, int info);

//busca na lista percorrendo as pseudo posições
int plts_pseudo_busca(PLista* pl, int info);

//imprimir item buscado
void plts_busca_imprime(PLista* pl, int info);