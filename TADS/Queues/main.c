#include <stdio.h>
#include "queue.h"

int main() {
    QUEUE_ST f;
    ELEMENT_ST e;
	POINTER_ST p;
    KNOT_ST knot;

    create(&f);

    e.key = 5;
    enqueue(&f, e);
    knot = see_next(&f);
    printf("%d (%d elements)\n", knot.element.key, count(&f));

    e.key = 3;
    enqueue(&f, e);
    knot = see_next(&f);
    printf("%d (%d elements)\n", knot.element.key, count(&f));

    e.key = 7;
    enqueue(&f, e);
    knot = see_next(&f);
    printf("%d (%d elements)\n", knot.element.key, count(&f));

    dequeue(&f);
    knot = see_next(&f);
    printf("%d (%d elements)\n", knot.element.key, count(&f));

    dequeue(&f);
    knot = see_next(&f);
    printf("%d (%d elements)\n", knot.element.key, count(&f));

	return 0;
}