#include "Vector_impl.h"

Vector::Vector() : data_(nullptr), size_(0), capacity_(0) {
}

Vector::Vector(unsigned int n) : data_(0), size_(n), capacity_(n) {
    if (capacity_ > 0) {
        data_ = new int[capacity_];
        for (unsigned int i = 0; i < size_; ++i) {
            data_[i] = 0;
        }
    }
}

Vector::Vector(std::initializer_list<int> init) : data_(0), size_(0), capacity_(0) {
    capacity_ = static_cast<unsigned int>(init.size());
    size_ = capacity_;
    if (capacity_ > 0) {
        data_ = new int[capacity_];
        unsigned int i = 0;
        for (std::initializer_list<int>::const_iterator it = init.begin(); it != init.end(); ++it) {
            data_[i++] = *it;
        }
    }
}

Vector::Vector(const Vector& other) : data_(0), size_(other.size_), capacity_(other.capacity_) {
    if (capacity_ > 0) {
        data_ = new int[capacity_];
        for (unsigned int i = 0; i < size_; ++i) {
            data_[i] = other.data_[i];
        }
    }
}

Vector& Vector::operator=(const Vector& other) {
    if (this == &other) {
        return *this;
    }
    int* new_data = 0;
    if (other.capacity_ > 0) {
        new_data = new int[other.capacity_];
        for (unsigned int i = 0; i < other.size_; ++i) {
            new_data[i] = other.data_[i];
        }
    }
    delete[] data_;
    data_ = new_data;
    size_ = other.size_;
    capacity_ = other.capacity_;
    return *this;
}

Vector::~Vector() {
    delete[] data_;
}

void Vector::Swap(Vector& other) {
    int* tmp_data = data_;
    data_ = other.data_;
    other.data_ = tmp_data;

    unsigned int tmp_size = size_;
    size_ = other.size_;
    other.size_ = tmp_size;

    unsigned int tmp_capacity = capacity_;
    capacity_ = other.capacity_;
    other.capacity_ = tmp_capacity;
}

int& Vector::operator[](unsigned int index) {
    return data_[index];
}

const int& Vector::operator[](unsigned int index) const {
    return data_[index];
}

int& Vector::At(unsigned int index) {
    if (index >= size_) {
        throw std::out_of_range("Vector::At: index out of range");
    }
    return data_[index];
}

const int& Vector::At(unsigned int index) const {
    if (index >= size_) {
        throw std::out_of_range("Vector::At: index out of range");
    }
    return data_[index];
}

unsigned int Vector::Size() const {
    return size_;
}

unsigned int Vector::Capacity() const {
    return capacity_;
}

void Vector::PushBack(int value) {
    if (size_ == capacity_) {
        unsigned int new_capacity = (capacity_ == 0) ? 1 : (capacity_ * 2);
        ReallocateTo(new_capacity);
    }
    data_[size_] = value;
    ++size_;
}

void Vector::PopBack() {
    if (size_ > 0) {
        --size_;
    }
}

void Vector::Clear() {
    size_ = 0;
}

void Vector::Reserve(unsigned int new_capacity) {
    if (new_capacity > capacity_) {
        ReallocateTo(new_capacity);
    }
}

void Vector::ReallocateTo(unsigned int new_capacity) {
    if (new_capacity < size_) {
        new_capacity = size_;
    }

    int* new_data = 0;
    if (new_capacity > 0) {
        new_data = new int[new_capacity];
        for (unsigned int i = 0; i < size_; ++i) {
            new_data[i] = data_[i];
        }
    }

    delete[] data_;
    data_ = new_data;
    capacity_ = new_capacity;
}

std::ostream& operator<<(std::ostream& os, const Vector& v) {
    os << "[";
    unsigned int n = v.Size();
    for (unsigned int i = 0; i < n; ++i) {
        os << v[i];
        if (i + 1 < n) {
            os << ", ";
        }
    }
    os << "]";
    return os;
}