/* Structure of Linked List Node
class Node {
  public:
    int data;
    Node* next;
    Node* random;

    Node(int x) {
        data = x;
        next = random = nullptr;
    }
};*/

class Solution
{
private:
    void InsTail(Node *&cloneH, Node *&cloneT, int val)
    {
        if (cloneH == nullptr)
        {
            cloneH = new Node(val);
            cloneT = cloneH;
            return;
        }

        cloneT->next = new Node(val);
        cloneT = cloneT->next;
    }

public:
    Node *cloneLinkedList(Node *head)
    {
        // code here
        Node *cloneH = nullptr;
        Node *cloneT = nullptr;

        // Create copy ll with only next pointers
        Node *tem = head;
        while (tem != nullptr)
        {
            InsTail(cloneH, cloneT, tem->data);
            tem = tem->next;
        }

        // Change next link of orignal & cloned ll with each other
        Node *ogH = head;
        Node *clH = cloneH;
        while (ogH != nullptr && clH != nullptr)
        {
            tem = ogH->next;
            ogH->next = clH;
            ogH = tem;

            tem = clH->next;
            clH->next = ogH;
            clH = tem;
        }

        // update cloned ll random link using modified next
        tem = head;
        while (tem != nullptr)
        {
            tem->next->random = (tem->random) ? (tem->random->next) : (tem->random);
            tem = tem->next->next;
        }

        // restore ll next link
        ogH = head;
        clH = cloneH;
        while (ogH != nullptr && clH != nullptr)
        {
            ogH->next = ogH->next->next;
            ogH = ogH->next;

            clH->next = (clH->next) ? (clH->next->next) : (clH->next);
            clH = clH->next;
        }

        return cloneH;
    }
};