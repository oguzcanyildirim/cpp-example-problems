 /*
 Given a linked list of numbers and a pivot k, 
 partition the linked list so that 
 all nodes less than k come before nodes greater than or equal to k.

For example, given the linked list 5 -> 1 -> 8 -> 0 -> 3 
and k = 3, 
the solution could be 1 -> 0 -> 5 -> 8 -> 3.208
*/

//Node class represent a node in a LinkedList class, which holds a data and points to the next node
class Node
{
    public:
        float m_value;
        Node* next;
        
        explicit Node(float value) : m_value{value}
        {}
    
};

class LinkedList
 {
     public:
        Node* m_firstNode;
        LinkedList (Node firstNode) : m_firstNode{&firstNode}
        {}
     
 };