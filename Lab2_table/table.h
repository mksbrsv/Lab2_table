#ifndef TABLE_H
#define TABLE_H
#include "table_stuff.h"
#include <initializer_list>
template <class Key, class Value>
class table : public table_stuff<Key, Value> {
	using table_stuff<Key, Value>::reset;
	using table_stuff<Key, Value>::is_end;
	using table_stuff<Key, Value>::next;
	using table_stuff<Key, Value>::m_table;
	using table_stuff<Key, Value>::m_current_position;
	using table_stuff<Key, Value>::m_count;
public:
	explicit table(size_t size);
	table(std::initializer_list<table_element<Key, Value>>);
	table(const table& table);
	table& operator=(const table& table);
	table(table&& table) noexcept;
	table& operator=(table&& table) noexcept;
	[[nodiscard]] Value& find(const Key& key) override;
	void insert(const Key& key, const Value& value) override;
	void insert(const Value& value) override;
	void insert(const std::vector<Value>& values) override;
	void insert(const std::initializer_list<Value>& values) override;
	void remove(const Key& key) override;
	friend std::ofstream& operator<<(std::ofstream& out, table<Key, Value> tab) {
		std::copy(tab.m_table.begin(), tab.m_table.end(), std::ostream_iterator<table_element<Key, Value>>(out, "\n"));
		return out;
	}
	friend std::ostream& operator<<(std::ostream& out, table<Key, Value> tab) {
		out << "Key\tValue\n";
		std::copy(tab.m_table.begin(), tab.m_table.end(), std::ostream_iterator<table_element<Key, Value>>(out, "\n"));
		out << "Size of table: " << tab.get_data_count() << " elements\n";
		return out;
	}
};

template <class Key, class Value>
table<Key, Value>::table(size_t size) : table_stuff<Key, Value>(size) {
}

template <class Key, class Value>
table<Key, Value>::table(std::initializer_list<table_element<Key, Value>> list) : table_stuff<Key, Value>(list.size()) {
	m_table = std::vector<table_element<Key, Value>>(list.begin(), list.end());
	m_count = m_table.size();
}

template <class Key, class Value>
table<Key, Value>::table(const table<Key, Value>& table) : table_stuff<Key, Value>(table) {
}

template <class Key, class Value>
table<Key, Value>& table<Key, Value>::operator=(const table<Key, Value>& table) {
	if (!this == &table) {
		m_count = table.m_count;
		m_table = table.m_table;
		reset();
		return *this;
	}
}

template <class Key, class Value>
table<Key, Value>::table(table&& table) noexcept : table_stuff<Key, Value>(table){
}

template <class Key, class Value>
table<Key, Value>& table<Key, Value>::operator=(table&& table) noexcept {
	std::swap(m_count, table.m_count);
	std::swap(m_table, table.m_table);
	std::swap(m_current_position, table.m_current_position);
	return *this;
}

template <class Key, class Value>
[[nodiscard]] Value& table<Key, Value>::find(const Key& key) {
	for (reset(); !is_end(); next()) {
		if (m_current_position->m_key == key)
			return m_current_position->m_value;
	}
	throw std::invalid_argument("This key doesn't exist");
}

template <class Key, class Value>
void table<Key, Value>::insert(const Key& key, const Value& value) {
	m_table.push_back(table_element<Key, Value>(key, value));
	++m_count;

}

template <class Key, class Value>
void table<Key, Value>::insert(const Value& value) {
	m_table.push_back(table_element<Key, Value>(static_cast<Key>(m_count + 1), value));
	++m_count;
	m_current_position = m_table.begin() + m_count;
}

template <class Key, class Value>
void table<Key, Value>::insert(const std::vector<Value>& values) {
	for(auto& x : values) {
		insert(x);
	}
}

template <class Key, class Value>
void table<Key, Value>::insert(const std::initializer_list<Value>& values) {
	for(auto& x : values) {
		insert(x);
	}
	m_current_position = m_table.begin() + values.size() - 1;
}

template <class Key, class Value>
void table<Key, Value>::remove(const Key& key) {
	int i = 0;
	for (reset(); !is_end(); next(), i++) {
		if (m_current_position->m_key == key) {
			m_table.erase(m_table.begin() + i);
			--m_count;
			break;
		}
	}
	reset();
}

#endif
