#include "forward_list_impl.h"

ForwardList::Node::Node(int value) : value_(value), next_(nullptr) {
}

ForwardList::ForwardListIterator::ForwardListIterator(Node* position) : position_(position) {
}

ForwardList::ForwardListIterator& ForwardList::ForwardListIterator::operator++() {
    if (position_ != nullptr) {
        position_ = position_->next_;
    }
    return *this;
}

ForwardList::ForwardListIterator ForwardList::ForwardListIterator::operator++(int) {
    ForwardListIterator retval = *this;
    ++(*this);
    return retval;
}

bool ForwardList::ForwardListIterator::operator==(const ForwardListIterator& other) const {
    return position_ == other.position_;
}

bool ForwardList::ForwardListIterator::operator!=(const ForwardListIterator& other) const {
    return !(*this == other);
}

ForwardList::ForwardListIterator::reference ForwardList::ForwardListIterator::operator*() const {
    return position_->value_;
}

ForwardList::ForwardListIterator::pointer ForwardList::ForwardListIterator::operator->() {
    return &position_->value_;
}

ForwardList::ForwardListIterator ForwardList::begin() {
    return ForwardListIterator(head_);
}

ForwardList::ForwardListIterator ForwardList::end() {
    return ForwardListIterator(nullptr);
}

ForwardList::ForwardListIterator ForwardList::begin() const {
    return ForwardListIterator(head_);
}

ForwardList::ForwardListIterator ForwardList::end() const {
    return ForwardListIterator(nullptr);
}

ForwardList::ForwardList() : head_(nullptr), size_(0) {
}

ForwardList::ForwardList(const ForwardList& rhs) : head_(nullptr), size_(0) {
    CopyFrom(rhs);
}

ForwardList::ForwardList(std::size_t count, int32_t value) : head_(nullptr), size_(0) {
    if (count == 0) {
        return;
    }

    head_ = new Node(value);
    Node* tail = head_;
    size_ = 1;

    for (std::size_t i = 1; i < count; ++i) {
        Node* node = new Node(value);
        tail->next_ = node;
        tail = node;
        ++size_;
    }
}

ForwardList::ForwardList(std::initializer_list<int32_t> init) : head_(nullptr), size_(0) {
    Node* tail = nullptr;
    for (int32_t v : init) {
        Node* node = new Node(v);
        if (head_ == nullptr) {
            head_ = node;
            tail = node;
        } else {
            tail->next_ = node;
            tail = node;
        }
        ++size_;
    }
}

ForwardList& ForwardList::operator=(const ForwardList& rhs) {
    if (this == &rhs) {
        return *this;
    }

    Clear();
    CopyFrom(rhs);
    return *this;
}

ForwardList::~ForwardList() {
    Clear();
}

void ForwardList::PushFront(int32_t value) {
    Node* node = new Node(value);
    node->next_ = head_;
    head_ = node;
    ++size_;
}

void ForwardList::PopFront() {
    if (head_ == nullptr) {
        return;
    }
    Node* old_head = head_;
    head_ = head_->next_;
    delete old_head;
    --size_;
}

void ForwardList::Remove(int32_t value) {
    while (head_ != nullptr && head_->value_ == value) {
        Node* old_head = head_;
        head_ = head_->next_;
        delete old_head;
        --size_;
    }

    Node* current = head_;
    Node* previous = nullptr;

    while (current != nullptr) {
        if (current->value_ == value) {
            Node* to_delete = current;
            if (previous != nullptr) {
                previous->next_ = current->next_;
            }
            current = current->next_;
            delete to_delete;
            --size_;
        } else {
            previous = current;
            current = current->next_;
        }
    }
}

void ForwardList::Clear() {
    Node* current = head_;
    while (current != nullptr) {
        Node* next = current->next_;
        delete current;
        current = next;
    }
    head_ = nullptr;
    size_ = 0;
}

bool ForwardList::FindByValue(int32_t value) {
    Node* current = head_;
    while (current != nullptr) {
        if (current->value_ == value) {
            return true;
        }
        current = current->next_;
    }
    return false;
}

void ForwardList::Print(std::ostream& out) {
    Node* current = head_;
    bool first = true;
    while (current != nullptr) {
        if (!first) {
            out << ' ';
        }
        out << current->value_;
        first = false;
        current = current->next_;
    }
}

int32_t ForwardList::Front() const {
    return head_->value_;
}

std::size_t ForwardList::Size() const {
    return size_;
}

void ForwardList::CopyFrom(const ForwardList& rhs) {
    if (rhs.head_ == nullptr) {
        head_ = nullptr;
        size_ = 0;
        return;
    }

    head_ = new Node(rhs.head_->value_);
    Node* tail = head_;
    size_ = 1;

    Node* current_rhs = rhs.head_->next_;
    while (current_rhs != nullptr) {
        Node* node = new Node(current_rhs->value_);
        tail->next_ = node;
        tail = node;
        current_rhs = current_rhs->next_;
        ++size_;
    }
}