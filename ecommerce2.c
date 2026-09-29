#include <stdio.h>
#include <string.h>

// struct dos produtos do e-commerce / typedef: evitar uso de struct toda vez
typedef struct {
    int codigo;
    char nome[100];
    float preco;
} Produto;

// função de intercalação - merge
void merge(Produto A[], int inicio, int meio, int fim) {
    int n1 = meio - inicio + 1;
    int n2 = fim - meio;
    Produto L[n1], R[n2]; // temporario, left(metade esquerda) e right(metade direita)

    for (int i = 0; i < n1; i++)
        L[i] = A[inicio + i];
    for (int j = 0; j < n2; j++)
        R[j] = A[meio + 1 + j];

    int i = 0, j = 0, k = inicio;
    while (i < n1 && j < n2) {
        if (L[i].codigo <= R[j].codigo) {
            A[k] = L[i];
            i++;
        } else {
            A[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        A[k] = L[i];
        i++;
        k++;
    }
    while (j < n2) {
        A[k] = R[j];
        j++;
        k++;
    }
}

// função Merge Sort
void mergeSort(Produto A[], int inicio, int fim) {
    if (inicio < fim) {
        int meio = inicio + (fim - inicio) / 2;

        mergeSort(A, inicio, meio);
        mergeSort(A, meio + 1, fim);
        merge(A, inicio, meio, fim);
    }
}

// função de Busca Binária Iterativa por código
int buscaBinaria(Produto arr[], int tamanho, int codigoBusc) {
    int inicio = 0;
    int fim = tamanho - 1;
    int meio;
    int tentativa = 1;

    while (inicio <= fim) {
        meio = inicio + (fim - inicio) / 2;
        
        printf("Tentativa %d - Testando indice %d (Codigo %d)...\n", tentativa, meio, arr[meio].codigo);
        
        if (arr[meio].codigo == codigoBusc) {
            return meio; // retorna o índice do elemento encontrado
        }
        
        if (codigoBusc < arr[meio].codigo) {
            fim = meio - 1; // busca na metade esquerda
        } else {
            inicio = meio + 1; // busca na metade direita
        }
        tentativa++;
    }
    return -1; // caso o elemento não seja encontrado
}

void imprimirVetor(Produto arr[], int tamanho){
    printf("%-10s | %-30s | %-10s\n", "Codigo", "Nome", "Preco");
    for (int i = 0; i < tamanho; i++) {
        printf("%-10d | %-30s | R$ %-10.2f\n", arr[i].codigo, arr[i].nome, arr[i].preco);
    }
    printf("\n");
}

int main() {
    // inicialização do vetor com os 10 registros da Amazon
    Produto estoque[10] = {
        {25, "Celular iPhone 17 256GB", 5598.75},
        {96, "Kindle 16GB", 759.05},
        {84, "Livro Caminhando nas Chamas", 96.03},
        {71, "Alexa Echo Dot", 429.00},
        {63, "Tenis Fila Street Fit 3", 199.99},
        {42, "Fone de Ouvido Bluetooth", 249.00},
        {12, "Luminaria de Mesa LED", 169.90},
        {10, "Garrafa Termica Stanley", 215.00},
        {59, "Mochila Casual para Notebook", 189.90},
        {38, "Apple Watch SE 3", 2272.62}
    };
    
    int tamanho = sizeof(estoque) / sizeof(estoque[0]);

    // mostrar situação inicial
    printf("---- ESTOQUE INICIAL (DESORGANIZADO) ----\n");
    imprimirVetor(estoque, tamanho);
    printf("----------------------------------------\n\n");

    printf("\nORDENANDO...\n");
    mergeSort(estoque, 0, tamanho - 1); // aplicação do algoritmo de ordenação
    
    printf("\n---- ESTOQUE ORDENADO ----\n");
    imprimirVetor(estoque, tamanho);
    printf("-------------------------\n");
    
    // menu
    int opcaoMenu;
    do {
        printf("\nMENU\n1- BUSCAR PRODUTO\n2- SAIR\nEscolha: ");
        scanf("%d", &opcaoMenu);

        if (opcaoMenu == 1) {
            int codBusca;
            printf("\nDigite o codigo do produto: ");
            scanf("%d", &codBusca);

            // implementação do algoritmo de busca
            int pos = buscaBinaria(estoque, tamanho, codBusca);

            if (pos != -1) {
                printf("\n[PRODUTO ENCONTRADO na posicao %d]\n", pos + 1);
                printf("Codigo: %d\n", estoque[pos].codigo);
                printf("Nome: %s\n", estoque[pos].nome);
                printf("Preco: R$ %.2f\n", estoque[pos].preco);
            } else {
                printf("\n[ERRO]\nCodigo %d nao foi encontrado no Estoque!\n", codBusca);
            }
        }
    } while (opcaoMenu != 2);

    printf("\nSistema encerrado.\n");

    return 0;
}