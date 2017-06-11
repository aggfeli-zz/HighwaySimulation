#include "highway.h"

int entrance::name = 0;


highway::highway(int NSegs,int K, double Percent)           //Highway constructor
{
    cout << "Αυτοκινητόδρομος σε λειτουργία" << endl;
    N = NSegs + 1;                                      // komvoi
    number_of_vehicles = 20;
    pHead = NULL;                                       // pointer of head node 
    pTail = NULL;                                       //pointer of tail node
    list_create(NSegs, K, Percent);
}

void highway::list_create(int NSegs,int K, double Percent)
{
    int i;
    class segment *s, *temp;

    for (i = 0; i <= NSegs; i++)                        //Create NSegs+1 nodes
    {
        temp = new class segment(K, Percent); 
        if (pHead == NULL)                              //If highway-list is empty
        {
            temp->segments_create();                    //Create first segment
            pHead = temp;                               //It's the head node
            pTail = temp;                               //It's also the tail node
        }
        else
        {
            s = pHead;                                  //Change head node-add new nodes at head
            s->segments_create(temp);                   //Create segment
        }
    }
}

void highway::operate()                           //Highway segments work from the end to the head
{
    class segment *temp;
    temp = pTail;
    while (temp != pHead)
    {
        temp->operate();                         //Segment operation
        temp = temp->get_previous();
    }
    cout << "No of vehicles = " << number_of_vehicles << endl;
}

void segment::segments_create()                 //Fix node's pointers when it's the first node in the list
{
    next_segment = NULL;
    previous_segment = NULL;
}

void segment::segments_create(class segment *temp)  //Enter new segment at the end of the list
{
    class segment *s;
    s = this;
    while (s->next_segment != NULL)         //Find the last node
        s = s->next_segment;
    s->next_segment = temp;                 //And put the new one after the last you found
    temp->previous_segment = s;
}

void highway::minus()
{
    number_of_vehicles = get_number_of_vehicles()-1;
}

highway::~highway()                     //Highway destructor
{
    cout << "Deleting highway" << endl;
    while (pTail != NULL)                   //Destruct whole list-highway
    {
        segment *temp = pTail;
        pTail = pTail->get_previous();
        delete temp;     
    }
    pTail = pHead = NULL; 
}

segment::segment(int K, double Percent)     //Segment constructor
{
    cout << "A segment has been created" << endl;
    entrance segment_entrance(K, Percent);
    capacity = (segment_entrance.get_no_of_tolls() * K) + (segment_entrance.get_no_of_electronic_tolls() * 2 * K);
    number_of_vehicles = rand() % K + 0;            //Random number of vehicles
}

void segment::enter()           //Enter new vehicle at the segment if it's possible
{
    if (number_of_vehicles < capacity) number_of_vehicles++;
}


void segment::exit()            //Vehicle exits from segment
{
    cars c;
    if (c.get_indication() == -1) number_of_vehicles--;      
}

int segment::get_no_of_vehicles()
{
    return number_of_vehicles;
}

entrance::entrance(int K, double Per)       //Entrance constructor
{	
    Percent = Per;
    number_of_tolls = 3;
    number_of_electronic_tolls = 2;
    name++;                                    // Increase every time object is created
    cout << "Entrance has been created " << name << endl;
    int temp = rand() % K + 0;
    Queue toll;                                 //Toll is created as a queue     
    cars c(name);                               //Create car
    toll.push(c);                               //Push car at the toll's queue
}

void entrance::operate(double Per)
{
    int ready;
    int number;
    Percent = Per;
    ready = Percent*number;	
}

cars::cars(int name)                           //Vehicle constructor
{
    cout << "Vehicle has been created" << endl;
    name_of_segment = name;
    if ((name % 2) == 0) 
        indication = -1;        //Indication for exiting the highway
    else
        indication = 1;         //Indication for entering next segment
}

void Queue::push(class cars data)       //Push vehicle in the queue
{
    cout << "A vehicle has been pushed at the queue-toll" << endl;
    node *temp = new node;
    temp->info = data;
    temp->next = NULL;
    if(front == NULL) front = temp;
    else rear->next = temp;
    rear = temp;
    size++;
}

Queue::~Queue()             //Destructor of Queue-Toll
{
    cout << "Deleting Queue-Toll" << endl;
    for (int i = 0; i < size; i++)
    {
        node *temp = front;
        front = front->next;
        delete temp;        
    }
    front = rear = NULL;
}