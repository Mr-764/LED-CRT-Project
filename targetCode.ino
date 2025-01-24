#include <FastLED.h>

#define NUM_LEDS 256
#define DATA_PIN 12

CRGB leds[NUM_LEDS];  // Array to store LED colors

// Store LED indices in PROGMEM to save SRAM

// the python code im using to make each frame

//def process_array(arr):
    //# Define the add and subtract ranges
    //range_add = [(0, 15), (32, 47), (64, 79), (96, 111), (128, 143), (160, 175), (192, 207), (224, 239)]
    //range_sub = [(16, 31), (48, 63), (80, 95), (112, 127), (144, 159), (176, 191), (208, 223), (240, 255)]

    //result = []
    
    //# Process each number in the array
    //for num in arr:
        //# Check if number is in the add range
        //for low, high in range_add:
            //if low <= num <= high:
                //num -= 1  # Add 1
                //# Check if the new number is still within the add range
                //if any(low <= num <= high for low, high in range_add):
                    //result.append(num)  # Append if valid
                //break
        //else:
            //# Check if number is in the subtract range
            //for low, high in range_sub:
                //if low <= num <= high:
                    //num += 1  # Subtract 1
                    //# Check if the new number is still within the subtract range
                    //if any(low <= num <= high for low, high in range_sub):
                        //result.append(num)  # Append if valid
                    //break
    
    //return result

//# Example usage
//input_array = [32, 127, 128, 159]

//output_array = process_array(input_array)
//print(output_array)


//background
const uint8_t yellowBackgroundLEDs[] PROGMEM = {64, 65, 66, 67, 68, 69, 70, 71, 72, 73, 74, 75, 76, 77, 78, 79, 80, 81, 82, 83, 84, 85, 86, 87, 88, 89, 90, 91, 92, 93, 94, 95, 96, 97, 98, 99, 100, 101, 102, 103, 104, 105, 106, 107, 108, 109, 110, 111, 112, 113, 114, 115, 116, 117, 118, 119, 120, 121, 122, 123, 124, 125, 126, 127, 128, 129, 130, 131, 132, 133, 134, 135, 136, 137, 138, 139, 140, 141, 142, 143, 144, 145, 146, 147, 148, 149, 150, 151, 152, 153, 154, 155, 156, 157, 158, 159, 160, 161, 162, 163, 164, 165, 166, 167, 168, 169, 170, 171, 172, 173, 174, 175, 176, 177, 178, 179, 180, 181, 182, 183, 184, 185, 186, 187, 188, 189, 190, 191, 192, 193, 194, 195, 196, 197, 198, 199, 200, 201, 202, 203, 204, 205, 206, 207, 208, 209, 210, 211, 212, 213, 214, 215, 216, 217, 218, 219, 220, 221, 222, 223, 224, 225, 226, 227, 228, 229, 230, 231, 232, 233, 234, 235, 236, 237, 238, 239, 240, 241, 242, 243, 244, 245, 246, 247, 248, 249, 250, 251, 252, 253, 254, 255};  //
const uint8_t greenBackgroundLEDs[] PROGMEM = {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36,37,38,39,40,41,42,43,44,45,46,47,48,49,50,51,52,53,54,55,56,57,58,59,60,61,62,63};

//green hills and yellow cloud LEDs
const uint8_t greenHillLEDs[] PROGMEM = {251,228,219,196,132,133,191,68,69,59};  // First 9 LED

//frame1
const uint8_t darkGreyLogoLEDs[] PROGMEM = {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,31,32,47,48,55,59,61,63,64,66,67,72,79,80,85,86,87,91,93,95,96,111,112,116,117,118,121,123,127,128,132,134,138,143,144,148,149,150,154,159,160,175,176,178,184,189,190,191,192,194,199,200,201,205,207,208,209,210,214,215,216,220,221,223,224,239,240,241,242,243,244,245,246,247,248,249,250,251,252,253,254,255};  // dark grey Leds for frame 1
const uint8_t lightGreyLogoLEDs[] PROGMEM = {46,51,56,58,69,71,76,82,83,84,89,113,114,115,120,124,126,129,130,131,135,140,142,145,146,147,151,152,156,157,158,179,180,181,185,186,187,196,198,202,203,211,212,213,217,219}; //light grey leds for frame 1
const uint8_t redLogoLEDs[] PROGMEM = {17,21,23,30,33,35};  // red logo leds for frame 1
const uint8_t tanLogoLEDs[] PROGMEM = {39,40};  // First 9 LEDs
const uint8_t yellowLogoLEDs[] PROGMEM = {37,42};  // First 9 LEDs
const uint8_t greenLogoLEDs[] PROGMEM = {19,24,26,28,44,};  // First 9 LEDs
const uint8_t blackLogoLEDs[] PROGMEM = {18,20,22,25,27,29,34,36,38,41,43,45,49,50,52,53,54,57,60,62,65,68,70,73,74,75,77,78,81,88,90,92,94,97,98,99,100,101,102,103,104,105,106,107,108,109,110,119,122,125,133,136,137,139,141,153,155,161,162,163,164,165,166,167,168,169,170,171,172,173,174,177,182,183,188,193,195,197,204,206,218,222,225,226,227,228,229,230,231,232,233,234,235,236,237,238};  // black leds for frame 1

//frame2
const uint8_t darkGreyLogoLEDs2[] PROGMEM = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,30,33,54,58,60,62,65,67,68,73,84,85,86,90,92,94,97,115,116,117,120,122,126,129,133,135,139,147,148,149,153,158,161,177,183,188,189,190,193,195,200,201,202,206,208,209,213,214,215,219,220,222,225,240,241,242,243,244,245,246,247,248,249,250,251,252,253,254};  // First 9 LEDs
const uint8_t lightGreyLogoLEDs2[] PROGMEM = {47,50,55,57,70,72,77,81,82,83,88,112,113,114,119,123,125,130,131,132,136,141,143,144,145,146,150,151,155,156,157,178,179,180,184,185,186,197,199,203,204,210,211,212,216,218};  // First 9 LEDs
const uint8_t redLogoLEDs2[] PROGMEM = {16, 20, 22, 29, 34, 36};  // First 9 LEDs
const uint8_t tanLogoLEDs2[] PROGMEM = {40,41};  // First 9 LEDs
const uint8_t yellowLogoLEDs2[] PROGMEM = {38, 43};  // First 9 LEDs
const uint8_t greenLogoLEDs2[] PROGMEM = {18, 23, 25, 27, 45};  // First 9 LEDs
const uint8_t blackLogoLEDs2[] PROGMEM = {17, 19, 21, 24, 26, 28, 35, 37, 39, 42, 44, 46, 48, 49, 51, 52, 53, 56, 59, 61, 66, 69, 71, 74, 75, 76, 78, 79, 80, 87, 89, 91, 93, 98, 99, 100, 101, 102, 103, 104, 105, 106, 107, 108, 109, 110, 111, 118, 121, 124, 134, 137, 138, 140, 142, 152, 154, 162, 163, 164, 165, 166, 167, 168, 169, 170, 171, 172, 173, 174, 175, 176, 181, 182, 187, 194, 196, 198, 205, 207, 217, 221, 226, 227, 228, 229, 230, 231, 232, 233, 234, 235, 236, 237, 238, 239};  // First 9 LEDs

const uint8_t blackMarioLEDs2[] PROGMEM = {31,32};  // First 9 LEDs


//frame 3

const uint8_t darkGreyLogoLEDs3[] PROGMEM = {2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 29, 34, 53, 57, 59, 61, 66, 68, 69, 74, 83, 84, 85, 89, 91, 93, 98, 114, 115, 116, 119, 121, 125, 130, 134, 136, 140, 146, 147, 148, 152, 157, 162, 176, 182, 187, 188, 189, 194, 196, 201, 202, 203, 207, 208, 212, 213, 214, 218, 219, 221, 226, 240, 241, 242, 243, 244, 245, 246, 247, 248, 249, 250, 251, 252, 253};  // First 9 LEDs
const uint8_t lightGreyLogoLEDs3[] PROGMEM = {49, 54, 56, 71, 73, 78, 80, 81, 82, 87, 112, 113, 118, 122, 124, 131, 132, 133, 137, 142, 144, 145, 149, 150, 154, 155, 156, 177, 178, 179, 183, 184, 185, 198, 200, 204, 205, 209, 210, 211, 215, 217};  // First 9 LEDs
const uint8_t redLogoLEDs3[] PROGMEM = {19, 21, 28, 35, 37};  // First 9 LEDs
const uint8_t tanLogoLEDs3[] PROGMEM = {41, 42};  // First 9 LEDs
const uint8_t yellowLogoLEDs3[] PROGMEM = {39, 44};  // First 9 LEDs
const uint8_t greenLogoLEDs3[] PROGMEM = {17, 22, 24, 26, 46};  // First 9 LEDs
const uint8_t blackLogoLEDs3[] PROGMEM = {16, 18, 20, 23, 25, 27, 36, 38, 40, 43, 45, 47, 48, 50, 51, 52, 55, 58, 60, 67, 70, 72, 75, 76, 77, 79, 86, 88, 90, 92, 99, 100, 101, 102, 103, 104, 105, 106, 107, 108, 109, 110, 111, 117, 120, 123, 135, 138, 139, 141, 143, 151, 153, 163, 164, 165, 166, 167, 168, 169, 170, 171, 172, 173, 174, 175, 180, 181, 186, 195, 197, 199, 206, 216, 220, 227, 228, 229, 230, 231, 232, 233, 234, 235, 236, 237, 238, 239};  // First 9 LEDs

const uint8_t blackMarioLEDs3[] PROGMEM = {30, 33,0,31,32,63};  // First 9 LEDs

//frame 4

const uint8_t darkGreyLogoLEDs4[] PROGMEM = {3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 28, 35, 52, 56, 58, 60, 67, 69, 70, 75, 82, 83, 84, 88, 90, 92, 99, 113, 114, 115, 118, 120, 124, 131, 135, 137, 141, 145, 146, 147, 151, 156, 163, 181, 186, 187, 188, 195, 197, 202, 203, 204, 211, 212, 213, 217, 218, 220, 227, 240, 241, 242, 243, 244, 245, 246, 247, 248, 249, 250, 251, 252};  // First 9 LEDs
const uint8_t lightGreyLogoLEDs4[] PROGMEM = {48, 53, 55, 72, 74, 79, 80, 81, 86, 112, 117, 121, 123, 132, 133, 134, 138, 143, 144, 148, 149, 153, 154, 155, 176, 177, 178, 182, 183, 184, 199, 201, 205, 206, 208, 209, 210, 214, 216};  // First 9 LEDs
const uint8_t redLogoLEDs4[] PROGMEM = {18, 20, 27, 36, 38};  // First 9 LEDs
const uint8_t tanLogoLEDs4[] PROGMEM = {42, 43};  // First 9 LEDs
const uint8_t yellowLogoLEDs4[] PROGMEM = {40, 45};  // First 9 LEDs
const uint8_t greenLogoLEDs4[] PROGMEM = {16, 21, 23, 25, 47};  // First 9 LEDs
const uint8_t blackLogoLEDs4[] PROGMEM = {17, 19, 22, 24, 26, 37, 39, 41, 44, 46, 49, 50, 51, 54, 57, 59, 68, 71, 73, 76, 77, 78, 85, 87, 89, 91, 100, 101, 102, 103, 104, 105, 106, 107, 108, 109, 110, 111, 116, 119, 122, 136, 139, 140, 142, 150, 152, 164, 165, 166, 167, 168, 169, 170, 171, 172, 173, 174, 175, 179, 180, 185, 196, 198, 200, 207, 215, 219, 228, 229, 230, 231, 232, 233, 234, 235, 236, 237, 238, 239};  // First 9 LEDs

const uint8_t blackMarioLEDs4[] PROGMEM = {29, 34, 1, 30, 33, 62,31,32,178,128,159,191};  // First 9 LEDs

//frame 5
const uint8_t darkGreyLogoLEDs5[] PROGMEM = {4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 27, 36, 51, 55, 57, 59, 68, 70, 71, 76, 81, 82, 83, 87, 89, 91, 100, 112, 113, 114, 117, 119, 123, 132, 136, 138, 142, 144, 145, 146, 150, 155, 164, 180, 185, 186, 187, 196, 198, 203, 204, 205, 210, 211, 212, 216, 217, 219, 228, 240, 241, 242, 243, 244, 245, 246, 247, 248, 249, 250, 251};  // First 9 LEDs
const uint8_t lightGreyLogoLEDs5[] PROGMEM = {52, 54, 73, 75, 80, 85, 116, 120, 122, 133, 134, 135, 139, 147, 148, 152, 153, 154, 176, 177, 181, 182, 183, 200, 202, 206, 207, 208, 209, 213, 215};  // First 9 LEDs
const uint8_t redLogoLEDs5[] PROGMEM = {17, 19, 26, 37, 39};  // First 9 LEDs
const uint8_t tanLogoLEDs5[] PROGMEM = {43, 44};  // First 9 LEDs
const uint8_t yellowLogoLEDs5[] PROGMEM = {41, 46};  // First 9 LEDs
const uint8_t greenLogoLEDs5[] PROGMEM = {20, 22, 24};  // First 9 LEDs
const uint8_t blackLogoLEDs5[] PROGMEM = {16, 18, 21, 23, 25, 38, 40, 42, 45, 47, 48, 49, 50, 53, 56, 58, 69, 72, 74, 77, 78, 79, 84, 86, 88, 90, 101, 102, 103, 104, 105, 106, 107, 108, 109, 110, 111, 115, 118, 121, 137, 140, 141, 143, 149, 151, 165, 166, 167, 168, 169, 170, 171, 172, 173, 174, 175, 178, 179, 184, 197, 199, 201, 214, 218, 229, 230, 231, 232, 233, 234, 235, 236, 237, 238, 239};  // First 9 LEDs

const uint8_t blackMarioLEDs5[] PROGMEM = {28, 35, 2, 29, 34, 61, 30, 33, 177, 129, 158, 190,160,192,127};  // First 9 LEDs
const uint8_t redMarioLEDs5[] PROGMEM = {191,32,31};  // First 9 LEDs
const uint8_t tanMarioLEDs5[] PROGMEM = {128,159};  // First 9 LEDs

//frame 6
const uint8_t darkGreyLogoLEDs6[] PROGMEM = {5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 26, 37, 50, 54, 56, 58, 69, 71, 72, 77, 80, 81, 82, 86, 88, 90, 101, 112, 113, 116, 118, 122, 133, 137, 139, 143, 144, 145, 149, 154, 165, 179, 184, 185, 186, 197, 199, 204, 205, 206, 209, 210, 211, 215, 216, 218, 229, 240, 241, 242, 243, 244, 245, 246, 247, 248, 249, 250};  // First 9 LEDs
const uint8_t lightGreyLogoLEDs6[] PROGMEM = {51, 53, 74, 76, 84, 115, 119, 121, 134, 135, 136, 140, 146, 147, 151, 152, 153, 176, 180, 181, 182, 201, 203, 207, 208, 212, 214};  // First 9 LEDs
const uint8_t redLogoLEDs6[] PROGMEM = {16, 18, 25, 38, 40};  // First 9 LEDs
const uint8_t tanLogoLEDs6[] PROGMEM = {44, 45};  // First 9 LEDs
const uint8_t yellowLogoLEDs6[] PROGMEM = {42, 47};  // First 9 LEDs
const uint8_t greenLogoLEDs6[] PROGMEM = {19, 21, 23};  // First 9 LEDs
const uint8_t blackLogoLEDs6[] PROGMEM = {17, 20, 22, 24, 39, 41, 43, 46, 48, 49, 52, 55, 57, 70, 73, 75, 78, 79, 83, 85, 87, 89, 102, 103, 104, 105, 106, 107, 108, 109, 110, 111, 114, 117, 120, 138, 141, 142, 148, 150, 166, 167, 168, 169, 170, 171, 172, 173, 174, 175, 177, 178, 183, 198, 200, 202, 213, 217, 230, 231, 232, 233, 234, 235, 236, 237, 238, 239};  // First 9 LEDs

const uint8_t blackMarioLEDs6[] PROGMEM = {27, 36, 3, 28, 35, 60, 29, 34, 176, 130, 157, 189, 161, 193, 126,192,160,126,96,63,64,127};  // First 9 LEDs
const uint8_t redMarioLEDs6[] PROGMEM = {190, 33, 30,191,31,32};  // First 9 LEDs
const uint8_t tanMarioLEDs6[] PROGMEM = {129, 158,128,159};  // First 9 LEDs

//frame 7
const uint8_t darkGreyLogoLEDs7[] PROGMEM = {6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 25, 38, 49, 53, 55, 57, 70, 72, 73, 78, 80, 81, 85, 87, 89, 102, 112, 115, 117, 121, 134, 138, 140, 144, 148, 153, 166, 178, 183, 184, 185, 198, 200, 205, 206, 207, 208, 209, 210, 214, 215, 217, 230, 240, 241, 242, 243, 244, 245, 246, 247, 248, 249};  // First 9 LEDs
const uint8_t lightGreyLogoLEDs7[] PROGMEM = {50, 52, 75, 77, 83, 114, 118, 120, 135, 136, 137, 141, 145, 146, 150, 151, 152, 179, 180, 181, 202, 204, 211, 213};  // First 9 LEDs
const uint8_t redLogoLEDs7[] PROGMEM = {17, 24, 39, 41};  // First 9 LEDs
const uint8_t tanLogoLEDs7[] PROGMEM = {45, 46};  // First 9 LEDs
const uint8_t yellowLogoLEDs7[] PROGMEM = {43};  // First 9 LEDs
const uint8_t greenLogoLEDs7[] PROGMEM = {18, 20, 22};  // First 9 LEDs
const uint8_t blackLogoLEDs7[] PROGMEM = {16, 19, 21, 23, 40, 42, 44, 47, 48, 51, 54, 56, 71, 74, 76, 79, 82, 84, 86, 88, 103, 104, 105, 106, 107, 108, 109, 110, 111, 113, 116, 119, 139, 142, 143, 147, 149, 167, 168, 169, 170, 171, 172, 173, 174, 175, 176, 177, 182, 199, 201, 203, 212, 216, 231, 232, 233, 234, 235, 236, 237, 238, 239};  // First 9 LEDs

