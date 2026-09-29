# 🛒 Sistema de Controle de Estoque (E-commerce)

> Sistema desenvolvido em **C** para gerenciamento e consulta de estoque de um e-commerce, aplicando estruturas de dados, algoritmos avançados de ordenação e busca eficiente.

---

## 📋 Sobre o Projeto
Este projeto foi desenvolvido com foco na aplicação prática de Estruturas de Dados e Algoritmos (EDA). O sistema simula o inventário de uma loja virtual contendo produtos reais (como eletrônicos, livros e acessórios), realizando a ordenação automática do catálogo e permitindo consultas rápidas por meio de busca otimizada.

## 🛠️ Tecnologias e Conceitos Aplicados
* **Linguagem:** C (Padrão C99)
* **Estruturas de Dados:** Uso de `struct` e `typedef` para modelagem de registros compostos (`Produto`).
* **Algoritmo de Ordenação:** **Merge Sort** (Abordagem *Divide and Conquer* / Divisão e Conquista) com complexidade de tempo $O(n \log n)$.
* **Algoritmo de Busca:** **Busca Binária Iterativa** para localização rápida de itens pelo código, com complexidade de tempo $O(\log n)$.
* **Manipulação de Entrada/Saída:** Exibição formatada de tabelas no console e menus interativos em loop (`do-while`).

---

## 🔍 Funcionalidades do Sistema
1. **Listagem Inicial:** Exibe o estoque cadastrado em sua ordem original de inserção (desorganizado).
2. **Ordenação Automática:** Aplica o *Merge Sort* para ordenar todo o vetor de produtos com base no **código do produto**.
3. **Busca Binária Interativa:** 
   * Menu no terminal para consulta de códigos.
   * Rastreio visual passo a passo das tentativas da busca binária (índices testados).
   * Exibição detalhada dos dados do produto encontrado (Nome, Código e Preço formatado em Reais) ou mensagem de erro caso o item não exista.

---

## 🚀 Como Executar o Projeto

Certifique-se de ter um compilador de C instalado em sua máquina (como o `gcc`). No seu terminal, execute os seguintes comandos:

```bash
# 1. Clone o repositório
git clone [https://github.com/tnals-s/Sistema-Estoque.git](https://github.com/tnals-s/Sistema-Estoque.git)

# 2. Entre na pasta do projeto
cd Sistema-Estoque

# 3. Compile o código (substitua 'ecommerce2.c' pelo nome do seu arquivo se necessário)
gcc ecommerce2.c -o ecommerce

# 4. Execute o programa
./ecommerce
