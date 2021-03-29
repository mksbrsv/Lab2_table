#ifndef TABLE_ORG_H
#define TABLE_ORG_H
#include "data_value.h"
#include <iostream>
#include <vector>
#include <initializer_list>
template <class Key, class Value>
class table_org {
protected:
	virtual bool is_empty() = 0;
	virtual bool is_full() = 0;
	virtual size_t get_data_count() = 0;
	virtual const Key& get_key() const = 0;
	virtual Value& get_value() const = 0;
	virtual std::pair<bool, Value> find(const Key& key) = 0;
	virtual void insert(const Key& key, const Value& value) = 0;
	virtual void insert(const Value& value) = 0;
	virtual void insert(const std::vector<Value>& values) = 0;
	virtual void insert(const std::initializer_list<Value>& values) = 0;
	virtual bool remove(const Key& key) = 0;
	virtual void reset() = 0;
	virtual bool is_end() const = 0;
	virtual	void next() = 0;
	virtual ~table_org() = default;

};

#endif

