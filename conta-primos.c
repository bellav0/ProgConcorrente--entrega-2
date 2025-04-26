#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>
#include <math.h>
#include "timer.h"

long long int n;
long int numPrimos = 0;
long long int nextIndex = 0;

pthread_mutex_t mutexIndex;
pthread_mutex_t mutexSoma;

int ehPrimo(long long int n)
{
    int i;
    if (n <= 1)
        return 0;
    if (n == 2)
        return 1;
    if (n % 2 == 0)
        return 0;
    for (i = 3; i < sqrt(n) + 1; i += 2)
        if (n % i == 0)
            return 0;
    return 1;
}

void *contaPrimos(void *arg)
{
    long int id = (long int)arg;
    long int somaLocal = 0;
    long long int localIndex;

    pthread_mutex_lock(&mutexIndex);
    localIndex = nextIndex;
    nextIndex += 1;
    pthread_mutex_unlock(&mutexIndex);
    while (nextIndex <= n)
    {
        int primo = ehPrimo(localIndex);
        somaLocal += primo;

        pthread_mutex_lock(&mutexIndex);
        localIndex = nextIndex;
        nextIndex += 1;
        pthread_mutex_unlock(&mutexIndex);
    }

    pthread_mutex_lock(&mutexSoma);
    numPrimos += somaLocal;
    pthread_mutex_unlock(&mutexSoma);
    printf("Thread : %ld terminou!\n", id);
    pthread_exit(NULL);
}

int main(int argc, char *argv[])
{
    int nthreads;
    pthread_t *tid;
    double timeInicio, timeFim, totalTime;
    if (argc < 3)
    {
        printf("Erro: inserir <numero de threads> <número de elementos>");
        exit(0);
    }

    nthreads = atoi(argv[1]);
    n = atoll(argv[2]);
    GET_TIME(timeInicio);
    tid = (pthread_t *)malloc(nthreads * sizeof(pthread_t));

    for (int i = 0; i < nthreads; i++)
    {

        if (pthread_create(tid + i, NULL, contaPrimos, (void *)i))
        {
            puts("ERRO--pthread_create");
            return 3;
        }
    }
    for (int i = 0; i < nthreads; i++)
    {
        pthread_join(*(tid + i), NULL);
    }

    pthread_mutex_destroy(&mutexSoma);
    pthread_mutex_destroy(&mutexIndex);
    free(tid);
    GET_TIME(timeFim);
    totalTime = timeFim - timeInicio;
    printf("Valor de 'soma' = %ld\n", numPrimos);
    printf("Tempo do trecho concorrente: %f\n", totalTime);

    return 1;
}
