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

int main(int argc, char* argv[])
{
	List* list;
	if ((list = (List*)malloc(sizeof(List))) == NULL){ return -1; }
	list_init(list, NULL);

	int frames[10];

	for (int node = 0; node < 10; node++)
	{
		frames[node] = node;
		list_insert_next(list, NULL, &frames[node]);
	}

	for (int node = 0; node < 10; node++)
	{
		int frame = (int)alloc_frames(list);
		printf("Recieved frame: %i\n", frame);
	}
}