const uint8_t blackMarioLEDs7[] PROGMEM = {26, 37, 4, 27, 36, 59, 28, 35, 131, 156, 188, 162, 194, 125, 193, 161, 125, 97, 62, 65,63,95,127,160,223,126};  // First 9 LEDs
const uint8_t redMarioLEDs7[] PROGMEM = {189, 34, 29, 190, 30, 33,31,32,64,191,192};  // First 9 LEDs
const uint8_t tanMarioLEDs7[] PROGMEM = {130, 157, 129, 158,128,159,96};  // First 9 LEDs

//frame 8

const uint8_t darkGreyLogoLEDs8[] PROGMEM = {7, 8, 9, 10, 11, 12, 13, 14, 15, 24, 39, 48, 52, 54, 56, 71, 73, 74, 79, 80, 84, 86, 88, 103, 114, 116, 120, 135, 139, 141, 147, 152, 167, 177, 182, 183, 184, 199, 201, 206, 207, 208, 209, 213, 214, 216, 231, 240, 241, 242, 243, 244, 245, 246, 247, 248};  // First 9 LEDs
const uint8_t lightGreyLogoLEDs8[] PROGMEM = {49, 51, 76, 78, 82, 113, 117, 119, 136, 137, 138, 142, 144, 145, 149, 150, 151, 178, 179, 180, 203, 205, 210, 212};  // First 9 LEDs
const uint8_t redLogoLEDs8[] PROGMEM = {16, 23, 40, 42};  // First 9 LEDs
const uint8_t tanLogoLEDs8[] PROGMEM = {46, 47};  // First 9 LEDs
const uint8_t yellowLogoLEDs8[] PROGMEM = {44};  // First 9 LEDs
const uint8_t greenLogoLEDs8[] PROGMEM = {17, 19, 21};  // First 9 LEDs
const uint8_t blackLogoLEDs8[] PROGMEM = {18, 20, 22, 41, 43, 45, 50, 53, 55, 72, 75, 77, 81, 83, 85, 87, 104, 105, 106, 107, 108, 109, 110, 111, 112, 115, 118, 140, 143, 146, 148, 168, 169, 170, 171, 172, 173, 174, 175, 176, 181, 200, 202, 204, 211, 215, 232, 233, 234, 235, 236, 237, 238, 239};  // First 9 LEDs

const uint8_t blackMarioLEDs8[] PROGMEM = {25, 38, 5, 26, 37, 58, 27, 36, 132, 155, 187, 163, 195, 124, 194, 162, 124, 98, 61, 66, 62, 94, 126, 161, 222,63,127,128,223,125};  // First 9 LEDs
const uint8_t redMarioLEDs8[] PROGMEM = {188, 35, 28, 189, 29, 34, 30, 33, 65, 190, 193,32,31,64,95,191,192};  // First 9 LEDs
const uint8_t tanMarioLEDs8[] PROGMEM = {131, 156, 130, 157, 129, 158, 97,96,159,160};  // First 9 LEDs

//frame 9
const uint8_t darkGreyLogoLEDs9[] PROGMEM = {8, 9, 10, 11, 12, 13, 14, 15, 23, 40, 51, 53, 55, 72, 74, 75, 83, 85, 87, 104, 113, 115, 119, 136, 140, 142, 146, 151, 168, 176, 181, 182, 183, 200, 202, 207, 208, 212, 213, 215, 232, 240, 241, 242, 243, 244, 245, 246, 247};  // First 9 LEDs
const uint8_t lightGreyLogoLEDs9[] PROGMEM = {48, 50, 77, 79, 81, 112, 116, 118, 137, 138, 139, 143, 144, 148, 149, 150, 177, 178, 179, 204, 206, 209, 211};  // First 9 LEDs
const uint8_t redLogoLEDs9[] PROGMEM = {22, 41, 43};  // First 9 LEDs
const uint8_t tanLogoLEDs9[] PROGMEM = {47};  // First 9 LEDs
const uint8_t yellowLogoLEDs9[] PROGMEM = {45};  // First 9 LEDs
const uint8_t greenLogoLEDs9[] PROGMEM = {16, 18, 20};  // First 9 LEDs
const uint8_t blackLogoLEDs9[] PROGMEM = {17, 19, 21, 42, 44, 46, 49, 52, 54, 73, 76, 78, 80, 82, 84, 86, 105, 106, 107, 108, 109, 110, 111, 114, 117, 141, 145, 147, 169, 170, 171, 172, 173, 174, 175, 180, 201, 203, 205, 210, 214, 233, 234, 235, 236, 237, 238, 239};  // First 9 LEDs

const uint8_t blackMarioLEDs9[] PROGMEM = {24, 39, 6, 25, 38, 57, 26, 37, 133, 154, 186, 164, 196, 123, 195, 163, 123, 99, 60, 67, 61, 93, 125, 162, 221, 62, 126, 129, 222, 124,127,160,223,64,63,159};  // First 9 LEDs
const uint8_t redMarioLEDs9[] PROGMEM = {187, 36, 27, 188, 28, 35, 29, 34, 66, 189, 194, 33, 30, 65, 94, 190, 193,31,32,95,191,192};  // First 9 LEDs
const uint8_t tanMarioLEDs9[] PROGMEM = {132, 155, 131, 156, 130, 157, 98, 97, 158, 161,96,128};  // First 9 LEDs

//frame 10
const uint8_t darkGreyLogoLEDs10[] PROGMEM = {9, 10, 11, 12, 13, 14, 15, 22, 41, 50, 52, 54, 73, 75, 76, 82, 84, 86, 105, 112, 114, 118, 137, 141, 143, 145, 150, 169, 180, 181, 182, 201, 203, 211, 212, 214, 233, 240, 241, 242, 243, 244, 245, 246};  // First 9 LEDs
const uint8_t lightGreyLogoLEDs10[] PROGMEM = {49, 78, 80, 115, 117, 138, 139, 140, 147, 148, 149, 176, 177, 178, 205, 207, 208, 210};  // First 9 LEDs
const uint8_t redLogoLEDs10[] PROGMEM = {21, 42, 44};  // First 9 LEDs
const uint8_t yellowLogoLEDs10[] PROGMEM = {46};  // First 9 LEDs
const uint8_t greenLogoLEDs10[] PROGMEM = {17, 19};  // First 9 LEDs
const uint8_t blackLogoLEDs10[] PROGMEM = {16, 18, 20, 43, 45, 47, 48, 51, 53, 74, 77, 79, 81, 83, 85, 106, 107, 108, 109, 110, 111, 113, 116, 142, 144, 146, 170, 171, 172, 173, 174, 175, 179, 202, 204, 206, 209, 213, 234, 235, 236, 237, 238, 239};  // First 9 LEDs

const uint8_t blackMarioLEDs10[] PROGMEM = {23, 40, 7, 24, 39, 56, 25, 38, 134, 153, 185, 165, 197, 122, 196, 164, 122, 100, 59, 68, 60, 92, 124, 163, 220, 61, 125, 130, 221, 123, 126, 158, 161, 222, 65, 62,63,64,95,223};  // First 9 LEDs
const uint8_t redMarioLEDs10[] PROGMEM = {186, 37, 26, 187, 27, 36, 28, 35, 67, 188, 195, 34, 29, 66, 93, 189, 194, 30, 33, 94, 190, 193,31,32,191,192};  // First 9 LEDs
const uint8_t tanMarioLEDs10[] PROGMEM = {133, 154, 132, 155, 131, 156, 99, 98, 157, 162, 97, 129,96,127,128,159,160};  // First 9 LEDs

//frame 11
const uint8_t darkGreyLogoLEDs11[] PROGMEM = {10, 11, 12, 13, 14, 15, 21, 42, 49, 51, 53, 74, 76, 77, 81, 83, 85, 106, 113, 117, 138, 142, 144, 149, 170, 179, 180, 181, 202, 204, 210, 211, 213, 234, 240, 241, 242, 243, 244, 245};  // First 9 LEDs
const uint8_t lightGreyLogoLEDs11[] PROGMEM = {48, 79, 114, 116, 139, 140, 141, 146, 147, 148, 176, 177, 206, 209};  // First 9 LEDs
const uint8_t redLogoLEDs11[] PROGMEM = {20, 43, 45};  // First 9 LEDs
const uint8_t yellowLogoLEDs11[] PROGMEM = {47};  // First 9 LEDs
const uint8_t greenLogoLEDs11[] PROGMEM = {16, 18};  // First 9 LEDs
const uint8_t blackLogoLEDs11[] PROGMEM = {17, 19, 44, 46, 50, 52, 75, 78, 80, 82, 84, 107, 108, 109, 110, 111, 112, 115, 143, 145, 171, 172, 173, 174, 175, 178, 203, 205, 207, 208, 212, 235, 236, 237, 238, 239};  // First 9 LEDs

const uint8_t blackMarioLEDs11[] PROGMEM = {22, 41, 8, 23, 40, 55, 24, 39, 135, 152, 184, 166, 198, 121, 197, 165, 121, 101, 58, 69, 59, 91, 123, 164, 219, 60, 124, 131, 220, 122, 125, 157, 162, 221, 66, 61, 62, 65, 94, 222,95,128,159,223};  // First 9 LEDs
const uint8_t redMarioLEDs11[] PROGMEM = {185, 38, 25, 186, 26, 37, 27, 36, 68, 187, 196, 35, 28, 67, 92, 188, 195, 29, 34, 93, 189, 194, 30, 33, 190, 193,32,31,63,64,191,192};  // First 9 LEDs
const uint8_t tanMarioLEDs11[] PROGMEM = {134, 153, 133, 154, 132, 155, 100, 99, 156, 163, 98, 130, 97, 126, 129, 158, 161,96,127,160};  // First 9 LEDs

//frame 12
const uint8_t darkGreyLogoLEDs12[] PROGMEM = {11, 12, 13, 14, 15, 20, 43, 48, 50, 52, 75, 77, 78, 80, 82, 84, 107, 112, 116, 139, 143, 148, 171, 178, 179, 180, 203, 205, 209, 210, 212, 235, 240, 241, 242, 243, 244};  // First 9 LEDs
const uint8_t lightGreyLogoLEDs12[] PROGMEM = {113, 115, 140, 141, 142, 145, 146, 147, 176, 207, 208};  // First 9 LEDs
const uint8_t redLogoLEDs12[] PROGMEM = {19, 44, 46};  // First 9 LEDs
const uint8_t greenLogoLEDs12[] PROGMEM = {17};  // First 9 LEDs
const uint8_t blackLogoLEDs12[] PROGMEM = {16, 18, 45, 47, 49, 51, 76, 79, 81, 83, 108, 109, 110, 111, 114, 144, 172, 173, 174, 175, 177, 204, 206, 211, 236, 237, 238, 239};  // First 9 LEDs

const uint8_t blackMarioLEDs12[] PROGMEM = {21, 42, 9, 22, 41, 54, 23, 40, 136, 151, 183, 167, 199, 120, 198, 166, 120, 102, 57, 70, 58, 90, 122, 165, 218, 59, 123, 132, 219, 121, 124, 156, 163, 220, 67, 60, 61, 66, 93, 221, 94, 129, 158, 222,96,128,159,160,223};  // First 9 LEDs
const uint8_t redMarioLEDs12[] PROGMEM = {184, 39, 24, 185, 25, 38, 26, 37, 69, 186, 197, 36, 27, 68, 91, 187, 196, 28, 35, 92, 188, 195, 29, 34, 189, 194, 33, 30, 62, 65, 190, 193,31,32,63,64,95,191,192};  // First 9 LEDs
const uint8_t tanMarioLEDs12[] PROGMEM = {135, 152, 134, 153, 133, 154, 101, 100, 155, 164, 99, 131, 98, 125, 130, 157, 162, 97, 126, 161,127};  // First 9 LEDs

//frame 13
const uint8_t darkGreyLogoLEDs13[] PROGMEM = {12, 13, 14, 15, 19, 44, 49, 51, 76, 78, 79, 81, 83, 108, 115, 140, 147, 172, 177, 178, 179, 204, 206, 208, 209, 211, 236, 240, 241, 242, 243};  // First 9 LEDs
const uint8_t lightGreyLogoLEDs13[] PROGMEM = {112, 114, 141, 142, 143, 144, 145, 146};  // First 9 LEDs
const uint8_t redLogoLEDs13[] PROGMEM = {18, 45, 47};  // First 9 LEDs
const uint8_t greenLogoLEDs13[] PROGMEM = {16};  // First 9 LEDs
const uint8_t blackLogoLEDs13[] PROGMEM = {17, 46, 48, 50, 77, 80, 82, 109, 110, 111, 113, 173, 174, 175, 176, 205, 207, 210, 237, 238, 239};  // First 9 LEDs

const uint8_t blackMarioLEDs13[] PROGMEM = {20, 43, 10, 21, 42, 53, 22, 41, 137, 150, 182, 168, 200, 119, 199, 167, 119, 103, 56, 71, 57, 89, 121, 166, 217, 58, 122, 133, 218, 120, 123, 155, 164, 219, 68, 59, 60, 67, 92, 220, 93, 130, 157, 221, 97, 129, 158, 161, 222,96,127,160,192};  // First 9 LEDs
const uint8_t redMarioLEDs13[] PROGMEM = {183, 40, 23, 184, 24, 39, 25, 38, 70, 185, 198, 37, 26, 69, 90, 186, 197, 27, 36, 91, 187, 196, 28, 35, 188, 195, 34, 29, 61, 66, 189, 194, 30, 33, 62, 65, 94, 190, 193,31,32,63,64,95,191};  // First 9 LEDs
const uint8_t tanMarioLEDs13[] PROGMEM = {136, 151, 135, 152, 134, 153, 102, 101, 154, 165, 100, 132, 99, 124, 131, 156, 163, 98, 125, 162, 126,128,159};  // First 9 LEDs

//frame 14
const uint8_t darkGreyLogoLEDs14[] PROGMEM = {13, 14, 15, 18, 45, 48, 50, 77, 79, 80, 82, 109, 114, 141, 146, 173, 176, 177, 178, 205, 207, 208, 210, 237, 240, 241, 242};  // First 9 LEDs
const uint8_t lightGreyLogoLEDs14[] PROGMEM = {113, 142, 143, 144, 145};  // First 9 LEDs
const uint8_t redLogoLEDs14[] PROGMEM = {17, 46};  // First 9 LEDs
const uint8_t blackLogoLEDs14[] PROGMEM = {16, 47, 49, 78, 81, 110, 111, 112, 174, 175, 206, 209, 238, 239};  // First 9 LEDs

const uint8_t blackMarioLEDs14[] PROGMEM = {19, 44, 11, 20, 43, 52, 21, 42, 138, 149, 181, 169, 201, 118, 200, 168, 118, 104, 55, 72, 56, 88, 120, 167, 216, 57, 121, 134, 217, 119, 122, 154, 165, 218, 69, 58, 59, 68, 91, 219, 92, 131, 156, 220, 98, 130, 157, 162, 221, 97, 126, 161, 193,31,32,95,127,160,191};  // First 9 LEDs
const uint8_t redMarioLEDs14[] PROGMEM = {182, 41, 22, 183, 23, 40, 24, 39, 71, 184, 199, 38, 25, 70, 89, 185, 198, 26, 37, 90, 186, 197, 27, 36, 187, 196, 35, 28, 60, 67, 188, 195, 29, 34, 61, 66, 93, 189, 194, 30, 33, 62, 65, 94, 190,63,64};  // First 9 LEDs
const uint8_t tanMarioLEDs14[] PROGMEM = {137, 150, 136, 151, 135, 152, 103, 102, 153, 166, 101, 133, 100, 123, 132, 155, 164, 99, 124, 163, 125, 129, 158,128,159};  // First 9 LEDs

//frame15
const uint8_t darkGreyLogoLEDs15[] PROGMEM = {14, 15, 17, 46, 49, 78, 81, 110, 113, 142, 145, 174, 176, 177, 206, 209, 238, 240, 241};  // First 9 LEDs
const uint8_t lightGreyLogoLEDs15[] PROGMEM = {112, 143, 144};  // First 9 LEDs
const uint8_t redLogoLEDs15[] PROGMEM = {16, 47};  // First 9 LEDs
const uint8_t blackLogoLEDs15[] PROGMEM = {48, 79, 80, 111, 175, 207, 208, 239};  // First 9 LEDs

const uint8_t blackMarioLEDs15[] PROGMEM = {18, 45, 12, 19, 44, 51, 20, 43, 139, 148, 180, 170, 202, 117, 201, 169, 117, 105, 54, 73, 55, 87, 119, 168, 215, 56, 120, 135, 216, 118, 121, 153, 166, 217, 70, 57, 58, 69, 90, 218, 91, 132, 155, 219, 99, 131, 156, 163, 220, 98, 125, 162, 194, 30, 33, 94, 126, 161, 190,0,31,32,63,128,159};  // First 9 LEDs
const uint8_t redMarioLEDs15[] PROGMEM = {181, 42, 21, 182, 22, 41, 23, 40, 72, 183, 200, 39, 24, 71, 88, 184, 199, 25, 38, 89, 185, 198, 26, 37, 186, 197, 36, 27, 59, 68, 187, 196, 28, 35, 60, 67, 92, 188, 195, 29, 34, 61, 66, 93, 189, 62, 65};  // First 9 LEDs
const uint8_t tanMarioLEDs15[] PROGMEM = {138, 149, 137, 150, 136, 151, 104, 103, 152, 167, 102, 134, 101, 122, 133, 154, 165, 100, 123, 164, 124, 130, 157, 129, 158};  // First 9 LEDs

