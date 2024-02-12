#ifndef ASLIST_H
#define ASLIST_H

#include "ItemType.h"

class ASList
{
public:
	ASList();
	~ASList();

	void MakeEmpty();
	bool IsFull() const;
	ItemType GetItem(ItemType item, bool& found);
	void PutItem(ItemType item);
	void DeleteItem(ItemType item);
	void ResetList();
	ItemType GetNextItem();

private:
	ItemType Items[MAX_ITEMS];
	int length;
	int loc;

	int findItem(ItemType item);
};

#endif // !ASLIST_H

