#ifndef EDGE
#define EDGE

template <class E>
class Edge<E> {
  /** Returns the element associated with the edge. */
  virtual E getElement();
};

#endif