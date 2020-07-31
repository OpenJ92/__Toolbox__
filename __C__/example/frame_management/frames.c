#include "frames.h"

int alloc_frames(List* frames)
{
	int frame_number, *data;

	if (list_size(frames) == 0) { return -1; }
	else
	{
		if (list_remove_next(frames, NULL, (void **)&data) != 0)
		{
			return -1;
		}
		else
		{
			frame_number = *data;
			// There's a problem with trying to free a 
			// pointer that's not been allocated.
			// free(data);
		}
	}
	return frame_number;
}

int free_frame(List* frames, int frame_number)
{
	int* data;
	if ((data = (int*)malloc(sizeof(int))) == NULL){ return -1; }
	*data = frame_number;

	if (list_insert_next(frames, NULL, data) != 0){ return -1; }
	return 0;
}