#pragma once

#define VLK_ASSETS_DIR

#ifdef VLK_PLATFORM_LINUX
	#undef VLK_ASSETS_DIR
	#define VLK_ASSETS_DIR std::string("assets/")
#elif VLK_PLATFORM_WINDOWS
	#undef VLK_ASSETS_DIR
	#define VLK_ASSETS_DIR std::string("../assets/")
#endif