#ifndef IT230_PROJECT1_MYSET_H
#define IT230_PROJECT1_MYSET_H
#include <string>
#include <type_traits>

namespace Set
{
    template<typename T>
        concept Numeric = std::is_arithmetic_v<T>;
    template<typename T>
    class MySet
    {
    private:
        static constexpr size_t DEFAULT_CAPACITY = 4;
        T* items; // pointing to a generic list of items
        size_t count = 0; // initializing the size of the list
        size_t capacity = 0; // initializing the capacity to be the same size as count
        // swap()
        void swap(size_t indexOne, size_t indexTwo);
        // grow()
        void grow(); // increase capacity when it is reached
        // shrink()
        void shrink(); // shrink capacity when it is reached
    public:
        // Getters
        [[nodiscard]] size_t getCount() const; // getter for count
        [[nodiscard]] size_t getCapacity() const; // getter for capacity

        // Default Constructor -> capacity for 4 elements
        MySet();

        // Capacity Constructor -> const not needed in argument because it's just a copy and who cares
        explicit MySet(size_t capacity);

        //Deconstructor
        ~MySet();

        // Copy Constructor
        MySet(const MySet& other);

        // Indexing
        size_t operator[](size_t index);

        // find() -> item as argument, returns index
        [[nodiscard]] size_t find(const T& item) const;

        // Inserts -> no dupes allowed, only argument is the item itself
        void insert(const T& item);

        void insert(const T& item, size_t index);

        // remove() -> takes item as argument
        bool remove(const T& item);

        // removeAt() -> takes index as argument
        void removeAt(size_t index);

        // clear() -> clears the set
        void clear();

        // toString()
        [[nodiscard]] std::string toString() const;

        // median() -> returns the median value of a set
        [[nodiscard]] double median();

        // ======= SORTING ========
        // bubbleSort() -> standard
        void bubbleSort();

        // bidirectionalBubbleSort() -> inner loop carry largest item to the right, inner loop will carry smallest item to the left
        void bidirectionalBubbleSort();

        // insertionSort() -> standard
        void insertionSort();

        // insertionSortVerbose() -> counts the number of copies and comparisons it makes during a sort and displays the totals
        void insertionSortVerbose();

        // selectionSort() -> standard
        void selectionSort();

        //oddEven() -> iterates through every other index and then compares to the value next to it, the starting value determines the odd even indexes
        void oddEven();

    };
    template class MySet<int>;
}





#endif //IT230_PROJECT1_MYSET_H
