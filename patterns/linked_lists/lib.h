
template <typename T>
class Node
{
public:
    Node(T data, Node *next) : data(data), next(next) {}
    ~Node()
    {
        delete next;
    }

    T data;
    Node *next;
};