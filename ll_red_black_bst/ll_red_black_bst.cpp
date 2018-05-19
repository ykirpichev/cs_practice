
#include <memory>
#include <string>
#include <stdexcept>

using namespace std;

template<typename Key, typename Value>
class LLRedBlackBST {
public:
    LLRedBlackBST() {}


    Value get(Key key) {
        auto node = get(root, key);
        if (!node) throw runtime_error(string("key: ") + to_string(key) + string(" is not found"));
        return node->value;
    }

    void put(Key key, Value value) {
        
        root = put(root, key, value);
        root->isRed = false;
    }

private:

    struct Node {
        Key key;
        Value value;
        bool isRed;
        shared_ptr<Node> left;
        shared_ptr<Node> right;

        Node(Key key, Value value) : key(key), value(value), isRed(false) {}
    };

    using NodePtr = shared_ptr<Node>;

    bool isRed(const NodePtr& node) {
        if (!node) return false;

        return node->isRed;
    }

    NodePtr get(NodePtr node, Key key) {
        while (node != nullptr) {
            if (node->key < key) node = node->right;
            else if (key < node->key) node = node->left;
            else return node; 
        }

        throw nullptr;
    }

    NodePtr put(NodePtr node, Key key, Value value) {
        if (node == nullptr) return make_shared<Node>(key, value);

        if (node->value < key) node->right = put(node->right, key, value);
        else if (node->value > key) node->left = put(node->left, key, value);
        else node->value = value;

        if (isRed(node->right) && !isRed(node->left)) node = rotateLeft(node);
        if (isRed(node->left) && isRed(node->left->left)) node = rotateRight(node);
        if (isRed(node->left) && isRed(node->right)) flipColors(node);

        return node;
    }

    NodePtr rotateLeft(const NodePtr& node) {
        auto newNode = node->right;
        newNode->isRed = node->isRed;

        node->right = newNode->left;
        newNode->left = node;

        node->isRed = true;

        return newNode;
    }

    NodePtr rotateRight(const NodePtr& node) {
        auto newNode = node->left;
        newNode->isRed = node->isRed;

        node->left = newNode->right;
        newNode->right = node;

        node->isRed = true;

        return newNode;
    }

    void flipColors(const NodePtr& node) {
        node->left->isRed = !node->left->isRed;
        node->right->isRed = !node->right->isRed;
        node->isRed = !node->isRed;
    }

    NodePtr root;
};


int main(int argc, char* argv[])
{
    LLRedBlackBST<int, int> rbt;
    rbt.put(10, 10);
    rbt.put(11, 11);
    rbt.put(12, 12);
    return 0;
}
