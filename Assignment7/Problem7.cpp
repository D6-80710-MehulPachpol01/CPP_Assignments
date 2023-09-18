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

    // Function to add an element to the array
    void addElement(int index, const T& element) {
        if (index < 0 || index >= size) {
            std::cout << "Index out of range" << std::endl;
            return;
        }
        elements[index] = element;
    }

    // Function to display an element at a given index
    void displayElement(int index) const {
        if (index < 0 || index >= size) {
            std::cout << "Index out of range" << std::endl;
            return;
        }
        std::cout << "Element at index " << index << ": " << elements[index] << std::endl;
    }

    // Function to delete an element at a given index
    void deleteElement(int index) {
        if (index < 0 || index >= size) {
            std::cout << "Index out of range" << std::endl;
            return;
        }
        elements[index] = T(); // Assign a default value to "delete" the element
    }

    // Mutator to change the size of the array
    void resize(int newSize) {
        if (newSize == size) return; // No change needed

        T* newElements = new T[newSize];

        // Copy the elements from the old array to the new array
        int minSize = (newSize < size) ? newSize : size;
        for (int i = 0; i < minSize; ++i) {
            newElements[i] = elements[i];
        }

        // Delete the old array and update the size
        delete[] elements;
        elements = newElements;
        size = newSize;
    }

    // Inspector to get the size of the array
    int getSize() const {
        return size;
    }
};

int main() {
    // Create an array of integers with size 5
    Array<int> intArray(5);
    // Array<float> intArray(5);

    // Add elements to the array
    intArray.addElement(0, 10);
    intArray.addElement(1, 20.78);
    intArray.addElement(2, 30.99);
    intArray.addElement(3, 40);
    intArray.addElement(4, 50);

    // Display elements
    intArray.displayElement(2); // Display element at index 2

    // Delete an element
    intArray.deleteElement(1);

    // Display the modified array
    intArray.displayElement(1);

    // Resize the array
    intArray.resize(3);

    // Display the resized array size
    std::cout << "Array size after resizing: " << intArray.getSize() << std::endl;

    return 0;
}
