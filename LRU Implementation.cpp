#include <unordered_map>

class LRUCache
{
private:
    struct Node {
        int key;
        int value;
        Node* prev;
        Node* next;
        
        Node(int k, int v) : key(k), value(v), prev(nullptr), next(nullptr) {}
    };
    
    int capacity;
    std::unordered_map<int, Node*> cache;
    Node* head;
    Node* tail;

public:
    LRUCache(int capacity)
    {
        this->capacity = capacity;
        head = new Node(-1, -1);  // dummy node for the front
        tail = new Node(-1, -1);  // dummy node for the back
        head->next = tail;
        tail->prev = head;
    }

    int get(int key)
    {
        if (cache.find(key) != cache.end()) {
            Node* node = cache[key];
            moveToHead(node);  // Move the accessed node to the front
            return node->value;
        }
        return -1;
    }

    void put(int key, int value)
    {
        if (cache.find(key) != cache.end()) {
            Node* node = cache[key];
            node->value = value;
            moveToHead(node);
        } else {
            Node* newNode = new Node(key, value);
            cache[key] = newNode;
            addToFront(newNode);
            
            if (cache.size() > capacity) {
                Node* removedNode = removeTail();
                cache.erase(removedNode->key);
                delete removedNode;
            }
        }
    }
    
private:
    void moveToHead(Node* node)
    {
        node->prev->next = node->next;
        node->next->prev = node->prev;
        
        node->next = head->next;
        node->prev = head;
        head->next->prev = node;
        head->next = node;
    }
    
    void addToFront(Node* node)
    {
        node->next = head->next;
        node->prev = head;
        head->next->prev = node;
        head->next = node;
    }
    
    Node* removeTail()
    {
        Node* node = tail->prev;
        tail->prev = node->prev;
        node->prev->next = tail;
        return node;
    }
};
