class ListNode {
public:
  ListNode(); //default
  ListNode(int d); //overloaded
  ~ListNode();

  int data;
  ListNode *next;

};

ListNode::ListNode(){
  //Build character here
}

ListNode::~ListNode(){
  //wtf goes in here
}

ListNode::ListNode(int d){
  data = d;
  next = NULL;
}


class NaiveList {
private:
  ListNode *front;
  unsigned int size;

public:
  NaiveList();
  ~NaiveList();

  void insert(int data); //fill in these methods
  int remove();
  void PrintList();
  int find(int data);
  unsigned int getSize;
  bool isEmpty();
};
