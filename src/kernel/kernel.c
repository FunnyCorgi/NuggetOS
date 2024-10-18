#include "../drivers/ports.h"

void main() {
    /* Screen cursor position: ask VGA control register (0x3d4) for bytes
     * 14 = high byte of cursor and 15 = low byte of cursor. */
    port_byte_out(0x3d4, 14); /* Requesting byte 14: high byte of cursor pos */
    /* Data is returned in VGA data register (0x3d5) */
    int position = port_byte_in(0x3d5);
    position = position << 8; /* high byte */

    port_byte_out(0x3d4, 15); /* requesting low byte */
    position += port_byte_in(0x3d5);

    /* VGA 'cells' consist of the character and its control data
     * e.g. 'white on black background', 'red text on white bg', etc */
    int offset_from_vga = position * 2; 

    /* Let's write on the current cursor position, we already know how
     * to do that */
    char *vga = (char *) 0xb8000;
    vga[offset_from_vga] = 'X'; 
    vga[offset_from_vga+1] = 0x0f;//white on black
    
    // testing color changes
    /*
        Available Colors for 2nd byte to be written to VGA:
    Num     Color           Num+Bright Bit Color

    0x0	    Black	        0x8	            Dark Gray
    0x1 	Blue	        0x9	            Light Blue
    0x2 	Green	        0xa	            Light Green
    0x3 	Cyan	        0xb	            Light Cyan
    0x4 	Red	            0xc	            Light Red
    0x5 	Magenta	        0xd	            Pink
    0x6 	Brown	        0xe	            Yellow
    0x7 	Light Gray	    0xf	            White
    */
    vga[offset_from_vga+2] = 'Y';
    vga[offset_from_vga+3] = 0x0e | 0x01;//should be black baskground with yellow blinking text
    vga[offset_from_vga+4] = 'Z';
    vga[offset_from_vga+5] = 0x0e | 0b00000001;//should be black baskground with yellow blinking text as well
    
}