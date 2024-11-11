# Programação Paralela em C: Exemplos Práticos

Este repositório contém exemplos de código em C para ilustrar conceitos fundamentais de programação paralela e sincronização. Cada código aborda um problema específico utilizando threads com a biblioteca `pthread`.

## Conteúdo

- [Descrição dos Códigos](#descrição-dos-códigos)
  - [Leitores e Escritores](#leitores-e-escritores)
  - [Barreiras](#barreiras)
  - [Sinais](#sinais)
  - [Deadlocks](#deadlocks)

---

## Descrição dos Códigos

### 1. Leitores e Escritores (`leitores_escritores.c`)

- **Descrição**: Este código implementa o problema de leitores e escritores, onde várias threads tentam acessar um recurso compartilhado. Leitores podem acessar o recurso simultaneamente, mas escritores precisam de exclusividade.
- **Funcionamento**: Utilizamos `pthread_rwlock_t` para controlar o acesso. Leitores adquirirem um bloqueio de leitura enquanto escritores precisam de um bloqueio de escrita.
- **Aplicação**: Comumente usado em bancos de dados, onde múltiplas leituras são permitidas ao mesmo tempo, mas a escrita exige exclusividade para evitar inconsistências.

### 2. Barreiras (`barreiras.c`)

- **Descrição**: O código demonstra o uso de barreiras, onde threads sincronizam em um ponto específico antes de avançarem.
- **Funcionamento**: Utilizamos `pthread_barrier_t` para que todas as threads alcancem uma barreira antes de qualquer uma seguir adiante. Isso garante que todas as threads estejam prontas antes de prosseguir.
- **Aplicação**: Utilizado em algoritmos de processamento paralelo, como cálculos de matrizes, onde é necessário que todas as threads completem uma etapa antes de iniciar a próxima.

### 3. Sinais (`sinais.c`)

- **Descrição**: Demonstra o uso de sinais para comunicação entre threads, permitindo que uma thread "acorde" outra para continuar a execução.
- **Funcionamento**: Utiliza `pthread_cond_t` e `pthread_mutex_t` para sinalizar a conclusão de uma tarefa. Uma thread espera até receber um sinal para continuar sua execução.
- **Aplicação**: Usado em sistemas de produção ou em pipelines de processamento, onde uma tarefa deve esperar pela conclusão de outra.

### 4. Deadlocks (`deadlock.c`)

- **Descrição**: Exemplo de situação de deadlock, onde duas threads ficam presas aguardando recursos que estão bloqueados entre si.
- **Funcionamento**: `pthread_mutex_t` é utilizado para simular um deadlock. Uma thread bloqueia um recurso e aguarda outro recurso já bloqueado pela outra thread, resultando em um ciclo de espera.
- **Aplicação**: Exemplifica situações que podem ocorrer em sistemas de banco de dados ou em sistemas que gerenciam recursos compartilhados, onde um controle de acesso cuidadoso é necessário para evitar deadlocks.

---


