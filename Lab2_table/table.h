#ifndef TABLE_H
#define TABLE_H
#include "table_stuff.h"
template <class key, class value>
class table : public table_stuff<key, value>{
public:
	table();
	value& find(const key& key) const override;
	void insert(const key& key) override;
	void remove(const key& key) override;

};
#endif
