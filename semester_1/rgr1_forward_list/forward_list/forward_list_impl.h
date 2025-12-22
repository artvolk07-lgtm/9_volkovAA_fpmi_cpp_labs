#pragma once

#include <cstdint>
#include <cstddef>
#include <iterator>
#include <iostream>
#include <initializer_list>

class ForwardList {
private:
    struct Node {
        int32_t value_;
        Node* next_;
        explicit Node(int value);
    };

public:
    class ForwardListIterator {
    public:
        using iterator_category = std::forward_iterator_tag;
        using difference_type = std::ptrdiff_t;
        using value_type = int32_t;
        using pointer = value_type*;
        using reference = value_type&;

        explicit ForwardListIterator(Node* position);

        ForwardListIterator& operator++();
        ForwardListIterator operator++(int);

        bool operator==(const ForwardListIterator& other) const;
        bool operator!=(const ForwardListIterator& other) const;

        reference operator*() const;
        pointer operator->();

    private:
        Node* position_;
    };

    ForwardListIterator begin();
    ForwardListIterator end();

    ForwardListIterator begin() const;
    ForwardListIterator end() const;

    ForwardList();

    ForwardList(const ForwardList& rhs);

    ForwardList(std::size_t count, int32_t value);

    ForwardList(std::initializer_list<int32_t> init);

    ForwardList& operator=(const ForwardList& rhs);

    ~ForwardList();

    void PushFront(int32_t value);

    void PopFront();

    void Remove(int32_t value);

    void Clear();

    bool FindByValue(int32_t value);

    void Print(std::ostream& out);

    int32_t Front() const;

    std::size_t Size() const;

private:
    Node* head_;
    std::size_t size_;

    void CopyFrom(const ForwardList& rhs);
};