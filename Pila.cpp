// Classe Pila (Stack) implementata con lista collegata
#include <iostream>

template <typename T>
class Pila {
private:
    // Nodo per la Pila
    struct Node {
        T data;
        Node* next;
        Node(T d) : data(d), next(nullptr) {}
    };

    Node* top;
    int countElements;

public:
    Pila() : top(nullptr), countElements(0) {}

    ~Pila() {
        while (!isEmpty()) {
            pop();
        }
    }

    //verifica se la pila é vuota
    bool isEmpty() const {
        return top == nullptr;
    }

    // Inserimento nella cima della pila
    void push(int data) {
        Node* newNode = new Node(data);
        newNode->next = top;
        top = newNode;
        countElements++;
    }

    // Rimozione dall'elemento in cima alla pila
    int pop() {
        if (isEmpty()) {
            cout << "Pila vuota!" << endl;
            return -1;
        }
        Node* temp = top;
        int value = top->data;
        top = top->next;
        delete temp;
        countElements--;
        return value;
    }

    // Leggi il primo elemento senza rimuoverlo
    T top() const {
        if (isEmpty()) {
            std::cout << "Pila vuota!" << std::endl;
            return T();  // Restituisce il valore di default del tipo T
        }
        return top->data;
    };                     

    // Visualizzazione degli elementi nella pila
    void display() const {
        Node* temp = top;
        cout << "Pila: ";
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    // Restituisce il numero di elementi presenti
    int count() const {
        return countElements;
    }

    // Inverte il contenuto della pila
    void invert() {
        Node* prev = nullptr;
        Node* current = top;
        Node* next = nullptr;
        while (current != nullptr) {
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }
        top = prev;
    }
};
