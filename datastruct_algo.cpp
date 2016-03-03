template <class T>
class LinkedList;
// IMMUTABILITY IS IMPORTANT, USE CONST TO AVOID PEOPLE CHANGING THINGS THAT DONT NEED CHANGING
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
  void Purge(); //Helper for destructor, cycles through the list and frees each value
  void InsertAfter(ListElement<T>const*, T const&);
  void InsertBefore(ListElement<T>const*, T const&);
};

template <class T>
ListElement<T>::ListElement(T const& _datum,ListElement<T>*_next):datum(_datum),next(_next){}

template <class T>
T const& ListElement<T>::Datum() const{ return datum;}

template <class T> // return a readable only vesrion of next
ListElement<T> const* ListElement<T>::Next() const{ return next;}

template <class T>
LinkedList<T>::LinkedList(): head(0),tail(0){}

template <class T>
void LinkedList<T>::Purge(){
    while(head != 0){
        ListElement<T>* const temp = head; /// initialize temporary pointer for the head
        head = head->next;
        delete temp;
        
    }
    tail =0;
}

template <class T>
LinkedList<T>::~LinkedList(){Purge();}

template <class T>
ListElement<T> const* LinkedList<T>::Head() const {return head;} // return a readable only reference to the head

template <class T>
ListElement<T> const* LinkedList<T>::Tail() const {return tail;}

template <class T>
bool LinkedList<T>::IsEmpty() const {return head ==0;}