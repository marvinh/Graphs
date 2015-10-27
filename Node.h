//
//  Node.h
//  Graph
//
//  Created by marvin h on 10/26/15.
//  Copyright © 2015 marvin h. All rights reserved.
//

#ifndef Node_h
#define Node_h
#include <ostream>
template<typename T>
struct Node{
public:
    Node();
    Node(int key,T data);
    template <typename V>
    friend std::ostream& operator<<(std::ostream& outs, const Node<V>& PrintMe);
    int _key;
    T _data;
    Node* _next=NULL;
};
template<typename T>
Node<T>::Node():_key(-1),_data(NULL),_next(NULL)
{
    
}
template<typename T>
Node<T>::Node(int key, T data):_key(key),_data(data),_next(NULL)
{
    
}
template <typename V>
std::ostream& operator<<(std::ostream& outs, const Node<V>& PrintMe)
{
    if(PrintMe._data!='\0'){
        outs<<"["<<PrintMe._key<<","<<PrintMe._data<<"]->";
    }else{
        outs<<"["<<PrintMe._key<<"]->";
    }
    return outs;
}

#endif /* Node_h */
