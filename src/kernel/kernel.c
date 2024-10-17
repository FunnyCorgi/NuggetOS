// #include "drivers/screen.h"
void main(){
    char* video_memory = (char*) 0xb8000;
    *video_memory = 'H';
    video_memory++;
    video_memory++;
    *video_memory = 'e';
    video_memory++;
    video_memory++;
    *video_memory = 'l';
    video_memory++;
    video_memory++;
    *video_memory = 'l';
    video_memory++;
    video_memory++;
    *video_memory = 'o';
    video_memory++;
    video_memory++;
    *video_memory = '!';
}