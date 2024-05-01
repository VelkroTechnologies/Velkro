#pragma once

#define VLK_DATA_DIR

#ifdef VLK_PLATFORM_LINUX
	#undef VLK_DATA_DIR
	#define VLK_DATA_DIR "data/"
#elif VLK_PLATFORM_WINDOWS
	#undef VLK_DATA_DIR
	#define VLK_DATA_DIR "../data/"
#endif