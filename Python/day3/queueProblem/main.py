class Queue:

    def __init__(self, size=0):
        self.rear = -1
        self.front = -1
        self.arr = [None] * size
        self.size = size

    def isFull(self):
        return (self.rear== self.size - 1 and self.front == 0) or (self.rear + 1 == self.front)
    
    def insert(self, value):
        if self.isFull():
            print(f"Queue is Full can't insert {value}")
            return
        if self.rear == -1:
            self.rear = self.front = 0
        elif self.rear == self.size - 1:
            self.rear = 0
        else: 
            self.rear += 1
        self.arr[self.rear] = value

    def isEmpty(self):
        return self.rear==-1

    def pop(self):
        if self.isEmpty():
            print("Queue is Empty")
            return None
        data=self.arr[self.front]
        self.arr[self.front] = None
        if self.front==self.rear:
            self.front = self.rear = -1
        elif self.front==self.size-1:
            self.front = 0
        else:
            self.front += 1
        return data

    def print_queue(self):
        if not self.isEmpty():
            print("Queue elements:", end=" ")
            for val in self.arr:
                if val == None:
                    continue
                print(val, end=" ")
            print()
        else:
            print("Queue is Empty")



q1 = Queue(2)
q1.insert(9)
q1.insert(3)
q1.insert(5)
q1.print_queue()

