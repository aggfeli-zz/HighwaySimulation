#ifndef HIGHWAY_H
#define	HIGHWAY_H
#include <cstdlib>
#include <string>
#include <iostream>

using namespace std;

class entrance{
public:
    static int name;
    entrance(int K, double Per);                //constructor with given value 
    entrance() {};
    virtual ~entrance(){cout << "An entrance has been deleted" << endl;};
    int get_no_of_tolls(){ return number_of_tolls;};
    int get_no_of_electronic_tolls(){ return number_of_electronic_tolls;};
    void operate(double Per);
private:
    int number_of_tolls;
    int number_of_electronic_tolls;
    int Percent;
};


class segment{
public:
    segment(int K, double Percent);         //constructor
    segment(){};
    ~segment(){cout << "A segment has been deleted" << endl;};
    void enter();
    void exit();
    int get_no_of_vehicles();
    void segments_create();
    void segments_create(class segment *temp);
    void operate(){};
    segment * get_previous(){ return previous_segment;};
private:
    class entrance segment_entrance;
    int number_of_vehicles;
    int capacity;
    class segment *next_segment;
    class segment *previous_segment;
};


class highway {
public:
    highway(int NSegs, int K, double Percent);
    highway(const highway& orig);
    virtual ~highway();
    void list_create(int NSegs, int K, double Percent);
    void operate();
    int get_number_of_vehicles(){ return number_of_vehicles;};
    void minus();
private:
    int number_of_vehicles;
    int N;                                                   //No of nodes
    class segment *pHead;
    class segment *pTail;
};


class cars {
public:
    cars(int name = -1);
    virtual ~cars(){cout << "Vehicle has been deleted" << endl;};
    int get_indication(){ return indication;};
private:
    int name_of_segment;
    int indication;
};

class Queue{
private:
    struct node{
        class cars info;
        struct node *next;
    };
    node *rear;
    node *front;
    int size;
public:
    Queue(){ rear = NULL; front = NULL; size = 0;};
    virtual ~Queue() ;
    void push(class cars data);
};

#endif	/* HIGHWAY_H */

