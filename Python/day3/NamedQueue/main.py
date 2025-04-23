import sys

sys.path.insert(0, "/home/ghx/Documents/iti-laps/ITI-Laps/Python/day4")

from queueProblem.main import Queue
class NamedQueue(Queue):
    queues = {}

    def __init__(self, name, size=0):
        super().__init__(size)
        self.name = name
        self.count = 0
        # store name of queue and its instance
        NamedQueue.queues[name] = self

    @staticmethod
    def QueueOutOfRange(message):
        return message

    @classmethod
    def getQueue(cls, name):
        return cls.queues.get(name, None)

    @classmethod
    def save(cls, queues):
        if isinstance(queues, NamedQueue):
            cls.queues[queues.name] = queues
        else:
            print("Invalid queue type. Only NamedQueue instances can be saved.")

    @classmethod
    def load(cls):
        return cls.queues

    def insert(self, value):
        if self.count == self.size:
            print(
                NamedQueue.QueueOutOfRange(
                    f"queue {self.name} is out of range can't insert {value}"
                )
            )
            return
        super().insert(value)
        self.count += 1

    def pop(self):
        if self.isEmpty():
            print(f"Queue {self.name} is Empty")
            return None
        vaule = super().pop()
        self.count -= 1
        return vaule

    def print_queue(self):

        print(f"Queue {self.name} elements:", end=" ")

        return super().print_queue()
q2 = NamedQueue("NamedQueue", 3)

q2.insert(1)
q2.insert(2)
q2.insert(3)
q2.insert(4)

q3 = NamedQueue("version2", 4)
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