//frame 16
const uint8_t darkGreyLogoLEDs16[] PROGMEM = {15, 16, 47, 48, 79, 80, 111, 112, 143, 144, 175, 176, 207, 208, 239, 240};  // First 9 LEDs

const uint8_t blackMarioLEDs16[] PROGMEM = {17, 46, 13, 18, 45, 50, 19, 44, 140, 147, 179, 171, 203, 116, 202, 170, 116, 106, 53, 74, 54, 86, 118, 169, 214, 55, 119, 136, 215, 117, 120, 152, 167, 216, 71, 56, 57, 70, 89, 217, 90, 133, 154, 218, 100, 132, 155, 164, 219, 99, 124, 163, 195, 29, 34, 93, 125, 162, 189, 1, 30, 33, 62, 129, 158,31,32,63,64,95,96};  // First 9 LEDs
const uint8_t redMarioLEDs16[] PROGMEM = {180, 43, 20, 181, 21, 42, 22, 41, 73, 182, 201, 40, 23, 72, 87, 183, 200, 24, 39, 88, 184, 199, 25, 38, 185, 198, 37, 26, 58, 69, 186, 197, 27, 36, 59, 68, 91, 187, 196, 28, 35, 60, 67, 92, 188, 61, 66};  // First 9 LEDs
const uint8_t tanMarioLEDs16[] PROGMEM = {139, 148, 138, 149, 137, 150, 105, 104, 151, 168, 103, 135, 102, 121, 134, 153, 166, 101, 122, 165, 123, 131, 156, 130, 157,127,128,159};  // First 9 LEDs

//frame 17

const uint8_t blackMarioLEDs17[] PROGMEM = {16, 47, 14, 17, 46, 49, 18, 45, 141, 146, 178, 172, 204, 115, 203, 171, 115, 107, 52, 75, 53, 85, 117, 170, 213, 54, 118, 137, 214, 116, 119, 151, 168, 215, 72, 55, 56, 71, 88, 216, 89, 134, 153, 217, 101, 133, 154, 165, 218, 100, 123, 164, 196, 28, 35, 92, 124, 163, 188, 2, 29, 34, 61, 130, 157, 30, 33, 62, 65, 94, 97};  // First 9 LEDs
const uint8_t redMarioLEDs17[] PROGMEM = {179, 44, 19, 180, 20, 43, 21, 42, 74, 181, 202, 41, 22, 73, 86, 182, 201, 23, 40, 87, 183, 200, 24, 39, 184, 199, 38, 25, 57, 70, 185, 198, 26, 37, 58, 69, 90, 186, 197, 27, 36, 59, 68, 91, 187, 60, 67};  // First 9 LEDs
const uint8_t tanMarioLEDs17[] PROGMEM = {140, 147, 139, 148, 138, 149, 106, 105, 150, 169, 104, 136, 103, 120, 135, 152, 167, 102, 121, 166, 122, 132, 155, 131, 156, 126, 129, 158};  // First 9 LEDs

//frame18
const uint8_t blackMarioLEDs18[] PROGMEM = {15, 16, 47, 48, 17, 46, 142, 145, 177, 173, 205, 114, 204, 172, 114, 108, 51, 76, 52, 84, 116, 171, 212, 53, 117, 138, 213, 115, 118, 150, 169, 214, 73, 54, 55, 72, 87, 215, 88, 135, 152, 216, 102, 134, 153, 166, 217, 101, 122, 165, 197, 27, 36, 91, 123, 164, 187, 3, 28, 35, 60, 131, 156, 29, 34, 61, 66, 93, 98};  // First 9 LEDs
const uint8_t redMarioLEDs18[] PROGMEM = {178, 45, 18, 179, 19, 44, 20, 43, 75, 180, 203, 42, 21, 74, 85, 181, 202, 22, 41, 86, 182, 201, 23, 40, 183, 200, 39, 24, 56, 71, 184, 199, 25, 38, 57, 70, 89, 185, 198, 26, 37, 58, 69, 90, 186, 59, 68};  // First 9 LEDs
const uint8_t tanMarioLEDs18[] PROGMEM = {141, 146, 140, 147, 139, 148, 107, 106, 149, 170, 105, 137, 104, 119, 136, 151, 168, 103, 120, 167, 121, 133, 154, 132, 155, 125, 130, 157};  // First 9 LEDs

//frame19
const uint8_t blackMarioLEDs19[] PROGMEM = {16, 47, 143, 144, 176, 174, 206, 113, 205, 173, 113, 109, 50, 77, 51, 83, 115, 172, 211, 52, 116, 139, 212, 114, 117, 149, 170, 213, 74, 53, 54, 73, 86, 214, 87, 136, 151, 215, 103, 135, 152, 167, 216, 102, 121, 166, 198, 26, 37, 90, 122, 165, 186, 4, 27, 36, 59, 132, 155, 28, 35, 60, 67, 92, 99};  // First 9 LEDs
const uint8_t redMarioLEDs19[] PROGMEM = {177, 46, 17, 178, 18, 45, 19, 44, 76, 179, 204, 43, 20, 75, 84, 180, 203, 21, 42, 85, 181, 202, 22, 41, 182, 201, 40, 23, 55, 72, 183, 200, 24, 39, 56, 71, 88, 184, 199, 25, 38, 57, 70, 89, 185, 58, 69};  // First 9 LEDs
const uint8_t tanMarioLEDs19[] PROGMEM = {142, 145, 141, 146, 140, 147, 108, 107, 148, 171, 106, 138, 105, 118, 137, 150, 169, 104, 119, 168, 120, 134, 153, 133, 154, 124, 131, 156};  // First 9 LEDs

//frame20
const uint8_t blackMarioLEDs20[] PROGMEM = {175, 207, 112, 206, 174, 112, 110, 49, 78, 50, 82, 114, 173, 210, 51, 115, 140, 211, 113, 116, 148, 171, 212, 75, 52, 53, 74, 85, 213, 86, 137, 150, 214, 104, 136, 151, 168, 215, 103, 120, 167, 199, 25, 38, 89, 121, 166, 185, 5, 26, 37, 58, 133, 154, 27, 36, 59, 68, 91, 100};  // First 9 LEDs
const uint8_t redMarioLEDs20[] PROGMEM = {176, 47, 16, 177, 17, 46, 18, 45, 77, 178, 205, 44, 19, 76, 83, 179, 204, 20, 43, 84, 180, 203, 21, 42, 181, 202, 41, 22, 54, 73, 182, 201, 23, 40, 55, 72, 87, 183, 200, 24, 39, 56, 71, 88, 184, 57, 70};  // First 9 LEDs
const uint8_t tanMarioLEDs20[] PROGMEM = {143, 144, 142, 145, 141, 146, 109, 108, 147, 172, 107, 139, 106, 117, 138, 149, 170, 105, 118, 169, 119, 135, 152, 134, 153, 123, 132, 155};  // First 9 LEDs

//frame21
const uint8_t blackMarioLEDs21[] PROGMEM = {207, 175, 111, 48, 79, 49, 81, 113, 174, 209, 50, 114, 141, 210, 112, 115, 147, 172, 211, 76, 51, 52, 75, 84, 212, 85, 138, 149, 213, 105, 137, 150, 169, 214, 104, 119, 168, 200, 24, 39, 88, 120, 167, 184, 6, 25, 38, 57, 134, 153, 26, 37, 58, 69, 90, 101};  // First 9 LEDs
const uint8_t redMarioLEDs21[] PROGMEM = {176, 16, 47, 17, 46, 78, 177, 206, 45, 18, 77, 82, 178, 205, 19, 44, 83, 179, 204, 20, 43, 180, 203, 42, 21, 53, 74, 181, 202, 22, 41, 54, 73, 86, 182, 201, 23, 40, 55, 72, 87, 183, 56, 71};  // First 9 LEDs
const uint8_t tanMarioLEDs21[] PROGMEM = {143, 144, 142, 145, 110, 109, 146, 173, 108, 140, 107, 116, 139, 148, 171, 106, 117, 170, 118, 136, 151, 135, 152, 122, 133, 154};  // First 9 LEDs

//frame22
const uint8_t blackMarioLEDs22[] PROGMEM = {48, 80, 112, 175, 208, 49, 113, 142, 209, 114, 146, 173, 210, 77, 50, 51, 76, 83, 211, 84, 139, 148, 212, 106, 138, 149, 170, 213, 105, 118, 169, 201, 23, 40, 87, 119, 168, 183, 7, 24, 39, 56, 135, 152, 25, 38, 57, 70, 89, 102};  // First 9 LEDs
const uint8_t redMarioLEDs22[] PROGMEM = {16, 47, 79, 176, 207, 46, 17, 78, 81, 177, 206, 18, 45, 82, 178, 205, 19, 44, 179, 204, 43, 20, 52, 75, 180, 203, 21, 42, 53, 74, 85, 181, 202, 22, 41, 54, 73, 86, 182, 55, 72};  // First 9 LEDs
const uint8_t tanMarioLEDs22[] PROGMEM = {143, 144, 111, 110, 145, 174, 109, 141, 108, 115, 140, 147, 172, 107, 116, 171, 117, 137, 150, 136, 151, 121, 134, 153};  // First 9 LEDs

//frame23
const uint8_t blackMarioLEDs23[] PROGMEM = {48, 112, 143, 208, 113, 145, 174, 209, 78, 49, 50, 77, 82, 210, 83, 140, 147, 211, 107, 139, 148, 171, 212, 106, 117, 170, 202, 22, 41, 86, 118, 169, 182, 8, 23, 40, 55, 136, 151, 24, 39, 56, 71, 88, 103};  // First 9 LEDs
const uint8_t redMarioLEDs23[] PROGMEM = {47, 16, 79, 80, 176, 207, 17, 46, 81, 177, 206, 18, 45, 178, 205, 44, 19, 51, 76, 179, 204, 20, 43, 52, 75, 84, 180, 203, 21, 42, 53, 74, 85, 181, 54, 73};  // First 9 LEDs
const uint8_t tanMarioLEDs23[] PROGMEM = {111, 144, 175, 110, 142, 109, 114, 141, 146, 173, 108, 115, 172, 116, 138, 149, 137, 150, 120, 135, 152};  // First 9 LEDs

//frame24
const uint8_t blackMarioLEDs24[] PROGMEM = {112, 144, 175, 208, 79, 48, 49, 78, 81, 209, 82, 141, 146, 210, 108, 140, 147, 172, 211, 107, 116, 171, 203, 21, 42, 85, 117, 170, 181, 9, 22, 41, 54, 137, 150, 23, 40, 55, 72, 87, 104};  // First 9 LEDs
const uint8_t redMarioLEDs24[] PROGMEM = {16, 47, 80, 176, 207, 17, 46, 177, 206, 45, 18, 50, 77, 178, 205, 19, 44, 51, 76, 83, 179, 204, 20, 43, 52, 75, 84, 180, 53, 74};  // First 9 LEDs
const uint8_t tanMarioLEDs24[] PROGMEM = {111, 143, 110, 113, 142, 145, 174, 109, 114, 173, 115, 139, 148, 138, 149, 119, 136, 151};  // First 9 LEDs

//frame25
const uint8_t blackMarioLEDs25[] PROGMEM = {48, 79, 80, 208, 81, 142, 145, 209, 109, 141, 146, 173, 210, 108, 115, 172, 204, 20, 43, 84, 116, 171, 180, 10, 21, 42, 53, 138, 149, 22, 41, 54, 73, 86, 105};  // First 9 LEDs
const uint8_t redMarioLEDs25[] PROGMEM = {16, 47, 176, 207, 46, 17, 49, 78, 177, 206, 18, 45, 50, 77, 82, 178, 205, 19, 44, 51, 76, 83, 179, 52, 75};  // First 9 LEDs
const uint8_t tanMarioLEDs25[] PROGMEM = {111, 112, 143, 144, 175, 110, 113, 174, 114, 140, 147, 139, 148, 118, 137, 150};  // First 9 LEDs

//frame26
const uint8_t blackMarioLEDs26[] PROGMEM = {80, 143, 144, 208, 110, 142, 145, 174, 209, 109, 114, 173, 205, 19, 44, 83, 115, 172, 179, 11, 20, 43, 52, 139, 148, 21, 42, 53, 74, 85, 106};  // First 9 LEDs
const uint8_t redMarioLEDs26[] PROGMEM = {47, 16, 48, 79, 176, 207, 17, 46, 49, 78, 81, 177, 206, 18, 45, 50, 77, 82, 178, 51, 76};  // First 9 LEDs
const uint8_t tanMarioLEDs26[] PROGMEM = {111, 112, 175, 113, 141, 146, 140, 147, 117, 138, 149};  // First 9 LEDs

//frame27
const uint8_t blackMarioLEDs27[] PROGMEM = {111, 143, 144, 175, 208, 110, 113, 174, 206, 18, 45, 82, 114, 173, 178, 12, 19, 44, 51, 140, 147, 20, 43, 52, 75, 84, 107};  // First 9 LEDs
const uint8_t redMarioLEDs27[] PROGMEM = {16, 47, 48, 79, 80, 176, 207, 17, 46, 49, 78, 81, 177, 50, 77};  // First 9 LEDs
const uint8_t tanMarioLEDs27[] PROGMEM = {112, 142, 145, 141, 146, 116, 139, 148};  // First 9 LEDs

//frame28
const uint8_t blackMarioLEDs28[] PROGMEM = {111, 112, 175, 207, 17, 46, 81, 113, 174, 177, 13, 18, 45, 50, 141, 146, 19, 44, 51, 76, 83, 108};  // First 9 LEDs
const uint8_t redMarioLEDs28[] PROGMEM = {16, 47, 48, 79, 80, 176, 49, 78};  // First 9 LEDs
const uint8_t tanMarioLEDs28[] PROGMEM = {143, 144, 142, 145, 115, 140, 147};  // First 9 LEDs

//frame29
const uint8_t blackMarioLEDs29[] PROGMEM = {16, 47, 80, 112, 175, 176, 14, 17, 46, 49, 142, 145, 18, 45, 50, 77, 82, 109};  // First 9 LEDs
const uint8_t redMarioLEDs29[] PROGMEM = {48, 79};  // First 9 LEDs
const uint8_t tanMarioLEDs29[] PROGMEM = {143, 144, 114, 141, 146};  // First 9 LEDs

//frame30
const uint8_t blackMarioLEDs30[] PROGMEM = {15, 16, 47, 48, 143, 144, 17, 46, 49, 78, 81, 110};  // First 9 LEDs
const uint8_t tanMarioLEDs30[] PROGMEM = {113, 142, 145};  // First 9 LEDs

//frame31
const uint8_t blackMarioLEDs31[] PROGMEM = {16, 47, 48, 79, 80, 111};  // First 9 LEDs
const uint8_t tanMarioLEDs31[] PROGMEM = {112, 143, 144};  // First 9 LEDs


//frame 32 the hill and cloud frames will be inserted in between


//last logo
const uint8_t darkGreyLogoLEDs71[] PROGMEM = {0, 31, 32, 63, 64, 95, 96, 127, 128, 159, 160, 191, 192, 223, 224, 255};  // dark grey Leds for frame 1




//last logo
const uint8_t darkGreyLogoLEDs72[] PROGMEM = {0, 1, 30, 33, 62, 65, 94, 97, 126, 129, 158, 161, 190, 193, 222, 223, 225, 254, 255};  // dark grey Leds for frame 1
const uint8_t lightGreyLogoLEDs72[] PROGMEM = {32, 127, 128, 159}; //light grey leds for frame 1
const uint8_t redLogoLEDs72[] PROGMEM = {31};  // red logo leds for frame 1
const uint8_t blackLogoLEDs72[] PROGMEM = {63, 64, 95, 96, 160, 191, 192, 224};  // black leds for frame 1


//last logo
const uint8_t darkGreyLogoLEDs73[] PROGMEM = {0, 1, 2, 29, 34, 61, 66, 93, 98, 125, 130, 157, 162, 189, 191, 192, 194, 221, 222, 223, 226, 253, 254, 255};  // dark grey Leds for frame 1
const uint8_t lightGreyLogoLEDs73[] PROGMEM = {33, 95, 126, 127, 129, 158, 159}; //light grey leds for frame 1
const uint8_t redLogoLEDs73[] PROGMEM = {30};  // red logo leds for frame 1
const uint8_t blackLogoLEDs73[] PROGMEM = {31, 32, 62, 63, 64, 65, 94, 96, 97, 128, 160, 161, 190, 193, 224, 225};  // black leds for frame 1


//last logo
const uint8_t darkGreyLogoLEDs74[] PROGMEM = {0, 1, 2, 3, 28, 35, 60, 67, 92, 99, 124, 131, 156, 163, 188, 190, 193, 195, 220, 221, 222, 227, 252, 253, 254, 255};  // dark grey Leds for frame 1
const uint8_t lightGreyLogoLEDs74[] PROGMEM = {34, 63, 64, 94, 95, 125, 126, 127, 128, 130, 157, 158, 159, 191, 223}; //light grey leds for frame 1
const uint8_t redLogoLEDs74[] PROGMEM = {29};  // red logo leds for frame 1
const uint8_t greenLogoLEDs74[] PROGMEM = {31, 32};  // First 9 LEDs
const uint8_t blackLogoLEDs74[] PROGMEM = {30, 33, 61, 62, 65, 66, 93, 96, 97, 98, 129, 160, 161, 162, 189, 192, 194, 224, 225, 226};  // black leds for frame 1

