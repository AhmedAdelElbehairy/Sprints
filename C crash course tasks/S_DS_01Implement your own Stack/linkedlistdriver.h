#ifndef LINKEDLISTDRIVER_H
	#define LINKEDLISTDRIVER_H
	#define END_NODE -1
	#define START_NODE 1
	struct Node{
		uint8_t data;
		struct Node* link;
	};
	typedef enum isEmpty
		{
			EMPTY,
			NOTEMPTY
		}isEmpty;

	uint8_t getValue (struct Node* head, uint32_t index);

	void Insert(struct Node** head, uint8_t data, uint32_t index);

	void Delete(struct Node** head, uint32_t index);

	void print(struct Node* head);

	void UnitTestLinkedListDriver(void);

#endif // LINKEDLISTDRIVER_H
