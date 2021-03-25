#ifndef TABLE_STUFF_H
#define TABLE_STUFF_H
#include "table_org.h"
#include "table_record.h"
#include <vector>
template <class key, class value>
class table_stuff : public table_org<key, value> {
public:
	table_stuff();
	bool is_empty() override;
	bool is_full() override;
	const key& get_key() const override;
	value& get_value() const override;
	void reset() override;
	bool is_end() const override;
	void next() override;
protected:
	std::vector<table_element<key, value>> m_table;
	typename std::vector<table_element<key, value>>::iterator m_current_position;

};
#endif
