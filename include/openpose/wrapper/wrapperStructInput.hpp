#ifndef OPENPOSE__WRAPPER__WRAPPER_STRUCT_INPUT_HPP
#define OPENPOSE__WRAPPER__WRAPPER_STRUCT_INPUT_HPP

#include <memory>
#include <openpose/producer/producer.hpp>

namespace op
{
    /**
     * WrapperStructInput: Input (images, video, webcam, etc.) configuration struct.
     * WrapperStructInput allows the user to set up the input frames generator.
     */
    struct WrapperStructInput
    {
        /**
         * Producer which will generate the frames.
         * Set to nullptr to disable the whole input, i.e. if the user is going to use his own frames generator.
         */
        std::shared_ptr<Producer> producerSharedPtr;

        /**
         * First image to obtain.
         * Default: 0.
         */
        unsigned long long frameFirst;

        /**
         * Last image to obtain.
         * Default: -1 (i.e. obtain all frames).
         */
        unsigned long long frameLast;

        /**
         * Whether to skip or sleep in order to keep the same FPS as the frames producer.
         */
        bool realTimeProcessing;

        /**
         * Whether to flip (mirror) the image.
         */
        bool frameFlip;

        /**
         * Image rotation.
         * Only 4 possible values: 0 (default, no rotation), 90, 180 or 270 degrees
         */
        int frameRotate;

        /**
         * Whether to re-open the producer if it reaches the end (e.g. video or image directory after the last frame).
         */
        bool framesRepeat;

        /**
         * Constructor of the struct.
         * It has the recommended and default values we recommend for each element of the struct.
         * Since all the elements of the struct are public, they can also be manually filled.
         */
        WrapperStructInput(const std::shared_ptr<Producer> producerSharedPtr = nullptr, const unsigned long long frameFirst = 0,
                           const unsigned long long frameLast = -1, const bool realTimeProcessing = false, const bool frameFlip = false,
                           const int frameRotate = 0, const bool framesRepeat = false);
    };
}

#endif // OPENPOSE__WRAPPER__WRAPPER_STRUCT_INPUT_HPP
