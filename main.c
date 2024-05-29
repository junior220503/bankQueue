#include <stdio.h>
#include <string.h>
#include "fila.h"

int main() {
    t_queue priority_queue, general_queue;
    createQueue(&priority_queue);
    createQueue(&general_queue);

    char command;
    Client client;
    int priority_count = 0;

    while (1) {
        scanf(" %c", &command);

        if (command == 'f') {
            break;
        }

        if (command == 'p' || command == 'g') {
            scanf("%s", client.name);
            client.type = command;

            if (client.type == 'p') {
                enqueue(&priority_queue, client);
            } else {
                enqueue(&general_queue, client);
            }
        } else if (command == 's') {
            if (!isEmpty(&priority_queue) && (priority_count < 3 || isEmpty(&general_queue))) {
                client = dequeue(&priority_queue);
                priority_count++;
            } else if (!isEmpty(&general_queue)) {
                client = dequeue(&general_queue);
                priority_count = 0;
            } else if (!isEmpty(&priority_queue)) {
                client = dequeue(&priority_queue);
                priority_count = 1;
            } else {
                continue;
            }
            printf("Cliente chamado: %s\n", client.name);
        }
    }

    printf("Fim do expediente. Ordem de atendimento restante:\n");
    while (!isEmpty(&priority_queue)) {
        client = dequeue(&priority_queue);
        printf("%s (%c)\n", client.name, client.type);
    }
    while (!isEmpty(&general_queue)) {
        client = dequeue(&general_queue);
        printf("%s (%c)\n", client.name, client.type);
    }
}