#ifndef TABLE_RECORD_H
#define TABLE_RECORD_H
template <class Key, class Value>
class table_element {
public:
	table_element() = default;
	table_element(Key key, Value value);
	Key m_key;
	Value m_value;
};

template <class Key, class Value>
table_element<Key, Value>::table_element(Key key, Value value) : m_key(key), m_value(value) { }
#endif

