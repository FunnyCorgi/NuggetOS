#include "keyboard.h"
#include "ports.h"
#include "../cpu/isr.h"
#include "screen.h"
#include "../kernel/util.h"  // Ensure util functions are included

typedef enum {
    //keydowns

    KeyA = 0x001E,
    KeyB = 0x0030,
    KeyC = 0x002E,
    KeyD = 0x0020,
    KeyE = 0x0012,
    KeyF = 0x0021,
    KeyG = 0x0022,
    KeyH = 0x0023,
    KeyI = 0x0017,
    KeyJ = 0x0024,
    KeyK = 0x0025,
    KeyL = 0x0026,
    KeyM = 0x0032,
    KeyN = 0x0031,
    KeyO = 0x0018,
    KeyP = 0x0019,
    KeyQ = 0x0010,
    KeyR = 0x0013,
    KeyS = 0x001F,
    KeyT = 0x0014,
    KeyU = 0x0016,
    KeyV = 0x002F,
    KeyW = 0x0011,
    KeyX = 0x002D,
    KeyY = 0x0015,
    KeyZ = 0x002C,


    Digit0 = 0x000B,
    Digit1 = 0x0002,
    Digit2 = 0x0003,
    Digit3 = 0x0004,
    Digit4 = 0x0005,
    Digit5 = 0x0006,
    Digit6 = 0x0007,
    Digit7 = 0x0008,
    Digit8 = 0x0009,
    Digit9 = 0x000A,


    Numpad1 = 0x004F,
    Numpad2 = 0x0050,
    Numpad3 = 0x0051,
    Numpad4 = 0x004B,
    Numpad5 = 0x004C,
    Numpad6 = 0x004D,
    Numpad7 = 0x0047,
    Numpad8 = 0x0048,
    Numpad9 = 0x0049,
    Numpad0 = 0x0052,


    Quote = 0x0028,
    Comma = 0x0033,
    Minus = 0x000C,
    Period = 0x0034,
    Slash = 0x0035,
    Semicolon = 0x0027,
    Equal = 0x000D,
    BracketLeft = 0x001A,
    BracketRight = 0x001B,
    Backquote = 0x0029,
    Backspace = 0x000E,
    Tab = 0x000F,
    Space = 0x0039,
    NumpadDecimal = 0x0053,
    NumpadSubtract = 0x004A,
    NumpadAdd = 0x004E,


    Enter = 0x001C,
    Escape = 0x0001,
    F1 = 0x003B,
    F2 = 0x003C,
    F3 = 0x003D,
    F4 = 0x003E,
    F5 = 0x003F,
    F6 = 0x0040,
    F7 = 0x0041,
    F8 = 0x0042,
    F9 = 0x0043,
    F10 = 0x0044,
    F11 = 0x0057,
    F12 = 0x0058,


    NumpadEnter = 0xE01C,
    NumpadDivide = 0xE035,
    NumpadMultiply = 0x0037,


    End = 0xE04F,
    ArrowDown = 0xE050,
    PageDown = 0xE051,
    ArrowLeft = 0xE04B,
    ArrowRight = 0xE04D,
    Home = 0xE047,
    ArrowUp = 0xE048,
    PageUp = 0xE049,
    Insert = 0xE052,
    Delete = 0xE053,


    ControlLeft = 0x001D,
    ShiftLeft = 0x002A,
    ShiftRight = 0x0036,
    CapsLock = 0x003A,
    NumLock = 0x0045,
    ScrollLock = 0x0046,
    AltLeft = 0x0038,
    AltRight = 0xE038,
    ControlRight = 0xE01D,
    Pause = 0xE11D,
    MetaLeft = 0xE05B,
    MetaRight = 0xE05C,
    ContextMenu = 0xE05D,
    Backslash = 0x002B,
    IntlBackslash = 0x0056,


    Plus = 0x0D,
    Tilde = 0x29,
    KeypadAsterisk = 0x37
} Keycode;

void print_letter(u8 scancode);

static void keyboard_callback(registers_t regs) {
    /* The PIC leaves us the scancode in port 0x60 */
    u8 scancode = port_byte_in(0x60);
    char sc_ascii[4];  // Fixed-size char array for ASCII conversion
    int_to_ascii(scancode, sc_ascii);

    kprint("Keyboard scancode: ");
    kprint(sc_ascii);
    kprint(", ");
    print_letter(scancode);
    kprint("\n");
}

void init_keyboard() {
   register_interrupt_handler(IRQ1, keyboard_callback); 
}

void print_letter(u8 scancode) {
    switch ((Keycode) scancode) {
        case 0x0:  kprint("ERROR"); break;
        case Escape:  kprint("ESC"); break;
        case Digit1:  kprint("1"); break;
        case Digit2:  kprint("2"); break;
        case Digit3:  kprint("3"); break;
        case Digit4:  kprint("4"); break;
        case Digit5:  kprint("5"); break;
        case Digit6:  kprint("6"); break;
        case Digit7:  kprint("7"); break;
        case Digit8:  kprint("8"); break;
        case Digit9: kprint("9"); break;
        case Digit0: kprint("0"); break;
        case Minus: kprint("-"); break;
        case Plus: kprint("+"); break;
        case Backspace: kprint("Backspace"); break;
        case Tab: kprint("Tab"); break;
        case KeyQ: kprint("Q"); break;
        case KeyW: kprint("W"); break;
        case KeyE: kprint("E"); break;
        case KeyR: kprint("R"); break;
        case KeyT: kprint("T"); break;
        case KeyY: kprint("Y"); break;
        case KeyU: kprint("U"); break;
        case KeyI: kprint("I"); break;
        case KeyO: kprint("O"); break;
        case KeyP: kprint("P"); break;
        case BracketLeft: kprint("["); break;
        case BracketRight: kprint("]"); break;
        case Enter: kprint("ENTER"); break;
        case NumpadEnter: kprint("NumpadEnter"); break;
        case ControlLeft: kprint("LCtrl"); break;
        case KeyA: kprint("A"); break;
        case KeyS: kprint("S"); break;
        case KeyD: kprint("D"); break;
        case KeyF: kprint("F"); break;
        case KeyG: kprint("G"); break;
        case KeyH: kprint("H"); break;
        case KeyJ: kprint("J"); break;
        case KeyK: kprint("K"); break;
        case KeyL: kprint("L"); break;
        case Semicolon: kprint(";"); break;
        case Quote: kprint("'"); break;
        case Tilde: kprint("`"); break;
        case ShiftLeft: kprint("LShift"); break;
        case Backslash: kprint("\\"); break;
        case KeyZ: kprint("Z"); break;
        case KeyX: kprint("X"); break;
        case KeyC: kprint("C"); break;
        case KeyV: kprint("V"); break;
        case KeyB: kprint("B"); break;
        case KeyN: kprint("N"); break;
        case KeyM: kprint("M"); break;
        case Comma: kprint(","); break;
        case Period: kprint("."); break;
        case Slash: kprint("/"); break;
        case ShiftRight: kprint("Rshift"); break;
        case KeypadAsterisk: kprint("Keypad *"); break;
        case AltLeft: kprint("LAlt"); break;
        case Space: kprint("Spc"); break;
        default:
            if (scancode <= 0x7f) {
                kprint("Unknown key down");
            } else if (scancode <= 0x39 + 0x80) {
                kprint("key up ");
                print_letter(scancode - 0x80);
            } else kprint("Unknown key up");
            break;
    }
}
