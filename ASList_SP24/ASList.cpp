#include "ASList.h"

ASList::ASList()
{
	length = 0;
	loc = -1;
}

ASList::~ASList()
{
}

void ASList::MakeEmpty()
{
	length = 0;
}

bool ASList::IsFull() const
{
	if(length == MAX_ITEMS)
		return true;
	else
		return false;
}

ItemType ASList::GetItem(ItemType item, bool& found)
{
	found = false;
	
	int index = findItem(item);

	if (index != -1)
	{
		found = true;
		return Items[index];
	}
	else
		return item;
}

void ASList::PutItem(ItemType item)
{
	Items[length] = item;
	length++;
}

void ASList::DeleteItem(ItemType item)
{
	int index = findItem(item);
	if(index != -1)
	{
		while(index < length - 1)
		{
			Items[index] = Items[index + 1];
			index++;
		}
		length--;
	}
}

void ASList::ResetList()
{
	loc = -1;
}

ItemType ASList::GetNextItem()
{
	loc++;
	return Items[loc];
}

int ASList::findItem(ItemType item)
{
	int i = length / 2;
	int unsortedSize = length;
	while (unsortedSize > 0)
	{
		if (Items[i].compareTo(item) == RelationType::LESS)
		{
			i = i + (unsortedSize / 2);
			unsortedSize = unsortedSize / 2;
		}
		else if (Items[i].compareTo(item) == RelationType::GREATER)
		{
			i = i / 2;
			unsortedSize = unsortedSize / 2;
		}
	}
	if (Items[i].compareTo(item) == RelationType::GREATER)
	{
		return -1;
	}
	else
		return i;
}
