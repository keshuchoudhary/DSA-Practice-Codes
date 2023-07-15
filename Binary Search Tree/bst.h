template <typename T>

class bstNode{
    public:
        T data;
        bstNode<T>* left;
        bstNode<T>* right;

        bstNode(T data){
            this->data=data;
            left=NULL;
            right=NULL;
        }

        ~bstNode(){
            delete left;
            delete right;
        }
};