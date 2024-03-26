#include <iostream>
#include <vector>

template <typename T> class Iterator
{
private:
    typedef typename std::vector<T>::iterator it_type; 
    it_type it;
public:
    Iterator(const it_type& iter) :it(iter) {}
    void operator ++() { ++it; }
    bool operator !=(const Iterator& other)const { return it != other.it; }
    T& operator*(){return *it;}
};

template <typename T> class Container
{
    std::vector<T>el;
public:
    void add(const T& element) { el.push_back(element); }
    Iterator<T> begin() { return Iterator<T>(el.begin()); }
    Iterator<T> end() { return Iterator<T>(el.end()); }
};


int main() {
    Container<int> container;
    for(int i=0;i<20;i++) 
    container.add(i+1);
    

    for (auto it = container.begin(); it != container.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    return 0;
}