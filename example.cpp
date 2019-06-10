#include <iostream>
#include <openpnp-capture.h>
#include <opencv2/opencv.hpp>
#include <opencv2/highgui.hpp>

int main() {
	uint32_t deviceFormatID = 2;
	uint32_t deviceID = 0;
	Cap_setLogLevel(1);
	CapContext context;
	context = Cap_createContext();
	uint32_t deviceCount = Cap_getDeviceCount(context);
	printf("Number of devices: %d\n", deviceCount);
	for (int32_t i = 0; i < deviceCount; i++) {
		printf("ID %d -> %s\n", i, Cap_getDeviceName(context, i));
		printf("Unique:  %s\n", Cap_getDeviceUniqueID(context, i));
		// show all supported frame buffer formats
		int32_t nFormats = Cap_getNumFormats(context, i);
		printf("  Number of formats: %d\n", nFormats);
		std::string fourccString;
		for (int32_t j = 0; j < nFormats; j++)
		{
			CapFormatInfo finfo_;
			Cap_getFormatInfo(context, i, j, &finfo_);
			//fourccString = FourCCToString(finfo.fourcc);
			std::string fourcc;
			for (int i = 3; i >= 0; i--) {
				fourcc += (char)((finfo_.fourcc >> (8 * i)) & 0xff);
			}
			printf("  Format ID %d: %d x %d pixels  %d FPS(max)  FOURCC=%s\n",j, finfo_.width, finfo_.height, finfo_.fps, fourcc.c_str());
		}
	}
	CapResult result = Cap_releaseContext(context);
	cv::Mat image(320, 240, CV_8UC3, cv::Scalar(0,0,0));
	cv::imshow("test", image);
}
