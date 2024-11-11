#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

pthread_mutex_t mutex;
pthread_cond_t cond;
int ready = 0;

void* worker(void* arg) {
    pthread_mutex_lock(&mutex);
    while (!ready) {
        printf("Worker aguardando sinal...\n");
        pthread_cond_wait(&cond, &mutex);
    }
    printf("Worker recebeu sinal!\n");
    pthread_mutex_unlock(&mutex);
    return NULL;
}

void* signaler(void* arg) {
    sleep(1);
    pthread_mutex_lock(&mutex);
    ready = 1;
    printf("Signaler enviando sinal...\n");
    pthread_cond_signal(&cond);
    pthread_mutex_unlock(&mutex);
    return NULL;
}

int main() {
    pthread_t worker_thread, signaler_thread;

    pthread_mutex_init(&mutex, NULL);
    pthread_cond_init(&cond, NULL);

    pthread_create(&worker_thread, NULL, worker, NULL);
    pthread_create(&signaler_thread, NULL, signaler, NULL);

    pthread_join(worker_thread, NULL);
    pthread_join(signaler_thread, NULL);

    pthread_mutex_destroy(&mutex);
    pthread_cond_destroy(&cond);
    return 0;
}
