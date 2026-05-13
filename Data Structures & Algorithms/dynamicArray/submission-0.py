class DynamicArray:
    
    def __init__(self, capacity: int):
        self.capacity = capacity
        self.array = [None] * self.capacity
        self.index = 0

    def get(self, i: int) -> int:
        return self.array[i]

    def set(self, i: int, n: int) -> None:
        if i < self.capacity:
            self.array[i] = n
            if self.index < i: 
                self.index = i

    def pushback(self, n: int) -> None:
        if self.index == self.capacity:
            self.resize()
        self.array[self.index] = n
        self.index += 1
        
    def popback(self) -> int:
        if (self.index != 0):
            self.index -= 1
            val = self.array[self.index]
            self.array[self.index] = None
            return val

    def resize(self) -> None:
        self.array.extend([None] * self.capacity)
        self.capacity *= 2

    def getSize(self) -> int:
        return self.index
    
    def getCapacity(self) -> int:
        return self.capacity