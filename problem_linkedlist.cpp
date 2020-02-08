/*
 Given a linked list of numbers and a threshold x, 
 partition the linked list so that 
 all nodes less than x come before nodes greater than or equal to x.

For example, given the linked list 5 -> 1 -> 8 -> 0 -> 3 
and x = 3, 
the solution could be 1 -> 0 -> 5 -> 8 -> 3.208
*/
#include <iostream>
//Node class represent a node in a LinkedList class, which holds a data and points to the next node
class Node
{
public:
    float m_value;
    Node *m_next;

    Node(float value = 0, Node *nextNode = nullptr) : m_value{value}, m_next(nextNode)
    {
    }
};

class LinkedList
{
public:
    Node *m_firstNode;
    Node *m_lastNode;

    // Constructor definition
    LinkedList(Node *firstNode = nullptr) : 
    m_firstNode{firstNode}, m_lastNode{firstNode}
    {
    }

    // method to add node to the beginning
    void addToBeginning(int value)
    {
        Node *beginningNode = new Node(value);
        if (nullptr != m_firstNode)
        {
            beginningNode->m_next = m_firstNode;
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
        Node* currNode = new Node(value);
        if (nullptr != m_lastNode)
        {
            m_lastNode->m_next = currNode;
            m_lastNode = currNode;
        }
        else
        {
            m_firstNode = currNode;
            m_lastNode = currNode;
        }
        
    }

    // traverses the LinkedList and puts the elements smaller than threshold
    // to the first one and the bigger ones to the second one. To achieve this,
    // it divides the first list into two lists and appends the list of the bigger 
    // ones to the end of the smaller one.
    LinkedList partitionMethod1(int thresholdVal)
    {
        Node *currNode = m_firstNode;
        LinkedList smallerList;
        LinkedList greaterList;
        while (nullptr != currNode)
        {
            int currVal = currNode->m_value;
            if (currVal < thresholdVal)
            {
                smallerList.addToEnd(currVal);
            }
            else
            {
                greaterList.addToEnd(currVal);
            }
            // go to the next node
            currNode = currNode->m_next;
        }
        currNode = greaterList.m_firstNode;
        while (nullptr != currNode)
        {
            smallerList.addToEnd(currNode -> m_value);
            currNode = currNode->m_next;
        }
        return smallerList;
    }

    // To partition the list, the method appends the 
    // bigger ones to the end and smaller ones to the beginning
    LinkedList partitionMethod2(int thresholdVal)
    {
        LinkedList resultantList;
        Node* currNode;
        currNode = m_firstNode;
        int currVal;

        // traverse the list
        while (nullptr != currNode)
        {
            currVal = currNode -> m_value;
            if (currVal < thresholdVal)
            {
                resultantList.addToBeginning(currVal);
            }
            else
            {
                resultantList.addToEnd(currVal);
            }
            
            currNode = currNode -> m_next;
        }
        return resultantList;
    }
    void traverseAndPrint(void)
    {
        Node *currNode = m_firstNode;
        while (nullptr != currNode)
        {
            std::cout << currNode->m_value << " -> ";
            currNode = currNode->m_next;
        }
        std::cout << "NULL" << std::endl;
    }
};

int main()
{
    LinkedList tLinkList;
    LinkedList partitionedList;


    tLinkList.addToEnd(5);
    tLinkList.addToEnd(1);
    tLinkList.addToEnd(8);
    tLinkList.addToEnd(0);
    tLinkList.addToEnd(3);    

    std::cout << "Original List: " << std::endl;
    tLinkList.traverseAndPrint();

    partitionedList = tLinkList.partitionMethod1(3);
    std::cout << "Partitioned List with method 1: " << std::endl;
    partitionedList.traverseAndPrint();
    
    partitionedList = tLinkList.partitionMethod2(3);
    std::cout << "Partitioned List with method 2: " << std::endl;
    partitionedList.traverseAndPrint();
    
    return 0;
}