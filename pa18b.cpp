/// @file pa18b.cpp
/// @author Ahmet Yilmaz <ahmet.yilmaz@student.csn.edu>
/// @date 2020-08-06
/// @note I pledge my word of honor that I have complied with the
/// CSN Academic Integrity Policy while completing this assignment.
/// @brief This is the interface for the simulated car wash assignment by using queues.
/// @note Queue

#include <iostream>
#include <iomanip>
#include <queue>
using namespace std;
//Car class with private variables and public functions below
class Car
{
    private:
        string carNumber;//number of cars
        int waitingTime;//waiting time for cars for car wash
    public:
        Car(string carN)
        {
            carNumber=carN;//initialize carNumber
            waitingTime=0;//initialize waitingTime
        }
        
        string getcarNumber()
        {
            return carNumber;
        }
    
        int getWaitingTime()
        {
            return waitingTime;
        }
    
        void setcarNumber(string cnum)
        {
            carNumber=cnum;
        }
    
        void setWaitingTime(int w)
        {
            waitingTime=w;
        }
};

void displayQueue(queue <Car> q)
{
    queue <Car> node = q;// Initialize the queue to q.
    while (!node.empty())
    {
        node.pop();
    }
    cout << '\n';
}

queue<Car> increaseWaitTimeForQueue(queue<Car> q)
{
    queue <Car> node = q;// Initialize the queue to q.
    queue <Car> newQueue;// Initialize the queue to newQueue.
    
    while (!node.empty())
    {
        Car c=node.front();
        c.setWaitingTime(c.getWaitingTime()+1);
        newQueue.push(c);
        node.pop();
    }
    return newQueue;
    
}
int totalWaitingTime(queue<Car> q)
{
    queue <Car> node = q;// Initialize the queue to q.
    int wait=0;// Initialize the wait time to 0.
    while (!node.empty())
    {
        Car c=node.front();
        wait += c.getWaitingTime();
        node.pop();
    }
    return wait;
    
}

int maxWaitingTime(queue<Car> q)
{
    queue <Car> node = q;// Initialize the queue to q.
    int maxWait=0;// initialize maximim wait time to 0
    while (!node.empty())//if node not empty
    {
        Car c=node.front();//assign the c object to front of the node
        int newMaxWait=c.getWaitingTime();//initialize the newMaxWait
        maxWait = maxWait>newMaxWait?maxWait:newMaxWait;//
        node.pop();
    }
    return maxWait;
    
}
int simulate1(int simDuration)
{
    int carNumber=0;//variable number of the cars ,initialized to 0
    int waitTime=0;// variable for wait time ,initialized to 0
    int simElapsed=0;//variable for simulation elapsed ,initialized to 0
    int maxWait=0;//variable for maximum wait time ,initialized to 0
    queue <Car> carQueue;// Initialize the queue to empty.
    
    while(simElapsed<=simDuration)//While the simulation is not done:
    {
        simElapsed++;//Increment simulated time by one minute
        if(!carQueue.empty())//If the queue is not empty
        {
            Car c=carQueue.front();
            //cout<<c.getcarNumber()<<" Serviced"<<endl;//check to see if it works
            carQueue.pop();// remove the car leaving the car wash.
            
        }
        int k=rand()%3;//Compute a random number k between 0 and 3.
        if(k==1)//if rand is equals 1
        {
            carNumber++;//add a car to the line
            Car c=Car("C"+to_string(carNumber));
            carQueue.push(c);
        }
        else if(k==2)
        {
            //If k is equal to 2, then add two cars to the line.
            carNumber++;
            Car c1=Car("C"+to_string(carNumber));
            carQueue.push(c1);
            carNumber++;
            Car c2=Car("C"+to_string(carNumber));
            carQueue.push(c2);
        }
        else
        {
            //Otherwise (if k is 0 or 3), do not add any cars to the line.
        }
        
        //Update queue
        carQueue=increaseWaitTimeForQueue(carQueue);
        //cout << "The  car Queue is : "<<carNumber;//check
        displayQueue(carQueue);
        
        waitTime+=totalWaitingTime(carQueue);
        //cout<<"Total Wait"<<waitTime<<endl;//check
        int newMaxWait=maxWaitingTime(carQueue);
        maxWait=maxWait>newMaxWait?maxWait:newMaxWait;
    
        //cout<<"Max Wait"<<maxWait<<endl;//check
        
    }//while end
    long remainingCars=carQueue.size();
    
    while(!carQueue.empty())
    {
        Car c=carQueue.front();
        //cout<<c.getcarNumber()<<" Serviced"<<endl;
        carQueue.pop();
        waitTime+=totalWaitingTime(carQueue);
        //cout<<"Total Wait"<<waitTime<<endl;
        int newMaxWait=maxWaitingTime(carQueue);
        maxWait=maxWait>newMaxWait?maxWait:newMaxWait;
        
        //cout<<"Max Wait"<<maxWait<<endl;
        
    }
    //Display outputs and match it to the sample output provided by Professor Kevin,
    cout<<"Simulation Duration:\t"<<simDuration<<endl;
    cout<<"Cars Washed:\t"<<carNumber<<endl;
    std::setprecision(1);
    cout<<"Average Wait:\t"<<setprecision(2)<<(float)waitTime/carNumber<<endl;
    cout<<"Longest Wait:\t"<<maxWait<<endl;
    cout<<"Cars in queue:\t"<<remainingCars<<endl;
    return simElapsed;
}

//checks if the value is an int or not
bool isNumeric(string str)
{
    for(int i=0;i<str.length();i++)
    {
        if(!isdigit(str.at(i)))
        {
            return false;
        }
    }
    return true;
    
}

//main function
int main(int argc, char *argv[])
{
    
    if(argc==2)
    {
        string strnum=argv[1];
        if(isNumeric(strnum))
        {
            
            int num = std::stoi(strnum);
            if(num>30)
            {
                simulate1(num);
            }
            else
            {
                cout<<"Invalid Duration"<<endl;
                cout<<"Usage: ./filename minutes (min 30)"<<endl;
            }
        }
        else
        {
            cout<<"Invalid Duration"<<endl;
            cout<<"Usage: ./filename minutes (min 30)"<<endl;
        }
    }
    else
    {
        simulate1(30);
    }
    
    return 0;
}//end of main