//last logo
const uint8_t darkGreyLogoLEDs75[] PROGMEM = {0, 1, 2, 3, 4, 27, 36, 59, 68, 91, 100, 123, 127, 132, 155, 159, 164, 187, 189, 194, 196, 219, 220, 221, 228, 251, 252, 253, 254, 255};  // dark grey Leds for frame 1
const uint8_t lightGreyLogoLEDs75[] PROGMEM = {35, 62, 65, 93, 94, 95, 124, 125, 126, 129, 131, 156, 157, 158, 190, 191, 192, 222, 223}; //light grey leds for frame 1
const uint8_t redLogoLEDs75[] PROGMEM = {28};  // red logo leds for frame 1
const uint8_t greenLogoLEDs75[] PROGMEM = {30, 33};  // First 9 LEDs
const uint8_t blackLogoLEDs75[] PROGMEM = {29, 31, 32, 34, 60, 61, 63, 64, 66, 67, 92, 96, 97, 98, 99, 128, 130, 160, 161, 162, 163, 188, 193, 195, 224, 225, 226, 227};  // black leds for frame 1

//last logo
const uint8_t darkGreyLogoLEDs76[] PROGMEM = {0, 1, 2, 3, 4, 5, 26, 37, 58, 69, 90, 95, 101, 122, 126, 127, 128, 133, 154, 158, 159, 165, 186, 188, 195, 197, 218, 219, 220, 229, 250, 251, 252, 253, 254, 255};  // dark grey Leds for frame 1
const uint8_t lightGreyLogoLEDs76[] PROGMEM = {36, 61, 66, 92, 93, 94, 123, 124, 125, 130, 132, 155, 156, 157, 189, 190, 191, 192, 193, 221, 222, 223}; //light grey leds for frame 1
const uint8_t redLogoLEDs76[] PROGMEM = {27, 31};  // red logo leds for frame 1
const uint8_t yellowLogoLEDs76[] PROGMEM = {32};  // First 9 LEDs
const uint8_t greenLogoLEDs76[] PROGMEM = {29, 34};  // First 9 LEDs
const uint8_t blackLogoLEDs76[] PROGMEM = {28, 30, 33, 35, 59, 60, 62, 63, 64, 65, 67, 68, 91, 96, 97, 98, 99, 100, 129, 131, 160, 161, 162, 163, 164, 187, 194, 196, 224, 225, 226, 227, 228};  // black leds for frame 1


//last logo
const uint8_t darkGreyLogoLEDs77[] PROGMEM = {0, 1, 2, 3, 4, 5, 6, 25, 38, 57, 70, 89, 94, 95, 102, 121, 125, 126, 127, 129, 134, 153, 157, 158, 159, 166, 185, 187, 192, 196, 198, 217, 218, 219, 223, 230, 249, 250, 251, 252, 253, 254, 255};  // dark grey Leds for frame 1
const uint8_t lightGreyLogoLEDs77[] PROGMEM = {37, 60, 67, 91, 92, 93, 122, 123, 124, 131, 133, 154, 155, 156, 188, 189, 190, 193, 194, 220, 221, 222}; //light grey leds for frame 1
const uint8_t redLogoLEDs77[] PROGMEM = {26, 30};  // red logo leds for frame 1
const uint8_t yellowLogoLEDs77[] PROGMEM = {33};  // First 9 LEDs
const uint8_t greenLogoLEDs77[] PROGMEM = {28, 35};  // First 9 LEDs
const uint8_t blackLogoLEDs77[] PROGMEM = {27, 29, 31, 32, 34, 36, 58, 59, 61, 62, 63, 64, 65, 66, 68, 69, 90, 96, 97, 98, 99, 100, 101, 128, 130, 132, 160, 161, 162, 163, 164, 165, 186, 191, 195, 197, 224, 225, 226, 227, 228, 229};  // black leds for frame 1


//last logo
const uint8_t darkGreyLogoLEDs78[] PROGMEM = {0, 1, 2, 3, 4, 5, 6, 7, 24, 39, 56, 63, 64, 71, 88, 93, 94, 95, 103, 120, 124, 125, 126, 130, 135, 152, 156, 157, 158, 167, 184, 186, 192, 193, 197, 199, 216, 217, 218, 222, 223, 231, 248, 249, 250, 251, 252, 253, 254, 255};  // dark grey Leds for frame 1
const uint8_t lightGreyLogoLEDs78[] PROGMEM = {38, 59, 68, 90, 91, 92, 121, 122, 123, 132, 134, 153, 154, 155, 159, 187, 188, 189, 194, 195, 219, 220, 221}; //light grey leds for frame 1
const uint8_t redLogoLEDs78[] PROGMEM = {25, 29, 31};  // red logo leds for frame 1
const uint8_t tanLogoLEDs78[] PROGMEM = {32};  // First 9 LEDs
const uint8_t yellowLogoLEDs78[] PROGMEM = {34};  // First 9 LEDs
const uint8_t greenLogoLEDs78[] PROGMEM = {27, 36};  // First 9 LEDs
const uint8_t blackLogoLEDs78[] PROGMEM = {26, 28, 30, 33, 35, 37, 57, 58, 60, 61, 62, 65, 66, 67, 69, 70, 89, 96, 97, 98, 99, 100, 101, 102, 127, 128, 129, 131, 133, 160, 161, 162, 163, 164, 165, 166, 185, 190, 191, 196, 198, 224, 225, 226, 227, 228, 229, 230};  // black leds for frame 1

//last logo
const uint8_t darkGreyLogoLEDs79[] PROGMEM = {0, 1, 2, 3, 4, 5, 6, 7, 8, 23, 40, 55, 62, 65, 72, 87, 92, 93, 94, 104, 119, 123, 124, 125, 131, 136, 151, 155, 156, 157, 168, 183, 185, 191, 192, 193, 194, 198, 200, 215, 216, 217, 221, 222, 223, 232, 247, 248, 249, 250, 251, 252, 253, 254, 255};  // dark grey Leds for frame 1
const uint8_t lightGreyLogoLEDs79[] PROGMEM = {39, 58, 63, 64, 69, 89, 90, 91, 120, 121, 122, 127, 128, 133, 135, 152, 153, 154, 158, 159, 186, 187, 188, 195, 196, 218, 219, 220}; //light grey leds for frame 1
const uint8_t redLogoLEDs79[] PROGMEM = {24, 28, 30};  // red logo leds for frame 1
const uint8_t tanLogoLEDs79[] PROGMEM = {32, 33};  // First 9 LEDs
const uint8_t yellowLogoLEDs79[] PROGMEM = {35};  // First 9 LEDs
const uint8_t greenLogoLEDs79[] PROGMEM = {26, 31, 37};  // First 9 LEDs
const uint8_t blackLogoLEDs79[] PROGMEM = {25, 27, 29, 34, 36, 38, 56, 57, 59, 60, 61, 66, 67, 68, 70, 71, 88, 95, 96, 97, 98, 99, 100, 101, 102, 103, 126, 129, 130, 132, 134, 160, 161, 162, 163, 164, 165, 166, 167, 184, 189, 190, 197, 199, 224, 225, 226, 227, 228, 229, 230, 231};  // black leds for frame 1

//last logo
const uint8_t darkGreyLogoLEDs80[] PROGMEM = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 22, 41, 54, 61, 66, 73, 86, 91, 92, 93, 105, 118, 122, 123, 124, 127, 128, 132, 137, 150, 154, 155, 156, 169, 182, 184, 190, 193, 194, 195, 199, 201, 214, 215, 216, 220, 221, 222, 233, 246, 247, 248, 249, 250, 251, 252, 253, 254, 255};  // dark grey Leds for frame 1
const uint8_t lightGreyLogoLEDs80[] PROGMEM = {40, 57, 62, 65, 70, 88, 89, 90, 95, 119, 120, 121, 126, 129, 134, 136, 151, 152, 153, 157, 158, 185, 186, 187, 191, 192, 196, 197, 217, 218, 219, 223}; //light grey leds for frame 1
const uint8_t redLogoLEDs80[] PROGMEM = {23, 27, 29};  // red logo leds for frame 1
const uint8_t tanLogoLEDs80[] PROGMEM = {33, 34};  // First 9 LEDs
const uint8_t yellowLogoLEDs80[] PROGMEM = {36};  // First 9 LEDs
const uint8_t greenLogoLEDs80[] PROGMEM = {25, 30, 38};  // First 9 LEDs
const uint8_t blackLogoLEDs80[] PROGMEM = {24, 26, 28, 31, 32, 35, 37, 39, 55, 56, 58, 59, 60, 63, 64, 67, 68, 69, 71, 72, 87, 94, 96, 97, 98, 99, 100, 101, 102, 103, 104, 125, 130, 131, 133, 135, 159, 160, 161, 162, 163, 164, 165, 166, 167, 168, 183, 188, 189, 198, 200, 224, 225, 226, 227, 228, 229, 230, 231, 232};  // black leds for frame 1


//last logo
const uint8_t darkGreyLogoLEDs81[] PROGMEM = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 21, 42, 53, 60, 67, 74, 85, 90, 91, 92, 106, 117, 121, 122, 123, 126, 129, 133, 138, 149, 153, 154, 155, 159, 170, 181, 183, 189, 194, 195, 196, 200, 202, 213, 214, 215, 219, 220, 221, 234, 245, 246, 247, 248, 249, 250, 251, 252, 253, 254, 255};  // dark grey Leds for frame 1
const uint8_t lightGreyLogoLEDs81[] PROGMEM = {41, 56, 61, 63, 64, 66, 71, 87, 88, 89, 94, 118, 119, 120, 125, 130, 135, 137, 150, 151, 152, 156, 157, 184, 185, 186, 190, 191, 193, 197, 198, 216, 217, 218, 222}; //light grey leds for frame 1
const uint8_t redLogoLEDs81[] PROGMEM = {22, 26, 28};  // red logo leds for frame 1
const uint8_t tanLogoLEDs81[] PROGMEM = {34, 35};  // First 9 LEDs
const uint8_t yellowLogoLEDs81[] PROGMEM = {32, 37};  // First 9 LEDs
const uint8_t greenLogoLEDs81[] PROGMEM = {24, 29, 31, 39};  // First 9 LEDs
const uint8_t blackLogoLEDs81[] PROGMEM = {23, 25, 27, 30, 33, 36, 38, 40, 54, 55, 57, 58, 59, 62, 65, 68, 69, 70, 72, 73, 86, 93, 95, 96, 97, 98, 99, 100, 101, 102, 103, 104, 105, 124, 127, 128, 131, 132, 134, 136, 158, 160, 161, 162, 163, 164, 165, 166, 167, 168, 169, 182, 187, 188, 192, 199, 201, 223, 224, 225, 226, 227, 228, 229, 230, 231, 232, 233};  // black leds for frame 1


//last logo
const uint8_t darkGreyLogoLEDs82[] PROGMEM = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 20, 43, 52, 59, 63, 68, 75, 84, 89, 90, 91, 95, 107, 116, 120, 121, 122, 125, 127, 128, 130, 134, 139, 148, 152, 153, 154, 158, 171, 180, 182, 188, 195, 196, 197, 201, 203, 212, 213, 214, 218, 219, 220, 235, 244, 245, 246, 247, 248, 249, 250, 251, 252, 253, 254, 255};  // dark grey Leds for frame 1
const uint8_t lightGreyLogoLEDs82[] PROGMEM = {42, 55, 60, 62, 65, 67, 72, 86, 87, 88, 93, 117, 118, 119, 124, 131, 136, 138, 149, 150, 151, 155, 156, 183, 184, 185, 189, 190, 191, 192, 194, 198, 199, 215, 216, 217, 221, 223}; //light grey leds for frame 1
const uint8_t redLogoLEDs82[] PROGMEM = {21, 25, 27};  // red logo leds for frame 1
const uint8_t tanLogoLEDs82[] PROGMEM = {35, 36};  // First 9 LEDs
const uint8_t yellowLogoLEDs82[] PROGMEM = {33, 38};  // First 9 LEDs
const uint8_t greenLogoLEDs82[] PROGMEM = {23, 28, 30, 40};  // First 9 LEDs
const uint8_t blackLogoLEDs82[] PROGMEM = {22, 24, 26, 29, 31, 32, 34, 37, 39, 41, 53, 54, 56, 57, 58, 61, 64, 66, 69, 70, 71, 73, 74, 85, 92, 94, 96, 97, 98, 99, 100, 101, 102, 103, 104, 105, 106, 123, 126, 129, 132, 133, 135, 137, 157, 159, 160, 161, 162, 163, 164, 165, 166, 167, 168, 169, 170, 181, 186, 187, 193, 200, 202, 222, 224, 225, 226, 227, 228, 229, 230, 231, 232, 233, 234};  // black leds for frame 1


//last logo
const uint8_t darkGreyLogoLEDs83[] PROGMEM = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 19, 44, 51, 58, 62, 64, 69, 76, 83, 88, 89, 90, 94, 108, 115, 119, 120, 121, 124, 126, 129, 131, 135, 140, 147, 151, 152, 153, 157, 172, 179, 181, 187, 196, 197, 198, 202, 204, 211, 212, 213, 217, 218, 219, 223, 236, 243, 244, 245, 246, 247, 248, 249, 250, 251, 252, 253, 254, 255};  // dark grey Leds for frame 1
const uint8_t lightGreyLogoLEDs83[] PROGMEM = {43, 54, 59, 61, 66, 68, 73, 85, 86, 87, 92, 116, 117, 118, 123, 127, 128, 132, 137, 139, 148, 149, 150, 154, 155, 159, 182, 183, 184, 188, 189, 190, 193, 195, 199, 200, 214, 215, 216, 220, 222}; //light grey leds for frame 1
const uint8_t redLogoLEDs83[] PROGMEM = {20, 24, 26, 32};  // red logo leds for frame 1
const uint8_t tanLogoLEDs83[] PROGMEM = {36, 37};  // First 9 LEDs
const uint8_t yellowLogoLEDs83[] PROGMEM = {34, 39};  // First 9 LEDs
const uint8_t greenLogoLEDs83[] PROGMEM = {22, 27, 29, 31, 41};  // First 9 LEDs
const uint8_t blackLogoLEDs83[] PROGMEM = {21, 23, 25, 28, 30, 33, 35, 38, 40, 42, 52, 53, 55, 56, 57, 60, 63, 65, 67, 70, 71, 72, 74, 75, 84, 91, 93, 95, 96, 97, 98, 99, 100, 101, 102, 103, 104, 105, 106, 107, 122, 125, 130, 133, 134, 136, 138, 156, 158, 160, 161, 162, 163, 164, 165, 166, 167, 168, 169, 170, 171, 180, 185, 186, 191, 192, 194, 201, 203, 221, 224, 225, 226, 227, 228, 229, 230, 231, 232, 233, 234, 235};  // black leds for frame 1

//last logo
const uint8_t darkGreyLogoLEDs84[] PROGMEM = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 18, 45, 50, 57, 61, 63, 64, 65, 70, 77, 82, 87, 88, 89, 93, 95, 109, 114, 118, 119, 120, 123, 125, 130, 132, 136, 141, 146, 150, 151, 152, 156, 173, 178, 180, 186, 191, 192, 197, 198, 199, 203, 205, 210, 211, 212, 216, 217, 218, 222, 223, 237, 242, 243, 244, 245, 246, 247, 248, 249, 250, 251, 252, 253, 254, 255};  // dark grey Leds for frame 1
const uint8_t lightGreyLogoLEDs84[] PROGMEM = {44, 53, 58, 60, 67, 69, 74, 84, 85, 86, 91, 115, 116, 117, 122, 126, 128, 129, 133, 138, 140, 147, 148, 149, 153, 154, 158, 159, 181, 182, 183, 187, 188, 189, 194, 196, 200, 201, 213, 214, 215, 219, 221}; //light grey leds for frame 1
const uint8_t redLogoLEDs84[] PROGMEM = {19, 23, 25, 33};  // red logo leds for frame 1
const uint8_t tanLogoLEDs84[] PROGMEM = {37, 38};  // First 9 LEDs
const uint8_t yellowLogoLEDs84[] PROGMEM = {35, 40};  // First 9 LEDs
const uint8_t greenLogoLEDs84[] PROGMEM = {21, 26, 28, 30, 42};  // First 9 LEDs
const uint8_t blackLogoLEDs84[] PROGMEM = {20, 22, 24, 27, 29, 31, 32, 34, 36, 39, 41, 43, 51, 52, 54, 55, 56, 59, 62, 66, 68, 71, 72, 73, 75, 76, 83, 90, 92, 94, 96, 97, 98, 99, 100, 101, 102, 103, 104, 105, 106, 107, 108, 121, 124, 127, 131, 134, 135, 137, 139, 155, 157, 160, 161, 162, 163, 164, 165, 166, 167, 168, 169, 170, 171, 172, 179, 184, 185, 190, 193, 195, 202, 204, 220, 224, 225, 226, 227, 228, 229, 230, 231, 232, 233, 234, 235, 236};  // black leds for frame 1

