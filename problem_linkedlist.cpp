 /*
 Given a linked list of numbers and a pivot k, 
 partition the linked list so that 
 all nodes less than k come before nodes greater than or equal to k.

For example, given the linked list 5 -> 1 -> 8 -> 0 -> 3 
and k = 3, 
the solution could be 1 -> 0 -> 5 -> 8 -> 3.208
*/
# include <iostream>
//Node class represent a node in a LinkedList class, which holds a data and points to the next node
class Node
{
    public:
        float m_value;
        Node* next;
        
        explicit Node(float value = 0) : m_value{value}
        {}
    
};

class LinkedList
 {
     public:
        Node* m_firstNode;
        Node* m_lastNode;
        LinkedList (Node* firstNode = nullptr) : m_firstNode{firstNode}
        {}
        // method to add node to the beginning
        void addToBeginning(int value)
        {
            Node* beginningNode = new Node(value);
            if (m_firstNode)
            {
                beginningNode -> next = m_firstNode;
                m_firstNode = beginningNode;
            }
            
        }
        // method to add Node to the end of the linkedlist
        void addToEnd(int value)
        {

        }     
 };

 int main()
 {
     LinkedList tLinkList;

     tLinkList.addToBeginning(5);
     std::cout << "No errors" << std::endl;
     return 0;
 }