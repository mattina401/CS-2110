#include "my_malloc.h"
#include "my_sbrk.c"
/*
Jongyeon Kim
*/

/* You *MUST* use this macro when calling my_sbrk to allocate the 
 * appropriate size. Failure to do so may result in an incorrect
 * grading!
 */
#define SBRK_SIZE 2048

/* If you want to use debugging printouts, it is HIGHLY recommended
 * to use this macro or something similar. If you produce output from
 * your code then you will receive a 20 point deduction. You have been
 * warned.
 */
#ifdef DEBUG
#define DEBUG_PRINT(x) printf x
#else
#define DEBUG_PRINT(x)
#endif

/* make sure this always points to the beginning of your current
 * heap space! if it does not, then the grader will not be able
 * to run correctly and you will receive 0 credit. remember that
 * only the _first_ call to my_malloc() returns the beginning of
 * the heap. sequential calls will return a pointer to the newly
 * added space!
 * Technically this should be declared static because we do not
 * want any program outside of this file to be able to access it
 * however, DO NOT CHANGE the way this variable is declared or
 * it will break the autograder.
 */
void* heap;

/* our freelist structure - this is where the current freelist of
 * blocks will be maintained. failure to maintain the list inside
 * of this structure will result in no credit, as the grader will
 * expect it to be maintained here.
 * Technically this should be declared static for the same reasons
 * as above, but DO NOT CHANGE the way this structure is declared
 * or it will break the autograder.
 */
metadata_t* freelist[8];

/**** SIZES FOR THE FREE LIST ****
 * freelist[0] -> 16
 * freelist[1] -> 32
 * freelist[2] -> 64
 * freelist[3] -> 128
 * freelist[4] -> 256
 * freelist[5] -> 512
 * freelist[6] -> 1024
 * freelist[7] -> 2048
 */




/*
get idx for freelist by size
*/
int getIdx(size_t size)
{
	int idx = 0;
	
	/*
	when size <= 16, idx is 0
	*/
	if (size <= 16)
	{
		idx = 0;
  	}
	/*
	when 16 < size <= 32, idx is 1
	*/
	else if (size > 16 && size <= 32)
	{
		idx = 1;
	}
	/*
	when 32 < size <= 64, idx is 2
	*/
	else if (size > 32 && size <= 64)
	{
		idx = 2;
	}
	/*
	when 64 < size <= 128, idx is 3
	*/
	else if (size > 64 && size <= 128)
	{
		idx = 3;
	}
	/*
	when 128 < size <= 256, idx is 4
	*/
	else if (size > 128 && size <= 256)
	{
		idx = 4;
	}
	/*
	when 256 < size <= 512, idx is 5
	*/
	else if (size > 256 && size <= 512)
	{
		idx = 5;
	}
	/*
	when 512 < size <= 1024, idx is 6
	*/
	else if (size > 512 && size <= 1024)
	{
		idx = 6;
	}
	/*
	when 1024 < size <= 2048, idx is 7
	*/
	else if (size > 1024 && size <= 2048)
	{
		idx = 7;
	}
	return idx;
}

/*
isolate node
*/
void isolate(metadata_t* prev, metadata_t* next, metadata_t* node)
{
	node -> next = NULL;
	node -> prev = NULL;
}

/*
delete node from freelist
*/
metadata_t* delete(metadata_t* node)
{	
	metadata_t* next = node->next;
	metadata_t* prev = node->prev;

	/*
	when node has both prev and next
	*/
	if ((prev != NULL) && (next != NULL))
	{
		prev->next = next;
		next->prev = prev;
		isolate(prev, next, node);
	}
	/*
	when node has only next
	*/
	else if ((prev != NULL) && (next== NULL))
	{
		prev->next = NULL;
		isolate(prev, next, node);
	}
	/*
	when node has only prev
	*/
	else if ((prev == NULL) && (next != NULL))
	{
		freelist[getIdx(node->size)] = next;
		next->prev = NULL;
		isolate(prev, next, node);
	}
	/*
	when node doenot have both prev and next
	*/
	else
	{
		freelist[getIdx(node->size)] = NULL;
		isolate(prev, next, node);
	}

	return node;
}

/*
add block to freelist
*/
void add(int idx, metadata_t* node)
{

	metadata_t *current = freelist[idx];

	/*
	when current is not null(already have block)
	*/
	if (current != NULL)
	{

		/*
		while current has next
		*/
		while(current -> next != NULL)
		{
			/*
			move to next
			*/
			current = current->next;
		}

		/*
		add node to last(tail)
		*/
		current->next = node;
		node->prev = current;
		node->next = NULL;
	}
	/*
	when current is null
	*/
	else
	{
		freelist[idx] = node;
	}

}


/*
helper method for divideTwo
*/
metadata_t* divideHelper(metadata_t *current)
{
	metadata_t *new = (metadata_t *) ((char *) current + current -> size);
	new -> in_use = 0;	
	new -> size = current -> size;
	new -> next = NULL;
	new -> prev = current;

	current -> next = new;
	current -> prev = NULL;
	
	return new;
}

/*
devide memory by two
*/
void divideTwo(int targetIdx, int currentIdx, metadata_t *current)
{
	int preIdx = currentIdx - 1;

	/*
	when targetidx is same current idx, return
	*/
	if (targetIdx == currentIdx)
	{
		return;
	}
	
	/*
	delete current
	*/
	delete(current);

	/*
	make current's size half
	*/
	current->size /= 2;
	add(preIdx, current);
	divideTwo(targetIdx, preIdx, divideHelper(current));
}

static int makeMergedBlock(metadata_t *block)
 
