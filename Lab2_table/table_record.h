#ifndef TABLE_RECORD_H
#define TABLE_RECORD_H
template <class Key, class Value>
class table_element {
public:
	table_element() = default;
	table_element(Key key, Value value) : m_key(key), m_value(std::move(value)) { }
	friend std::ostream& operator<<(std::ostream& out, table_element<Key, Value> tab) {
		out << tab.m_key << "\t" << tab.m_value;
		return out;
	}
	Key m_key;
	Value m_value;
	
};
#endif

