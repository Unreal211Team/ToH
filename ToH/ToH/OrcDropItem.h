#pragma once

#include "Item.h"

class OrcDropItem : public Item
{
private:
	const std::string name;
	const bool canUsing;
	const int price;

public:
	OrcDropItem(std::string name = "�μ��� ��ũ�� ��ġ", bool canUsing = false, int price = 200);
	std::string getName() const override;
	bool canUse() const override;
	void use(Character* character) const override;
	int getPrice() const override;
};