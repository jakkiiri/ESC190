# Implement Queue ADT as a circular array

class Queue:
    def __init__(self, size, start):
        self.list = [None] * size
        self.size = size
        self.start = start
        self.num_elems = 0

    def print_queue(self):
        print("index", end = "\t")
        for i in range(self.size):
            print(i, end = "\t")
        print()
        print(" " * 5, end = '\t')
        for i in range(self.size):
            if self.list[i] is not None:
                print(self.list[i], end = '\t')
            else:
                print(end = '\t')
        print()
        print("Being at index: ", self.start)
        if (self.start + self.num_elems > self.size):
            end = (self.start + self.num_elems) % self.size - 1
        else:
            end = self.start + self.num_elems - 1
        print("End at index: ", end)
        print("-" * 69)

    def enqueue(self, data):
        if (self.start + self.num_elems >= self.size):
            end_index = (self.start + self.num_elems) % self.size
        else:
            end_index = self.start + self.num_elems
        self.list[end_index] = data
        self.num_elems += 1
        print("After enqueue " + str(data) + ":")
        self.print_queue()
    
    def dequeue(self):
        if (self.start + self.num_elems >= self.size):
            end_index = (self.start + self.num_elems) % self.size
        data = self.list[self.start]
        self.list[self.start] = None
        self.start = (self.start + 1) % self.size
        self.num_elems -= 1
        print("After dequeue: ")
        self.print_queue()
        return data

    def __lt__ (self, other):
        loop_times = min(self.num_elems, other.num_elems)
        for x in range (loop_times):
            if (self.start + x > self.size):
                self_index = (self.start + x) % self.size
            else:
                self_index = self.start + x
            if (other.start + x > other.size):
                other_index = (other.start + x) % other.size
            else:
                other_index = other.start + x
            if (self.list[self_index] != other.list[other_index]):
                return self.list[self_index] < other.list[other_index]
        return self.num_elems < other.num_elems


if __name__ == "__main__":
    queue = Queue(5, 1)
    Queue.enqueue(queue, 10)
    Queue.enqueue(queue, 12)
    Queue.enqueue(queue, 7)
    Queue.dequeue(queue)
    Queue.enqueue(queue, 4)
    Queue.enqueue(queue, 8)
    Queue.dequeue(queue)
    queue1 = Queue(5, 0)
    Queue.enqueue(queue1, 1)
    Queue.enqueue(queue1, 5)
    Queue.enqueue(queue1, 5)
    queue2 = Queue(5, 0)
    Queue.enqueue(queue2, 2)
    Queue.enqueue(queue2, 1)
    Queue.enqueue(queue2, 5)
    queue3 = Queue(5, 0)
    Queue.enqueue(queue3, 2)
    Queue.enqueue(queue3, 5)
    Queue.enqueue(queue3, 10)
    Queue.enqueue(queue3, 12)
    queue4 = Queue(5, 0)
    Queue.enqueue(queue4, 11)
    Queue.enqueue(queue4, 2)
    queue_list = [queue3, queue4, queue1, queue2]
    queue_list.sort()
    for q in queue_list:
        q.print_queue()


    
            


    

    