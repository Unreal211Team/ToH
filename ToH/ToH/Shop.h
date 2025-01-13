#pragma once

#include <vector>
#include "Item.h"
#include "Character.h"

class Shop
{
private:
	static Shop* instance;
	std::vector<Item*> avaliableItems;

	Shop();
	Shop(const Shop&) = delete;
	Shop& operator=(const Shop&) = delete;

public:
	static Shop* getInstance();
	void displayItems() const;
	void buyItem(int index, Character* player);
	void sellItem(int index, Character* player);
	~Shop();
};