//last logo
const uint8_t darkGreyLogoLEDs85[] PROGMEM = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 17, 46, 49, 56, 60, 62, 65, 66, 71, 78, 81, 86, 87, 88, 92, 94, 110, 113, 117, 118, 119, 122, 124, 131, 133, 137, 142, 145, 149, 150, 151, 155, 174, 177, 179, 185, 190, 191, 193, 198, 199, 200, 204, 206, 209, 210, 211, 215, 216, 217, 221, 222, 238, 241, 242, 243, 244, 245, 246, 247, 248, 249, 250, 251, 252, 253, 254, 255};  // dark grey Leds for frame 1
const uint8_t lightGreyLogoLEDs85[] PROGMEM = {45, 52, 57, 59, 68, 70, 75, 83, 84, 85, 90, 114, 115, 116, 121, 125, 127, 128, 129, 130, 134, 139, 141, 146, 147, 148, 152, 153, 157, 158, 159, 180, 181, 182, 186, 187, 188, 195, 197, 201, 202, 212, 213, 214, 218, 220}; //light grey leds for frame 1
const uint8_t redLogoLEDs85[] PROGMEM = {18, 22, 24, 31, 32, 34};  // red logo leds for frame 1
const uint8_t tanLogoLEDs85[] PROGMEM = {38, 39};  // First 9 LEDs
const uint8_t yellowLogoLEDs85[] PROGMEM = {36, 41};  // First 9 LEDs
const uint8_t greenLogoLEDs85[] PROGMEM = {20, 25, 27, 29, 43};  // First 9 LEDs
const uint8_t blackLogoLEDs85[] PROGMEM = {19, 21, 23, 26, 28, 30, 33, 35, 37, 40, 42, 44, 50, 51, 53, 54, 55, 58, 61, 63, 64, 67, 69, 72, 73, 74, 76, 77, 82, 89, 91, 93, 95, 96, 97, 98, 99, 100, 101, 102, 103, 104, 105, 106, 107, 108, 109, 120, 123, 126, 132, 135, 136, 138, 140, 154, 156, 160, 161, 162, 163, 164, 165, 166, 167, 168, 169, 170, 171, 172, 173, 178, 183, 184, 189, 192, 194, 196, 203, 205, 219, 223, 224, 225, 226, 227, 228, 229, 230, 231, 232, 233, 234, 235, 236, 237};  // black leds for frame 1




// Function to set colors for specific LEDs (from flash memory indices)
void setLEDColors(const uint8_t* ledIndices, uint8_t numLEDs, CRGB color) {
  for (uint8_t i = 0; i < numLEDs; i++) {
    leds[pgm_read_byte(ledIndices + i)] = color;  // Read from PROGMEM
  }
}

void setup() {
  delay(1000);
  FastLED.addLeds<WS2811, DATA_PIN, GRB>(leds, NUM_LEDS);
  FastLED.clear();  // Clear all LEDs at the start
  FastLED.setBrightness(30);  // set initial brightness
  delay(500);
}

