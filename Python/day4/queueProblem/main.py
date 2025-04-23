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


class NamedQueue(Queue):
    queues={}
    def __init__(self,name,size=0):
        super().__init__(size)
        self.name = name
        self.count=0
        #store name of queue and its instance
        NamedQueue.queues[name]=self

    @staticmethod
    def QueueOutOfRange(message):
        return message
    
    @classmethod
    def getQueue(cls,name):
        return cls.queues.get(name, None)
    
    @classmethod
    def save(cls,queues):
        if isinstance(queues, NamedQueue):
           cls.queues[queues.name]=queues
        else:
            print("Invalid queue type. Only NamedQueue instances can be saved.")

    

    @classmethod 
    def load(cls):
        return cls.queues
    
    def insert(self, value):
        if(self.count == self.size):
            print(NamedQueue.QueueOutOfRange(f"queue {self.name} is out of range can't insert {value}"))
            return
        super().insert(value)
        self.count+=1

    def pop(self):
        if self.isEmpty():
            print(f'Queue {self.name} is Empty')
            return None
        vaule=super().pop()
        self.count-=1
        return vaule
    def print_queue(self):
        
        print(f'Queue {self.name} elements:', end=" ")
       
        return super().print_queue()


q1 = Queue(2)
q1.insert(9)
q1.insert(3)
q1.insert(5)
q1.print_queue()

q2= NamedQueue("NamedQueue", 3)

q2.insert(1)
q2.insert(2)
q2.insert(3)
q2.insert(4)

q3=NamedQueue('version2',4)
q3.insert(5)
q3.insert(6)
q3.insert(7)
q3.insert(8)
NamedQueue.save(q3)
NamedQueue.save(q2)
print(f"saved Queues are {NamedQueue.load()}")

returned_value = NamedQueue.getQueue("version2")
# for i in NamedQueue.queues.items():
#     print('Queue name:', i)
# print(f'returned value= {returned_value.name}')
if returned_value:
    print(f"Queue found: {returned_value.name}")
else:
    print("Queue not found")
q2.print_queue()
