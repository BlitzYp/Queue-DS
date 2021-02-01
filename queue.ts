interface queueNode {
    value: string | number;
    next?: queueNode;
}

interface queue {
    size: number;
    head?: queueNode;
    tail?: queueNode;
};

const enqueue = (value: string | number, q: queue) => {
    const node: queueNode = {value};
    if (q.size == 0) {
        q.size++;
        q.head = node;
        q.tail = node;
        return;
    }
    q.size++;
    q.tail.next = node;
    q.tail = node;
    return;
}

const dequeue = (q:queue): string | number => {
    if (!q.size) return "Empty";
    const tmp = q.head;
    q.head = q.head.next;
    q.size--;
    return tmp.value;
}

const main = (): void => {
    const q: queue = {size: 0};
    enqueue("Blitz", q);
    enqueue(5, q);
    console.log(dequeue(q));
    console.log(dequeue(q));
    console.log(dequeue(q));
}

main();