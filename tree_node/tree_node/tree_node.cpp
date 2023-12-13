#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// Шаблонный класс TreeNode для представления узла бинарного дерева
template <typename T>
class TreeNode {
public:
    T data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(T data) : data(data), left(nullptr), right(nullptr) {}
};

// Функция для отображения содержимого узла
template <typename T>
void displayNode(TreeNode<T>* node) {
    if (node != nullptr) {
        cout << "Node data: " << node->data << endl;
    }
    else {
        cout << "Node is null" << endl;
    }
}

// Функция для удаления всех узлов в дереве
template <typename T>
void deleteTree(TreeNode<T>* root) {
    if (root != nullptr) {
        deleteTree(root->left);
        deleteTree(root->right);
        delete root;
    }
}

// NLR (префиксный обход)
template <typename T>
void traverseNLR(TreeNode<T>* root, vector<T>& result) {
    if (root != nullptr) {
        result.push_back(root->data);   // Добавляем данные узла
        traverseNLR(root->left, result); // Рекурсивно обходим левое поддерево
        traverseNLR(root->right, result);// Рекурсивно обходим правое поддерево
    }
}

// LNR (инфиксный обход)
template <typename T>
void traverseLNR(TreeNode<T>* root, vector<T>& result) {
    if (root != nullptr) {
        traverseLNR(root->left, result); // Рекурсивно обходим левое поддерево
        result.push_back(root->data);    // Добавляем данные узла
        traverseLNR(root->right, result);// Рекурсивно обходим правое поддерево
    }
}

// LRN (постфиксный обход)
template <typename T>
void traverseLRN(TreeNode<T>* root, vector<T>& result) {
    if (root != nullptr) {
        traverseLRN(root->left, result); // Рекурсивно обходим левое поддерево
        traverseLRN(root->right, result);// Рекурсивно обходим правое поддерево
        result.push_back(root->data);    // Добавляем данные узла
    }
}

// Создание массива на основе обхода
template <typename T>
vector<T> createTraversalArray(TreeNode<T>* root, const string& traversalType) {
    vector<T> result;
    if (traversalType == "NLR") {
        traverseNLR(root, result);
    }
    else if (traversalType == "LNR") {
        traverseLNR(root, result);
    }
    else if (traversalType == "LRN") {
        traverseLRN(root, result);
    }
    return result;
}

// Вывод содержимого узлов дерева
template <typename T>
void printTreeContent(TreeNode<T>* root) {
    vector<T> result = createTraversalArray(root, "NLR");
    for (const auto& data : result) {
        cout << data << " ";
    }
    cout << endl;
}

// Подсчет узлов в дереве
template <typename T>
int countNodes(TreeNode<T>* root) {
    if (root == nullptr) {
        return 0;
    }
    return 1 + countNodes(root->left) + countNodes(root->right);
}

// Определение глубины дерева
template <typename T>
int depthOfTree(TreeNode<T>* root) {
    if (root == nullptr) {
        return 0;
    }
    int leftDepth = depthOfTree(root->left);
    int rightDepth = depthOfTree(root->right);
    return 1 + std::max(leftDepth, rightDepth);
}

// Функция для обхода в ширину
template <typename T>
void breadthFirstSearch(TreeNode<T>* root) {
    if (root == nullptr) {
        return;
    }

    queue<TreeNode<T>*> q;
    q.push(root);

    while (!q.empty()) {
        TreeNode<T>* current = q.front();
        q.pop();

        std::cout << current->data << " ";

        if (current->left != nullptr) {
            q.push(current->left);
        }
        if (current->right != nullptr) {
            q.push(current->right);
        }
    }
}

// Функция для копирования бинарного дерева
template <typename T>
TreeNode<T>* copyTree(TreeNode<T>* root) {
    if (root == nullptr) {
        return nullptr;
    }

    TreeNode<T>* newRoot = new TreeNode<T>(root->data);
    newRoot->left = copyTree(root->left);
    newRoot->right = copyTree(root->right);

    return newRoot;
}


int main()
{
    // Создание бинарного дерева
    TreeNode<int>* root = new TreeNode<int>(1);
    root->left = new TreeNode<int>(3);
    root->right = new TreeNode<int>(2);
    root->left->left = new TreeNode<int>(4);
    root->left->right = new TreeNode<int>(5);
    vector<int> nlrArray = createTraversalArray(root, "NLR");
    vector<int> lnrArray = createTraversalArray(root, "LNR");
    vector<int> lrnArray = createTraversalArray(root, "LRN");

    // Вывод массивов
    cout << "NLR Array: ";
    for (const auto& data : nlrArray) {
        cout << data << " ";
    }
    cout << endl;

    cout << "LNR Array: ";
    for (const auto& data : lnrArray) {
        cout << data << " ";
    }
    cout << endl;

    cout << "LRN Array: ";
    for (const auto& data : lrnArray) {
        cout << data << " ";
    }
    cout << endl;

    // Вывод содержимого узлов дерева
    printTreeContent(root);

    // Подсчет узлов в дереве
    cout << "Number of nodes in the tree: " << countNodes(root) << endl;

    // Определение глубины дерева
    cout << "Depth of the tree: " << depthOfTree(root) << endl;

    // Обход в ширину и вывод исходного дерева
    cout << "Breadth-First Search (Original Tree): ";
    breadthFirstSearch(root);
    cout << endl;

    // Копируем исходное бинарное дерево
    TreeNode<int>* copiedTree = copyTree(root);

    // Удаление дерева
    deleteTree(root);
}
