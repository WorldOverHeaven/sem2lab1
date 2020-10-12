template <class T> class QueueSequence {
private:
    //Queue<T>* items;
    Sequence<T>* items;
public:
    QueueSequence() {
        this->items = new Queue<T>();
    }

    Queue<T> getItems() const {
        return *items;
    }

    explicit QueueSequence(Queue<T> a) {
        this->items = new Queue<T>(a);
    }

    explicit  QueueSequence(int size) {
        this->items = new Queue<T>(size);
    }

    QueueSequence(const QueueSequence<T> & obj) {
        this->items = new Queue<T>(obj.getItems());
    }

    ~QueueSequence() {
        delete items;
    }

    void addNode(const T value) {
        this->items->addNode(value);
    }

    T get() {
        return this->items->get();
    }

    int getLen() {
        return this->items->getLen();
    }

    QueueSequence<T> GetSubList(int start, int end) {
        QueueSequence<T> a (this->items->GetSubList(start, end));
        return a;
    }

    QueueSequence<T> concat(QueueSequence<T> queue1, QueueSequence<T> queue2) {
        QueueSequence<T> a (this->items->concat(queue1.getItems(), queue2.getItems()));
        return a;
    }

    QueueSequence<T> map(T (*function) (T)) {
        QueueSequence<T> a (this->items->map(function));
        return a;
    }

    QueueSequence<bool> where(bool (*function) (T)) {
        QueueSequence<bool> a (this->items->where(function));
        return a;
    }

    T reduce(T (*function) (T, T), T c) {
        return this->items->reduce(function, c);
    }

    void print() {
        this->items->print();
    }

    void printComplex() {
        this->items->printComplex();
    }
};