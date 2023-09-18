#include <iostream>

template <typename T>
class Array {
private:
    T* elements;
    int size;

public:
    Array(int size) {
        this->size = size;
        elements = new T[size];
    }

    ~Array() {
        delete[] elements;
    }

    void addElement(int index, const T& element) {
        if (index < 0 || index >= size) {
            std::cout << "Index out of range" << std::endl;
            return;
        }
        elements[index] = element;
    }

    void displayElement(int index) const {
        if (index < 0 || index >= size) {
            std::cout << "Index out of range" << std::endl;
            return;
        }
        std::cout << "Element at index " << index << ": " << elements[index] << std::endl;
    }

    void deleteElement(int index) {
        if (index < 0 || index >= size) {
            std::cout << "Index out of range" << std::endl;
            return;
        }
        elements[index] = T(); 
    }

    void resize(int newSize) {
        if (newSize == size) return; 

        T* newElements = new T[newSize];

        int minSize = (newSize < size) ? newSize : size;
        for (int i = 0; i < minSize; ++i) {
            newElements[i] = elements[i];
        }

        
        delete[] elements;
        elements = newElements;
        size = newSize;
    }

    
    int getSize() const {
        return size;
    }
};

int main() {
 
    Array<int> intArray(5);
   

    
    intArray.addElement(0, 10);
    intArray.addElement(1, 20.78);
    intArray.addElement(2, 30.99);
    intArray.addElement(3, 40);
    intArray.addElement(4, 50);

    
    intArray.displayElement(2); 

    
    intArray.deleteElement(1);

    
    intArray.displayElement(1);

   
    intArray.resize(3);

    
    std::cout << "Array size after resizing: " << intArray.getSize() << std::endl;

    return 0;
}
