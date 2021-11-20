#pragma once

#include "darray.h"

template <typename K, typename V> class dictionary
{
private:
	darray<K> keys_;
	darray<V> values_;

	bool DoesKeyAlreadyExist(K key)
	{
		if (keys_.Find(key) == nullptr)
		{
			return false;
		}
		return true;
	}

	int IndexOf(K key)
	{
		if (keys_.Find(key) != nullptr)
		{
			for (int i = 0; i < keys_.Length(); i++)
			{
				if (*keys_.Get(i) == key)
				{
					return i;
				}
			}
		}
		return -1;
	}
public:
	bool Insert(K key, V value)
	{
		if (!DoesKeyAlreadyExist(key))
		{
			keys_.Push(key);
			values_.Push(value);
			return true;
		}
		return false;
	}

	V* Get(K key)
	{
		int keyIndex = IndexOf(key);
		if (keyIndex >= 0)
		{
			return values_.Get(keyIndex);
		}
		return nullptr;
	}
};
