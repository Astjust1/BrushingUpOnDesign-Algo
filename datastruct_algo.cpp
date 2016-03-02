template <class T>
class LinkedList;

template <class T>
class ListElement
{
  T datum;
  ListElement* next;

  ListElement (T const&, ListElement*);
public:
  T const& Datum() const;
  ListElement const* Next() const;

  friend LinkedList<T>;
};

template <class T>
class LinkedList
{
  ListElement<T>* head;
  ListElement<T>* tail;
public:
  LinkedList();
  ~LinkedList();

  LinkedList(LinkedList const&);
  LinkedList& operator=(LinkedList const&);
//overrides the = operator to pass a readable only version of a linked list
  ListElement<T> const* Head() const;
  ListElement<T> const* Tail() const;
  bool IsEmpty() const;
  T const& First() const;
  T const& Last() const;

  void Prepend(T const&);
  void Append(T const&);
  void Extract(T const&);
  void Purge(); //clear list
  void InsertAfter(ListElement<T>const*, T const&);
  void InsertBefore(ListElement<T>const*, T const&);
};

template <class T>
ListElement<T>::ListElement(T const& _datum,ListElement<T>*_next):datum(_datum),next(_next){}

template <class T>
T const& ListElement<T>::Datum() const{ return datum;}

template <class T>
ListElement<T> const* ListElement<T>::Next() const{ return next;}
