#ifndef TABLE_H
#define TABLE_H
#include "table_stuff.h"
template <class Key, class Value>
class table : public table_stuff<Key, Value> {
public:
	table(size_t size);
	Value& find(const Key& key) const override;
	void insert(const Key& key, const Value& value) override;
	void remove(const Key& key) override;
};

template <class Key, class Value>
table<Key, Value>::table(size_t size) : table_stuff<Key, Value>(size) {
}

template <class Key, class Value>
Value& table<Key, Value>::find(const Key& key) const {
	
}

template <class Key, class Value>
void table<Key, Value>::insert(const Key& key, const Value& value) {
	m_table.push_back(table_element<Key, Value>(key, value));
}

template <class Key, class Value>
void table<Key, Value>::remove(const Key& key) {
}

#endif
