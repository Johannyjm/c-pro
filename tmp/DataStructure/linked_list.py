class Cell:
    def __init__(self, value):
        self.value = value
        self.next = None

class LinkedList:
    def __init__(self):
        self.head = Cell(None)
    
    def insert(self, value):
        front = self.head
        rear = front.next

        while (rear is not None) and (value > rear.value):
            front = rear
            rear = rear.next

        cell = Cell(value)
        cell.next = rear
        front.next = cell

    def delete(self, value):
        front = self.head
        rear = front.next

        while(rear is not None):
            if(rear.value == value):
                front.next = rear.next
                return
            
            front = rear
            rear = rear.next
        
        print("Not found...")
    
    def show(self):
        tmp = self.head.next
        while tmp is not None:
            print(tmp.value, end=" ")
            tmp = tmp.next
        print()

if __name__ == "__main__":
    li = LinkedList()
    li.show()
    li.insert(1)
    li.insert(8)
    li.show()
    li.insert(6)
    li.insert(3)
    li.show()

    li.delete(6)
    li.show()
    li.delete(2)
    li.show()
    li.delete(3)
    li.show()