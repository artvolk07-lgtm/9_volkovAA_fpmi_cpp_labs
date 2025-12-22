    #pragma once

    #include <initializer_list>
    #include <stdexcept>
    #include <ostream>

    class Vector {
    public:
        Vector();
        explicit Vector(unsigned int n);
        Vector(std::initializer_list<int> init);
        Vector(const Vector& other);
        Vector& operator=(const Vector& other);
        ~Vector();

        void Swap(Vector& other);

        int& operator[](unsigned int index);
        const int& operator[](unsigned int index) const;

        int& At(unsigned int index);
        const int& At(unsigned int index) const;

        unsigned int Size() const;
        unsigned int Capacity() const;

        void PushBack(int value);
        void PopBack();
        void Clear();
        void Reserve(unsigned int new_capacity);

    private:
        int* data_;
        unsigned int size_;
        unsigned int capacity_;

        void ReallocateTo(unsigned int new_capacity);
    };

    std::ostream& operator<<(std::ostream& os, const Vector& v);
