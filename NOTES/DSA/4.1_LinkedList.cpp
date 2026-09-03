#include <iostream>
#include <memory>
using namespace std;

// Singly Linked List - one way of connected nodes
struct Node
{
     int data;   // Data
     Node *next; // pointer to Next node

     Node(int val) : data(val), next(nullptr) {} // Constructor

     ~Node() // Destructor - works when use delete
     {
          int val = this->data;

          if (this->next != nullptr)
          {
               delete next;          // free the node
               this->next = nullptr; // free the pointer
          }

          cout << "memory freed of data : " << val << "\n\n";
     }
};
void InsHead(Node *&head, int d)
{
     if (head == nullptr) // list is empty
     {
          head = new Node(d);
          return;
     }

     Node *tem = new Node(d);
     tem->next = head;
     head = tem;
}
void InsTail(Node *&tail, int d)
{
     if (tail == nullptr) // list is empty
     {
          tail = new Node(d);
          return;
     }

     Node *tem = new Node(d);
     tail->next = tem;
     tail = tem;
}
void InsPos(Node *&head, int pos, int d)
{
     if (pos == 1) // inserting at head
     {
          InsHead(head, d);
          return;
     }

     if (head == nullptr) // list is empty
     {
          return;
     }

     Node *tem = head;
     int cnt = 1;
     while (cnt < pos - 1)
     {
          tem = tem->next;
          cnt++;
     }

     if (tem == nullptr) // position is tail or beyond
     {
          return;
     }

     Node *tem1 = new Node(d);
     tem1->next = tem->next;
     tem->next = tem1;
}
void pList(const Node *node)
{
     if (node == nullptr) // list is empty
     {
          return;
     }

     cout << "Singly Linked List: ";
     while (node) // iterating the list
     {
          cout << node->data << " -> ";
          node = node->next;
     }
     cout << "NULL\n\n";
}
void DelNode(Node *&head, int pos)
{
     if (head == nullptr) // list is empty
     {
          return;
     }

     if (pos == 1) // deleting first node
     {
          Node *tem = head;
          head = head->next;
          tem->next = nullptr;
          delete tem;
          return;
     }

     Node *cur = head;
     Node *prv = nullptr;
     int cnt = 1;
     while (cnt < pos)
     {
          prv = cur;
          cur = cur->next;
          cnt++;
     }

     if (cur == nullptr) // position is tail or beyond
     {
          return;
     }

     prv->next = cur->next;
     cur->next = nullptr;
     delete cur;
}

// Doubly Linked List - two way of connected nodes
struct Node1
{
     int data;
     Node1 *next; // pointer to next node
     Node1 *prev; // pointer to previous node

     Node1(int val) : data(val), next(nullptr), prev(nullptr) {}

     ~Node1()
     {
          int val = this->data;

          if (this->next != nullptr)
          {
               delete next;
               this->next = nullptr;
          }

          cout << "memory freed of data : " << val << "\n\n";
     }
};
void InsHead1(Node1 *&head, int d)
{
     if (head == nullptr)
     {
          head = new Node1(d);
          return;
     }

     Node1 *tem = new Node1(d);
     tem->next = head;
     head->prev = tem;
     head = tem;
}
void InsTail1(Node1 *&tail, int d)
{
     if (tail == nullptr)
     {
          tail = new Node1(d);
          return;
     }

     Node1 *tem = new Node1(d);
     tail->next = tem;
     tem->prev = tail;
     tail = tem;
}
void InsPos1(Node1 *&head, int pos, int d)
{
     if (pos == 1)
     {
          InsHead1(head, d);
          return;
     }

     if (head == nullptr)
     {
          return;
     }

     Node1 *tem = head;
     int cnt = 1;
     while (cnt < pos - 1)
     {
          tem = tem->next;
          cnt++;
     }

     if (tem == nullptr)
     {
          return;
     }

     Node1 *tem1 = new Node1(d);
     tem1->next = tem->next;
     tem->next->prev = tem1;
     tem->next = tem1;
     tem1->prev = tem;
}
void pList1(const Node1 *head)
{
     if (head == nullptr)
     {
          return;
     }

     cout << "Doubly Linked List: " << endl;

     cout << "Forward: "; // iterating head -> tail
     const Node1 *node = head;
     const Node1 *tail = nullptr;
     while (node)
     {
          cout << node->data << " -> ";
          tail = node;
          node = node->next;
     }
     cout << "NULL\n";

     cout << "Backward: "; // iterating tail -> head
     node = tail;
     cout << "NULL";
     while (node)
     {
          cout << " -> " << node->data;
          node = node->prev;
     }
     cout << "\n\n";
}
void DelNode1(Node1 *&head, int pos)
{
     if (head == nullptr)
     {
          return;
     }

     if (pos == 1) // deleting first node
     {
          Node1 *tem = head;
          head = head->next;
          head->prev = nullptr;
          tem->next = nullptr;
          delete tem;
          return;
     }

     Node1 *cur = head;
     Node1 *prv = nullptr;
     int cnt = 1;
     while (cnt < pos)
     {
          prv = cur;
          cur = cur->next;
          cnt++;
     }

     if (cur == nullptr)
     {
          return;
     }

     prv->next = cur->next;
     cur->next->prev = prv;
     cur->next = nullptr;
     cur->prev = nullptr;
     delete cur;
}

