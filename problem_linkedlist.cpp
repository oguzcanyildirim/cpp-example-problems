 /*
 Given a linked list of numbers and a threshold x, 
 partition the linked list so that 
 all nodes less than x come before nodes greater than or equal to x.

For example, given the linked list 5 -> 1 -> 8 -> 0 -> 3 
and x = 3, 
the solution could be 1 -> 0 -> 5 -> 8 -> 3.208
*/
# include <iostream>
//Node class represent a node in a LinkedList class, which holds a data and points to the next node
class Node
{
    public:
        float m_value;
        Node* m_next;
        
        explicit Node(float value = 0, Node* nextNode = nullptr) : 
        m_value{value}, m_next(nextNode)
        {}
    
};

class LinkedList
 {
     public:
        Node* m_firstNode;
        Node* m_lastNode;

        // Constructor definition
        LinkedList (Node* firstNode = nullptr) : m_firstNode{firstNode}
        {}

        // method to add node to the beginning
        void addToBeginning(int value)
        {
            Node* beginningNode = new Node(value);
            if (m_firstNode)
            {
                beginningNode -> m_next = m_firstNode;
                m_firstNode = beginningNode;
            } 
            else
            {
                m_firstNode = beginningNode;
                m_lastNode = beginningNode;
            }
            
        }

        // method to add Node to the end of the linkedlist
        void addToEnd(int value)
        {
            if(m_lastNode)
            {
                m_lastNode -> m_next = new Node(value);
            }
        }     

        // traverses the LinkedList and puts the elements smaller than threshold
        // to the first one and the bigger ones to the second one
        void partition(int thresholdVal, LinkedList &smallerList, LinkedList &greaterList)
        {

        }

        void traverseAndPrint(void)
        {
            Node* currNode = m_firstNode;
            while (currNode)
            {
                std::cout << currNode -> m_value << " -> ";
                currNode = currNode -> m_next;
            }
            std::cout << "NULL" << std::endl;
        }
 };

 int main()
 {
     LinkedList tLinkList;

     tLinkList.addToBeginning(5);
     tLinkList.addToBeginning(3);
     tLinkList.addToEnd(8);

     tLinkList.traverseAndPrint();
     std::cout << "No errors" << std::endl;
     return 0;
 }