#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

pthread_rwlock_t lock;
int shared_data = 0;

void* reader(void* arg) {
    int id = *((int*)arg);
    pthread_rwlock_rdlock(&lock);
    printf("Leitor %d lendo dado: %d\n", id, shared_data);
    pthread_rwlock_unlock(&lock);
    return NULL;
}

void* writer(void* arg) {
    int id = *((int*)arg);
    pthread_rwlock_wrlock(&lock);
    shared_data++;
    printf("Escritor %d modificou dado para: %d\n", id, shared_data);
    pthread_rwlock_unlock(&lock);
    return NULL;
}

int main() {
    pthread_t readers[3], writers[2];
    int ids[] = {1, 2, 3, 4, 5};

    pthread_rwlock_init(&lock, NULL);

    for (int i = 0; i < 3; i++)
        pthread_create(&readers[i], NULL, reader, &ids[i]);
    for (int i = 0; i < 2; i++)
        pthread_create(&writers[i], NULL, writer, &ids[i + 3]);

    for (int i = 0; i < 3; i++)
        pthread_join(readers[i], NULL);
    for (int i = 0; i < 2; i++)
        pthread_join(writers[i], NULL);

    pthread_rwlock_destroy(&lock);
    return 0;
}