// Circular Linked List - tail connects to head (making a circle of connected nodes)
struct Node2
{
     int data;
     Node2 *next;

     Node2(int val) : data(val), next(nullptr) {}

     ~Node2()
     {
          int val = this->data;
          cout << "memory freed of data : " << val << "\n\n";
     }
};
void InsNode(Node2 *&tail, int d)
{
     if (tail == nullptr) // make it circular
     {
          tail = new Node2(d);
          tail->next = tail;
          return;
     }

     Node2 *tem = new Node2(d);
     tem->next = tail->next;
     tail->next = tem;
}
void pList2(const Node2 *head)
{
     if (head == nullptr)
     {
          return;
     }

     cout << "Circular Linked List: ";
     const Node2 *node = head;

     do // iterating until found head again
     {
          cout << node->data << " -> ";
          node = node->next;
     } while (node != head);
     cout << "(back to " << head->data << ")\n\n";
}
void DelNode2(Node2 *&head, Node2 *&tail, int vtd)
{
     if (head == nullptr)
          return;

     if (head == tail)
     {
          delete head;
          head = tail = nullptr;
          return;
     }

     Node2 *prev = tail;
     Node2 *cur = head;

     do
     {
          if (cur->data == vtd)
          {
               prev->next = cur->next;

               if (cur == head)
                    head = cur->next;
               if (cur == tail)
                    tail = prev;

               delete cur;
               return;
          }

          prev = cur;
          cur = cur->next;
     } while (cur != head);
}

// Doubly-Circular Linked List - Doubly + Circular Linked List

int main()
{
     Node *nodeA = new Node(20); // made a node with val = 5
     Node *head = nodeA;         // currently both are..
     Node *tail = nodeA;         // ..pointers to first node
     InsHead(head, 15);
     InsHead(head, 5);
     InsTail(tail, 25);
     InsTail(tail, 30);
     InsPos(head, 2, 10);
     cout << "Head = " << head->data              // now points head of linked list
          << "\nTail = " << tail->data << "\n\n"; // now points tail of linked list
     pList(head);
     pList(tail);
     DelNode(head, 1); // freed node of 5
     DelNode(head, 3); // this freed 20 instead of 15, previos freed 5
     pList(head);
     pList(tail);
     cout << endl;

     Node1 *nodeB = new Node1(4);
     Node1 *head1 = nodeB;
     Node1 *tail1 = nodeB;
     InsHead1(head1, 8);
     InsHead1(head1, 10);
     InsTail1(tail1, 2);
     InsTail1(tail1, 0);
     InsPos1(head1, 3, 6);
     cout << "Head = " << head1->data
          << "\nTail = " << tail1->data << "\n\n";
     pList1(head1);
     DelNode1(head1, 1);
     DelNode1(head1, 3);
     pList1(head1);
     cout << endl;

     Node2 *tail2 = nullptr;
     InsNode(tail2, 3);
     InsNode(tail2, 6);
     InsNode(tail2, 9);
     Node2 *head2 = tail2->next;
     cout << "Head = " << head2->data
          << "\nTail = " << tail2->data << "\n\n";
     pList2(head2);
     DelNode2(head2, tail2, 6);
     pList2(head2);
     cout << endl;

     return 0;
}