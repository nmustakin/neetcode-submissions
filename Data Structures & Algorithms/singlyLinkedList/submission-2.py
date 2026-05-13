class Node:
    
    def __init__(self, val=None, nxt=None):
        self.nxt = nxt
        self.val = val

    def set_nxt(self, nxt):
        self.nxt = nxt


class LinkedList:
    
    def __init__(self):
        self.head = None
        self.tail = None
    
    def get(self, index: int) -> int:
        current = self.head
        count = 0
        while current:
            if count == index:
                return current.val
            count += 1
            current = current.nxt

        return -1 

    def insertHead(self, val: int) -> None:
        newHead = Node(val)
        newHead.set_nxt(self.head)
        self.head = newHead
        if self.tail == None:
            self.tail = newHead

    def insertTail(self, val: int) -> None:
        newTail = Node(val)
        if self.tail:
            self.tail.set_nxt(newTail)
        else:
            self.head = newTail
        self.tail = newTail
        

    def remove(self, index: int) -> bool:
        count = 0
        prev = None
        current = self.head
        while current: 
            if count == index:
                #logic for remove
                if(current != self.head and current!=self.tail):
                    prev.set_nxt(current.nxt)
                
                else:
                    if(current == self.head):
                        self.head = current.nxt
                    if(current == self.tail):
                        self.tail = prev
                
                    
                #remove current
                del current
                return True 

            count += 1
            prev = current
            current = current.nxt

        return False

    def getValues(self) -> List[int]:
        values = []
        current = self.head
        while current:
            values.append(current.val)
            current = current.nxt
        
        return values
