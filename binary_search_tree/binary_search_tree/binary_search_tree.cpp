#include <iostream>
using namespace std;

class Node {
public:
    int key;
    Node* left;
    Node* right;

    Node(int k) : key(k), left(nullptr), right(nullptr) {}  // Конструктор узла дерева
};

class BinaryTree {
public:
    Node* root;

    BinaryTree() : root(nullptr) {}  // Конструктор дерева

    Node* insert(Node* root, int key) {
        if (root == nullptr) {
            return new Node(key);  // Если узел пустой, создаем новый узел
        }

        if (key < root->key) {
            root->left = insert(root->left, key);  // Рекурсивно вставляем в левое поддерево
        }
        else {
            root->right = insert(root->right, key);  // Рекурсивно вставляем в правое поддерево
        }

        return root;
    }

    void inorderTraversal(Node* root) {
        if (root != nullptr) {
            inorderTraversal(root->left);  // Рекурсивно обходим левое поддерево
            cout << root->key << " ";  // Выводим значение узла
            inorderTraversal(root->right);  // Рекурсивно обходим правое поддерево
        }
    }
};

void testBinaryTree() {
    BinaryTree binaryTree;
    binaryTree.root = binaryTree.insert(binaryTree.root, 50);
    binaryTree.insert(binaryTree.root, 30);
    binaryTree.insert(binaryTree.root, 20);
    binaryTree.insert(binaryTree.root, 40);
    binaryTree.insert(binaryTree.root, 70);
    binaryTree.insert(binaryTree.root, 60);
    binaryTree.insert(binaryTree.root, 80);

    // Тест обхода дерева
    cout << "In-order traversal: ";
    binaryTree.inorderTraversal(binaryTree.root);// Выполняем обход дерева в порядке "in-order"
    cout << endl;
}

int main() 
{
    testBinaryTree();
}