{
        metadata_t* buddy;
	metadata_t* new_block;

	
	/*
	get buddy
	*/
	long buddy_address = (long) block ^ (long) block->size;
	metadata_t* buddy1 = (metadata_t*) buddy_address;

	/*
	if block's size is same as buddy1's size
	*/
	if (block->size == buddy1->size)
	{
		buddy = buddy1;
	}
	else
	{
		buddy = NULL;
 	}
 
        if(buddy == NULL || buddy->in_use || block->size == SBRK_SIZE)
 
        {
 

	/*
	add to head
	*/
	size_t dataSize = block->size - sizeof(metadata_t);
	int listIdx = getIdx(dataSize);

        if(freelist[listIdx] != NULL)
 
        {
 
                block->next = freelist[listIdx];
 
                freelist[listIdx]->prev = block;
 
        }
 
        freelist[listIdx] = block;
 	return 0;
 
        }
 
        delete(buddy);
 
        /*
	the address of the new block is the address of whichever block has the smaller address
	*/
 
        new_block = (block < buddy) ? block : buddy;
        new_block->size = block->size * 2;
 
        makeMergedBlock(new_block);
 
        return 1;
 
}

/*
make new heap
*/
void makeNew(void)
{
	heap = my_sbrk(SBRK_SIZE);
	freelist[7] = (metadata_t *) heap;
	freelist[7]->size = SBRK_SIZE;
	freelist[7]->in_use = 0;
	freelist[7]->next = NULL;
	freelist[7]->prev = NULL;	
}


void* my_malloc(size_t size)
{
	int idx = 0;
	int nextIdx = 0;
	metadata_t *new_heap;
	metadata_t* block;

	
	/*
	we needs to add metadata_t's size to size
	*/
	size = sizeof(metadata_t) + size;

	/*
	if size (include metadata_t's size) is bigger than 2048
	*/
	if (size > SBRK_SIZE) 
	{
		ERRNO = SINGLE_REQUEST_TOO_LARGE;
		return NULL;
	}

	/*
	when heap doesnot have any blocks
	*/
	if (heap == NULL)
	{
		/*
		makenew heap
		*/
		makeNew();
		if (heap == NULL)
		{
			return NULL;
		}
	}

	idx = getIdx(size);

	/*
	when freelist is not null
	*/
	if (freelist[idx] != NULL)
	{
		metadata_t* block = delete(freelist[idx]);
		block->in_use = 1;

		ERRNO = NO_ERROR;
		return (void *)(((char *)block) + sizeof(metadata_t));
	}
	

	nextIdx = idx + 1;
	while ((freelist[nextIdx] == NULL) && (nextIdx < 9))
	{
		nextIdx++;
	}

	/*
	is next index is 8 (over index)
	*/
	if (nextIdx == 8)
	{
		void* heap_ptr = my_sbrk(SBRK_SIZE);

		if (heap_ptr == (void*) -1)
		{
			ERRNO = OUT_OF_MEMORY;
			return NULL;
		}

		new_heap = (metadata_t *) heap_ptr;

		new_heap->in_use = 0;
		new_heap->size = SBRK_SIZE;
		new_heap->next = NULL;
		new_heap->prev = NULL;

		add(7, new_heap);


		divideTwo(idx, 7, freelist[7]);

		block = delete(freelist[idx]);
		block->in_use = 1;

		ERRNO = NO_ERROR;
		return (void *)(((char *)block) + sizeof(metadata_t));
	}
	/*
	when nextIdx is smaller than 8(nextIdx < 8)
	*/
	else
	{

		divideTwo(idx, nextIdx, freelist[nextIdx]);
		block = delete(freelist[idx]);
		block->in_use = 1;

		ERRNO = NO_ERROR;
		return (void *)(((char *)block) + sizeof(metadata_t));
	}
}

void* my_calloc(size_t num, size_t size)
{

	/*
	call my_malloc
	*/
	char* returnA = my_malloc(num*size);
	int i;
	char* zero = returnA;

	/*
	if return address is null
	*/
	if (returnA == NULL)
	{
		ERRNO = SINGLE_REQUEST_TOO_LARGE;
		return NULL;
	}
	for(i =0; i < num*size; i++)
	{
		*zero = 0;
		zero++;
	}
  	return (void*) returnA;
}

void my_free(void* ptr)	
{

	/*
 	if pointer is null
	*/
        if(ptr == NULL)
	{
		return;
	}
 
        if(((char *)ptr < (char *)heap - sizeof(metadata_t)))
	{
		return;
 	}

        if(!((metadata_t *)ptr - 1)->in_use)
        {
  
                ERRNO = DOUBLE_FREE_DETECTED;
 
                return;
 
        }
 
        ((metadata_t *)ptr - 1)->in_use = 0;
 
        makeMergedBlock((metadata_t *)ptr - 1);
 
}

void* my_memmove(void* dest, const void* src, size_t num_bytes)
{
	char* destination = (char*) dest;
	char* source = (char*) src;
	int i;
	int k;

	/*
	when source is same with destination
	*/
	if(src == dest)
	{
		ERRNO = NO_ERROR;
    		return (void *)dest;
	}

	/*
	when source is bigger than destination
	*/
	if(src > dest)
	{
		for(i = 0; i < num_bytes; i++)
		{
			destination[i] = source[i];
		}
	}
	/*
	when source is smaller than destination
	*/
	else
	{
		for(k = 0; k < num_bytes; k++)
		{
			destination[(num_bytes-1)-k] = source[(num_bytes-1)-k]; 
		}
	}

	ERRNO = NO_ERROR;
    	return (void *)dest;
}