void loop() {
  // set the first pattern (darkGreyLEDs)
  setLEDColors(yellowBackgroundLEDs, sizeof(yellowBackgroundLEDs) / sizeof(yellowBackgroundLEDs[0]), CRGB(249,239,11));
  setLEDColors(greenBackgroundLEDs, sizeof(greenBackgroundLEDs) / sizeof(greenBackgroundLEDs[0]), CRGB(44,254,27));
  setLEDColors(darkGreyLogoLEDs, sizeof(darkGreyLogoLEDs) / sizeof(darkGreyLogoLEDs[0]), CRGB(90, 88, 72));
  setLEDColors(lightGreyLogoLEDs, sizeof(lightGreyLogoLEDs) / sizeof(lightGreyLogoLEDs[0]), CRGB(213,212,232));
  setLEDColors(redLogoLEDs, sizeof(redLogoLEDs) / sizeof(redLogoLEDs[0]), CRGB(211, 4, 4));
  setLEDColors(tanLogoLEDs, sizeof(tanLogoLEDs) / sizeof(tanLogoLEDs[0]), CRGB(255, 100, 40));
  setLEDColors(yellowLogoLEDs, sizeof(yellowLogoLEDs) / sizeof(yellowLogoLEDs[0]), CRGB(249,239,11));
  setLEDColors(greenLogoLEDs, sizeof(greenLogoLEDs) / sizeof(greenLogoLEDs[0]), CRGB(44,254,27));
  setLEDColors(blackLogoLEDs, sizeof(blackLogoLEDs) / sizeof(blackLogoLEDs[0]), CRGB(0, 0, 0));
  
  // Fade the brightness
  for (uint8_t brightness = 30; brightness > 5; brightness -= 5) {
    FastLED.setBrightness(brightness);
    FastLED.show();
    delay(250);
  }
  for (uint8_t brightness = 5; brightness < 30; brightness += 5) {
    FastLED.setBrightness(brightness);
    FastLED.show();
    delay(250);
  }
  for (uint8_t brightness = 30; brightness > 5; brightness -= 5) {
    FastLED.setBrightness(brightness);
    FastLED.show();
    delay(250);
  }
  for (uint8_t brightness = 5; brightness < 30; brightness += 5) {
    FastLED.setBrightness(brightness);
    FastLED.show();
    delay(250);
  }
  for (uint8_t brightness = 30; brightness > 5; brightness -= 5) {
    FastLED.setBrightness(brightness);
    FastLED.show();
    delay(250);
  }
  for (uint8_t brightness = 5; brightness < 30; brightness += 5) {
    FastLED.setBrightness(brightness);
    FastLED.show();
    delay(250);
  }

  // Clear the pattern before moving to the next one
  FastLED.clear();

  // set the second frame
  //background
  setLEDColors(yellowBackgroundLEDs, sizeof(yellowBackgroundLEDs) / sizeof(yellowBackgroundLEDs[0]), CRGB(249,239,11));
  setLEDColors(greenBackgroundLEDs, sizeof(greenBackgroundLEDs) / sizeof(greenBackgroundLEDs[0]), CRGB(44,254,27));
 //Green hills and Yellow clouds

 //Logo
  setLEDColors(blackLogoLEDs2, sizeof(blackLogoLEDs2) / sizeof(blackLogoLEDs2[0]), CRGB(0, 0, 0));
  setLEDColors(darkGreyLogoLEDs2, sizeof(darkGreyLogoLEDs2) / sizeof(darkGreyLogoLEDs2[0]), CRGB(90, 88, 72));
  setLEDColors(lightGreyLogoLEDs2, sizeof(lightGreyLogoLEDs2) / sizeof(lightGreyLogoLEDs2[0]), CRGB(213,212,232));
  setLEDColors(redLogoLEDs2, sizeof(redLogoLEDs2) / sizeof(redLogoLEDs2[0]), CRGB(211, 4, 4));
  setLEDColors(tanLogoLEDs2, sizeof(tanLogoLEDs2) / sizeof(tanLogoLEDs2[0]), CRGB(255, 100, 40));
  setLEDColors(yellowLogoLEDs2, sizeof(yellowLogoLEDs2) / sizeof(yellowLogoLEDs2[0]), CRGB(249,239,11));
  setLEDColors(greenLogoLEDs2, sizeof(greenLogoLEDs2) / sizeof(greenLogoLEDs2[0]), CRGB(44,254,27));
  //Mario
  setLEDColors(blackMarioLEDs2, sizeof(blackMarioLEDs2) / sizeof(blackMarioLEDs2[0]), CRGB(0, 0, 0));

  // Show the new pattern
  FastLED.show();
  delay(250);
  FastLED.clear();
   //set the third frame
    //background
  setLEDColors(yellowBackgroundLEDs, sizeof(yellowBackgroundLEDs) / sizeof(yellowBackgroundLEDs[0]), CRGB(249,239,11));
  setLEDColors(greenBackgroundLEDs, sizeof(greenBackgroundLEDs) / sizeof(greenBackgroundLEDs[0]), CRGB(44,254,27));
 //Green hills and Yellow clouds

 //Logo
  setLEDColors(blackLogoLEDs3, sizeof(blackLogoLEDs3) / sizeof(blackLogoLEDs3[0]), CRGB(0, 0, 0));
  setLEDColors(darkGreyLogoLEDs3, sizeof(darkGreyLogoLEDs3) / sizeof(darkGreyLogoLEDs3[0]), CRGB(90, 88, 72));
  setLEDColors(lightGreyLogoLEDs3, sizeof(lightGreyLogoLEDs3) / sizeof(lightGreyLogoLEDs3[0]), CRGB(213,212,232));
  setLEDColors(redLogoLEDs3, sizeof(redLogoLEDs3) / sizeof(redLogoLEDs3[0]), CRGB(211, 4, 4));
  setLEDColors(tanLogoLEDs3, sizeof(tanLogoLEDs3) / sizeof(tanLogoLEDs3[0]), CRGB(255, 100, 40));
  setLEDColors(yellowLogoLEDs3, sizeof(yellowLogoLEDs3) / sizeof(yellowLogoLEDs3[0]), CRGB(249,239,11));
  setLEDColors(greenLogoLEDs3, sizeof(greenLogoLEDs3) / sizeof(greenLogoLEDs3[0]), CRGB(44,254,27));
  //Mario
  setLEDColors(blackMarioLEDs3, sizeof(blackMarioLEDs3) / sizeof(blackMarioLEDs3[0]), CRGB(0, 0, 0));
  FastLED.show();
  delay(250);
  FastLED.clear();
  //set the fourth frame
    //background
  setLEDColors(yellowBackgroundLEDs, sizeof(yellowBackgroundLEDs) / sizeof(yellowBackgroundLEDs[0]), CRGB(249,239,11));
  setLEDColors(greenBackgroundLEDs, sizeof(greenBackgroundLEDs) / sizeof(greenBackgroundLEDs[0]), CRGB(44,254,27));
 //Green hills and Yellow clouds

 //Logo
  setLEDColors(blackLogoLEDs4, sizeof(blackLogoLEDs4) / sizeof(blackLogoLEDs4[0]), CRGB(0, 0, 0));
  setLEDColors(darkGreyLogoLEDs4, sizeof(darkGreyLogoLEDs4) / sizeof(darkGreyLogoLEDs4[0]), CRGB(90, 88, 72));
  setLEDColors(lightGreyLogoLEDs4, sizeof(lightGreyLogoLEDs4) / sizeof(lightGreyLogoLEDs4[0]), CRGB(213,212,232));
  setLEDColors(redLogoLEDs4, sizeof(redLogoLEDs4) / sizeof(redLogoLEDs4[0]), CRGB(211, 4, 4));
  setLEDColors(tanLogoLEDs4, sizeof(tanLogoLEDs4) / sizeof(tanLogoLEDs4[0]), CRGB(255, 100, 40));
  setLEDColors(yellowLogoLEDs4, sizeof(yellowLogoLEDs4) / sizeof(yellowLogoLEDs4[0]), CRGB(249,239,11));
  setLEDColors(greenLogoLEDs4, sizeof(greenLogoLEDs4) / sizeof(greenLogoLEDs4[0]), CRGB(44,254,27));
  //Mario
  setLEDColors(blackMarioLEDs4, sizeof(blackMarioLEDs4) / sizeof(blackMarioLEDs4[0]), CRGB(0, 0, 0));

  FastLED.show();
  delay(250);
   FastLED.clear();
   //set the 5th frame
    //background
  setLEDColors(yellowBackgroundLEDs, sizeof(yellowBackgroundLEDs) / sizeof(yellowBackgroundLEDs[0]), CRGB(249,239,11));
  setLEDColors(greenBackgroundLEDs, sizeof(greenBackgroundLEDs) / sizeof(greenBackgroundLEDs[0]), CRGB(44,254,27));
 //Green hills and Yellow clouds

 //Logo
  setLEDColors(blackLogoLEDs5, sizeof(blackLogoLEDs5) / sizeof(blackLogoLEDs5[0]), CRGB(0, 0, 0));
  setLEDColors(darkGreyLogoLEDs5, sizeof(darkGreyLogoLEDs5) / sizeof(darkGreyLogoLEDs5[0]), CRGB(90, 88, 72));
  setLEDColors(lightGreyLogoLEDs5, sizeof(lightGreyLogoLEDs5) / sizeof(lightGreyLogoLEDs5[0]), CRGB(213,212,232));
  setLEDColors(redLogoLEDs5, sizeof(redLogoLEDs5) / sizeof(redLogoLEDs5[0]), CRGB(211, 4, 4));
  setLEDColors(tanLogoLEDs5, sizeof(tanLogoLEDs5) / sizeof(tanLogoLEDs5[0]), CRGB(255, 100, 40));
  setLEDColors(yellowLogoLEDs5, sizeof(yellowLogoLEDs5) / sizeof(yellowLogoLEDs5[0]), CRGB(249,239,11));
  setLEDColors(greenLogoLEDs5, sizeof(greenLogoLEDs5) / sizeof(greenLogoLEDs5[0]), CRGB(44,254,27));
  //Mario
  setLEDColors(blackMarioLEDs5, sizeof(blackMarioLEDs5) / sizeof(blackMarioLEDs5[0]), CRGB(0, 0, 0));
  setLEDColors(redMarioLEDs5, sizeof(redMarioLEDs5) / sizeof(redMarioLEDs5[0]), CRGB(211, 4, 4));
  setLEDColors(tanMarioLEDs5, sizeof(tanMarioLEDs5) / sizeof(tanMarioLEDs5[0]), CRGB(255, 100, 40));

  FastLED.show();
  delay(250);
   FastLED.clear();
   //set the 6th frame
    //background
  setLEDColors(yellowBackgroundLEDs, sizeof(yellowBackgroundLEDs) / sizeof(yellowBackgroundLEDs[0]), CRGB(249,239,11));
  setLEDColors(greenBackgroundLEDs, sizeof(greenBackgroundLEDs) / sizeof(greenBackgroundLEDs[0]), CRGB(44,254,27));
 //Green hills and Yellow clouds

 //Logo
  setLEDColors(blackLogoLEDs6, sizeof(blackLogoLEDs6) / sizeof(blackLogoLEDs6[0]), CRGB(0, 0, 0));
  setLEDColors(darkGreyLogoLEDs6, sizeof(darkGreyLogoLEDs6) / sizeof(darkGreyLogoLEDs6[0]), CRGB(90, 88, 72));
  setLEDColors(lightGreyLogoLEDs6, sizeof(lightGreyLogoLEDs6) / sizeof(lightGreyLogoLEDs6[0]), CRGB(213,212,232));
  setLEDColors(redLogoLEDs6, sizeof(redLogoLEDs6) / sizeof(redLogoLEDs6[0]), CRGB(211, 4, 4));
  setLEDColors(tanLogoLEDs6, sizeof(tanLogoLEDs6) / sizeof(tanLogoLEDs6[0]), CRGB(255, 100, 40));
  setLEDColors(yellowLogoLEDs6, sizeof(yellowLogoLEDs6) / sizeof(yellowLogoLEDs6[0]), CRGB(249,239,11));
  setLEDColors(greenLogoLEDs6, sizeof(greenLogoLEDs6) / sizeof(greenLogoLEDs6[0]), CRGB(44,254,27));
  //Mario
  setLEDColors(blackMarioLEDs6, sizeof(blackMarioLEDs6) / sizeof(blackMarioLEDs6[0]), CRGB(0, 0, 0));
  setLEDColors(redMarioLEDs6, sizeof(redMarioLEDs6) / sizeof(redMarioLEDs6[0]), CRGB(211, 4, 4));
  setLEDColors(tanMarioLEDs6, sizeof(tanMarioLEDs6) / sizeof(tanMarioLEDs6[0]), CRGB(255, 100, 40));

  FastLED.show();
  delay(250);
   FastLED.clear();
 //set the 7th frame
    //background
  setLEDColors(yellowBackgroundLEDs, sizeof(yellowBackgroundLEDs) / sizeof(yellowBackgroundLEDs[0]), CRGB(249,239,11));
  setLEDColors(greenBackgroundLEDs, sizeof(greenBackgroundLEDs) / sizeof(greenBackgroundLEDs[0]), CRGB(44,254,27));
 //Green hills and Yellow clouds

 //Logo
  setLEDColors(blackLogoLEDs7, sizeof(blackLogoLEDs7) / sizeof(blackLogoLEDs7[0]), CRGB(0, 0, 0));
  setLEDColors(darkGreyLogoLEDs7, sizeof(darkGreyLogoLEDs7) / sizeof(darkGreyLogoLEDs7[0]), CRGB(90, 88, 72));
  setLEDColors(lightGreyLogoLEDs7, sizeof(lightGreyLogoLEDs7) / sizeof(lightGreyLogoLEDs7[0]), CRGB(213,212,232));
  setLEDColors(redLogoLEDs7, sizeof(redLogoLEDs7) / sizeof(redLogoLEDs7[0]), CRGB(211, 4, 4));
  setLEDColors(tanLogoLEDs7, sizeof(tanLogoLEDs7) / sizeof(tanLogoLEDs7[0]), CRGB(255, 100, 40));
  setLEDColors(yellowLogoLEDs7, sizeof(yellowLogoLEDs7) / sizeof(yellowLogoLEDs7[0]), CRGB(249,239,11));
  setLEDColors(greenLogoLEDs7, sizeof(greenLogoLEDs7) / sizeof(greenLogoLEDs7[0]), CRGB(44,254,27));
  //Mario
  setLEDColors(blackMarioLEDs7, sizeof(blackMarioLEDs7) / sizeof(blackMarioLEDs7[0]), CRGB(0, 0, 0));
  setLEDColors(redMarioLEDs7, sizeof(redMarioLEDs7) / sizeof(redMarioLEDs7[0]), CRGB(211, 4, 4));
  setLEDColors(tanMarioLEDs7, sizeof(tanMarioLEDs7) / sizeof(tanMarioLEDs7[0]), CRGB(255, 100, 40));

  FastLED.show();
  delay(250);
   FastLED.clear();
   //set the 8th frame
    //background
  setLEDColors(yellowBackgroundLEDs, sizeof(yellowBackgroundLEDs) / sizeof(yellowBackgroundLEDs[0]), CRGB(249,239,11));
  setLEDColors(greenBackgroundLEDs, sizeof(greenBackgroundLEDs) / sizeof(greenBackgroundLEDs[0]), CRGB(44,254,27));
 //Green hills and Yellow clouds

 //Logo
  setLEDColors(blackLogoLEDs8, sizeof(blackLogoLEDs8) / sizeof(blackLogoLEDs8[0]), CRGB(0, 0, 0));
  setLEDColors(darkGreyLogoLEDs8, sizeof(darkGreyLogoLEDs8) / sizeof(darkGreyLogoLEDs8[0]), CRGB(90, 88, 72));
  setLEDColors(lightGreyLogoLEDs8, sizeof(lightGreyLogoLEDs8) / sizeof(lightGreyLogoLEDs8[0]), CRGB(213,212,232));
  setLEDColors(redLogoLEDs8, sizeof(redLogoLEDs8) / sizeof(redLogoLEDs8[0]), CRGB(211, 4, 4));
  setLEDColors(tanLogoLEDs8, sizeof(tanLogoLEDs8) / sizeof(tanLogoLEDs8[0]), CRGB(255, 100, 40));
  setLEDColors(yellowLogoLEDs8, sizeof(yellowLogoLEDs8) / sizeof(yellowLogoLEDs8[0]), CRGB(249,239,11));
  setLEDColors(greenLogoLEDs8, sizeof(greenLogoLEDs8) / sizeof(greenLogoLEDs8[0]), CRGB(44,254,27));
  //Mario
  setLEDColors(blackMarioLEDs8, sizeof(blackMarioLEDs8) / sizeof(blackMarioLEDs8[0]), CRGB(0, 0, 0));
  setLEDColors(redMarioLEDs8, sizeof(redMarioLEDs8) / sizeof(redMarioLEDs8[0]), CRGB(211, 4, 4));
  setLEDColors(tanMarioLEDs8, sizeof(tanMarioLEDs8) / sizeof(tanMarioLEDs8[0]), CRGB(255, 100, 40));

  FastLED.show();
  delay(250);
   FastLED.clear();
   //set the 9th frame
    //background
  setLEDColors(yellowBackgroundLEDs, sizeof(yellowBackgroundLEDs) / sizeof(yellowBackgroundLEDs[0]), CRGB(249,239,11));
  setLEDColors(greenBackgroundLEDs, sizeof(greenBackgroundLEDs) / sizeof(greenBackgroundLEDs[0]), CRGB(44,254,27));
 //Green hills and Yellow clouds

 //Logo
  setLEDColors(blackLogoLEDs9, sizeof(blackLogoLEDs9) / sizeof(blackLogoLEDs9[0]), CRGB(0, 0, 0));
  setLEDColors(darkGreyLogoLEDs9, sizeof(darkGreyLogoLEDs9) / sizeof(darkGreyLogoLEDs9[0]), CRGB(90, 88, 72));
  setLEDColors(lightGreyLogoLEDs9, sizeof(lightGreyLogoLEDs9) / sizeof(lightGreyLogoLEDs9[0]), CRGB(213,212,232));
  setLEDColors(redLogoLEDs9, sizeof(redLogoLEDs9) / sizeof(redLogoLEDs9[0]), CRGB(211, 4, 4));
  setLEDColors(tanLogoLEDs9, sizeof(tanLogoLEDs9) / sizeof(tanLogoLEDs9[0]), CRGB(255, 100, 40));
  setLEDColors(yellowLogoLEDs9, sizeof(yellowLogoLEDs9) / sizeof(yellowLogoLEDs9[0]), CRGB(249,239,11));
  setLEDColors(greenLogoLEDs9, sizeof(greenLogoLEDs9) / sizeof(greenLogoLEDs9[0]), CRGB(44,254,27));
  //Mario
  setLEDColors(blackMarioLEDs9, sizeof(blackMarioLEDs9) / sizeof(blackMarioLEDs9[0]), CRGB(0, 0, 0));
  setLEDColors(redMarioLEDs9, sizeof(redMarioLEDs9) / sizeof(redMarioLEDs9[0]), CRGB(211, 4, 4));
  setLEDColors(tanMarioLEDs9, sizeof(tanMarioLEDs9) / sizeof(tanMarioLEDs9[0]), CRGB(255, 100, 40));

  FastLED.show();
  delay(250);
   FastLED.clear();
    //set the 10th frame
    //background
  setLEDColors(yellowBackgroundLEDs, sizeof(yellowBackgroundLEDs) / sizeof(yellowBackgroundLEDs[0]), CRGB(249,239,11));
  setLEDColors(greenBackgroundLEDs, sizeof(greenBackgroundLEDs) / sizeof(greenBackgroundLEDs[0]), CRGB(44,254,27));
 //Green hills and Yellow clouds

 //Logo
  setLEDColors(blackLogoLEDs10, sizeof(blackLogoLEDs10) / sizeof(blackLogoLEDs10[0]), CRGB(0, 0, 0));
  setLEDColors(darkGreyLogoLEDs10, sizeof(darkGreyLogoLEDs10) / sizeof(darkGreyLogoLEDs10[0]), CRGB(90, 88, 72));
  setLEDColors(lightGreyLogoLEDs10, sizeof(lightGreyLogoLEDs10) / sizeof(lightGreyLogoLEDs10[0]), CRGB(213,212,232));
  setLEDColors(redLogoLEDs10, sizeof(redLogoLEDs10) / sizeof(redLogoLEDs10[0]), CRGB(211, 4, 4));
  setLEDColors(yellowLogoLEDs10, sizeof(yellowLogoLEDs10) / sizeof(yellowLogoLEDs10[0]), CRGB(249,239,11));
  setLEDColors(greenLogoLEDs10, sizeof(greenLogoLEDs10) / sizeof(greenLogoLEDs9[0]), CRGB(44,254,27));
  //Mario
  setLEDColors(blackMarioLEDs10, sizeof(blackMarioLEDs10) / sizeof(blackMarioLEDs10[0]), CRGB(0, 0, 0));
  setLEDColors(redMarioLEDs10, sizeof(redMarioLEDs10) / sizeof(redMarioLEDs10[0]), CRGB(211, 4, 4));
  setLEDColors(tanMarioLEDs10, sizeof(tanMarioLEDs10) / sizeof(tanMarioLEDs10[0]), CRGB(255, 100, 40));

  FastLED.show();
  delay(250);
   FastLED.clear();
    //set the 11th frame
    //background
  setLEDColors(yellowBackgroundLEDs, sizeof(yellowBackgroundLEDs) / sizeof(yellowBackgroundLEDs[0]), CRGB(249,239,11));
  setLEDColors(greenBackgroundLEDs, sizeof(greenBackgroundLEDs) / sizeof(greenBackgroundLEDs[0]), CRGB(44,254,27));
 //Green hills and Yellow clouds

 //Logo
  setLEDColors(blackLogoLEDs11, sizeof(blackLogoLEDs11) / sizeof(blackLogoLEDs11[0]), CRGB(0, 0, 0));
  setLEDColors(darkGreyLogoLEDs11, sizeof(darkGreyLogoLEDs11) / sizeof(darkGreyLogoLEDs11[0]), CRGB(90, 88, 72));
  setLEDColors(lightGreyLogoLEDs11, sizeof(lightGreyLogoLEDs11) / sizeof(lightGreyLogoLEDs11[0]), CRGB(213,212,232));
  setLEDColors(redLogoLEDs11, sizeof(redLogoLEDs11) / sizeof(redLogoLEDs11[0]), CRGB(211, 4, 4));
  setLEDColors(yellowLogoLEDs11, sizeof(yellowLogoLEDs11) / sizeof(yellowLogoLEDs11[0]), CRGB(249,239,11));
  setLEDColors(greenLogoLEDs11, sizeof(greenLogoLEDs11) / sizeof(greenLogoLEDs11[0]), CRGB(44,254,27));
  //Mario
  setLEDColors(blackMarioLEDs11, sizeof(blackMarioLEDs11) / sizeof(blackMarioLEDs11[0]), CRGB(0, 0, 0));
  setLEDColors(redMarioLEDs11, sizeof(redMarioLEDs11) / sizeof(redMarioLEDs11[0]), CRGB(211, 4, 4));
  setLEDColors(tanMarioLEDs11, sizeof(tanMarioLEDs11) / sizeof(tanMarioLEDs11[0]), CRGB(255, 100, 40));

  FastLED.show();
  delay(250);
   FastLED.clear();

    //set the 12th frame
    //background
  setLEDColors(yellowBackgroundLEDs, sizeof(yellowBackgroundLEDs) / sizeof(yellowBackgroundLEDs[0]), CRGB(249,239,11));
  setLEDColors(greenBackgroundLEDs, sizeof(greenBackgroundLEDs) / sizeof(greenBackgroundLEDs[0]), CRGB(44,254,27));
 //Green hills and Yellow clouds

 //Logo
  setLEDColors(blackLogoLEDs12, sizeof(blackLogoLEDs12) / sizeof(blackLogoLEDs12[0]), CRGB(0, 0, 0));
  setLEDColors(darkGreyLogoLEDs12, sizeof(darkGreyLogoLEDs12) / sizeof(darkGreyLogoLEDs12[0]), CRGB(90, 88, 72));
  setLEDColors(lightGreyLogoLEDs12, sizeof(lightGreyLogoLEDs12) / sizeof(lightGreyLogoLEDs12[0]), CRGB(213,212,232));
  setLEDColors(redLogoLEDs12, sizeof(redLogoLEDs12) / sizeof(redLogoLEDs12[0]), CRGB(211, 4, 4));
  setLEDColors(greenLogoLEDs12, sizeof(greenLogoLEDs12) / sizeof(greenLogoLEDs12[0]), CRGB(44,254,27));
  //Mario
  setLEDColors(blackMarioLEDs12, sizeof(blackMarioLEDs12) / sizeof(blackMarioLEDs12[0]), CRGB(0, 0, 0));
  setLEDColors(redMarioLEDs12, sizeof(redMarioLEDs12) / sizeof(redMarioLEDs12[0]), CRGB(211, 4, 4));
  setLEDColors(tanMarioLEDs12, sizeof(tanMarioLEDs12) / sizeof(tanMarioLEDs12[0]), CRGB(255, 100, 40));

  FastLED.show();
  delay(250);
   FastLED.clear();
 
     //set the 13th frame
    //background
  setLEDColors(yellowBackgroundLEDs, sizeof(yellowBackgroundLEDs) / sizeof(yellowBackgroundLEDs[0]), CRGB(249,239,11));
  setLEDColors(greenBackgroundLEDs, sizeof(greenBackgroundLEDs) / sizeof(greenBackgroundLEDs[0]), CRGB(44,254,27));
 //Green hills and Yellow clouds

 //Logo
  setLEDColors(blackLogoLEDs13, sizeof(blackLogoLEDs13) / sizeof(blackLogoLEDs13[0]), CRGB(0, 0, 0));
  setLEDColors(darkGreyLogoLEDs13, sizeof(darkGreyLogoLEDs13) / sizeof(darkGreyLogoLEDs13[0]), CRGB(90, 88, 72));
  setLEDColors(lightGreyLogoLEDs13, sizeof(lightGreyLogoLEDs13) / sizeof(lightGreyLogoLEDs13[0]), CRGB(213,212,232));
  setLEDColors(redLogoLEDs13, sizeof(redLogoLEDs13) / sizeof(redLogoLEDs13[0]), CRGB(211, 4, 4));
  setLEDColors(greenLogoLEDs13, sizeof(greenLogoLEDs13) / sizeof(greenLogoLEDs13[0]), CRGB(44,254,27));
  //Mario
  setLEDColors(blackMarioLEDs13, sizeof(blackMarioLEDs13) / sizeof(blackMarioLEDs13[0]), CRGB(0, 0, 0));
  setLEDColors(redMarioLEDs13, sizeof(redMarioLEDs13) / sizeof(redMarioLEDs13[0]), CRGB(211, 4, 4));
  setLEDColors(tanMarioLEDs13, sizeof(tanMarioLEDs13) / sizeof(tanMarioLEDs13[0]), CRGB(255, 100, 40));

  FastLED.show();
  delay(250);
   FastLED.clear();
 
     //set the 14th frame
    //background
  setLEDColors(yellowBackgroundLEDs, sizeof(yellowBackgroundLEDs) / sizeof(yellowBackgroundLEDs[0]), CRGB(249,239,11));
  setLEDColors(greenBackgroundLEDs, sizeof(greenBackgroundLEDs) / sizeof(greenBackgroundLEDs[0]), CRGB(44,254,27));
 //Green hills and Yellow clouds

 //Logo
  setLEDColors(blackLogoLEDs14, sizeof(blackLogoLEDs14) / sizeof(blackLogoLEDs14[0]), CRGB(0, 0, 0));
  setLEDColors(darkGreyLogoLEDs14, sizeof(darkGreyLogoLEDs14) / sizeof(darkGreyLogoLEDs14[0]), CRGB(90, 88, 72));
  setLEDColors(lightGreyLogoLEDs14, sizeof(lightGreyLogoLEDs14) / sizeof(lightGreyLogoLEDs14[0]), CRGB(213,212,232));
  setLEDColors(redLogoLEDs14, sizeof(redLogoLEDs14) / sizeof(redLogoLEDs14[0]), CRGB(211, 4, 4));
  //Mario
  setLEDColors(blackMarioLEDs14, sizeof(blackMarioLEDs14) / sizeof(blackMarioLEDs14[0]), CRGB(0, 0, 0));
  setLEDColors(redMarioLEDs14, sizeof(redMarioLEDs14) / sizeof(redMarioLEDs14[0]), CRGB(211, 4, 4));
  setLEDColors(tanMarioLEDs14, sizeof(tanMarioLEDs14) / sizeof(tanMarioLEDs14[0]), CRGB(255, 100, 40));

  FastLED.show();
  delay(250);
   FastLED.clear();
 
     //set the 15th frame
    //background
  setLEDColors(yellowBackgroundLEDs, sizeof(yellowBackgroundLEDs) / sizeof(yellowBackgroundLEDs[0]), CRGB(249,239,11));
  setLEDColors(greenBackgroundLEDs, sizeof(greenBackgroundLEDs) / sizeof(greenBackgroundLEDs[0]), CRGB(44,254,27));
 //Green hills and Yellow clouds

 //Logo
  setLEDColors(blackLogoLEDs15, sizeof(blackLogoLEDs15) / sizeof(blackLogoLEDs15[0]), CRGB(0, 0, 0));
  setLEDColors(darkGreyLogoLEDs15, sizeof(darkGreyLogoLEDs15) / sizeof(darkGreyLogoLEDs15[0]), CRGB(90, 88, 72));
  setLEDColors(lightGreyLogoLEDs15, sizeof(lightGreyLogoLEDs15) / sizeof(lightGreyLogoLEDs15[0]), CRGB(213,212,232));
  setLEDColors(redLogoLEDs15, sizeof(redLogoLEDs15) / sizeof(redLogoLEDs15[0]), CRGB(211, 4, 4));
  //Mario
  setLEDColors(blackMarioLEDs15, sizeof(blackMarioLEDs15) / sizeof(blackMarioLEDs15[0]), CRGB(0, 0, 0));
  setLEDColors(redMarioLEDs15, sizeof(redMarioLEDs15) / sizeof(redMarioLEDs15[0]), CRGB(211, 4, 4));
  setLEDColors(tanMarioLEDs15, sizeof(tanMarioLEDs15) / sizeof(tanMarioLEDs15[0]), CRGB(255, 100, 40));

  FastLED.show();
  delay(250);
   FastLED.clear();
 
     //set the 16th frame
    //background
  setLEDColors(yellowBackgroundLEDs, sizeof(yellowBackgroundLEDs) / sizeof(yellowBackgroundLEDs[0]), CRGB(249,239,11));
  setLEDColors(greenBackgroundLEDs, sizeof(greenBackgroundLEDs) / sizeof(greenBackgroundLEDs[0]), CRGB(44,254,27));
 //Green hills and Yellow clouds

 //Logo
  setLEDColors(darkGreyLogoLEDs16, sizeof(darkGreyLogoLEDs16) / sizeof(darkGreyLogoLEDs16[0]), CRGB(90, 88, 72));
  //Mario
  setLEDColors(blackMarioLEDs16, sizeof(blackMarioLEDs16) / sizeof(blackMarioLEDs16[0]), CRGB(0, 0, 0));
  setLEDColors(redMarioLEDs16, sizeof(redMarioLEDs16) / sizeof(redMarioLEDs16[0]), CRGB(211, 4, 4));
  setLEDColors(tanMarioLEDs16, sizeof(tanMarioLEDs16) / sizeof(tanMarioLEDs16[0]), CRGB(255, 100, 40));

  FastLED.show();
  delay(250);
   FastLED.clear();
 
     //set the 17th frame
    //background
  setLEDColors(yellowBackgroundLEDs, sizeof(yellowBackgroundLEDs) / sizeof(yellowBackgroundLEDs[0]), CRGB(249,239,11));
  setLEDColors(greenBackgroundLEDs, sizeof(greenBackgroundLEDs) / sizeof(greenBackgroundLEDs[0]), CRGB(44,254,27));
 //Green hills and Yellow clouds

  //Mario
  setLEDColors(blackMarioLEDs17, sizeof(blackMarioLEDs17) / sizeof(blackMarioLEDs17[0]), CRGB(0, 0, 0));
  setLEDColors(redMarioLEDs17, sizeof(redMarioLEDs17) / sizeof(redMarioLEDs17[0]), CRGB(211, 4, 4));
  setLEDColors(tanMarioLEDs17, sizeof(tanMarioLEDs17) / sizeof(tanMarioLEDs17[0]), CRGB(255, 100, 40));

  FastLED.show();
  delay(250);
   FastLED.clear();
 
     //set the 18th frame
    //background
  setLEDColors(yellowBackgroundLEDs, sizeof(yellowBackgroundLEDs) / sizeof(yellowBackgroundLEDs[0]), CRGB(249,239,11));
  setLEDColors(greenBackgroundLEDs, sizeof(greenBackgroundLEDs) / sizeof(greenBackgroundLEDs[0]), CRGB(44,254,27));
 //Green hills and Yellow clouds

  //Mario
  setLEDColors(blackMarioLEDs18, sizeof(blackMarioLEDs18) / sizeof(blackMarioLEDs18[0]), CRGB(0, 0, 0));
  setLEDColors(redMarioLEDs18, sizeof(redMarioLEDs18) / sizeof(redMarioLEDs18[0]), CRGB(211, 4, 4));
  setLEDColors(tanMarioLEDs18, sizeof(tanMarioLEDs18) / sizeof(tanMarioLEDs18[0]), CRGB(255, 100, 40));

  FastLED.show();
  delay(250);
   FastLED.clear();
 
     //set the 19th frame
    //background
  setLEDColors(yellowBackgroundLEDs, sizeof(yellowBackgroundLEDs) / sizeof(yellowBackgroundLEDs[0]), CRGB(249,239,11));
  setLEDColors(greenBackgroundLEDs, sizeof(greenBackgroundLEDs) / sizeof(greenBackgroundLEDs[0]), CRGB(44,254,27));
 //Green hills and Yellow clouds

  //Mario
  setLEDColors(blackMarioLEDs19, sizeof(blackMarioLEDs19) / sizeof(blackMarioLEDs19[0]), CRGB(0, 0, 0));
  setLEDColors(redMarioLEDs19, sizeof(redMarioLEDs19) / sizeof(redMarioLEDs19[0]), CRGB(211, 4, 4));
  setLEDColors(tanMarioLEDs19, sizeof(tanMarioLEDs19) / sizeof(tanMarioLEDs19[0]), CRGB(255, 100, 40));

  FastLED.show();
  delay(250);
   FastLED.clear();
 
     //set the 20th frame
    //background
  setLEDColors(yellowBackgroundLEDs, sizeof(yellowBackgroundLEDs) / sizeof(yellowBackgroundLEDs[0]), CRGB(249,239,11));
  setLEDColors(greenBackgroundLEDs, sizeof(greenBackgroundLEDs) / sizeof(greenBackgroundLEDs[0]), CRGB(44,254,27));
 //Green hills and Yellow clouds

  //Mario
  setLEDColors(blackMarioLEDs20, sizeof(blackMarioLEDs20) / sizeof(blackMarioLEDs20[0]), CRGB(0, 0, 0));
  setLEDColors(redMarioLEDs20, sizeof(redMarioLEDs20) / sizeof(redMarioLEDs20[0]), CRGB(211, 4, 4));
  setLEDColors(tanMarioLEDs20, sizeof(tanMarioLEDs20) / sizeof(tanMarioLEDs20[0]), CRGB(255, 100, 40));

  FastLED.show();
  delay(250);
   FastLED.clear();
 
     //set the 21st frame
    //background
  setLEDColors(yellowBackgroundLEDs, sizeof(yellowBackgroundLEDs) / sizeof(yellowBackgroundLEDs[0]), CRGB(249,239,11));
  setLEDColors(greenBackgroundLEDs, sizeof(greenBackgroundLEDs) / sizeof(greenBackgroundLEDs[0]), CRGB(44,254,27));
 //Green hills and Yellow clouds

  //Mario
  setLEDColors(blackMarioLEDs21, sizeof(blackMarioLEDs21) / sizeof(blackMarioLEDs21[0]), CRGB(0, 0, 0));
  setLEDColors(redMarioLEDs21, sizeof(redMarioLEDs21) / sizeof(redMarioLEDs21[0]), CRGB(211, 4, 4));
  setLEDColors(tanMarioLEDs21, sizeof(tanMarioLEDs21) / sizeof(tanMarioLEDs21[0]), CRGB(255, 100, 40));

  FastLED.show();
  delay(250);
   FastLED.clear();
 
     //set the 22nd frame
    //background
  setLEDColors(yellowBackgroundLEDs, sizeof(yellowBackgroundLEDs) / sizeof(yellowBackgroundLEDs[0]), CRGB(249,239,11));
  setLEDColors(greenBackgroundLEDs, sizeof(greenBackgroundLEDs) / sizeof(greenBackgroundLEDs[0]), CRGB(44,254,27));
 //Green hills and Yellow clouds

  //Mario
  setLEDColors(blackMarioLEDs22, sizeof(blackMarioLEDs22) / sizeof(blackMarioLEDs22[0]), CRGB(0, 0, 0));
  setLEDColors(redMarioLEDs22, sizeof(redMarioLEDs22) / sizeof(redMarioLEDs22[0]), CRGB(211, 4, 4));
  setLEDColors(tanMarioLEDs22, sizeof(tanMarioLEDs22) / sizeof(tanMarioLEDs22[0]), CRGB(255, 100, 40));

  FastLED.show();
  delay(250);
   FastLED.clear();
 
     //set the 23rd frame
    //background
  setLEDColors(yellowBackgroundLEDs, sizeof(yellowBackgroundLEDs) / sizeof(yellowBackgroundLEDs[0]), CRGB(249,239,11));
  setLEDColors(greenBackgroundLEDs, sizeof(greenBackgroundLEDs) / sizeof(greenBackgroundLEDs[0]), CRGB(44,254,27));
 //Green hills and Yellow clouds

  //Mario
  setLEDColors(blackMarioLEDs23, sizeof(blackMarioLEDs23) / sizeof(blackMarioLEDs23[0]), CRGB(0, 0, 0));
  setLEDColors(redMarioLEDs23, sizeof(redMarioLEDs23) / sizeof(redMarioLEDs23[0]), CRGB(211, 4, 4));
  setLEDColors(tanMarioLEDs23, sizeof(tanMarioLEDs23) / sizeof(tanMarioLEDs23[0]), CRGB(255, 100, 40));

  FastLED.show();
  delay(250);
   FastLED.clear();
 
     //set the 24th frame
    //background
  setLEDColors(yellowBackgroundLEDs, sizeof(yellowBackgroundLEDs) / sizeof(yellowBackgroundLEDs[0]), CRGB(249,239,11));
  setLEDColors(greenBackgroundLEDs, sizeof(greenBackgroundLEDs) / sizeof(greenBackgroundLEDs[0]), CRGB(44,254,27));
 //Green hills and Yellow clouds

  //Mario
  setLEDColors(blackMarioLEDs24, sizeof(blackMarioLEDs24) / sizeof(blackMarioLEDs24[0]), CRGB(0, 0, 0));
  setLEDColors(redMarioLEDs24, sizeof(redMarioLEDs24) / sizeof(redMarioLEDs24[0]), CRGB(211, 4, 4));
  setLEDColors(tanMarioLEDs24, sizeof(tanMarioLEDs24) / sizeof(tanMarioLEDs24[0]), CRGB(255, 100, 40));

  FastLED.show();
  delay(250);
   FastLED.clear();
 
     //set the 25th frame
    //background
  setLEDColors(yellowBackgroundLEDs, sizeof(yellowBackgroundLEDs) / sizeof(yellowBackgroundLEDs[0]), CRGB(249,239,11));
  setLEDColors(greenBackgroundLEDs, sizeof(greenBackgroundLEDs) / sizeof(greenBackgroundLEDs[0]), CRGB(44,254,27));
 //Green hills and Yellow clouds

  //Mario
  setLEDColors(blackMarioLEDs25, sizeof(blackMarioLEDs25) / sizeof(blackMarioLEDs25[0]), CRGB(0, 0, 0));
  setLEDColors(redMarioLEDs25, sizeof(redMarioLEDs25) / sizeof(redMarioLEDs25[0]), CRGB(211, 4, 4));
  setLEDColors(tanMarioLEDs25, sizeof(tanMarioLEDs25) / sizeof(tanMarioLEDs25[0]), CRGB(255, 100, 40));

  FastLED.show();
  delay(250);
   FastLED.clear();
 
     //set the 26th frame
    //background
  setLEDColors(yellowBackgroundLEDs, sizeof(yellowBackgroundLEDs) / sizeof(yellowBackgroundLEDs[0]), CRGB(249,239,11));
  setLEDColors(greenBackgroundLEDs, sizeof(greenBackgroundLEDs) / sizeof(greenBackgroundLEDs[0]), CRGB(44,254,27));
 //Green hills and Yellow clouds

  //Mario
  setLEDColors(blackMarioLEDs26, sizeof(blackMarioLEDs26) / sizeof(blackMarioLEDs26[0]), CRGB(0, 0, 0));
  setLEDColors(redMarioLEDs26, sizeof(redMarioLEDs26) / sizeof(redMarioLEDs26[0]), CRGB(211, 4, 4));
  setLEDColors(tanMarioLEDs26, sizeof(tanMarioLEDs26) / sizeof(tanMarioLEDs26[0]), CRGB(255, 100, 40));

  FastLED.show();
  delay(250);
   FastLED.clear();
 
     //set the 27th frame
    //background
  setLEDColors(yellowBackgroundLEDs, sizeof(yellowBackgroundLEDs) / sizeof(yellowBackgroundLEDs[0]), CRGB(249,239,11));
  setLEDColors(greenBackgroundLEDs, sizeof(greenBackgroundLEDs) / sizeof(greenBackgroundLEDs[0]), CRGB(44,254,27));
 //Green hills and Yellow clouds

  //Mario
  setLEDColors(blackMarioLEDs27, sizeof(blackMarioLEDs27) / sizeof(blackMarioLEDs27[0]), CRGB(0, 0, 0));
  setLEDColors(redMarioLEDs27, sizeof(redMarioLEDs27) / sizeof(redMarioLEDs27[0]), CRGB(211, 4, 4));
  setLEDColors(tanMarioLEDs27, sizeof(tanMarioLEDs27) / sizeof(tanMarioLEDs27[0]), CRGB(255, 100, 40));

  FastLED.show();
  delay(250);
   FastLED.clear();
 
     //set the 28th frame
    //background
  setLEDColors(yellowBackgroundLEDs, sizeof(yellowBackgroundLEDs) / sizeof(yellowBackgroundLEDs[0]), CRGB(249,239,11));
  setLEDColors(greenBackgroundLEDs, sizeof(greenBackgroundLEDs) / sizeof(greenBackgroundLEDs[0]), CRGB(44,254,27));
 //Green hills and Yellow clouds

  //Mario
  setLEDColors(blackMarioLEDs28, sizeof(blackMarioLEDs28) / sizeof(blackMarioLEDs28[0]), CRGB(0, 0, 0));
  setLEDColors(redMarioLEDs28, sizeof(redMarioLEDs28) / sizeof(redMarioLEDs28[0]), CRGB(211, 4, 4));
  setLEDColors(tanMarioLEDs28, sizeof(tanMarioLEDs28) / sizeof(tanMarioLEDs28[0]), CRGB(255, 100, 40));

  FastLED.show();
  delay(250);
   FastLED.clear();
 
     //set the 29th frame
    //background
  setLEDColors(yellowBackgroundLEDs, sizeof(yellowBackgroundLEDs) / sizeof(yellowBackgroundLEDs[0]), CRGB(249,239,11));
  setLEDColors(greenBackgroundLEDs, sizeof(greenBackgroundLEDs) / sizeof(greenBackgroundLEDs[0]), CRGB(44,254,27));
 //Green hills and Yellow clouds

  //Mario
  setLEDColors(blackMarioLEDs29, sizeof(blackMarioLEDs29) / sizeof(blackMarioLEDs29[0]), CRGB(0, 0, 0));
  setLEDColors(redMarioLEDs29, sizeof(redMarioLEDs29) / sizeof(redMarioLEDs29[0]), CRGB(211, 4, 4));
  setLEDColors(tanMarioLEDs29, sizeof(tanMarioLEDs29) / sizeof(tanMarioLEDs29[0]), CRGB(255, 100, 40));

  FastLED.show();
  delay(250);
   FastLED.clear();
 
     //Set the 30th frame
    //background
  setLEDColors(yellowBackgroundLEDs, sizeof(yellowBackgroundLEDs) / sizeof(yellowBackgroundLEDs[0]), CRGB(249,239,11));
  setLEDColors(greenBackgroundLEDs, sizeof(greenBackgroundLEDs) / sizeof(greenBackgroundLEDs[0]), CRGB(44,254,27));
 //Green hills and Yellow clouds

  //Mario
  setLEDColors(blackMarioLEDs30, sizeof(blackMarioLEDs30) / sizeof(blackMarioLEDs30[0]), CRGB(0, 0, 0));
  setLEDColors(tanMarioLEDs30, sizeof(tanMarioLEDs30) / sizeof(tanMarioLEDs30[0]), CRGB(255, 100, 40));

  FastLED.show();
  delay(250);
   FastLED.clear();
 
     //Set the 31st frame
    //background
  setLEDColors(yellowBackgroundLEDs, sizeof(yellowBackgroundLEDs) / sizeof(yellowBackgroundLEDs[0]), CRGB(249,239,11));
  setLEDColors(greenBackgroundLEDs, sizeof(greenBackgroundLEDs) / sizeof(greenBackgroundLEDs[0]), CRGB(44,254,27));
 //Green hills and Yellow clouds

  //Mario
  setLEDColors(blackMarioLEDs31, sizeof(blackMarioLEDs31) / sizeof(blackMarioLEDs31[0]), CRGB(0, 0, 0));
  setLEDColors(tanMarioLEDs31, sizeof(tanMarioLEDs31) / sizeof(tanMarioLEDs31[0]), CRGB(255, 100, 40));

  FastLED.show();
  delay(250);
   FastLED.clear();
 
      //Set the 71st frame
    //background
  setLEDColors(yellowBackgroundLEDs, sizeof(yellowBackgroundLEDs) / sizeof(yellowBackgroundLEDs[0]), CRGB(249,239,11));
  setLEDColors(greenBackgroundLEDs, sizeof(greenBackgroundLEDs) / sizeof(greenBackgroundLEDs[0]), CRGB(44,254,27));
 //Green hills and Yellow clouds

  //logo
  setLEDColors(darkGreyLogoLEDs71, sizeof(darkGreyLogoLEDs71) / sizeof(darkGreyLogoLEDs71[0]), CRGB(90, 88, 72));

  FastLED.show();
  delay(250);
   FastLED.clear();


      //Set the 72st frame
    //background
  setLEDColors(yellowBackgroundLEDs, sizeof(yellowBackgroundLEDs) / sizeof(yellowBackgroundLEDs[0]), CRGB(249,239,11));
  setLEDColors(greenBackgroundLEDs, sizeof(greenBackgroundLEDs) / sizeof(greenBackgroundLEDs[0]), CRGB(44,254,27));
 //Green hills and Yellow clouds

  //logo
  setLEDColors(darkGreyLogoLEDs72, sizeof(darkGreyLogoLEDs72) / sizeof(darkGreyLogoLEDs72[0]), CRGB(90, 88, 72));
  setLEDColors(lightGreyLogoLEDs72, sizeof(lightGreyLogoLEDs72) / sizeof(lightGreyLogoLEDs72[0]), CRGB(213,212,232));
  setLEDColors(redLogoLEDs72, sizeof(redLogoLEDs72) / sizeof(redLogoLEDs72[0]), CRGB(211, 4, 4));
  setLEDColors(blackLogoLEDs72, sizeof(blackLogoLEDs72) / sizeof(blackLogoLEDs72[0]), CRGB(0, 0, 0));
  FastLED.show();
  delay(250);
   FastLED.clear();
 
      //Set the 73st frame
    //background
  setLEDColors(yellowBackgroundLEDs, sizeof(yellowBackgroundLEDs) / sizeof(yellowBackgroundLEDs[0]), CRGB(249,239,11));
  setLEDColors(greenBackgroundLEDs, sizeof(greenBackgroundLEDs) / sizeof(greenBackgroundLEDs[0]), CRGB(44,254,27));
 //Green hills and Yellow clouds

  //logo
  setLEDColors(darkGreyLogoLEDs73, sizeof(darkGreyLogoLEDs73) / sizeof(darkGreyLogoLEDs73[0]), CRGB(90, 88, 72));
  setLEDColors(lightGreyLogoLEDs73, sizeof(lightGreyLogoLEDs73) / sizeof(lightGreyLogoLEDs73[0]), CRGB(213,212,232));
  setLEDColors(redLogoLEDs73, sizeof(redLogoLEDs73) / sizeof(redLogoLEDs73[0]), CRGB(211, 4, 4));
  setLEDColors(blackLogoLEDs73, sizeof(blackLogoLEDs73) / sizeof(blackLogoLEDs73[0]), CRGB(0, 0, 0));
  FastLED.show();
  delay(250);
   FastLED.clear();
 
      //Set the 74st frame
    //background
  setLEDColors(yellowBackgroundLEDs, sizeof(yellowBackgroundLEDs) / sizeof(yellowBackgroundLEDs[0]), CRGB(249,239,11));
  setLEDColors(greenBackgroundLEDs, sizeof(greenBackgroundLEDs) / sizeof(greenBackgroundLEDs[0]), CRGB(44,254,27));
 //Green hills and Yellow clouds

  //logo
  setLEDColors(darkGreyLogoLEDs74, sizeof(darkGreyLogoLEDs74) / sizeof(darkGreyLogoLEDs74[0]), CRGB(90, 88, 72));
  setLEDColors(lightGreyLogoLEDs74, sizeof(lightGreyLogoLEDs74) / sizeof(lightGreyLogoLEDs74[0]), CRGB(213,212,232));
  setLEDColors(redLogoLEDs74, sizeof(redLogoLEDs74) / sizeof(redLogoLEDs74[0]), CRGB(211, 4, 4));
  setLEDColors(greenLogoLEDs74, sizeof(greenLogoLEDs74) / sizeof(greenLogoLEDs74[0]), CRGB(44,254,27));
  setLEDColors(blackLogoLEDs74, sizeof(blackLogoLEDs74) / sizeof(blackLogoLEDs74[0]), CRGB(0, 0, 0));
  FastLED.show();
  delay(250);
   FastLED.clear();
 
      //Set the 75st frame
    //background
  setLEDColors(yellowBackgroundLEDs, sizeof(yellowBackgroundLEDs) / sizeof(yellowBackgroundLEDs[0]), CRGB(249,239,11));
  setLEDColors(greenBackgroundLEDs, sizeof(greenBackgroundLEDs) / sizeof(greenBackgroundLEDs[0]), CRGB(44,254,27));
 //Green hills and Yellow clouds

  //logo
  setLEDColors(darkGreyLogoLEDs75, sizeof(darkGreyLogoLEDs75) / sizeof(darkGreyLogoLEDs75[0]), CRGB(90, 88, 72));
  setLEDColors(lightGreyLogoLEDs75, sizeof(lightGreyLogoLEDs75) / sizeof(lightGreyLogoLEDs75[0]), CRGB(213,212,232));
  setLEDColors(redLogoLEDs75, sizeof(redLogoLEDs75) / sizeof(redLogoLEDs75[0]), CRGB(211, 4, 4));
  setLEDColors(greenLogoLEDs75, sizeof(greenLogoLEDs75) / sizeof(greenLogoLEDs75[0]), CRGB(44,254,27));
  setLEDColors(blackLogoLEDs75, sizeof(blackLogoLEDs75) / sizeof(blackLogoLEDs75[0]), CRGB(0, 0, 0));
  FastLED.show();
  delay(250);
   FastLED.clear();
 
      //Set the 76st frame
    //background
  setLEDColors(yellowBackgroundLEDs, sizeof(yellowBackgroundLEDs) / sizeof(yellowBackgroundLEDs[0]), CRGB(249,239,11));
  setLEDColors(greenBackgroundLEDs, sizeof(greenBackgroundLEDs) / sizeof(greenBackgroundLEDs[0]), CRGB(44,254,27));
 //Green hills and Yellow clouds

  //logo
  setLEDColors(darkGreyLogoLEDs76, sizeof(darkGreyLogoLEDs76) / sizeof(darkGreyLogoLEDs76[0]), CRGB(90, 88, 72));
  setLEDColors(lightGreyLogoLEDs76, sizeof(lightGreyLogoLEDs76) / sizeof(lightGreyLogoLEDs76[0]), CRGB(213,212,232));
  setLEDColors(redLogoLEDs76, sizeof(redLogoLEDs76) / sizeof(redLogoLEDs76[0]), CRGB(211, 4, 4));
  setLEDColors(yellowLogoLEDs76, sizeof(yellowLogoLEDs76) / sizeof(yellowLogoLEDs76[0]), CRGB(249,239,11));
  setLEDColors(greenLogoLEDs76, sizeof(greenLogoLEDs76) / sizeof(greenLogoLEDs76[0]), CRGB(44,254,27));
  setLEDColors(blackLogoLEDs76, sizeof(blackLogoLEDs76) / sizeof(blackLogoLEDs76[0]), CRGB(0, 0, 0));
  FastLED.show();
  delay(250);
   FastLED.clear();
 
      //Set the 77st frame
    //background
  setLEDColors(yellowBackgroundLEDs, sizeof(yellowBackgroundLEDs) / sizeof(yellowBackgroundLEDs[0]), CRGB(249,239,11));
  setLEDColors(greenBackgroundLEDs, sizeof(greenBackgroundLEDs) / sizeof(greenBackgroundLEDs[0]), CRGB(44,254,27));
 //Green hills and Yellow clouds

  //logo
  setLEDColors(darkGreyLogoLEDs77, sizeof(darkGreyLogoLEDs77) / sizeof(darkGreyLogoLEDs77[0]), CRGB(90, 88, 72));
  setLEDColors(lightGreyLogoLEDs77, sizeof(lightGreyLogoLEDs77) / sizeof(lightGreyLogoLEDs77[0]), CRGB(213,212,232));
  setLEDColors(redLogoLEDs77, sizeof(redLogoLEDs77) / sizeof(redLogoLEDs77[0]), CRGB(211, 4, 4));
  setLEDColors(yellowLogoLEDs77, sizeof(yellowLogoLEDs77) / sizeof(yellowLogoLEDs77[0]), CRGB(249,239,11));
  setLEDColors(greenLogoLEDs77, sizeof(greenLogoLEDs77) / sizeof(greenLogoLEDs77[0]), CRGB(44,254,27));
  setLEDColors(blackLogoLEDs77, sizeof(blackLogoLEDs77) / sizeof(blackLogoLEDs77[0]), CRGB(0, 0, 0));
  FastLED.show();
  delay(250);
   FastLED.clear();
 
      //Set the 78st frame
    //background
  setLEDColors(yellowBackgroundLEDs, sizeof(yellowBackgroundLEDs) / sizeof(yellowBackgroundLEDs[0]), CRGB(249,239,11));
  setLEDColors(greenBackgroundLEDs, sizeof(greenBackgroundLEDs) / sizeof(greenBackgroundLEDs[0]), CRGB(44,254,27));
 //Green hills and Yellow clouds

  //logo
  setLEDColors(darkGreyLogoLEDs78, sizeof(darkGreyLogoLEDs78) / sizeof(darkGreyLogoLEDs78[0]), CRGB(90, 88, 72));
  setLEDColors(lightGreyLogoLEDs78, sizeof(lightGreyLogoLEDs78) / sizeof(lightGreyLogoLEDs78[0]), CRGB(213,212,232));
  setLEDColors(redLogoLEDs78, sizeof(redLogoLEDs78) / sizeof(redLogoLEDs78[0]), CRGB(211, 4, 4));
  setLEDColors(tanLogoLEDs78, sizeof(tanLogoLEDs78) / sizeof(tanLogoLEDs78[0]), CRGB(255, 100, 40));
  setLEDColors(yellowLogoLEDs78, sizeof(yellowLogoLEDs78) / sizeof(yellowLogoLEDs78[0]), CRGB(249,239,11));
  setLEDColors(greenLogoLEDs78, sizeof(greenLogoLEDs78) / sizeof(greenLogoLEDs78[0]), CRGB(44,254,27));
  setLEDColors(blackLogoLEDs78, sizeof(blackLogoLEDs78) / sizeof(blackLogoLEDs78[0]), CRGB(0, 0, 0));
  FastLED.show();
  delay(250);
   FastLED.clear();
 
      //Set the 79st frame
    //background
  setLEDColors(yellowBackgroundLEDs, sizeof(yellowBackgroundLEDs) / sizeof(yellowBackgroundLEDs[0]), CRGB(249,239,11));
  setLEDColors(greenBackgroundLEDs, sizeof(greenBackgroundLEDs) / sizeof(greenBackgroundLEDs[0]), CRGB(44,254,27));
 //Green hills and Yellow clouds

  //logo
  setLEDColors(darkGreyLogoLEDs79, sizeof(darkGreyLogoLEDs79) / sizeof(darkGreyLogoLEDs79[0]), CRGB(90, 88, 72));
  setLEDColors(lightGreyLogoLEDs79, sizeof(lightGreyLogoLEDs79) / sizeof(lightGreyLogoLEDs79[0]), CRGB(213,212,232));
  setLEDColors(redLogoLEDs79, sizeof(redLogoLEDs79) / sizeof(redLogoLEDs79[0]), CRGB(211, 4, 4));
  setLEDColors(tanLogoLEDs79, sizeof(tanLogoLEDs79) / sizeof(tanLogoLEDs79[0]), CRGB(255, 100, 40));
  setLEDColors(yellowLogoLEDs79, sizeof(yellowLogoLEDs79) / sizeof(yellowLogoLEDs79[0]), CRGB(249,239,11));
  setLEDColors(greenLogoLEDs79, sizeof(greenLogoLEDs79) / sizeof(greenLogoLEDs79[0]), CRGB(44,254,27));
  setLEDColors(blackLogoLEDs79, sizeof(blackLogoLEDs79) / sizeof(blackLogoLEDs79[0]), CRGB(0, 0, 0));
  FastLED.show();
  delay(250);
   FastLED.clear();
 
      //Set the 80st frame
    //background
  setLEDColors(yellowBackgroundLEDs, sizeof(yellowBackgroundLEDs) / sizeof(yellowBackgroundLEDs[0]), CRGB(249,239,11));
  setLEDColors(greenBackgroundLEDs, sizeof(greenBackgroundLEDs) / sizeof(greenBackgroundLEDs[0]), CRGB(44,254,27));
 //Green hills and Yellow clouds

  //logo
  setLEDColors(darkGreyLogoLEDs80, sizeof(darkGreyLogoLEDs80) / sizeof(darkGreyLogoLEDs80[0]), CRGB(90, 88, 72));
  setLEDColors(lightGreyLogoLEDs80, sizeof(lightGreyLogoLEDs80) / sizeof(lightGreyLogoLEDs80[0]), CRGB(213,212,232));
  setLEDColors(redLogoLEDs80, sizeof(redLogoLEDs80) / sizeof(redLogoLEDs80[0]), CRGB(211, 4, 4));
  setLEDColors(tanLogoLEDs80, sizeof(tanLogoLEDs80) / sizeof(tanLogoLEDs80[0]), CRGB(255, 100, 40));
  setLEDColors(yellowLogoLEDs80, sizeof(yellowLogoLEDs80) / sizeof(yellowLogoLEDs80[0]), CRGB(249,239,11));
  setLEDColors(greenLogoLEDs80, sizeof(greenLogoLEDs80) / sizeof(greenLogoLEDs80[0]), CRGB(44,254,27));
  setLEDColors(blackLogoLEDs80, sizeof(blackLogoLEDs80) / sizeof(blackLogoLEDs80[0]), CRGB(0, 0, 0));
  FastLED.show();
  delay(250);
   FastLED.clear();
 
      //Set the 81st frame
    //background
  setLEDColors(yellowBackgroundLEDs, sizeof(yellowBackgroundLEDs) / sizeof(yellowBackgroundLEDs[0]), CRGB(249,239,11));
  setLEDColors(greenBackgroundLEDs, sizeof(greenBackgroundLEDs) / sizeof(greenBackgroundLEDs[0]), CRGB(44,254,27));
 //Green hills and Yellow clouds

  //logo
  setLEDColors(darkGreyLogoLEDs81, sizeof(darkGreyLogoLEDs81) / sizeof(darkGreyLogoLEDs81[0]), CRGB(90, 88, 72));
  setLEDColors(lightGreyLogoLEDs81, sizeof(lightGreyLogoLEDs81) / sizeof(lightGreyLogoLEDs81[0]), CRGB(213,212,232));
  setLEDColors(redLogoLEDs81, sizeof(redLogoLEDs81) / sizeof(redLogoLEDs81[0]), CRGB(211, 4, 4));
  setLEDColors(tanLogoLEDs81, sizeof(tanLogoLEDs81) / sizeof(tanLogoLEDs81[0]), CRGB(255, 100, 40));
  setLEDColors(yellowLogoLEDs81, sizeof(yellowLogoLEDs81) / sizeof(yellowLogoLEDs81[0]), CRGB(249,239,11));
  setLEDColors(greenLogoLEDs81, sizeof(greenLogoLEDs81) / sizeof(greenLogoLEDs81[0]), CRGB(44,254,27));
  setLEDColors(blackLogoLEDs81, sizeof(blackLogoLEDs81) / sizeof(blackLogoLEDs81[0]), CRGB(0, 0, 0));
  FastLED.show();
  delay(250);
   FastLED.clear();
 
      //Set the 82st frame
    //background
  setLEDColors(yellowBackgroundLEDs, sizeof(yellowBackgroundLEDs) / sizeof(yellowBackgroundLEDs[0]), CRGB(249,239,11));
  setLEDColors(greenBackgroundLEDs, sizeof(greenBackgroundLEDs) / sizeof(greenBackgroundLEDs[0]), CRGB(44,254,27));
 //Green hills and Yellow clouds

  //logo
  setLEDColors(darkGreyLogoLEDs82, sizeof(darkGreyLogoLEDs82) / sizeof(darkGreyLogoLEDs82[0]), CRGB(90, 88, 72));
  setLEDColors(lightGreyLogoLEDs82, sizeof(lightGreyLogoLEDs82) / sizeof(lightGreyLogoLEDs82[0]), CRGB(213,212,232));
  setLEDColors(redLogoLEDs82, sizeof(redLogoLEDs82) / sizeof(redLogoLEDs82[0]), CRGB(211, 4, 4));
  setLEDColors(tanLogoLEDs82, sizeof(tanLogoLEDs82) / sizeof(tanLogoLEDs82[0]), CRGB(255, 100, 40));
  setLEDColors(yellowLogoLEDs82, sizeof(yellowLogoLEDs82) / sizeof(yellowLogoLEDs82[0]), CRGB(249,239,11));
  setLEDColors(greenLogoLEDs82, sizeof(greenLogoLEDs82) / sizeof(greenLogoLEDs82[0]), CRGB(44,254,27));
  setLEDColors(blackLogoLEDs82, sizeof(blackLogoLEDs82) / sizeof(blackLogoLEDs82[0]), CRGB(0, 0, 0));
  FastLED.show();
  delay(250);
   FastLED.clear();
 
      //Set the 83st frame
    //background
  setLEDColors(yellowBackgroundLEDs, sizeof(yellowBackgroundLEDs) / sizeof(yellowBackgroundLEDs[0]), CRGB(249,239,11));
  setLEDColors(greenBackgroundLEDs, sizeof(greenBackgroundLEDs) / sizeof(greenBackgroundLEDs[0]), CRGB(44,254,27));
 //Green hills and Yellow clouds

  //logo
  setLEDColors(darkGreyLogoLEDs83, sizeof(darkGreyLogoLEDs83) / sizeof(darkGreyLogoLEDs83[0]), CRGB(90, 88, 72));
  setLEDColors(lightGreyLogoLEDs83, sizeof(lightGreyLogoLEDs83) / sizeof(lightGreyLogoLEDs83[0]), CRGB(213,212,232));
  setLEDColors(redLogoLEDs83, sizeof(redLogoLEDs83) / sizeof(redLogoLEDs83[0]), CRGB(211, 4, 4));
  setLEDColors(tanLogoLEDs83, sizeof(tanLogoLEDs83) / sizeof(tanLogoLEDs83[0]), CRGB(255, 100, 40));
  setLEDColors(yellowLogoLEDs83, sizeof(yellowLogoLEDs83) / sizeof(yellowLogoLEDs83[0]), CRGB(249,239,11));
  setLEDColors(greenLogoLEDs83, sizeof(greenLogoLEDs83) / sizeof(greenLogoLEDs83[0]), CRGB(44,254,27));
  setLEDColors(blackLogoLEDs83, sizeof(blackLogoLEDs83) / sizeof(blackLogoLEDs83[0]), CRGB(0, 0, 0));
  FastLED.show();
  delay(250);
   FastLED.clear();
 
      //Set the 84st frame
    //background
  setLEDColors(yellowBackgroundLEDs, sizeof(yellowBackgroundLEDs) / sizeof(yellowBackgroundLEDs[0]), CRGB(249,239,11));
  setLEDColors(greenBackgroundLEDs, sizeof(greenBackgroundLEDs) / sizeof(greenBackgroundLEDs[0]), CRGB(44,254,27));
 //Green hills and Yellow clouds

  //logo
  setLEDColors(darkGreyLogoLEDs84, sizeof(darkGreyLogoLEDs84) / sizeof(darkGreyLogoLEDs84[0]), CRGB(90, 88, 72));
  setLEDColors(lightGreyLogoLEDs84, sizeof(lightGreyLogoLEDs84) / sizeof(lightGreyLogoLEDs84[0]), CRGB(213,212,232));
  setLEDColors(redLogoLEDs84, sizeof(redLogoLEDs84) / sizeof(redLogoLEDs84[0]), CRGB(211, 4, 4));
  setLEDColors(tanLogoLEDs84, sizeof(tanLogoLEDs84) / sizeof(tanLogoLEDs84[0]), CRGB(255, 100, 40));
  setLEDColors(yellowLogoLEDs84, sizeof(yellowLogoLEDs84) / sizeof(yellowLogoLEDs84[0]), CRGB(249,239,11));
  setLEDColors(greenLogoLEDs84, sizeof(greenLogoLEDs84) / sizeof(greenLogoLEDs84[0]), CRGB(44,254,27));
  setLEDColors(blackLogoLEDs84, sizeof(blackLogoLEDs84) / sizeof(blackLogoLEDs84[0]), CRGB(0, 0, 0));
  FastLED.show();
  delay(250);
   FastLED.clear();
 
      //Set the 85st frame
    //background
  setLEDColors(yellowBackgroundLEDs, sizeof(yellowBackgroundLEDs) / sizeof(yellowBackgroundLEDs[0]), CRGB(249,239,11));
  setLEDColors(greenBackgroundLEDs, sizeof(greenBackgroundLEDs) / sizeof(greenBackgroundLEDs[0]), CRGB(44,254,27));
 //Green hills and Yellow clouds

  //logo
  setLEDColors(darkGreyLogoLEDs85, sizeof(darkGreyLogoLEDs85) / sizeof(darkGreyLogoLEDs85[0]), CRGB(157,148,147));
  setLEDColors(lightGreyLogoLEDs85, sizeof(lightGreyLogoLEDs85) / sizeof(lightGreyLogoLEDs85[0]), CRGB(213,212,232));
  setLEDColors(redLogoLEDs85, sizeof(redLogoLEDs85) / sizeof(redLogoLEDs85[0]), CRGB(211, 4, 4));
  setLEDColors(tanLogoLEDs85, sizeof(tanLogoLEDs85) / sizeof(tanLogoLEDs85[0]), CRGB(255, 100, 40));
  setLEDColors(yellowLogoLEDs85, sizeof(yellowLogoLEDs85) / sizeof(yellowLogoLEDs85[0]), CRGB(249,239,11));
  setLEDColors(greenLogoLEDs85, sizeof(greenLogoLEDs85) / sizeof(greenLogoLEDs85[0]), CRGB(44,254,27));
  setLEDColors(blackLogoLEDs85, sizeof(blackLogoLEDs85) / sizeof(blackLogoLEDs85[0]), CRGB(0, 0, 0));
  FastLED.show();
  delay(250);
   FastLED.clear();
 





 
}
