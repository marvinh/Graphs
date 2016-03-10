#ifndef MINPRIORITYQUEUE_H
#define MINPRIORITYQUEUE_H
#define CAPACITY 50

struct MinPriorityQueueNode{
    MinPriorityQueueNode(){
        key=-1;
        pos=-1;
    }
    int key;
    int pos;
};

class MinPriorityQueue{
public:
    MinPriorityQueue();
    ~MinPriorityQueue();
    int parent(int i);
    int left(int i);
    int right(int i);
    void swap(int i, int j);
    void insert(int key, int pos);
    MinPriorityQueueNode extractMin();
    int minHeapify(int i);
    void decreaseKey(int key, int pos);
    bool empty();
private:
    int heapSize;
    MinPriorityQueueNode set[CAPACITY];
};

MinPriorityQueue::MinPriorityQueue(){
    heapSize = 0;
}

MinPriorityQueue::~MinPriorityQueue(){

}

int MinPriorityQueue::parent(int i){
    return (i-1)/2;
}

int MinPriorityQueue::left(int i){
    return 2*i+1;
}

int MinPriorityQueue::right(int i){
    return 2*i+2;
}

void MinPriorityQueue::swap(int i, int j){
    MinPriorityQueueNode temp = set[i];
    set[i] = set[j];
    set[j] = temp;
}

int MinPriorityQueue::minHeapify(int i){
    int l = left(i);
    int r = right(i);
    int smallest = i;
    if(l<=heapSize&&set[l].key<set[i].key){
        smallest = l;
    }
    if(r<=heapSize&&set[r].key<set[smallest].key){
        smallest = r;
    }
    if(smallest!=i){
        swap(i,smallest);
        minHeapify(smallest);
    }
    return smallest;
}

void MinPriorityQueue::insert(int key, int pos){
    heapSize++;
    set[heapSize-1].key = key;
    set[heapSize-1].pos = pos;
    decreaseKey(key, pos);
}

void MinPriorityQueue::decreaseKey(int key, int pos){
    int i = heapSize-1;
    set[i].key = key;
    set[i].pos = pos;
    while(i>0&&set[parent(i)].key>set[i].key){
        swap(i,parent(i));
        i=parent(i);
    }
}

MinPriorityQueueNode MinPriorityQueue::extractMin(){
    MinPriorityQueueNode min = set[0];
    MinPriorityQueueNode max = set[heapSize-1];
    set[0]=max;
    heapSize--;
    minHeapify(0);
    return min;
}

bool MinPriorityQueue::empty(){
    return heapSize==0;
}



#endif // MINPRIORITYQUEUE_H
