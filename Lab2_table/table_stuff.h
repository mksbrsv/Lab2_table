#ifndef TABLE_STUFF_H
#define TABLE_STUFF_H
#include "table_org.h"
#include "table_record.h"
#include <vector>
template <class Key, class Value>
class table_stuff : public table_org<Key, Value> {
public:
	table_stuff(size_t size);
	bool is_empty() override;
	bool is_full() override;
	[[nodiscard]] size_t get_data_count() override;
	[[nodiscard]] const Key& get_key() const override;
	[[nodiscard]] Value& get_value() const override;
	void reset() override;
	[[nodiscard]] bool is_end() const override;
	void next() override;
protected:
	size_t m_count;
	std::vector<table_element<Key, Value>> m_table;
	typename std::vector<table_element<Key, Value>>::iterator m_current_position;
};

template <class Key, class Value>
table_stuff<Key, Value>::table_stuff(size_t size) : m_count(0) {
	m_table.reserve(size);
	m_current_position = m_table.begin();
}

template <class Key, class Value>
bool table_stuff<Key, Value>::is_empty() {
	return m_table.size() == 0;
}

template <class Key, class Value>
bool table_stuff<Key, Value>::is_full() {
	return m_table.size() == m_count;
}

template <class Key, class Value>
size_t table_stuff<Key, Value>::get_data_count() {
	return m_count;
}

template <class Key, class Value>
[[nodiscard]] auto table_stuff<Key, Value>::get_key() const -> const Key&{
	return m_current_position->m_key;
}

template <class Key, class Value>
[[nodiscard]] auto table_stuff<Key, Value>::get_value() const -> Value& {
	return m_current_position->m_value;
}

template <class Key, class Value>
void table_stuff<Key, Value>::reset() {
	m_current_position = m_table.begin();
}

template <class Key, class Value>
[[nodiscard]] auto table_stuff<Key, Value>::is_end() const -> bool {
	return m_current_position == m_table.end() - 1;
}

template <class Key, class Value>
void table_stuff<Key, Value>::next() {
	if (!is_end())
		++m_current_position;
	else
		std::cerr << "Table is full";
}

#endif
