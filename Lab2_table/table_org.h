#ifndef TABLE_ORG_H
#define TABLE_ORG_H
#include "data_value.h"
template <class key, class value>
class table_org {
protected:
	virtual bool is_empty() = 0;
	virtual bool is_full() = 0;
	virtual size_t get_data_count() = 0;
	virtual const key& get_key() const = 0;
	virtual value& get_value() const = 0;
	virtual const value& find(const key& key) const = 0;
	virtual void insert(const key& key) = 0;
	virtual void remove(const key& key) = 0;
	virtual void reset() = 0;
	virtual bool is_end() const = 0;
	virtual	void next() = 0;
	virtual ~table_org() = default;

};
#endif

