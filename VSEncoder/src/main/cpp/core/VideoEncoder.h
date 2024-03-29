//
// Created by chao.ma on 6/28/21.
//

#ifndef AVPROJECT_VIDEOENCODER_H
#define AVPROJECT_VIDEOENCODER_H
#include <inttypes.h>
#include <jni.h>
#include <x264.h>
#include "JavaCallHelper.h"

class VideoEncoder {

public:
    VideoEncoder();
    ~VideoEncoder();

    void initEncoder(int width, int height, int fps, int bitrate, int bFrame, int iFrameInterval, int level_idc, const char *profileIdc);

    void start();

    void encodeData(int8_t *data);
private:
    int mWidth;
    int mHeight;
    int mFps;
    int mBitrate;

    int mYSize;
    int mUVSize;

    // x264 编码器
    x264_t *videoCodec = 0;

    x264_picture_t *pic_in = 0;
    //x264 参数
    x264_param_t param;
public:
    JavaCallHelper *javaHelper = 0;
};
#endif //AVPROJECT_VIDEOENCODER_H
