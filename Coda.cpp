#include <iostream>

template <typename T>
class Coda {
private:
    // Nodo per la Coda
    struct Node {
        T data;
        Node* next;
        Node(T d) : data(d), next(nullptr) {}
    };

    Node* front;
    Node* rear;
    int countElements;

public:
    // Costruttore
    Coda(): front(nullptr), rear(nullptr), countElements(0) {}

    // Distruttore: libera la memoria occupata dalla coda
    ~Coda(){
          while (!isEmpty()) {
              dequeue();
          }
      }

    // Verifica se la coda è vuota
    bool isEmpty() const {
        return front == nullptr;
    }    

    // Aggiungi un elemento alla coda
    void enqueue(T data){
        Node* newNode = new Node(data);
        if (isEmpty()) {
            front = rear = newNode;
        } else {
            rear->next = newNode;
            rear = newNode;
        }
        countElements++;
    }

    // Rimuovi un elemento dalla coda
    T dequeue(){
        if (isEmpty()) {
            std::cout << "Coda vuota!" << std::endl;
            return T();  // Restituisce il valore di default del tipo T
        }
        Node* temp = front;
        T value = front->data;
        front = front->next;
        if (front == nullptr) {
            rear = nullptr;
        }
        delete temp;
        countElements--;
        return value;
    }

    //Legge il primo elemento in coda senza rimuoverlo
    T peek() const {
        if (isEmpty()) {
            std::cout << "Coda vuota!" << std::endl;
            return T();  // Restituisce il valore di default del tipo T
        }
        return front->data;  // Restituisce il dato del primo nodo (in cima alla coda)
    }

    // Visualizza la coda
    void display() {
        Node* temp = front;
        std::cout << "Coda: ";
        while (temp != nullptr) {
            std::cout << temp->data << " ";
            temp = temp->next;
        }
        std::cout << std::endl;
    }

    // Conta il numero di elementi nella coda
    int count() const{
        return countElements;
    }                
};
