#include <iostream>

class Node {
    public:
        Node *left;
        Node *right;
        char data;
        Node(char);
        Node(char, Node*, Node*);
};

class MorseTree {
    private:
        Node *root;
        void add(char, std::string, Node*);
        char decode(std::string, Node*);
    public:
        MorseTree();
        ~MorseTree();
        void add(char, std::string);
        char decode(std::string);
};
