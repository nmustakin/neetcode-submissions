class DynamicArray {
private:
    int* array; 
    int index; 
    int capacity; 
public:

    DynamicArray(int capacity) {
        this->array = (int*)malloc(sizeof(int)*capacity);
        this->index = 0;
        this->capacity = capacity; 
    }

    int get(int i) {
        return this->array[i];
    }

    void set(int i, int n) {
        if(i < this->capacity)
            this->array[i] = n;      
    }

    void pushback(int n) {
        if(this->index == this->capacity) resize();
        this->array[this->index] = n;
        this->index++; 
    }

    int popback() {   
        if(this->index > 0){
            int value = this->array[this->index-1];
            this->index--;
            return value;
        }

    }

    void resize() {
        this->capacity *= 2;  
        int* new_array = (int*)malloc(sizeof(int)*this->capacity);
        memcpy(new_array, this->array, sizeof(int)*this->capacity/2);
        delete[] this->array;
        this->array = new_array; 
    }

    int getSize() {
        return this->index; 
    }

    int getCapacity() {
        return this->capacity; 
    }
};
