
#include <iostream>


using namespace std;
template <class T>
class DBHistory
{
    public:
        DBHistory();
        DBHistory(T* p, bool deleted);
        ~DBHistory();
        T* getPerson();
        bool getCommand();

    private:
        bool wasDeleted; //true means deleted from BST, false means added into BST
        T* person;
};

template<class T>
DBHistory<T>::DBHistory(){}

template<class T>
DBHistory<T>::DBHistory(T* p, bool deleted){
    person = p;
    wasDeleted = deleted;//true means deleted, false means added into BST
}
template<class T>
DBHistory<T>::~DBHistory(){

}
template<class T>
T* DBHistory<T>::getPerson(){
    return person;
}
template<class T>
bool DBHistory<T>::getCommand(){
    return wasDeleted;//true means deleted, false means added into BST
}
