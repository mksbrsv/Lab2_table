#ifndef TABLE_RECORD_H
#define TABLE_RECORD_H
template <class key, class value>
class table_element {
public:
	table_element() = default;
private:
	key m_key;
	value m_value;
};
#endif

