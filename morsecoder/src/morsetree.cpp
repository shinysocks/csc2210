#include "morsetree.h"

Node::Node(char c, Node *left, Node *right) {
    data = c;
    Node::left = left;
    Node::right = right;
}

Node::Node(char c) {
    Node(c, nullptr, nullptr);
}

Node::~Node() {
    delete left;
    delete right;
}

MorseTree::MorseTree() {
    root = new Node('\0');
}

MorseTree::~MorseTree() {
    delete root;
}

void MorseTree::add(char c, std::string code, Node *node) {
        if (code.length() == 0) {
            node->data = tolower(c);
        } else if (code[0] == '.') {
            node->left = (node->left == nullptr) ? new Node('\0') : node->left;
            add(c, code.substr(1, code.length()), node->left);
        } else {
            node->right = (node->right == nullptr) ? new Node('\0') : node->right;
            add(c, code.substr(1, code.length()), node->right);
        }
}

void MorseTree::add(char c, std::string code) {
    add(c, code, root);
}

char MorseTree::decode(std::string code, Node *node) {
        if (code.length() == 0) {
            return node->data;
        }

        if (code[0] == '.') {
            return decode(code.substr(1, code.length()), node->left);
        } 

        if (code[0] == '-') {
            return decode(code.substr(1, code.length()), node->right);
        }

        return '\0';
}

char MorseTree::decode(std::string code) {
    return decode(code, root);
}
